// DrawDoc.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MDI.h"
#include "DrawDoc.h"


// CDrawDoc

IMPLEMENT_DYNCREATE(CDrawDoc, CDocument)

CDrawDoc::CDrawDoc()
{
}

BOOL CDrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CDrawDoc::~CDrawDoc()
{
}


BEGIN_MESSAGE_MAP(CDrawDoc, CDocument)
END_MESSAGE_MAP()


// CDrawDoc �����Դϴ�.

#ifdef _DEBUG
void CDrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CDrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CDrawDoc serialization�Դϴ�.

void CDrawDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}
#endif


// CDrawDoc ����Դϴ�.
