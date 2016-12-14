#pragma once

#define BORDERCOLOR RGB(180,180,180)
#define BKCOLOR RGB(245,245,245)
// CBorderStatic

class CBorderStatic : public CStatic
{
	DECLARE_DYNAMIC(CBorderStatic)

public:
	CBorderStatic();
	CBorderStatic(COLORREF bkcolor,COLORREF bdcolor);
	virtual ~CBorderStatic();
protected:
	COLORREF m_bkcolor;
	COLORREF m_bordercolor;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
};


