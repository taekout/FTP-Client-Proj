#if !defined(AFX_INPUTDIALOG_H__6A305CC6_69C0_11D6_A08B_000021EAA6E1__INCLUDED_)
#define AFX_INPUTDIALOG_H__6A305CC6_69C0_11D6_A08B_000021EAA6E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInputDialog dialog

class CInputDialog : public CDialog
{
// Construction
public:
	CInputDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInputDialog)
	enum { IDD = IDD_INPUT };
	CString	m_strNewName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInputDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTDIALOG_H__6A305CC6_69C0_11D6_A08B_000021EAA6E1__INCLUDED_)
