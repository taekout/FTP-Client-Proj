//		Drag 첨가!
//		처음 뷰의 최대화...  ,  List 박스 챠일드 윈도우 내에서 Char 메시지 처리....
// FTPView.cpp : implementation of the CFTPView class
//

#include "stdafx.h"
#include "FTP.h"

#include "FTPDoc.h"
#include "FTPView.h"
#include "MyListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define		MAKE_UPPER(x)	for( INT nIndexCount = 0 ; nIndexCount < 10 && *(x+nIndexCount)	\
									; nIndexCount++ )	\
							{							\
								if( *(x+nIndexCount) >= 'a' && *(x+nIndexCount) <= 'z' )	\
									*x -= 0x20 ;		\
							}

//	#define		ANSI
//	#define		_UNICODE

/////////////////////////////////////////////////////////////////////////////
// CFTPView

//  public Variables
//	CString		szDir;				//  보류 !! szDir 을 자세히 봐둘 것...

IMPLEMENT_DYNCREATE(CFTPView, CFormView)

BEGIN_MESSAGE_MAP(CFTPView, CFormView)
	//{{AFX_MSG_MAP(CFTPView)
	ON_BN_CLICKED(IDC_UPLOAD_BUTTON, OnUpload)
	ON_BN_CLICKED(IDC_DOWNLOAD_BUTTON, OnDownload)
	ON_BN_CLICKED(IDC_CONNECT_BUTTON, OnConnect)
	ON_LBN_DBLCLK(IDC_FILELIST_LISTBOX, OnDblclkServerListbox)
	ON_WM_PAINT()
	ON_LBN_DBLCLK(IDC_LOCALLIST_LISTBOX, OnDblclkLocallistListbox)
	ON_LBN_DBLCLK(IDC_MANAGEADDRESS_LIST, OnDblclkManageaddressList)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFTPView construction/destruction

CFTPView::CFTPView()
	: CFormView(CFTPView::IDD)
{
	//{{AFX_DATA_INIT(CFTPView)
	m_strPassword = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	SetCursor( LoadCursor( NULL, IDC_CROSS ) );
	m_pConnect = NULL;
	m_pFileFind = NULL;
//	SendMessage( WM_SIZE,

}

CFTPView::~CFTPView()
{
}

void CFTPView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFTPView)
	DDX_Control(pDX, IDC_MANAGEADDRESS_LIST, m_listManageAddress);
	DDX_Control(pDX, IDC_LOCALLIST_LISTBOX, m_listLocal);
	DDX_Control(pDX, IDC_FILELIST_LISTBOX, m_listServer);
	DDX_Control(pDX, IDC_ADDRESS_COMBOBOX, m_comboAddress);
	DDX_Control(pDX, IDC_NAME_COMBOBOX, m_comboName);
	DDX_Text(pDX, IDC_PASSWORD_EDIT, m_strPassword);
	DDV_MaxChars(pDX, m_strPassword, 30);
	//}}AFX_DATA_MAP
}

BOOL CFTPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CFTPView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	SetWindowText("Al FTP Program Ver 0.01");
	m_listManageAddress.AddString("ce.sejong.ac.kr");
	m_listManageAddress.AddString("www.daum.net");
	m_listManageAddress.AddString("www.freechal.com");
	m_listManageAddress.AddString("www.interface.co.kr");
	m_listServer.m_pDoc = GetDocument();
	SetScrollSizes( MM_TEXT, CSize( 403, 363 ) );
}

/////////////////////////////////////////////////////////////////////////////
// CFTPView printing

BOOL CFTPView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFTPView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFTPView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CFTPView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CFTPView diagnostics

