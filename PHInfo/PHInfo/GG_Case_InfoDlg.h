#pragma once
#include "basedlg.h"
#include "InspectorDlg.h"
#include "BorderStatic.h"
#include "Label.h"
class GG_Case_InfoDlg :
	public CBaseDlg
{
public:
	GG_Case_InfoDlg(void);
	~GG_Case_InfoDlg(void);
public:

	int			m_nDlgHeight;
	int			m_nDlgWidth;
	CString		m_strWndTitle;
	BOOL		IsCreate;


	InspectorDlg m_InspectorDlg;
	CBorderStatic m_BorderStatic;
	CLabel		m_Labelflag;
	CLabel		m_LabelCase_Name;
	CLabel		m_LabelCase_No;
	CLabel		m_LabelCase_Type;
	CLabel		m_LabelInspector;
	CLabel		m_LabelHander;
	CLabel		m_LabelRemark;
	CEdit		m_EditCase_Name;
	CEdit		m_EditCase_No;
	CComboBox	m_ComCase_Type;
	CComboBox	m_ComInspector;
	CEdit		m_EditHander;
	CEdit		m_EditRemark;
	CStatic		m_StaticAddInspector;
	CButton		m_BtnOk;
	CButton		m_BtnCancle;
public:
	DECLARE_MESSAGE_MAP()
	void AdjustLayout();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void AddComInspector();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

