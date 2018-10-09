// DrawDoc.cpp : 구현 파일입니다.
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


// CDrawDoc 진단입니다.

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
// CDrawDoc serialization입니다.

void CDrawDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}
#endif


// CDrawDoc 명령입니다.
