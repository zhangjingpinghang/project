#pragma once
#include "BorderStatic.h"
#include "BaseDlg.h"
#include "Label.h"


// GG_Collect_infoDlg dialog

class GG_Collect_infoDlg : public CBaseDlg
{
	

public:
	GG_Collect_infoDlg(void);   // standard constructor
	~GG_Collect_infoDlg(void);

// Dialog Data
protected:
	int					m_nDlgHeight;
	int					m_nDlgWidth;
	CString				m_strWndTitle;
	BOOL				IsCreate;

	CString				m_CStrCPCode;
	CString				m_CStrCPName;
	CString				m_CStrCPIP;
	CString				m_CStrCollector_ID;
	CString				m_CStrCollector_Name;
	CString				m_CStrSOwner;
	CString				m_CStrSOwnerNo;
	CString				m_CStrSIdCard;
	CString				m_CStrHzNm;




				
	CBorderStatic	m_BSCollect;
	CLabel			m_LabelCollect;
	CLabel			m_LabelCPCode;
	CLabel			m_LabelCPName;
	CLabel			m_LabelCPIP;
	CLabel		m_LabelCollector_ID;
	CLabel			m_LabelCollector_Name;
	CEdit			m_EditCPCode;
	CEdit			m_EditCPName;
	CIPAddressCtrl	m_CIPCtrlCPIP;
	CEdit			m_EditCollector_ID;
	CEdit			m_EditCollector_Name;

	CBorderStatic	m_BSSource;
	CLabel			m_LabelSource;
	CLabel			m_LabelSOwner;
	CLabel			m_LabelSOwnerNo;
	CLabel			m_LabelSIdCard;
	CLabel			m_LabelHzNm;
	CEdit			m_EditSOwner;
	CEdit			m_EditSOwnerNo;
	CEdit			m_EditSIdCard;
	CEdit			m_EditHzNm;
	CButton			m_BtnOk;
	CButton			m_BtnCancle;
					
protected:

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);

public:
	void AdjustLayout();
	void IsEmpty();
	bool IDCardValidate(CString IDCard);
	afx_msg void OnClickOk();
	afx_msg void OnClickCancle();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
