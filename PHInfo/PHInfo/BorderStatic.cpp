// BorderStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BorderStatic.h"


// CBorderStatic

IMPLEMENT_DYNAMIC(CBorderStatic, CStatic)

CBorderStatic::CBorderStatic()
{
	m_bkcolor = BKCOLOR;
	m_bordercolor = BORDERCOLOR;
}

CBorderStatic::CBorderStatic(COLORREF bkcolor,COLORREF bdcolor)
{
	m_bkcolor = bkcolor;
	m_bordercolor = bdcolor;
}

CBorderStatic::~CBorderStatic()
{
}


BEGIN_MESSAGE_MAP(CBorderStatic, CStatic)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()



// CBorderStatic ��Ϣ�������




void CBorderStatic::OnPaint()
{
	CPaintDC   dc(this); 
	CBrush   newbrush,   *oldbrush; 
	newbrush.CreateSolidBrush(m_bordercolor); 
	oldbrush=dc.SelectObject(&newbrush); 
	CRect   rect;   
	GetClientRect(rect); 

//	rect.InflateRect(1,1);
	dc.FrameRect(rect,   &newbrush); 
	rect.InflateRect(-1,-1);
	dc.FillSolidRect(rect,m_bkcolor);
	dc.SelectObject(oldbrush); 


}


HBRUSH CBorderStatic::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
	if (CTLCOLOR_STATIC == nCtlColor)  
	{  
		//		 pDC->SelectObject(&m_font);  
		//		 pDC->SetTextColor(m_crText);  
		pDC-> SetBkMode(TRANSPARENT); 
		HBRUSH hr = CreateSolidBrush(RGB(245,245,245)); 

		return hr;

	}  
	return NULL;
}
