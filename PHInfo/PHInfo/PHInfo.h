
// PHInfo.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPHInfoApp:
// See PHInfo.cpp for the implementation of this class
//

class CPHInfoApp : public CWinApp
{
public:
	CPHInfoApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPHInfoApp theApp;