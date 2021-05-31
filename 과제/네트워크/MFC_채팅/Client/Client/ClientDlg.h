
//ClientDlg.h: 헤더 파일
//
#include "CClient_Socket.h"
#pragma once
#define MAX_BUFFER_SIZE 2048
//#pragma pack(1)
//
//struct PackHeader
//{
//	int type;
//	PackHeader(int value) : type(value) {}
//};
//struct UserMessage : public PackHeader
//{
//	char msg[132];
//	UserMessage() : PackHeader(0) {}
//};
//struct UserData : public PackHeader
//{
//	char Name[128];
//
//	UserData() : PackHeader(1) {}
//};
//#pragma pack()

// CClientDlg 대화 상자
class CClientDlg : public CDialogEx
{
private:
	bool isLogin = false;;

public:
	CListBox m_List;
	CClient_Socket m_client_Socket;

	CClientDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnEnChangeEdit1();
	CEdit m_edit_chat;
	CEdit Name;
	afx_msg void OnEnChangeEdit2();
};
