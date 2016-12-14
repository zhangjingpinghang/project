// Label.cpp : implementation file
//

#include "stdafx.h"
//#include "ForensicsAnalyser.h"
#include "Label.h"


// CLabel

IMPLEMENT_DYNAMIC(CLabel, CStatic)

CLabel::CLabel()
{
	m_bLeftAlign = TRUE;
	m_nLabelHeight = 0;
	m_nLabelWidth = 0;
	//
	m_nXOffset = 5;
	m_nYOffset = 4;
	m_clrText = RGB(0,0,0);
	m_clrBG = RGB(255,255,255);
	//
}

CLabel::~CLabel()
{
}

BEGIN_MESSAGE_MAP(CLabel, CStatic)
	ON_WM_CREATE()
	ON_WM_PAINT()
END_MESSAGE_MAP()
//////////////////////////////////////////////////////////////////////////
//
BOOL CLabel::CreateLabel(LPCTSTR lpszText,CWnd * pParent)
{
	m_strText = lpszText;
	return Create(lpszText,WS_VISIBLE|WS_CHILD,CRect(0,0,0,0),pParent);
}
//////////////////////////////////////////////////////////////////////////
// CLabel message handlers
int CLabel::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}
void CLabel::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetClientRect(&rect);
	dc.FillSolidRect(rect,m_clrBG);
	CFont *pFont = GetFont();
	dc.SetTextColor(m_clrText);
	if (pFont)
	{
		dc.SelectObject(pFont);
		rect.left += m_nXOffset;
		rect.top += m_nYOffset;
		if(!m_bLeftAlign)
		{
			CSize sizeText = dc.GetTextExtent(m_strText);
			if(sizeText.cx < rect.Width())
			{
				rect.left = rect.Width() - sizeText.cx - 4;
			}
		}
	    dc.DrawText(m_strText,&rect,DT_WORDBREAK);
		
	}
}
