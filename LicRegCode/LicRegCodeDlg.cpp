
// LicRegCodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LicRegCode.h"
#include "LicRegCodeDlg.h"
#include "afxdialogex.h"

#include <IPHlpApi.h>  
#include <stdio.h>
using namespace std;
#pragma comment(lib, "IPHlpApi.Lib")  

#include "..\..\softlic\source\api.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLicRegCodeDlg dialog




CLicRegCodeDlg::CLicRegCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLicRegCodeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLicRegCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLicRegCodeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CLicRegCodeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLicRegCodeDlg message handlers

BOOL CLicRegCodeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	char sOut[800];
	char sMac[100];
	char sIp[100];
	getLocalInfo(sMac, sIp);
	if(encodeData(sOut, sMac, "~!@#$%^&") == -1)
	{
		AfxMessageBox(L"��ʧ��Ҫ�ļ�������ϵ����Ա");
		_exit(0);
	}

	char sOut2[1024];
	encodeData(sOut2, sOut, ")(*&^%$#");
	USES_CONVERSION;
	CString sBuf =A2T(sOut2);
	SetDlgItemText(IDC_RICHEDIT21, sBuf);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLicRegCodeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLicRegCodeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLicRegCodeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLicRegCodeDlg::OnBnClickedOk()
{
	char sText[1024] = {0};
	GetDlgItemTextA(GetSafeHwnd(), IDC_RICHEDIT21, sText, 1024);

	DWORD dwLength = strlen(sText); // Ҫ���Ƶ��ִ�����
	HANDLE hGlobalMemory = GlobalAlloc(GHND, dwLength + 1); // ����ȫ���ڴ沢��ȡ���
	LPBYTE lpGlobalMemory = (LPBYTE)GlobalLock(hGlobalMemory); // ����ȫ���ڴ�
	//for (int i = 0; i<dwLength; i++) 
	//{   // ��"*"���Ƶ�ȫ���ڴ��
	//  *lpGlobalMemory++ = '*';     
	//}
	memcpy(lpGlobalMemory, sText, dwLength);

	lpGlobalMemory[dwLength] = '\0';

	GlobalUnlock(hGlobalMemory); // �����ڴ�����
	HWND hWnd = GetSafeHwnd(); // ��ȡ��ȫ���ھ��


	if(::OpenClipboard(hWnd) && ::EmptyClipboard()) // �򿪼�����
	{
		::SetClipboardData(CF_TEXT, hGlobalMemory); // ���ڴ��е����ݷ��õ�������
		::CloseClipboard(); // �رռ�����
		MessageBox(L"�������",L"��ʾ");
	}
	else
	{
		AfxMessageBox(L"����ʧ�ܣ��볢���ֶ����ƣ�");
	}
}
