
// TCPClient.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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

    // ���� �ʱ�ȭ.
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return -1;

    // socket() ���� ����.
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (INVALID_SOCKET == sock) exit(-1);

    // ���� ���� ��ü ����.
    SOCKADDR_IN serveraddr;
    ZeroMemory(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9000);
    serveraddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    // connect()
    if (SOCKET_ERROR == connect(sock, (SOCKADDR*)&serveraddr, sizeof(serveraddr))) exit(-1);

    int len, retval;
    char buf[sizeof(UserData)];
    // ������ ������ ���.
    while (1)
    {
        // ������ �Է�.
        ZeroMemory(buf, sizeof(buf));


        if (!isLogin)
        {
            isLogin = true;
            UserData userData;
            ZeroMemory(&userData, sizeof(userData));
            printf("[�̸� �Է�]");
            if (fgets(userData.Name, sizeof(userData.Name), stdin) == NULL) break;
            printf("[���� �Է�]");
            char Level[4];
            if (fgets(Level, sizeof(Level), stdin) == NULL) break;
            userData.Level = (int)Level;

            //scanf("%d", &userData.Level);
            // ������ ������.
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
            printf("[ä�� �Է�]");
            if (fgets(Msg.msg, sizeof(Msg.msg), stdin) == NULL) break;
            // ������ ������.
            retval = send(sock, (char*)&Msg, sizeof(Msg), 0);
            if (SOCKET_ERROR == retval)
            {
                printf("send()");
                break;
            }
        }




        printf("[TCP Ŭ���̾�Ʈ] %d����Ʈ�� ���½��ϴ�.\n", retval);

        // ������ �ޱ�.
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

        // ���� ������ ���.
       // buf[retval] = '\0';
        printf("[TCP Ŭ���̾�Ʈ] %d����Ʈ�� �޾ҽ��ϴ�.\n", retval);
        printf("[���� ������]%s\n", buf);
    }

    closesocket(sock);

    WSACleanup();
}