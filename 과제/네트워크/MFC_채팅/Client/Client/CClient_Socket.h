#pragma once
#include <afxsock.h>


#define MAX_BUFFER_SIZE 2048
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

class CClient_Socket :
    public CSocket
{
private:

public:
    virtual void OnClose(int nErrorCode);
    virtual void OnReceive(int nErrorCode);
};

