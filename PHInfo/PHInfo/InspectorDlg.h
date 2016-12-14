#pragma once
#include "basedlg.h"
class InspectorDlg :
	public CBaseDlg
{
public:
	InspectorDlg(void);
	~InspectorDlg(void);
public:
	void AdjustLayout();


public:
	CStatic	m_SticInspector;
	CEdit	m_EditInspector;
	CButton m_BtnOK;
	CButton m_BtnCancel;
	CString m_addInspectorName;
	CString m_CsTitle;
	
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void AddName();
};

