// Network.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <WinSock2.h>

#define MAX_BUFFER_SIZE 2048
HANDLE hThread;
DWORD threadID;
SOCKET client_socket;

//HANDLE CreateThread(
//    LPSECURITY_ATTRIBUTES lpThreadAttributes,
//    SIZE_T dwStackSize,
//    LPTHREAD_START_ROUTINE lpStartAddress,
//    LPVOID lpParameter,
//    DWORD dwCreationFlags,
//    LPDWORD lpThreadId);

DWORD WINAPI ProcessClient(LPVOID arg)
{
    SOCKET client_sock = (SOCKET)arg;
    SOCKADDR_IN clientaddr;
    int addrlen = sizeof(clientaddr);
    getpeername(client_sock, (SOCKADDR*)&clientaddr, &addrlen); // Ŭ���̾�Ʈ ���� ���.
    int retval;
    char buf[MAX_BUFFER_SIZE + 1];
    while (1)
    {
        ZeroMemory(buf, MAX_BUFFER_SIZE + 1);
        // ������ �ޱ�.
        retval = recv(client_socket, buf, MAX_BUFFER_SIZE, 0);

        if (SOCKET_ERROR == retval)
        {
            printf("recv()");
            break;
        }
        else if (0 == retval) break;

        // ���� ������ ���.
        buf[retval] = '\0';
        printf("\n[TCP/%s:%d]%s\n",
            inet_ntoa(clientaddr.sin_addr),
            ntohs(clientaddr.sin_port),
            buf);

        // ������ ������.
        retval = send(client_socket, buf, retval, 0);
        if (SOCKET_ERROR == retval)
        {
            printf("send()");
            break;
        }
    }

    // closesocket()
    closesocket(client_sock);
    printf("\n[TCP ����] Ŭ���̾�Ʈ ���� : IP �ּ�=%s, ��Ʈ ��ȣ=%d\n",
        inet_ntoa(clientaddr.sin_addr),
        ntohs(clientaddr.sin_port));

    return 0;
}

int main()
{
    // ���� �ʱ�ȭ.
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return -1;

    // socket() ���� ����.
    SOCKET listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (INVALID_SOCKET == listen_socket) exit(-1);

    // ���� ���� ��ü ����.
    // INADDR_ANY : ������ IP �ּҸ� �ڵ����� ã�Ƽ� �������ִ� �Լ�(������ #define���Ƿ� ���� ��)
    // ������ �� �� �̻��� IP�� ���� ���(multihomed host)�� �ƴϸ� �ش� ���� ���.
    SOCKADDR_IN serveraddr;
    // �ش� �޸𸮿� ���� ������ ���� 0���� �����ش�.
    ZeroMemory(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9000);
    serveraddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

    // bind() ���� ����.
    if (bind(listen_socket, (SOCKADDR*)&serveraddr, sizeof(serveraddr)) == SOCKET_ERROR)
    {
        closesocket(listen_socket);
        WSACleanup();
        printf("bind()");
        exit(-1);
    }

    // listen() ���� ��⿭ ����.
    // SOMAXCONN : Socket Max Connection
    if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR)
    {
        closesocket(listen_socket);
        WSACleanup();
        printf("listen()");
        exit(-1);
    }

    // ������ ��ſ� ����� ����.
    SOCKADDR_IN clientaddr;
    int addrlen = sizeof(SOCKADDR_IN);
    ZeroMemory(&clientaddr, addrlen);


    int retval;
    char buf[MAX_BUFFER_SIZE + 1];

    hThread = CreateThread(NULL, 0, ProcessClient, (LPVOID)client_socket, 0, &threadID);
    if (NULL == hThread) std::cout << "[����] ������ ���� ����!" << std::endl;
    else CloseHandle(hThread);


    while (1)
    {
        // accept() ���� ���.
        client_socket = accept(listen_socket, (SOCKADDR*)&clientaddr, &addrlen);
        if (INVALID_SOCKET == client_socket)
        {
            printf("accept()");
            continue;
        }

        printf("\n[TCP ����] Ŭ���̾�Ʈ ���� : IP �ּ�=%s, ��Ʈ ��ȣ=%d\n",
            inet_ntoa(clientaddr.sin_addr),
            ntohs(clientaddr.sin_port));

        // ������ ���.
        //while (1)
        //{
            //    ZeroMemory(buf, MAX_BUFFER_SIZE + 1);
            //    // ������ �ޱ�.
            //    retval = recv(client_socket, buf, MAX_BUFFER_SIZE, 0);

            //    if (SOCKET_ERROR == retval)
            //    {
            //        printf("recv()");
            //        break;
            //    }
            //    else if (0 == retval) break;

            //    // ���� ������ ���.
            //    buf[retval] = '\0';
            //    printf("\n[TCP/%s:%d]%s\n",
            //        inet_ntoa(clientaddr.sin_addr),
            //        ntohs(clientaddr.sin_port),
            //        buf);

            //    // ������ ������.
            //    retval = send(client_socket, buf, retval, 0);
            //    if (SOCKET_ERROR == retval)
            //    {
            //        printf("send()");
            //        break;
            //    }
            //}

            //// closesocket().
            //// Ŭ���̾�Ʈ ���� ����.
            //closesocket(client_socket);
            //printf("\n[TCP ����] Ŭ���̾�Ʈ ���� : IP �ּ�=%s, ��Ʈ ��ȣ=%d\n",
            //    inet_ntoa(clientaddr.sin_addr),
            //    ntohs(clientaddr.sin_port));
    }

    // closesocket().
    // ���� ���� ����.
    closesocket(listen_socket);

    // ���� ����.
    WSACleanup();
}