#include "pch.h"
#include "CClient_Socket.h"


void CClient_Socket::OnClose(int nErrorCode)
{
	ShutDown();
	Close();

	CSocket::OnClose(nErrorCode);
	AfxMessageBox(_T("ERROR : Disconnected From Server!!"));

}

#include "ClientDlg.h"
void CClient_Socket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
    char buf[sizeof(UserData)];

    ZeroMemory(buf, sizeof(buf));

    if (Receive(buf, sizeof(buf)) > 0)
    {
        UserMessage* Msg = (UserMessage*)buf;
        CClientDlg* pMain = (CClientDlg*)AfxGetMainWnd();
        CString    csTemp;
        csTemp = Msg->msg;
        pMain->m_List.AddString(csTemp);
    }


    //retval = recv(sock, buf, retval, 0);
    //// printf()
    //UserMessage* Msg = (UserMessage*)buf;
    //if (SOCKET_ERROR == retval)
    //{
    //    printf("recv()");
    //    break;
    //}
    //else if (0 == retval) break;
	CSocket::OnReceive(nErrorCode);
}
