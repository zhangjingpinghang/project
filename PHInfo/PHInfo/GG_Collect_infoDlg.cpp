// GG_Collect_info.cpp : implementation file
//

#include "stdafx.h"
#include "PHInfo.h"
#include "GG_Collect_infoDlg.h"
#include "afxdialogex.h"
#include "compatible4mobile.h"


// GG_Collect_info dialog


GG_Collect_infoDlg::GG_Collect_infoDlg(void)
{
	m_nDlgHeight=650;
	m_nDlgWidth=500;
	this->m_strWndTitle = L"�ɼ���־��";
	CCompatibleFont::InitFonts();
	IsCreate=FALSE;
}

GG_Collect_infoDlg::~GG_Collect_infoDlg()
{
}



BEGIN_MESSAGE_MAP(GG_Collect_infoDlg, CBaseDlg)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_STN_CLICKED(IDC_BtnOk,&GG_Collect_infoDlg::OnClickOk)
	ON_STN_CLICKED(IDC_BtnCancle,&GG_Collect_infoDlg::OnClickCancle)
END_MESSAGE_MAP()


// GG_Collect_infoDlg message handlers


int GG_Collect_infoDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CBaseDlg::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetWindowText(m_strWndTitle);

	// TODO:  Add your specialized creation code here
	if(!m_BSCollect.Create(L"", WS_CHILD|WS_VISIBLE | SS_LEFT,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_LabelCollect.CreateLabel(L"�ɼ���Ϣ:",this))
		return FALSE;
	if(!m_LabelCPCode.CreateLabel(L"�ɼ�����:",this))
		return FALSE;
	if(!m_LabelCPName.CreateLabel(L"�ɼ�������:",this))
		return FALSE;
	if(!m_LabelCPIP.CreateLabel(L"�ɼ���IP:",this))
		return FALSE;
	if(!m_LabelCollector_ID.CreateLabel(L"�ɼ��񾯾���:",this))
		return FALSE;
	if(!m_LabelCollector_Name.CreateLabel(L"�ɼ�������:",this))
		return FALSE;
	if(!m_EditCPCode.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP|ES_NUMBER,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_EditCPName.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP,CRect(0,0,0,0),this,-1))
		return -1;
	//int i=m_CIPCtrlCPIP.Create(WS_CHILD |WS_VISIBLE|WS_BORDER ,CRect(00,0,0,0),this,-1);
	if(!m_CIPCtrlCPIP.Create(WS_CHILD |WS_VISIBLE ,CRect(60,445,322,470),this,IDC_CIPCtrlCPIP))
		return -1;
	if(!m_EditCollector_Name.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_EditCollector_ID.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP|ES_NUMBER,CRect(0,0,0,0),this,-1))
		return -1;

	if(!m_BSSource.Create(L"", WS_CHILD|WS_VISIBLE | SS_LEFT,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_LabelSource.CreateLabel(L"��������Ϣ:",this))
		return FALSE;
	if(!m_LabelSOwner.CreateLabel(L"���ݳ�����:",this))
		return FALSE;
	if(!m_LabelSOwnerNo.CreateLabel(L"������Ա���:",this))
		return FALSE;
	if(!m_LabelSIdCard.CreateLabel(L"��Դ�����֤:",this))
		return FALSE;
	if(!m_LabelHzNm.CreateLabel(L"�ֻ�����:",this))
		return FALSE;
	if(!m_EditSOwner.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_EditSOwnerNo.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP|ES_NUMBER,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_EditSIdCard.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_EditHzNm.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP|ES_NUMBER,CRect(0,0,0,0),this,-1))
		return -1;
	if(!m_BtnOk.Create(L"ȷ��",WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(0,0,0,0),this,IDC_BtnOk))
		return -1;
	if(!m_BtnCancle.Create(L"ȡ��",WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(0,0,0,0),this,IDC_BtnCancle))
		return -1;

	m_LabelCollect.SetFont(&CCompatibleFont::NormalFont);
	m_LabelSource.SetFont(&CCompatibleFont::NormalFont);
	m_LabelCPCode.SetFont(&CCompatibleFont::NormalFont);
	m_LabelCPName.SetFont(&CCompatibleFont::NormalFont);
	m_LabelCPIP.SetFont(&CCompatibleFont::NormalFont);
	m_LabelCollector_ID.SetFont(&CCompatibleFont::NormalFont);
	m_LabelCollector_Name.SetFont(&CCompatibleFont::NormalFont);
	m_EditCPCode.SetFont(&CCompatibleFont::NormalFont);
	m_EditCPName.SetFont(&CCompatibleFont::NormalFont);
	m_CIPCtrlCPIP.SetFont(&CCompatibleFont::NormalFont);
	m_EditCollector_ID.SetFont(&CCompatibleFont::NormalFont);
	m_EditCollector_Name.SetFont(&CCompatibleFont::NormalFont);
	m_LabelSource.SetFont(&CCompatibleFont::NormalFont);
	m_LabelSOwner.SetFont(&CCompatibleFont::NormalFont);
	m_EditSOwner.SetFont(&CCompatibleFont::NormalFont);
	m_LabelSOwnerNo.SetFont(&CCompatibleFont::NormalFont);
	m_EditSOwnerNo.SetFont(&CCompatibleFont::NormalFont);
	m_LabelSIdCard.SetFont(&CCompatibleFont::NormalFont);
	m_EditSIdCard.SetFont(&CCompatibleFont::NormalFont);
	m_LabelHzNm.SetFont(&CCompatibleFont::NormalFont);
	m_EditHzNm.SetFont(&CCompatibleFont::NormalFont);
	m_BtnOk.SetFont(&CCompatibleFont::NormalFont);
	m_BtnCancle.SetFont(&CCompatibleFont::NormalFont);
	m_LabelCollect.SetBGClr(RGB(240,240,240));
	m_LabelSource.SetBGClr(RGB(240,240,240));
	m_LabelCPCode.SetBGClr(RGB(240,240,240));
	m_LabelCPName.SetBGClr(RGB(240,240,240));
	m_LabelCPIP.SetBGClr(RGB(240,240,240));
	m_LabelCollector_ID.SetBGClr(RGB(240,240,240));
	m_LabelCollector_Name.SetBGClr(RGB(240,240,240));
	m_LabelSource.SetBGClr(RGB(240,240,240));
	m_LabelSIdCard.SetBGClr(RGB(240,240,240));
	m_LabelCollector_Name.SetBGClr(RGB(240,240,240));
	m_LabelHzNm.SetBGClr(RGB(240,240,240));
	m_LabelSOwnerNo.SetBGClr(RGB(240,240,240));
	m_LabelSource.SetTextClr(RGB(0,10,240));
	m_LabelCollect.SetTextClr(RGB(0,10,240));
	IsCreate=TRUE;
	return 0;
}

