#include "StdAfx.h"
#include "InspectorDlg.h"
#include "compatible4mobile.h"


InspectorDlg::InspectorDlg(void)
{
	m_nDlgHeight=150;
	m_nDlgWidth=400;
	m_bCreateCompleted=FALSE;
	CCompatibleFont::InitFonts();
	m_CsTitle=L"添加审查员";
}


InspectorDlg::~InspectorDlg(void)
{
}
void InspectorDlg::AdjustLayout()
{
	int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	int nLeft = (nScreenWidth - m_nDlgWidth) / 2;
	int nTop = (nScreenHeight - m_nDlgHeight) / 2;
	//::SetWindowPos(this->m_hWnd,HWND_TOPMOST,nLeft,nTop,m_nDlgWidth,m_nDlgHeight,SWP_NOMOVE);
	SetWindowPos(NULL,nLeft,nTop,m_nDlgWidth,m_nDlgHeight,SWP_NOACTIVATE|SWP_NOZORDER);
	if(m_bCreateCompleted)
	{
		
		CRect rcClient;
		GetClientRect(&rcClient);
		int nLeft = 0, nTop = 20, nOffset = 20;

		int nLeft11=nLeft+nOffset*2;
		int nStaticW=(rcClient.Width()-3*nOffset)/3;
		int nStaticH=(rcClient.Height()-3*nOffset)/4*2;
		m_SticInspector.SetWindowPos(NULL,nLeft11,nTop,nStaticW,nStaticH,SWP_NOZORDER|SWP_NOACTIVATE);
		int nLeft12=nLeft+nStaticW+nOffset;
		m_EditInspector.SetWindowPos(NULL,nLeft12,nTop,nStaticW*2,nStaticH,SWP_NOZORDER|SWP_NOACTIVATE);

		int nLeft21=(rcClient.Width()-3*nOffset)/2;
		int nBtnW=nStaticW-40;
		int nTop2=nTop+nStaticH+nOffset;
		m_BtnOK.SetWindowPos(NULL,nLeft21,nTop2,nBtnW,nStaticH,SWP_NOZORDER|SWP_NOACTIVATE);
		int nLeft22=nLeft21+nBtnW+nOffset;
		m_BtnCancel.SetWindowPos(NULL,nLeft22,nTop2,nBtnW,nStaticH,SWP_NOZORDER|SWP_NOACTIVATE);

	}
}
BEGIN_MESSAGE_MAP(InspectorDlg, CBaseDlg)
	/*ON_BN_CLICKED(IDC_BTN_ADD,&InspectorDlg::AddName)*/
	ON_WM_CREATE()
END_MESSAGE_MAP()

void InspectorDlg::AddName()
{
	m_EditInspector.GetWindowTextW(m_addInspectorName);
}

	
int InspectorDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CBaseDlg::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetWindowText(m_CsTitle);
	// TODO:  Add your specialized creation code here
	if(!m_BtnOK.Create(L"确定",WS_VISIBLE|WS_CHILD,CRect(0,0,0,10),this,IDC_BTN_OK))
		return -1;
	if(!m_BtnCancel.Create(L"取消",WS_VISIBLE|WS_CHILD,CRect(0,0,0,0),this,IDC_BTN_CANCEL))
		return -1;
	if(!m_SticInspector.Create(L"审查员",WS_CHILD|WS_VISIBLE|ES_LEFT,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_EditInspector.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_TABSTOP|WS_BORDER,CRect(0,0,0,0),this,-1))
		return -1;
	m_SticInspector.SetFont(&CCompatibleFont::NormalFont);
	m_EditInspector.SetFont(&CCompatibleFont::NormalFont);
	m_BtnOK.SetFont(&CCompatibleFont::NormalFont);
	m_BtnCancel.SetFont(&CCompatibleFont::NormalFont);

	return 0;
}
