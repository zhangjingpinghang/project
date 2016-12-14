#pragma once


// CLabel

class CLabel : public CStatic
{
	DECLARE_DYNAMIC(CLabel)
public:
	CLabel();
	virtual ~CLabel();

protected:
	DECLARE_MESSAGE_MAP()
protected:
	CString m_strText;
	BOOL    m_bLeftAlign;
	int     m_nLabelHeight;
	int     m_nLabelWidth;
	int     m_nXOffset;
	int     m_nYOffset;
	COLORREF m_clrText;
	COLORREF m_clrBG;
public:
	void SetOffset(int x,int y){m_nXOffset = x; m_nYOffset = y;}
	void SetLabelText(const CString & strText){m_strText = strText;}
	CString GetLabelText(){return m_strText;}
	void SetBLeftAlign(BOOL b){m_bLeftAlign = b;}
	int  Height()const{return m_nLabelHeight;}
	void SetWidth(int w){m_nLabelWidth = w;}
	void SetTextClr(COLORREF clr){m_clrText = clr;}
	void SetBGClr(COLORREF clr){m_clrBG = clr;}
	//
	BOOL CreateLabel(LPCTSTR lpszText,CWnd * pParent);
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnPaint();
};


