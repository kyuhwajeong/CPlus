
// 리스트뷰Doc.cpp : C리스트뷰Doc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "리스트뷰.h"
#endif

#include "리스트뷰Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C리스트뷰Doc

IMPLEMENT_DYNCREATE(C리스트뷰Doc, CDocument)

BEGIN_MESSAGE_MAP(C리스트뷰Doc, CDocument)
END_MESSAGE_MAP()


// C리스트뷰Doc 생성/소멸

C리스트뷰Doc::C리스트뷰Doc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

C리스트뷰Doc::~C리스트뷰Doc()
{
}

BOOL C리스트뷰Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	for (int i = 0; i < NUMITEM; i++)
	{
		m_item[i].name.Format(L"상품 #%d", i);
		m_item[i].price = 1000 + i;
		m_item[i].quantity = 10000 + i;
	}

	return TRUE;
}




// C리스트뷰Doc serialization

void C리스트뷰Doc::Serialize(CArchive& ar)
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

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void C리스트뷰Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void C리스트뷰Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void C리스트뷰Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C리스트뷰Doc 진단

#ifdef _DEBUG
void C리스트뷰Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C리스트뷰Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C리스트뷰Doc 명령