#ifdef _DEBUG
void CFTPView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFTPView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFTPDoc* CFTPView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFTPDoc)));
	return (CFTPDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFTPView message handlers

HRESULT CFTPView::DownloadFile( CString dwnFile )
{
	CFTPDoc	*pDoc = GetDocument();
//	UpdateData( FALSE );
//	int	num = m_listServer.GetCurSel ();
	LPTSTR	temp = (LPTSTR) malloc( 512 );
	_tcscpy( temp, dwnFile );
//	m_listServer.GetText( num, temp );

	if( temp[ _tcslen(temp) - 1] == '/' )
	{
		AfxMessageBox( "디렉토리는 복사를 할 수 없스므니다... ^^ㆀ");
		return	E_FAIL;
	}
	CString	downData;
	downData += temp;	// error 나지 않나? 확인..

//	CFileDialog	dlg( TRUE, NULL, temp, OFN_HIDEREADONLY
//		, _T("모든 파일 (*.*) |*.*|"), this );
	CFile	*pFile = new CFile( downData, CFile::modeCreate );
	pDoc ->m_strLocalPath = pFile ->GetFilePath ();
	delete	pFile;
	CFile::Remove( pDoc ->m_strLocalPath );
	SetCursor( LoadCursor( NULL, IDC_WAIT ) );
	if( m_pConnect ->GetFile( downData, pDoc ->m_strLocalPath ) == NULL )
	{
		TRACE1( _T("%d"), GetLastError() );
		return	E_FAIL;
	}
	SetCursor( LoadCursor( NULL, IDC_CROSS ) );

	//	Free Memory
	free( temp );

	//  Local List Initialization
	//	Enumerate Now Loading Folder
/*	m_listLocal.ResetContent();
	WIN32_FIND_DATA		fd;
	HANDLE	hFind = ::FindFirstFile( _T("*.*"), &fd );

	if( hFind != INVALID_HANDLE_VALUE ) {
		do {
			if( !(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
				m_listLocal.AddString( fd.cFileName );
			else
			{
				CString		strDirectory;
				strDirectory = fd.cFileName;
				strDirectory += "/";
				m_listLocal.AddString( strDirectory );
			}
		} while( ::FindNextFile( hFind, &fd ) );
	}*/
	m_listLocal.EnumerateList();
	//  End ENUMERATING FOLDER.
	return	S_OK;
}

HRESULT CFTPView::UploadFile( CString upFile )
{
	CFTPDoc	*pDoc = GetDocument();
	CString		strFileName;
	SetCursor( LoadCursor( NULL, IDC_WAIT ));
//	INT		nIndex = m_listLocal.GetCurSel();
/*	if( nIndex == LB_ERR )
	{
		MessageBox("Local 목록 상자의 항목을 선택하여주십시오.");
		return	E_FAIL;
	}*/
//	m_listLocal.GetText( nIndex, strFileName );
//	strFileName = dlg.GetFileName();
	strFileName = upFile;
	if( strFileName[ strFileName.GetLength()-1 ] == '/' )
	{
		MessageBox("디렉토리는 업로드시킬 수 없습니다.");
		return	E_FAIL;
	}
	CFile	*pFile = new CFile( strFileName, CFile::modeRead );
	pDoc ->m_strLocalPath = pFile ->GetFilePath ();
	delete	pFile;
	if( m_pConnect ->PutFile( pDoc ->m_strLocalPath, strFileName ) == NULL ) // Error!
	{
		TRACE1( _T("%d"), GetLastError() );
		MessageBox("네트워킹 에러. 서버나 클라이언트의 경로 이상 또는 서버 상태 불량입니다.");
	}

/*	m_listServer.ResetContent();
	CString		data;
	m_pConnect ->GetCurrentDirectory( pDoc ->m_strServerPath );
	m_pFileFind ->FindFile( pDoc ->m_strServerPath );
	BOOL	bContinue = TRUE;
	while( bContinue )
	{
		bContinue = m_pFileFind ->FindNextFile();
		data = m_pFileFind ->GetFileName();
		if( m_pFileFind ->IsDirectory() )
			data += "/";
		m_listServer.AddString( data );
	}
	m_listServer.AddString( "./" );
	m_listServer.AddString( "../" );
	*/
	m_listServer.EnumerateList();
	SetCursor( LoadCursor( NULL, IDC_CROSS ));
	return	S_OK;
}

void CFTPView::OnUpload() 
{
	// TODO: Add your control notification handler code here
	CFTPDoc	*pDoc = GetDocument();
	CString		strFileName;
	SetCursor( LoadCursor( NULL, IDC_WAIT ));
	INT		nIndex = m_listLocal.GetCurSel();
	if( nIndex == LB_ERR )
	{
		MessageBox("Local 목록 상자의 항목을 선택하여주십시오.");
		return;
	}
	m_listLocal.GetText( nIndex, strFileName );
//	strFileName = dlg.GetFileName();
	if( strFileName[ strFileName.GetLength()-1 ] == '/' )
	{
		MessageBox("디렉토리는 업로드시킬 수 없습니다.");
		return;
	}
	CFile	*pFile = new CFile( strFileName, CFile::modeRead );
	pDoc ->m_strLocalPath = pFile ->GetFilePath ();
	delete	pFile;
	if( m_pConnect ->PutFile( pDoc ->m_strLocalPath, strFileName ) == NULL ) // Error!
	{
		TRACE1( _T("%d"), GetLastError() );
		MessageBox("네트워킹 에러. 서버나 클라이언트의 경로 이상 또는 서버 상태 불량입니다.");
	}

/*
	m_listServer.ResetContent();
	CString		data;
	m_pConnect ->GetCurrentDirectory( pDoc ->m_strServerPath );
	m_pFileFind ->FindFile( pDoc ->m_strServerPath );
	BOOL	bContinue = TRUE;
	while( bContinue )
	{
		bContinue = m_pFileFind ->FindNextFile();
		data = m_pFileFind ->GetFileName();
		if( m_pFileFind ->IsDirectory() )
			data += "/";
		m_listServer.AddString( data );
	}
	m_listServer.AddString( "./" );
	m_listServer.AddString( "../" );
	*/
	m_listServer.EnumerateList();
	SetCursor( LoadCursor( NULL, IDC_CROSS ));
}

void CFTPView::OnDownload()
{
	// TODO: Add your control notification handler code here
	CFTPDoc	*pDoc = GetDocument();
	UpdateData( FALSE );
	int	num = m_listServer.GetCurSel ();
	LPTSTR	temp = (LPTSTR) malloc( 512 );
	m_listServer.GetText( num, temp );

	if( temp[ _tcslen(temp) - 1] == '/' )
	{
		AfxMessageBox( "디렉토리는 복사를 할 수 없스므니다... ^^ㆀ");
		return;
	}
	CString	downData;
	downData += temp;	// error 나지 않나? 확인..

//	CFileDialog	dlg( TRUE, NULL, temp, OFN_HIDEREADONLY
//		, _T("모든 파일 (*.*) |*.*|"), this );
	CFile	*pFile = new CFile( downData, CFile::modeCreate );
	pDoc ->m_strLocalPath = pFile ->GetFilePath ();
	delete	pFile;
	CFile::Remove( pDoc ->m_strLocalPath );
	SetCursor( LoadCursor( NULL, IDC_WAIT ) );
	if( m_pConnect ->GetFile( downData, pDoc ->m_strLocalPath ) == NULL )
	{
		TRACE1( _T("%d"), GetLastError() );
		return;
	}
	SetCursor( LoadCursor( NULL, IDC_CROSS ) );

	//	Free Memory
	free( temp );

	//  Local List Initialization
	//	Enumerate Now Loading Folder
	m_listLocal.EnumerateList();
	//  End ENUMERATING FOLDER.
}

void CFTPView::OnConnect()
{
	// TODO: Add your control notification handler code here
	CFTPDoc	*pDoc = (CFTPDoc *) GetDocument();
	if( pDoc ->m_bConnected )
	{
		MessageBox("이미 접속되어 있는 상태입니다.");
		return;
	}

	UpdateData( TRUE );
	try
	{
		SetCursor( LoadCursor( NULL, IDC_WAIT ) );
	}
	catch( CInternetException	*pEx )
	{
		pEx ->Delete();
		pEx ->ReportError();
		AfxMessageBox("오류!");
	}

	CString	strAddress, strName ;
	INT		nIndex;
	if( (nIndex = m_comboAddress.GetCurSel()) == CB_ERR )	// 주소를 편집 콘트롤에 직접 입력시
	{
		m_comboAddress.GetWindowText( strAddress );
		LPTSTR	lpszToken = (LPTSTR) malloc( 500 );
		_tcscpy( lpszToken , strAddress.GetBuffer(7));
		for( INT i = 0 ; i < 10 && *(lpszToken + i) ; i++ )
		{
			if( *(lpszToken + i) >= 'a' && *(lpszToken + i) <= 'z' )
			{
				*(lpszToken + i) -= 0x20;
			}
		}
		*(lpszToken + 7) = '\0';

		if( _tcscmp( lpszToken , "HTTP://" ) == NULL )
			strAddress.Delete( 0 , 7 );
		if( m_comboAddress.FindString( -1 , strAddress ) == CB_ERR )
			m_comboAddress.AddString( strAddress );
		if( m_listManageAddress.FindString( -1 , strAddress ) == LB_ERR )
			m_listManageAddress.AddString( strAddress );
		free(lpszToken);
	}
	else
	{
		TCHAR	lpszAdd[300];
		m_comboAddress.GetLBText( nIndex, lpszAdd );
		strAddress = lpszAdd;
	}
	if( (nIndex = m_comboName.GetCurSel()) == CB_ERR )		// user 명을 편집 콘트롤에 직접 입력시
	{
		m_comboName.GetWindowText( strName );
		if( m_comboName.FindString( -1 , strName ) == CB_ERR )
			m_comboName.AddString( strName );
	}
	else
	{
		TCHAR	lpszName[300];
		m_comboName.GetLBText( nIndex, lpszName );
		strName = lpszName;
	}
	SetWindowText( strAddress );
	if( strName.GetLength() == 0 )
		m_pConnect = m_Session.GetFtpConnection( strAddress );
	else
		m_pConnect = m_Session.GetFtpConnection( strAddress, strName, m_strPassword );
	m_listServer.m_pConnection = m_pConnect;	// CFtpConnection 의 주소를 ListBox 멤버에 저장
	m_listServer.m_pSession = &m_Session;
//	m_listServer.m_pFileFind = m_pFileFind;
	m_listServer.m_pDoc = GetDocument();
	m_listLocal.m_pConnection = m_pConnect;
	m_listLocal.m_pSession = &m_Session;
	m_listLocal.m_pFileFind = m_pFileFind;
	m_listLocal.m_pDoc = GetDocument();
	if( m_pConnect )
	{
		// 보류! szDir 의 정체를 제대로 알아볼 것!
		m_pConnect ->GetCurrentDirectory( pDoc ->m_strServerPath );
		pDoc ->m_strServerPath += "/";
		if( m_pFileFind )
			delete	m_pFileFind;
		m_pFileFind = new CFtpFileFind( m_pConnect );
		m_listServer.m_pFileFind = m_pFileFind;
		//  여기가 원본과 다름
		/*
		m_listServer.ResetContent();
		CString	data;
		m_pConnect ->GetCurrentDirectory( pDoc ->m_strServerPath );
		m_pFileFind ->FindFile( pDoc ->m_strServerPath );
		BOOL	bContinue = TRUE;
		while( bContinue )
		{
			// 파일명을 얻음
			bContinue = m_pFileFind ->FindNextFile ();
			data = m_pFileFind ->GetFileName ();
			if( m_pFileFind ->IsDirectory() )
				data += "/";
			//	리스트 상자에 첨가... 원본과 다름
			m_listServer.AddString( data );
		}
		m_listServer.AddString( "./" );
		m_listServer.AddString( "../" );
		*/
		m_listServer.EnumerateList();
	}
	else
	{
		AfxMessageBox( "에러입니다... 주소 이상.");
	}
	SetCursor( LoadCursor( NULL, IDC_CROSS ) );

	//  여기부턴 로컬 디스크의 파일을 표시...
	m_listLocal.EnumerateList();
/*
	m_listLocal.ResetContent();
	WIN32_FIND_DATA		fd;
	HANDLE	hFind = ::FindFirstFile( _T("*.*"), &fd );

	if( hFind != INVALID_HANDLE_VALUE )
	{
		do {
			if( !(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
			{
				m_listLocal.AddString( fd.cFileName );
			}
			else
			{
				CString		strDirectoryName = fd.cFileName ;
				strDirectoryName += "/";
				m_listLocal.AddString( strDirectoryName );
			}
		}  while( ::FindNextFile( hFind, &fd ) );
		::FindClose( hFind );
	}
	*/
	//  Connecting 상태임을 멤버 변수에 표시
	pDoc ->m_bConnected = 1;
	m_listServer.m_pConnection = m_pConnect;	// CFtpConnection 의 주소를 ListBox 멤버에 저장
	m_listServer.m_pSession = &m_Session;
	m_listServer.m_pFileFind = m_pFileFind;
	m_listServer.m_pDoc = GetDocument();
	m_listLocal.m_pConnection = m_pConnect;
	m_listLocal.m_pSession = &m_Session;
	m_listLocal.m_pFileFind = m_pFileFind;
	m_listLocal.m_pDoc = GetDocument();
}

void CFTPView::OnDblclkServerListbox() 
{
	// TODO: Add your control notification handler code here
	UpdateData( FALSE );
	CFTPDoc	*pDoc = GetDocument ();

	int	num = m_listServer.GetCurSel();
	if( num == LB_ERR )		//  이런 상황은 아마 안 날 것이나 혹시 만약의 경우...
		return;
	CString	strDir;
	m_listServer.GetText( num , strDir );
	if( strDir == "./" )
		return;
	if( strDir == "../" )		// 상위 디렉토리로 이동할 경우
	{
		m_pConnect ->GetCurrentDirectory( pDoc ->m_strServerPath );
		if( pDoc ->m_strServerPath == "/" )
		{
			MessageBox("지금 현 디렉토리가 가장 상위 디렉토리입니다.");
			return;
		}
		LPTSTR	temp = (LPTSTR) malloc( 100 );
		_tcscpy( temp , pDoc ->m_strServerPath );
		if( temp[ _tcslen(temp) -1 ] == '/' )
			temp[ _tcslen(temp) -1 ] = NULL;
		int nLen = _tcslen( temp ) -1;
		for( INT i = nLen ; i >= 0 ; i-- )
		{
			if( temp[i] == '/' )
			{
				temp[i + 1] = NULL;
				break;
			}
		}
		pDoc ->m_strServerPath = temp;
//		pDoc ->m_strServerPath += "/";
		free( temp );
		if( !m_pConnect ->SetCurrentDirectory( pDoc ->m_strServerPath ) )
		{
			MessageBox( "디렉토리 이동 실패! 지금 경로가 가장 최상 경로일 수도 있습니다.");
			return;
		}

		// Server List Initialization
		/*
		CString	data;
		data.Empty();
		m_listServer.ResetContent();
		m_pConnect ->GetCurrentDirectory( pDoc ->m_strServerPath );
		m_pFileFind ->FindFile( pDoc ->m_strServerPath );

		BOOL	bContinue;
		while( bContinue )
		{
			bContinue = m_pFileFind ->FindNextFile ();
			data = m_pFileFind ->GetFileName ();
			if( m_pFileFind ->IsDirectory() )
				data += "/";
			m_listServer.AddString( data );
		}
		m_listServer.AddString( "./" );
		m_listServer.AddString( "../" );
		*/
		m_listServer.EnumerateList();
		SetCursor( LoadCursor( NULL, IDC_CROSS ) );
		return;
	}
	else
	{
		pDoc ->m_strServerPath += strDir;
	}
	if( pDoc ->m_strServerPath[pDoc ->m_strServerPath.GetLength()-1] != '/' )
	{
		UpdateData( FALSE );
		int	num = m_listServer.GetCurSel ();
		LPTSTR	temp = (LPTSTR) malloc( 512 );
		m_listServer.GetText( num, temp );

		CString	downData;
		downData += temp;	// error 나지 않나? 확인..

//		CFileDialog	dlg( TRUE, NULL, temp, OFN_HIDEREADONLY
//			, _T("모든 파일 (*.*) |*.*|"), this );
		free( temp );
//		dlg.DoModal();
		SetCursor( LoadCursor( NULL, IDC_WAIT ) );
//		CString		str = dlg.GetPathName();
		CFile	*pFile = new CFile( downData, CFile::modeCreate );
		pDoc ->m_strLocalPath = pFile ->GetFilePath();
		delete	pFile;
		CFile::Remove( pDoc ->m_strLocalPath );
		if( m_pConnect ->GetFile( downData, pDoc ->m_strLocalPath ) == NULL )
		{
			TRACE1( _T("%d"), GetLastError() );
			MessageBox("다운로드 에러!");
		}
		SetCursor( LoadCursor( NULL, IDC_CROSS ) );

		//  Local 초기화
		/*
		m_listLocal.ResetContent();
		WIN32_FIND_DATA		fd;
		HANDLE	hFind = ::FindFirstFile( _T("*.*"), &fd );
		if( hFind != INVALID_HANDLE_VALUE ) {
			do {
				if( !(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
					m_listLocal.AddString( fd.cFileName );
				else
				{
					CString		strDirectory;
					strDirectory = fd.cFileName;
					strDirectory += "/";
					m_listLocal.AddString( strDirectory );
				}
			} while( ::FindNextFile( hFind, &fd ) );
		}
		*/
		m_listLocal.EnumerateList();
		//  End ENUMERATING FOLDER.

		return;
	}

	if( !m_pConnect ->SetCurrentDirectory( pDoc ->m_strServerPath ) )
	{
		pDoc ->m_strServerPath += "/";
		AfxMessageBox("디렉토리 이동 불가");
		return;
	}
	SetCursor( LoadCursor( NULL, IDC_WAIT ) );

//	BOOL	bContinue = TRUE;
//	m_listServer.ResetContent();
//	CString	data;
//	m_pConnect ->GetCurrentDirectory( pDoc ->m_strServerPath );
//	bContinue = m_pFileFind ->FindFile( pDoc ->m_strServerPath );
//	if( bContinue == NULL )	// 에러 발생시
//		if( GetLastError() == ERROR_NO_MORE_FILES )		// 파일이 없을 경우는 예외
//		{
//			SetCursor( LoadCursor( NULL, IDC_CROSS ) );
//			m_listServer.EnumerateList();
//			return;
//		}
//	while( bContinue )
//	{
//		bContinue = m_pFileFind ->FindNextFile ();
//		data = m_pFileFind ->GetFileName ();
//		if( m_pFileFind ->IsDirectory() )
//			data += "/";
//		m_listServer.AddString( data );
//	}
//	m_listServer.AddString( "./" );
//	m_listServer.AddString( "../" );
	m_listServer.EnumerateList();
	SetCursor( LoadCursor( NULL, IDC_CROSS ) );
}
/*
	BOOL	bContinue = TRUE;
	while( bContinue )
	{
		bContinue = m_pFileFind ->FindNextFile();
		data = m_pFileFind ->GetFileName();
		if( m_pFileFind ->IsDirectory() )
			data += "/";
		m_listServer.AddString( data );
	}
	m_listServer.AddString( "./" );
	m_listServer.AddString( "../" );
*/

void CFTPView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
//	CRect	rt;
//	GetClientRect( &rt );
//	dc.SetMapMode( MM_ANISOTROPIC );
//	dc.SetWindowExt( 500 , 500 );
//	dc.SetViewportExt( rt.Width(), rt.Height() );
	
	// Do not call CFormView::OnPaint() for painting messages
}

