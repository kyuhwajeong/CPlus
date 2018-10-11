
// WorkThreadView.cpp : CWorkThreadView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "WorkThread.h"
#endif

#include "WorkThreadDoc.h"
#include "WorkThreadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWorkThreadView

IMPLEMENT_DYNCREATE(CWorkThreadView, CView)

BEGIN_MESSAGE_MAP(CWorkThreadView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CWorkThreadView 생성/소멸

CWorkThreadView::CWorkThreadView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CWorkThreadView::~CWorkThreadView()
{
}

BOOL CWorkThreadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CWorkThreadView 그리기

void CWorkThreadView::OnDraw(CDC* /*pDC*/)
{
	CWorkThreadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CWorkThreadView 인쇄

BOOL CWorkThreadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CWorkThreadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CWorkThreadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CWorkThreadView 진단

#ifdef _DEBUG
void CWorkThreadView::AssertValid() const
{
	CView::AssertValid();
}

void CWorkThreadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWorkThreadDoc* CWorkThreadView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWorkThreadDoc)));
	return (CWorkThreadDoc*)m_pDocument;
}
#endif //_DEBUG


// CWorkThreadView 메시지 처리기


void CWorkThreadView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDblClk(nFlags, point);
}
