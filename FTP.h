// FTP.h : main header file for the FTP application
//

#if !defined(AFX_FTP_H__8A284FF2_64EE_11D6_A08B_000021EAA6E1__INCLUDED_)
#define AFX_FTP_H__8A284FF2_64EE_11D6_A08B_000021EAA6E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFTPApp:
// See FTP.cpp for the implementation of this class
//

class CFTPApp : public CWinApp
{
public:
	CFTPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFTPApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTP_H__8A284FF2_64EE_11D6_A08B_000021EAA6E1__INCLUDED_)
