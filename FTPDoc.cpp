// FTPDoc.cpp : implementation of the CFTPDoc class
//

#include "stdafx.h"
#include "FTP.h"

#include "FTPDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFTPDoc

IMPLEMENT_DYNCREATE(CFTPDoc, CDocument)

BEGIN_MESSAGE_MAP(CFTPDoc, CDocument)
	//{{AFX_MSG_MAP(CFTPDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFTPDoc construction/destruction

CFTPDoc::CFTPDoc()
{
	// TODO: add one-time construction code here
	m_bConnected = NULL;

}

CFTPDoc::~CFTPDoc()
{
}

BOOL CFTPDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFTPDoc serialization

void CFTPDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CFTPDoc diagnostics

#ifdef _DEBUG
void CFTPDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFTPDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFTPDoc commands