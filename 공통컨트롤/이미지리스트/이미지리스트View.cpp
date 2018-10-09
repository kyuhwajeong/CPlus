
// 이미지리스트View.cpp : C이미지리스트View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "이미지리스트.h"
#endif

#include "이미지리스트Doc.h"
#include "이미지리스트View.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C이미지리스트View

IMPLEMENT_DYNCREATE(C이미지리스트View, CView)

BEGIN_MESSAGE_MAP(C이미지리스트View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// C이미지리스트View 생성/소멸

C이미지리스트View::C이미지리스트View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C이미지리스트View::~C이미지리스트View()
{
}

BOOL C이미지리스트View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// C이미지리스트View 그리기

void C이미지리스트View::OnDraw(CDC* pDC)
{
	C이미지리스트Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 배경을 칠한다.
	CBrush brush(HS_DIAGCROSS, RGB(0, 255, 0));
	pDC->SelectObject(&brush);
	CRect rect;
	GetClientRect(&rect);
	pDC->Rectangle(&rect);

	// 배경을 투명색으로 설정한다.
	m_il.SetBkColor(CLR_NONE);
	m_il.Draw(pDC, 0, CPoint(100, 100), ILD_NORMAL);
	m_il.Draw(pDC, 0, CPoint(200, 100), ILD_TRANSPARENT);
	m_il.Draw(pDC, 0, CPoint(300, 100), ILD_BLEND25);
	m_il.Draw(pDC, 0, CPoint(400, 100), ILD_BLEND50);
	m_il.Draw(pDC, 0, CPoint(500, 100), ILD_MASK);

	// 배경을 검정색으로 설정한다
	m_il.SetBkColor(RGB(0,0,0));
	m_il.Draw(pDC, 1, CPoint(100, 200), ILD_NORMAL);
	m_il.Draw(pDC, 1, CPoint(200, 200), ILD_TRANSPARENT);
	m_il.Draw(pDC, 1, CPoint(300, 200), ILD_BLEND25);
	m_il.Draw(pDC, 1, CPoint(400, 200), ILD_BLEND50);
	m_il.Draw(pDC, 1, CPoint(500, 200), ILD_MASK);
}


// C이미지리스트View 인쇄

BOOL C이미지리스트View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void C이미지리스트View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void C이미지리스트View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// C이미지리스트View 진단

#ifdef _DEBUG
void C이미지리스트View::AssertValid() const
{
	CView::AssertValid();
}

void C이미지리스트View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C이미지리스트Doc* C이미지리스트View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C이미지리스트Doc)));
	return (C이미지리스트Doc*)m_pDocument;
}
#endif //_DEBUG


// C이미지리스트View 메시지 처리기


int C이미지리스트View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_il.Create(IDB_BITMAP1, 48, 1, RGB(255, 255, 255));

	return 0;
}