void GG_Collect_infoDlg::AdjustLayout()
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
		int nLeft = 0, nTop = 20, nOffset = 20;

		//���òɼ���Ϣ���⼰�׿�
		int nleft00=nOffset;
		int nTop00=nTop;
		int nStaticW=rcClient.Width()/4;
		int nStaticH=(rcClient.Height()-nOffset*17)/14;
		m_LabelCollect.SetWindowPos(NULL,nleft00,nTop00,nStaticW,nStaticH,SWP_NOZORDER|SWP_NOACTIVATE);
		int nBorderStaticW=rcClient.Width() - 2 * nOffset;
		int nBorderStaticH=rcClient.Height()/2-nOffset*2 ;
		nTop00=nTop00+nStaticH;
		m_BSCollect.SetWindowPos(NULL,nleft00,nTop00,nBorderStaticW,nBorderStaticH-nOffset,SWP_NOZORDER|SWP_NOACTIVATE);
		//���òɼ���Ϣ���һ��
		int nLeft110=nleft00+nOffset*2;
		int nTop11=nTop00+nOffset;
		int nBSStaticW=(nBorderStaticW-3*nOffset)/3;
		int nBSStaticH=(nBorderStaticH-6*nOffset)/6;
		m_LabelCPName.SetWindowPos(NULL,nLeft110,nTop11,nBSStaticW,nBSStaticH,SWP_NOZORDER|SWP_NOACTIVATE);
		
		
		int nLeft111=nLeft110+nStaticW-nOffset-10;
		int nEditW=nBSStaticW*2;
		int nEditH=nBSStaticH;
		m_EditCPName.SetWindowPos(NULL,nLeft111,nTop11,nEditW,nEditH,SWP_NOZORDER|SWP_NOACTIVATE);
		

		//���òɼ���Ϣ��ڶ���
		int nTop12=nTop11+nBSStaticH+nOffset;
		m_LabelCPCode.SetWindowPos(NULL,nLeft110,nTop12,nBSStaticW,nBSStaticH,SWP_NOZORDER|SWP_NOACTIVATE);
		m_EditCPCode.SetWindowPos(NULL,nLeft111,nTop12,nEditW,nEditH,SWP_NOZORDER|SWP_NOACTIVATE);
		//���òɼ���Ϣ�������
		int nTop13=nTop12+nBSStaticH+nOffset;
		m_LabelCPIP.SetWindowPos(NULL,nLeft110,nTop13,nBSStaticW,nBSStaticH,SWP_NOZORDER|SWP_NOACTIVATE);
		m_CIPCtrlCPIP.SetWindowPos(NULL,nLeft111,nTop13,nEditW,nEditH,SWP_NOZORDER|SWP_NOACTIVATE);

		//���òɼ���Ϣ����Ĳ�
		int nTop14=nTop13+nBSStaticH+nOffset;
		m_LabelCollector_Name.SetWindowPos(NULL,nLeft110,nTop14,nBSStaticW,nBSStaticH,SWP_NOZORDER|SWP_NOACTIVATE);
		m_EditCollector_Name.SetWindowPos(NULL,nLeft111,nTop14,nEditW,nEditH,SWP_NOZORDER|SWP_NOACTIVATE);
		//���òɼ���Ϣ������
		int nTop15=nTop14+nBSStaticH+nOffset;
		m_LabelCollector_ID.SetWindowPos(NULL,nLeft110,nTop15,nBSStaticW,nBSStaticH,SWP_NOZORDER|SWP_NOACTIVATE);
		m_EditCollector_ID.SetWindowPos(NULL,nLeft111,nTop15,nEditW,nEditH,SWP_NOZORDER|SWP_NOACTIVATE);


		//������������Ϣ���⼰�׿�
		int nleft11=nOffset;
		int nTop20=nBorderStaticH+nTop00;
		m_LabelSource.SetWindowPos(NULL,nleft11,nTop20,nStaticW,nStaticH,SWP_NOZORDER|SWP_NOACTIVATE);
		nTop20=nTop20+nStaticH;
		m_BSSource.SetWindowPos(NULL,nleft00,nTop20,nBorderStaticW,nBorderStaticH-3*nOffset,SWP_NOZORDER|SWP_NOACTIVATE);
		//������������Ϣ���һ��
		int nLeft210=nLeft110;
		int nTop21=nTop20+nOffset+5;
		m_LabelSOwner.SetWindowPos(NULL,nLeft210,nTop21,nBSStaticW,nBSStaticH,SWP_NOZORDER|SWP_NOACTIVATE);

		int nLeft211=nLeft210+nStaticW-nOffset-10;
		m_EditSOwner.SetWindowPos(NULL,nLeft211,nTop21,nEditW,nEditH,SWP_NOZORDER|SWP_NOACTIVATE);


		//������������Ϣ��ڶ���
		int nTop22=nTop21+nBSStaticH+nOffset;
		m_LabelSOwnerNo.SetWindowPos(NULL,nLeft210,nTop22,nBSStaticW,nBSStaticH,SWP_NOZORDER|SWP_NOACTIVATE);
		m_EditSOwnerNo.SetWindowPos(NULL,nLeft211,nTop22,nEditW,nEditH,SWP_NOZORDER|SWP_NOACTIVATE);
		////������������Ϣ�������
		int nTop23=nTop22+nBSStaticH+nOffset;
		m_LabelSIdCard.SetWindowPos(NULL,nLeft210,nTop23,nBSStaticW,nBSStaticH,SWP_NOZORDER|SWP_NOACTIVATE);
		m_EditSIdCard.SetWindowPos(NULL,nLeft211,nTop23,nEditW,nEditH,SWP_NOZORDER|SWP_NOACTIVATE);
		////������������Ϣ����Ĳ�
		int nTop24=nTop23+nBSStaticH+nOffset;
		m_LabelHzNm.SetWindowPos(NULL,nLeft210,nTop24,nBSStaticW,nBSStaticH,SWP_NOZORDER|SWP_NOACTIVATE);
		m_EditHzNm.SetWindowPos(NULL,nLeft211,nTop24,nEditW,nEditH,SWP_NOZORDER|SWP_NOACTIVATE);

		//����ȷ��ȡ����ťλ��
		int nTop31=nTop21+nBorderStaticH-3*nOffset;
		int nBtnW=rcClient.Width()/8;
		int nBtnH=nStaticH+5;
		int nleft310=rcClient.Width()-nOffset*2-nBtnW*2;
		int nleft311=rcClient.Width()-nOffset-nBtnW;
		m_BtnOk.SetWindowPos(NULL,nleft310,nTop31,nBtnW,nBtnH,SWP_NOZORDER|SWP_NOACTIVATE);
		m_BtnCancle.SetWindowPos(NULL,nleft311,nTop31,nBtnW,nBtnH,SWP_NOZORDER|SWP_NOACTIVATE);+nBorderStaticH;
		

	


	}

}
void GG_Collect_infoDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	AdjustLayout();
}


