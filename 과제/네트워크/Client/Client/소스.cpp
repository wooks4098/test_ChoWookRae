
// TCPClient.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <iostream> 
#include <WinSock2.h>

#define MAX_BUFFER_SIZE 2048
#pragma pack(1)

struct PackHeader
{
    int type;
    PackHeader(int value) : type(value) {}
};
struct UserMessage : public PackHeader
{
    char msg[132];
    UserMessage() : PackHeader(0) {}
};
struct UserData : public PackHeader
{
    char Name[128];
    int Level;

    UserData() : PackHeader(1) {}
};
#pragma pack()
int main()
{
    bool isLogin = false;

    // 윈속 초기화.
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return -1;

    // socket() 소켓 생성.
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (INVALID_SOCKET == sock) exit(-1);

    // 서버 정보 객체 설정.
    SOCKADDR_IN serveraddr;
    ZeroMemory(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9000);
    serveraddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    // connect()
    if (SOCKET_ERROR == connect(sock, (SOCKADDR*)&serveraddr, sizeof(serveraddr))) exit(-1);

    int len, retval;
    char buf[sizeof(UserData)];
    // 서버와 데이터 통신.
    while (1)
    {
        // 데이터 입력.
        ZeroMemory(buf, sizeof(buf));


        if (!isLogin)
        {
            isLogin = true;
            UserData userData;
            ZeroMemory(&userData, sizeof(userData));
            printf("[이름 입력]");
            if (fgets(userData.Name, sizeof(userData.Name), stdin) == NULL) break;
            printf("[레벨 입력]");
            char Level[4];
            if (fgets(Level, sizeof(Level), stdin) == NULL) break;
            userData.Level = (int)Level;

            //scanf("%d", &userData.Level);
            // 데이터 보내기.
            retval = send(sock, (char*)&userData, sizeof(userData), 0);
            if (SOCKET_ERROR == retval)
            {
                printf("send()");
                break;
            }
        }
        else
        {
            UserMessage Msg;
            printf("[채팅 입력]");
            if (fgets(Msg.msg, sizeof(Msg.msg), stdin) == NULL) break;
            // 데이터 보내기.
            retval = send(sock, (char*)&Msg, sizeof(Msg), 0);
            if (SOCKET_ERROR == retval)
            {
                printf("send()");
                break;
            }
        }




        printf("[TCP 클라이언트] %d바이트를 보냈습니다.\n", retval);

        // 데이터 받기.
        ZeroMemory(buf, sizeof(buf));
        retval = recv(sock, buf, retval, 0);
       // printf()
        UserMessage* Msg = (UserMessage*)buf;
        printf(Msg->msg);
        if (SOCKET_ERROR == retval)
        {
            printf("recv()");
            break;
        }
        else if (0 == retval) break;

        // 받은 데이터 출력.
       // buf[retval] = '\0';
        printf("[TCP 클라이언트] %d바이트를 받았습니다.\n", retval);
        printf("[받은 데이터]%s\n", buf);
    }

    closesocket(sock);

    WSACleanup();
}