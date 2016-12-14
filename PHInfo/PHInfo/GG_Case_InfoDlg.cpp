#include "StdAfx.h"
#include "GG_Case_InfoDlg.h"
#include "compatible4mobile.h"


GG_Case_InfoDlg::GG_Case_InfoDlg(void)
{
	m_nDlgHeight=500;
	m_nDlgWidth=500;
	this->m_strWndTitle = L"�½�����";
	//CCompatibleFont::InitFonts();
	IsCreate=FALSE;
}


GG_Case_InfoDlg::~GG_Case_InfoDlg(void)
{
}

BEGIN_MESSAGE_MAP(GG_Case_InfoDlg, CBaseDlg)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_STN_CLICKED(IDC_StaticAddInspector,&GG_Case_InfoDlg::AddComInspector)
END_MESSAGE_MAP()
int GG_Case_InfoDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CBaseDlg::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetWindowText(m_strWndTitle);
	// TODO:  Add your specialized creation code here

	if(!m_BorderStatic.Create(L"", WS_CHILD|WS_VISIBLE | SS_LEFT,CRect(0,0,0,0),this,-1))
		return -1;
	/*if(!m_Labelflag.CreateLabel(L"*",this))
		return -1;*/
	if(!m_LabelCase_Name.CreateLabel(L"��������:",this))
		return -1;
	if(!m_LabelCase_No.CreateLabel(L"�������:",this))
		return -1;
	if(!m_LabelCase_Type.CreateLabel(L"��������:",this))
		return -1;
	if(!m_LabelInspector.CreateLabel(L"���Ա����:",this))
		return -1;
	if(!m_LabelHander.CreateLabel(L"�ͼ�������:",this))
		return -1;
	if(!m_LabelRemark.CreateLabel(L"��ע:",this))
		return -1;
	if(!m_EditCase_Name.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_EditCase_No.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_ComCase_Type.Create(WS_VISIBLE | WS_CHILD|CBS_DROPDOWN|CBS_HASSTRINGS|WS_VSCROLL|CBS_DROPDOWNLIST, CRect(0,0,0,0),this, -1))
		return -1;
	if(!m_ComInspector.Create(WS_VISIBLE | WS_CHILD|CBS_DROPDOWN|CBS_HASSTRINGS|WS_VSCROLL|CBS_DROPDOWNLIST, CRect(0,0,0,0),this, -1))
		return -1;
	if(!m_EditHander.Create(WS_CHILD|WS_VISIBLE|WS_TABSTOP|ES_MULTILINE|WS_BORDER,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_EditRemark.Create(WS_CHILD|WS_VISIBLE|WS_TABSTOP|ES_MULTILINE|WS_BORDER|WS_VSCROLL,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_StaticAddInspector.Create(L"���",WS_CHILD|WS_VISIBLE|SS_NOTIFY,CRect(0,0,0,0),this,IDC_StaticAddInspector))
		return -1;
	
	if(!m_BtnOk.Create(L"ȷ��",WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(0,0,0,0),this,IDC_BtnOk))
		return -1;
	if(!m_BtnCancle.Create(L"ȡ��",WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(0,0,0,0),this,IDC_BtnCancle))
		return -1;

	m_LabelCase_Name.SetFont(&CCompatibleFont::NormalFont);
	m_LabelCase_No.SetFont(&CCompatibleFont::NormalFont);
	m_LabelCase_Type.SetFont(&CCompatibleFont::NormalFont);
	m_LabelInspector.SetFont(&CCompatibleFont::NormalFont);
	m_LabelHander.SetFont(&CCompatibleFont::NormalFont);
	m_LabelRemark.SetFont(&CCompatibleFont::NormalFont);
	m_EditCase_Name.SetFont(&CCompatibleFont::NormalFont);
	m_EditCase_No.SetFont(&CCompatibleFont::NormalFont);
	m_ComCase_Type.SetFont(&CCompatibleFont::NormalFont);
	m_ComInspector.SetFont(&CCompatibleFont::NormalFont);
	m_EditHander.SetFont(&CCompatibleFont::NormalFont);
	m_EditRemark.SetFont(&CCompatibleFont::NormalFont);
	m_StaticAddInspector.SetFont(&CCompatibleFont::NormalFont);
	m_BtnOk.SetFont(&CCompatibleFont::NormalFont);
	m_BtnCancle.SetFont(&CCompatibleFont::NormalFont);

	m_LabelCase_Name.SetBGClr(RGB(240,240,240));
	m_LabelCase_No.SetBGClr(RGB(240,240,240));
	m_LabelCase_Type.SetBGClr(RGB(240,240,240));
	m_LabelInspector.SetBGClr(RGB(240,240,240));
	m_LabelHander.SetBGClr(RGB(240,240,240));
	m_LabelRemark.SetBGClr(RGB(240,240,240));
//	m_Labelflag.SetBGClr(RGB(240,240,240));

	m_ComCase_Type.AddString(L"FL��");
	m_ComCase_Type.AddString(L"������");
	m_ComCase_Type.AddString(L"������");
	m_ComCase_Type.AddString(L"թƭ��");
	m_ComCase_Type.AddString(L"�Ĳ���");
	m_ComCase_Type.AddString(L"����");
	m_ComCase_Type.SetCurSel(2);

	IsCreate=TRUE;
	AdjustLayout();
	return 0;
}

void GG_Case_InfoDlg::AddComInspector()
{
	m_InspectorDlg.DoModal();

}

void GG_Case_InfoDlg::AdjustLayout()
{
	//���ڴ�С
	int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	int nLeft =(nScreenWidth - m_nDlgWidth)/2;
	int nTop = (nScreenHeight - m_nDlgHeight)/2;
	SetWindowPos(NULL,nLeft,nTop,m_nDlgWidth,m_nDlgHeight,SWP_NOACTIVATE|SWP_NOZORDER);
	if(IsCreate)
	{
		CRect rcClient;
		GetClientRect(&rcClient);
		int nLeft = 0, nTop = 30, nOffset = 25;

		//���õײ���ʽ���С

		int nTop0=nTop;
		int nLeft0=nOffset;
		int nBorderStaticW=rcClient.Width() - 2 * nOffset;
		int nBorderStaticH=rcClient.Height() - nOffset * 4-10;
		m_BorderStatic.SetWindowPos(NULL,nLeft0,nTop0,nBorderStaticW,nBorderStaticH,SWP_NOZORDER|SWP_NOACTIVATE);


		//���õ�һ����ʽ��Ĵ�С
		int nTop1=nTop0+nOffset;
		int nLeft11=nLeft+nOffset*2;
		int nStaticW = (rcClient.Width() - 4 * nOffset)/4;
		int nStaticH = (rcClient.Height() - nOffset * 8)/12;
		m_LabelCase_Name.SetWindowPos(NULL,nLeft11,nTop1,nStaticW,nStaticH,SWP_NOZORDER|SWP_NOACTIVATE);


		int nLeft12=nLeft11+nStaticW-nOffset;
		int nEditW = (rcClient.Width() - 4 * nOffset)/4*3;
		int nEditH = (rcClient.Height() - nOffset * 8)/11;
		m_EditCase_Name.SetWindowPos(NULL,nLeft12,nTop1,nEditW,nEditH,SWP_NOZORDER|SWP_NOACTIVATE);
		//m_Labelflag.SetWindowPos(NULL,nLeft12+nEditW+5,nTop1,20,nEditH,SWP_NOZORDER|SWP_NOACTIVATE);
		//���õڶ�����ʽ��Ĵ�С

		int nTop2=nTop1+nOffset+nStaticH;
		m_LabelCase_No.SetWindowPos(NULL,nLeft11,nTop2,nStaticW,nStaticH,SWP_NOACTIVATE|SWP_NOZORDER);
		m_EditCase_No.SetWindowPos(NULL,nLeft12,nTop2,nEditW,nEditH,SWP_NOZORDER|SWP_NOACTIVATE);

		//���õ�������ʽ���С

		int nTop3=nTop2+nOffset+nStaticH;
		m_LabelCase_Type.SetWindowPos(NULL,nLeft11,nTop3,nStaticW,nStaticH,SWP_NOACTIVATE|SWP_NOZORDER);
		m_ComCase_Type.SetWindowPos(NULL,nLeft12,nTop3,nEditW,nEditH,SWP_NOACTIVATE|SWP_NOZORDER);
		m_ComCase_Type.SetItemHeight(-1,nEditH-2);
		//���õ��Ĳ���ʽ���С

		int nTop4=nTop3+nStaticH+nOffset;
		m_LabelInspector.SetWindowPos(NULL,nLeft11,nTop4,nStaticW,nStaticH,SWP_NOACTIVATE|SWP_NOZORDER);
		m_ComInspector.SetWindowPos(NULL,nLeft12,nTop4,nEditW,nEditH,SWP_NOACTIVATE|SWP_NOZORDER);
		m_ComInspector.SetItemHeight(-1,nEditH-2);
		int nleft43=nLeft12+nEditW;
		m_StaticAddInspector.SetWindowPos(NULL,nleft43+5,nTop4,40,nStaticH,SWP_NOZORDER|SWP_NOACTIVATE);

		//���õ������ʽ���С

		int nTop5=nTop4+nStaticH+nOffset;
		m_LabelHander.SetWindowPos(NULL,nLeft11,nTop5,nStaticW,nStaticH,SWP_NOACTIVATE|SWP_NOZORDER);
		m_EditHander.SetWindowPos(NULL,nLeft12,nTop5,nEditW,nEditH,SWP_NOACTIVATE|SWP_NOZORDER);

		//���õ�������ʽ���С

		int nTop6=nTop5+nOffset+nStaticH;
		m_LabelRemark.SetWindowPos(NULL,nLeft11,nTop6,nStaticW,nStaticH,SWP_NOACTIVATE|SWP_NOZORDER);
		m_EditRemark.SetWindowPos(NULL,nLeft12,nTop6,nEditW,nEditH*3,SWP_NOACTIVATE|SWP_NOZORDER);

		//���߲���ʽ���С

		int nTop7=nTop0+nOffset+nBorderStaticH;
		int nBtnW=rcClient.Width()/8;
		int nBtnH=nStaticH;


		int nleft82=rcClient.Width()-nOffset-nBtnW;
		int nleft81=nleft82-nOffset*2-nBtnW;
		m_BtnOk.SetWindowPos(NULL,nleft81,nTop7,nBtnW,nBtnH,SWP_NOZORDER|SWP_NOACTIVATE);
		m_BtnCancle.SetWindowPos(NULL,nleft82,nTop7,nBtnW,nBtnH,SWP_NOZORDER|SWP_NOACTIVATE);


	}

}


void GG_Case_InfoDlg::OnSize(UINT nType, int cx, int cy)
{
	CBaseDlg::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	AdjustLayout();
}




HBRUSH GG_Case_InfoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CBaseDlg::OnCtlColor(pDC, pWnd, nCtlColor);

	if(IDC_StaticAddInspector==pWnd->GetDlgCtrlID())
	{

		pDC->SetTextColor(RGB(0,10,255));


	}

	return hbr;
}
