// FTPView.h : interface of the CFTPView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FTPVIEW_H__8A284FFC_64EE_11D6_A08B_000021EAA6E1__INCLUDED_)
#define AFX_FTPVIEW_H__8A284FFC_64EE_11D6_A08B_000021EAA6E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyListBox.h"

class CFTPView : public CFormView
{
//  Bool Status Variables
protected:

protected: // create from serialization only
	CFTPView();
	DECLARE_DYNCREATE(CFTPView)

public:
	//{{AFX_DATA(CFTPView)
	enum { IDD = IDD_FTP };
	CListBox	m_listManageAddress;
	CLocalListBox	m_listLocal;
	CServerListBox	m_listServer;
	CComboBox	m_comboAddress;
	CComboBox	m_comboName;
	CString		m_strPassword;
	//}}AFX_DATA

	//  FTP CLASS DATA(CFTPView)
	CFtpFileFind	*m_pFileFind;	// FTP 파일 검색 용도 클래스
	CInternetSession	m_Session;	// 세션 클래스
	CFtpConnection	*m_pConnect;		// FTP 명령 연결 컨트롤 클래스
	//  FTP CLASS DATA{CFTPView)

	//	Status -- Boolean
//	BOOL	m_bIsSelectLocal;
//	BOOL	m_bIsSelectServer;
//	BOOL	m_bInServer;
//	BOOL	m_bInLocal;

// Attributes
public:
	CFTPDoc* GetDocument();
	void	EnumerateFolder();
	HRESULT	DownloadFile( CString  dwnFile );
	HRESULT	UploadFile( CString upFile );

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTPView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFTPView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFTPView)
	afx_msg void OnUpload();
	afx_msg void OnDownload();
	afx_msg void OnConnect();
	afx_msg void OnDblclkServerListbox();
	afx_msg void OnPaint();
	afx_msg void OnDblclkLocallistListbox();
	afx_msg void OnDblclkManageaddressList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FTPView.cpp
inline CFTPDoc* CFTPView::GetDocument()
   { return (CFTPDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPVIEW_H__8A284FFC_64EE_11D6_A08B_000021EAA6E1__INCLUDED_)
