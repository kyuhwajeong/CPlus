
// MFC도큐먼트뷰구조View.cpp : CMFC도큐먼트뷰구조View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC도큐먼트뷰구조.h"
#endif

#include "MFC도큐먼트뷰구조Doc.h"
#include "MFC도큐먼트뷰구조View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC도큐먼트뷰구조View

IMPLEMENT_DYNCREATE(CMFC도큐먼트뷰구조View, CView)

BEGIN_MESSAGE_MAP(CMFC도큐먼트뷰구조View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC도큐먼트뷰구조View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC도큐먼트뷰구조View 생성/소멸

CMFC도큐먼트뷰구조View::CMFC도큐먼트뷰구조View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFC도큐먼트뷰구조View::~CMFC도큐먼트뷰구조View()
{
}

BOOL CMFC도큐먼트뷰구조View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFC도큐먼트뷰구조View 그리기

void CMFC도큐먼트뷰구조View::OnDraw(CDC* /*pDC*/)
{
	CMFC도큐먼트뷰구조Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFC도큐먼트뷰구조View 인쇄


void CMFC도큐먼트뷰구조View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC도큐먼트뷰구조View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFC도큐먼트뷰구조View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFC도큐먼트뷰구조View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMFC도큐먼트뷰구조View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC도큐먼트뷰구조View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC도큐먼트뷰구조View 진단

#ifdef _DEBUG
void CMFC도큐먼트뷰구조View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC도큐먼트뷰구조View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC도큐먼트뷰구조Doc* CMFC도큐먼트뷰구조View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC도큐먼트뷰구조Doc)));
	return (CMFC도큐먼트뷰구조Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC도큐먼트뷰구조View 메시지 처리기
