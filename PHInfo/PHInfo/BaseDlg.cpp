// BaseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BaseDlg.h"
#include "afxdialogex.h"


// CBaseDlg dialog

IMPLEMENT_DYNAMIC(CBaseDlg, CDialogEx)

CBaseDlg::CBaseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBaseDlg::IDD, pParent)
{
	m_nDlgHeight = 1600;
	m_nDlgWidth = 1000;
	m_bCreateCompleted = FALSE;
}

CBaseDlg::~CBaseDlg()
{
}

void CBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(CBaseDlg, CDialogEx)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BTN_OK,&CBaseDlg::OnBnOK)
	ON_BN_CLICKED(IDC_BTN_CANCEL,&CBaseDlg::OnBnCancel)
END_MESSAGE_MAP()
//////////////////////////////////////////////////////////////////////////
//
void CBaseDlg::AdjustLayout()
{
	if(m_bCreateCompleted)
	{
		int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
		int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
		int nLeft = (nScreenWidth - m_nDlgWidth) / 2;
		int nTop = (nScreenHeight - m_nDlgHeight) / 2;
		//::SetWindowPos(this->m_hWnd,HWND_TOPMOST,nLeft,nTop,m_nDlgWidth,m_nDlgHeight,SWP_NOMOVE);
		SetWindowPos(NULL,nLeft,nTop,m_nDlgWidth,m_nDlgHeight,SWP_NOACTIVATE|SWP_NOZORDER);
	}
	

}
BOOL CBaseDlg::CreateControllers()
{
	return TRUE;
}
BOOL CBaseDlg::UpdateControllers()
{
	return TRUE;
}
//////////////////////////////////////////////////////////////////////////
// CBaseDlg message handlers
BOOL CBaseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	return TRUE;  
}
int CBaseDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	if(!m_btnOK.Create(L"È·¶¨",WS_VISIBLE|WS_CHILD,CRect(0,0,0,10),this,IDC_BTN_OK))
		return -1;
	if(!m_btnCancel.Create(L"È¡Ïû",WS_VISIBLE|WS_CHILD,CRect(0,0,0,0),this,IDC_BTN_CANCEL))
		return -1;

	//m_btnOK.SetFont(&CCompatibleFont::NormalFont);
	//m_btnCancel.SetFont(&CCompatibleFont::NormalFont);

	if(!CreateControllers())
		return -1;
	ModifyStyleEx(WS_EX_APPWINDOW,WS_EX_TOOLWINDOW);
	m_bCreateCompleted = TRUE;
	SetWindowText(m_strWndTitle);

	return 0;
}

void CBaseDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	AdjustLayout();
}
BOOL CBaseDlg::PreTranslateMessage(MSG* pMsg)
{
	if( pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;      //ÆÁ±ÎµôEsc¼ü
	}
	if( pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		return TRUE;      //ÆÁ±ÎµôEnter¼ü
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CBaseDlg::DealOKMsg()
{
	CDialogEx::OnOK();
}

void CBaseDlg::DealCancelMsg()
{
	CDialogEx::OnCancel();
}

void CBaseDlg::OnBnOK()
{
	DealOKMsg();
}

void CBaseDlg::OnBnCancel()
{
	DealCancelMsg();
}