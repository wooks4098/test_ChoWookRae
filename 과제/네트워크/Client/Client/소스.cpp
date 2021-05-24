
// TCPClient.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <iostream> 
#include <WinSock2.h>

#define MAX_BUFFER_SIZE 2048

int main()
{
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
    char buf[MAX_BUFFER_SIZE + 1];
    // ������ ������ ���.
    while (1)
    {
        // ������ �Է�.
        ZeroMemory(buf, sizeof(buf));
        printf("\n[���� ������]");
        if (fgets(buf, MAX_BUFFER_SIZE + 1, stdin) == NULL) break;

        // '\n' ���� ����.
        len = strlen(buf);
        if (buf[len - 1] == '\n') buf[len - 1] = '\0';
        if (strlen(buf) == 0) break;

        // ������ ������.
        retval = send(sock, buf, strlen(buf), 0);
        if (SOCKET_ERROR == retval)
        {
            printf("send()");
            break;
        }

        printf("[TCP Ŭ���̾�Ʈ] %d����Ʈ�� ���½��ϴ�.\n", retval);

        // ������ �ޱ�.
        ZeroMemory(buf, sizeof(buf));
        retval = recv(sock, buf, retval, 0);
        if (SOCKET_ERROR == retval)
        {
            printf("recv()");
            break;
        }
        else if (0 == retval) break;

        // ���� ������ ���.
        buf[retval] = '\0';
        printf("[TCP Ŭ���̾�Ʈ] %d����Ʈ�� �޾ҽ��ϴ�.\n", retval);
        printf("[���� ������]%s\n", buf);
    }

    closesocket(sock);

    WSACleanup();
}