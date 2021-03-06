// Network.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <WinSock2.h>
#include <vector>
#include <algorithm>

#pragma pack(1)
struct PackHeader
{
    int type;
    PackHeader(int value) : type(value) {}
};
struct UserMessage : public PackHeader
{
    char msg[128];
    UserMessage() : PackHeader(0) {}
};
struct UserData : public PackHeader
{
    char Name[128];

    UserData() : PackHeader(1) {}
};
#pragma pack()

#define MAX_BUFFER_SIZE 2048
HANDLE g_hMutex; // 전역 변수로 선언.
std::vector<SOCKET> Save_Socket;
//g_hMutex = CreateMutex(NULL, false, NULL);
// 공용 리소스를 사용, 임의의 시간(INFINITE:작업이 끝날 때 까지)동안 대기.
//WaitForSingleObject(g_hMutex, INFINITE);
//ReleaseMutex(g_hMutex); // 공용 리소스 사용이 끝났다.
//CloseHandle(g_hMutex); // 뮤텍스 사용을 끝내고 제거.
DWORD WINAPI ProcessClient(LPVOID arg)
{
    SOCKET client_sock = (SOCKET)arg;
    SOCKADDR_IN clientaddr;
    int addrlen = sizeof(clientaddr);
    getpeername(client_sock, (SOCKADDR*)&clientaddr, &addrlen); // 클라이언트 정보 얻기.
    int retval;
    char buf[sizeof(UserMessage)];
    std::string name;
    UserData* userData;
    UserMessage SendMessage;
    while (1)
    {
        ZeroMemory(buf, sizeof(buf));
        // 데이터 받기.
        retval = recv(client_sock, buf, sizeof(buf), 0);

        if (SOCKET_ERROR == retval)
        {
            printf("recv()");
            break;
        }
        else if (0 == retval) break;

        PackHeader* data = (PackHeader*)buf;

        ZeroMemory(&SendMessage, sizeof(SendMessage));
        switch (data->type)
        {
        case 0:
        {
            UserMessage* Msg = (UserMessage*)buf;
            std::string str;
            str.append("[");
            str.append(name);
            str.append("] : ");
            str.append(Msg->msg);
            strcpy(SendMessage.msg, str.c_str());
            break;
        }
        case 1:
        {
            userData = (UserData*)buf;

            name = userData->Name;
            std::string str;
            str.append(name);
            str.append("님이 접속하셨습니다.");

            strcpy(SendMessage.msg, str.c_str());
           // auto str = strcat(userData->Name, "님이 접속하셨습니다.");
           // strcpy_s(SendMessage.msg, strlen(SendMessage.msg), str);

            break;
        }
        default:
            break;
        }

        

        //send_data.type

        WaitForSingleObject(g_hMutex, INFINITE);
        printf(SendMessage.msg);
        printf("\n");
        // 데이터 보내기.
        for (auto sock : Save_Socket)
        {
            if (data->type == 1 && client_sock == sock)
                continue;
            retval = send(sock, (char*)&SendMessage, sizeof(SendMessage), 0);
            if (SOCKET_ERROR == retval)
            {
                printf("send()");
                break;
            }
        }
        ReleaseMutex(g_hMutex);
    }

    // closesocket()
    WaitForSingleObject(g_hMutex, INFINITE);
    auto re = std::find(Save_Socket.begin(), Save_Socket.end(), client_sock);
    if (re != Save_Socket.end())
        Save_Socket.erase(re);
    std::string str;
    str.append(name);
    str.append("님이 접속을 종료하셨습니다.");
    ZeroMemory(&SendMessage, sizeof(SendMessage));

    strcpy_s(SendMessage.msg, sizeof(SendMessage.msg), str.c_str());
    for (auto sock : Save_Socket)
    {

        retval = send(sock, (char*)&SendMessage, sizeof(SendMessage), 0);
        if (SOCKET_ERROR == retval)
        {
            printf("send()");
            break;
        }
    }
    ReleaseMutex(g_hMutex);
    closesocket(client_sock);
    printf("\n[TCP 서버] 클라이언트 종료 : IP 주소=%s, 포트 번호=%d\n",
        inet_ntoa(clientaddr.sin_addr),
        ntohs(clientaddr.sin_port));

    return 0;
}

int main()
{

    // 윈속 초기화.
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return -1;

    // socket() 소켓 생성.
    SOCKET listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (INVALID_SOCKET == listen_socket) exit(-1);

    // 서버 정보 객체 설정.
    // INADDR_ANY : 서버의 IP 주소를 자동으로 찾아서 대입해주는 함수(복잡한 #define문의로 정의 됨)
    // 서버가 두 개 이상의 IP를 가진 경우(multihomed host)가 아니면 해당 값을 사용.
    SOCKADDR_IN serveraddr;
    // 해당 메모리에 있을 쓰래기 값을 0으로 지워준다.
    ZeroMemory(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9000);
    serveraddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

    // bind() 소켓 설정.
    if (bind(listen_socket, (SOCKADDR*)&serveraddr, sizeof(serveraddr)) == SOCKET_ERROR)
    {
        closesocket(listen_socket);
        WSACleanup();
        printf("bind()");
        exit(-1);
    }

    // listen() 수신 대기열 생성.
    // SOMAXCONN : Socket Max Connection
    if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR)
    {
        closesocket(listen_socket);
        WSACleanup();
        printf("listen()");
        exit(-1);
    }

    // 데이터 통신에 사용할 변수.
    SOCKADDR_IN clientaddr;
    int addrlen = sizeof(SOCKADDR_IN);
    ZeroMemory(&clientaddr, addrlen);


    int retval;
    char buf[MAX_BUFFER_SIZE + 1];

    SOCKET client_socket;
    HANDLE hThread;
    DWORD threadID;

    g_hMutex = CreateMutex(NULL, false, NULL);
    if (NULL == g_hMutex) return -1; // 뮤텍스 생성 실패.
    if (GetLastError() == ERROR_ALREADY_EXISTS) // 이미 생성된 뮤텍스가 있습니다!!
    {
        CloseHandle(g_hMutex);
        return -1;
    }
    while (1)
    {
        // accept() 연결 대기.
        client_socket = accept(listen_socket, (SOCKADDR*)&clientaddr, &addrlen);
        if (INVALID_SOCKET == client_socket)
        {
            printf("accept()");
            continue;
        }

        printf("\n[TCP 서버] 클라이언트 접속 : IP 주소=%s, 포트 번호=%d\n",
            inet_ntoa(clientaddr.sin_addr),
            ntohs(clientaddr.sin_port));

        WaitForSingleObject(g_hMutex, INFINITE);    
        Save_Socket.push_back(client_socket);
        ReleaseMutex(g_hMutex);
        hThread = CreateThread(NULL, 0, ProcessClient, (LPVOID)client_socket, 0, &threadID);
        if (NULL == hThread) std::cout << "[오류] 스레드 생성 실패!" << std::endl;
        else CloseHandle(hThread);
    }

    // closesocket().
    // 리슨 소켓 종료.
    closesocket(listen_socket);

    // 윈속 종료.
    WSACleanup();



    CloseHandle(g_hMutex);
}