// FTPDoc.h : interface of the CFTPDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FTPDOC_H__8A284FFA_64EE_11D6_A08B_000021EAA6E1__INCLUDED_)
#define AFX_FTPDOC_H__8A284FFA_64EE_11D6_A08B_000021EAA6E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFTPDoc : public CDocument
{
//  Status Variables
public:
	BOOL	m_bConnected;

protected: // create from serialization only
	CFTPDoc();
	DECLARE_DYNCREATE(CFTPDoc)

// Attributes
public:
	CString		m_strLocalPath;
	CString		m_strServerPath;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTPDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFTPDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFTPDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPDOC_H__8A284FFA_64EE_11D6_A08B_000021EAA6E1__INCLUDED_)