void CFTPView::OnDblclkLocallistListbox() 
{
	// TODO: Add your control notification handler code here
	CFTPDoc	*pDoc = GetDocument();
	CString		strFileName;
	SetCursor( LoadCursor( NULL, IDC_WAIT ));

	m_listLocal.GetText( m_listLocal.GetCurSel(), strFileName );
	if( strFileName[ strFileName.GetLength()-1 ] == '/' )	// Is Directory...?
	{
		strFileName.Delete( strFileName.GetLength()-1 );
		::SetCurrentDirectory( strFileName );
		// Enumerate Folders.
		/*
		m_listLocal.ResetContent();
		WIN32_FIND_DATA		fd;
		HANDLE	hFind = ::FindFirstFile( _T("*.*"), &fd );

		if( hFind != INVALID_HANDLE_VALUE ) {
			do {
				if( !(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
					m_listLocal.AddString( fd.cFileName );
				else
				{
					CString		strDirectory;
					strDirectory = fd.cFileName;
					strDirectory += "/";
					m_listLocal.AddString( strDirectory );
				}
			} while( ::FindNextFile( hFind, &fd ) );
		}
		*/
		m_listLocal.EnumerateList();
		strFileName += "/" ;
		//  End ENUMERATING FOLDER.
		return;
	}
	if( strFileName == "../" )	// 상위 디렉토리로 이동하라
	{
		::SetCurrentDirectory( _T("..") );
//		LPTSTR	strTemp = (LPTSTR) malloc( 30 );
//		::GetCurrentDirectory( 30 , strTemp );
//		pDoc ->m_strLocalPath = strTemp;
//		free(strTemp);
		//  ENUMERATE FOLDER   CFileDialog
		/*
		m_listLocal.ResetContent();
		WIN32_FIND_DATA		fd;
		HANDLE	hFind = ::FindFirstFile( _T("*.*"), &fd );

		if( hFind != INVALID_HANDLE_VALUE )
		{
			do {
				if( fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )	// Is Directory..
				{
					CString		strDirectory;
					strDirectory = fd.cFileName;
					strDirectory += "/";
					m_listLocal.AddString( fd.cFileName );
				}
				else		// Is Files..
					m_listLocal.AddString( fd.cFileName );
			} while( ::FindNextFile( hFind, &fd ) );
		}
		*/
		m_listLocal.EnumerateList();
		return;
	}
	strFileName.Empty ();		//  삭제 가능
	m_listLocal.GetText( m_listLocal.GetCurSel(), strFileName );	// 삭제 가능
	CFile		*pFile = new CFile( strFileName, CFile::modeRead );
	pDoc ->m_strLocalPath = pFile ->GetFilePath();
	delete	pFile;
//	pDoc ->m_strLocalPath.Replace( "\\", "\\\\" );
//	pDoc ->m_strServerPath.Replace( "//", "/" );
//	if( pDoc ->m_strServerPath[0] == '/' )
//		pDoc ->m_strServerPath.Delete( 0 );
	if( m_pConnect ->PutFile( pDoc ->m_strLocalPath , strFileName ) == NULL ) // Error!
	{
		TRACE1( _T("%d"), GetLastError() );
		MessageBox("네트워킹 에러. 서버나 클라이언트의 경로 이상 또는 서버 상태 불량입니다.");
		return;
		// Error Code ==> (53)ERROR_BAD_NETPATH : The network path was not found.
		// ==> (32)The process cannot access the file because it is being used by another process.  ERROR_SHARING_VIOLATION
	}
//	if( pDoc ->m_strServerPath[ nLeng - 1 ] != '/' )
//		pDoc ->m_strServerPath += "/";
	/*
	m_listServer.ResetContent();
	CString		data;
	m_pConnect ->GetCurrentDirectory( pDoc ->m_strServerPath );
	m_pFileFind ->FindFile( pDoc ->m_strServerPath );
	BOOL	bContinue = TRUE;
	while( bContinue )
	{
		bContinue = m_pFileFind ->FindNextFile();
		data = m_pFileFind ->GetFileName();
		if( m_pFileFind ->IsDirectory() )
			data += "/";
		m_listServer.AddString( data );
	}
	m_listServer.AddString( "./" );
	m_listServer.AddString( "../" );
	*/
	m_listServer.EnumerateList();
	SetCursor( LoadCursor( NULL, IDC_CROSS ));
}

void CFTPView::OnDblclkManageaddressList() 
{
	// TODO: Add your control notification handler code here
	INT		nIndex;
	if( (nIndex = m_listManageAddress.GetCurSel()) == LB_ERR )
		return;
	CString		strAddress;
	m_listManageAddress.GetText( nIndex , strAddress );
	m_comboAddress.SetWindowText( strAddress );
	UpdateData( FALSE );
}
/*
void CFTPView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if( m_listLocal.m_bDragStartPointInLocal == TRUE &&
		m_listServer.m_bDragEndPointInServer == TRUE )
	{
		MessageBox("Upload");
	}
	if( m_listLocal.m_bDragEndPointInLocal == TRUE &&
		m_listServer.m_bDragStartPointInServer == TRUE )
	{
		MessageBox("Download");
	}

	CFormView::OnLButtonDown(nFlags, point);
}
*/