HBRUSH GG_Collect_infoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CBaseDlg::OnCtlColor(pDC, pWnd, nCtlColor);

	if(IDC_StaticCollect==pWnd->GetDlgCtrlID())
	{
		pDC->SetTextColor(RGB(0,10,255));//�����ı���ɫΪ��ɫ
	}
	if(IDC_StaticSource==pWnd->GetDlgCtrlID())
	{

		pDC->SetTextColor(RGB(0,10,255));

	}
	return hbr;
}
void GG_Collect_infoDlg::OnClickOk()
{
	IsEmpty();
}
void GG_Collect_infoDlg::OnClickCancle()
{
	DestroyWindow( );
}

void GG_Collect_infoDlg::IsEmpty()
{
	m_EditCPName.GetWindowTextW(m_CStrCPName);
	if(m_CStrCPName == L"")
	{
		MessageBox(L"������ɼ������ƣ�",L"��ʾ");
		return;
	}
	m_EditCPCode.GetWindowTextW(m_CStrCPCode);
	if(m_CStrCPCode == L"")
	{
		MessageBox(L"������ɼ�����룡",L"��ʾ");
		return;
	}
	if(m_CIPCtrlCPIP.IsBlank())
	{
		MessageBox(L"������ɼ���IP��",L"��ʾ");
		return;
	}
	
	m_EditCollector_Name.GetWindowTextW(m_CStrCollector_Name);
	if(m_CStrCollector_Name == L"")
	{
		MessageBox(L"������ɼ���������",L"��ʾ");
		return;
	}
	m_EditCollector_ID.GetWindowTextW(m_CStrCollector_ID);
	if(m_CStrCollector_ID == L"")
	{
		MessageBox(L"������ɼ��񾯾��ţ�",L"��ʾ");
		return;
	}
	
	m_EditSOwner.GetWindowTextW(m_CStrSOwner);
	if(m_CStrSOwner == L"")
	{
		MessageBox(L"���������ݳ����ˣ�",L"��ʾ");
		return;
	}
	m_EditSOwnerNo.GetWindowTextW(m_CStrSOwnerNo);
	if(m_CStrSOwnerNo == L"")
	{
		MessageBox(L"������������Ա��ţ�",L"��ʾ");
		return;
	}
	m_EditSIdCard.GetWindowTextW(m_CStrSIdCard);
	if(m_CStrSIdCard == L"")
	{
		MessageBox(L"��������Դ�����֤��",L"��ʾ");
		return;
	}
	if(!IDCardValidate(m_CStrSIdCard))
	{
		MessageBox(L"��������Ч�����֤��",L"��ʾ");
		return;
	}
	m_EditHzNm.GetWindowTextW(m_CStrHzNm);
	if(m_CStrHzNm == L"")
	{
		MessageBox(L"�������ֻ����룡",L"��ʾ");
		return;
	}
}
//�ж����֤�Ƿ�Ϸ�
bool GG_Collect_infoDlg::IDCardValidate(CString IDCard)  
{  
	int weight[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};  
	char validate[]={ '1','0','X','9','8','7','6','5','4','3','2'};    
	int sum=0;  
	int mode=0;  
	if (IDCard.GetLength()==18)  
	{  
		for(int i=0;i<IDCard.GetLength()-1;i++){  
			sum=sum+(IDCard[i]-'0')*weight[i];  
		}  
		mode=sum%11;  
		if (validate[mode]==IDCard[17])  
		{  
			return true;  
		}  
	}
		return false;  
}  

