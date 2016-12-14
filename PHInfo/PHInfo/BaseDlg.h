#pragma once
#include "resource.h"

// CBaseDlg dialog

#define  IDC_BTN_OK  100001
#define  IDC_BTN_CANCEL  100002

class CBaseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBaseDlg)

public:
	CBaseDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBaseDlg();

// Dialog Data
	enum { IDD = IDD_BASEDLG };
protected:
	BOOL m_bCreateCompleted;
	int m_nDlgWidth;
	int m_nDlgHeight;
	CString m_strWndTitle;
	CButton m_btnOK;
	CButton m_btnCancel;


public:
	virtual void AdjustLayout();
	virtual BOOL CreateControllers();
	virtual BOOL UpdateControllers();
	virtual void DealOKMsg();
	virtual void DealCancelMsg();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnBnOK();
	virtual void OnBnCancel();
};
