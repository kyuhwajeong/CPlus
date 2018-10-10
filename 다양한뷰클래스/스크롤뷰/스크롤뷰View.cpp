
// 스크롤뷰View.cpp : C스크롤뷰View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "스크롤뷰.h"
#endif

#include "스크롤뷰Doc.h"
#include "스크롤뷰View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C스크롤뷰View

IMPLEMENT_DYNCREATE(C스크롤뷰View, CScrollView)

BEGIN_MESSAGE_MAP(C스크롤뷰View, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// C스크롤뷰View 생성/소멸

C스크롤뷰View::C스크롤뷰View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C스크롤뷰View::~C스크롤뷰View()
{
}

BOOL C스크롤뷰View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// C스크롤뷰View 그리기

void C스크롤뷰View::OnDraw(CDC* pDC)
{
	C스크롤뷰Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect rect;
	pDC->GetClipBox(&rect);
	rect.InflateRect(100, 100, 100, 100);

	CString str;
	for (int x = 0; x < 4000; x += 100)
		for (int y = 0; y < 4000; y += 100){
			// 무효 영역 사각형에 포함되지 않으면 출력하지 않는다.
			// 만약 이 코드를 제거하면 스크롤 속도가 매우 느려진다.
			if (!rect.PtInRect(CPoint(x, y))) continue;

			// 느린 속도로 사각형을 그린다.
			MyDraw(pDC, x + 50, y + 50);

			// 사각형 중심 좌표를 출력한다.
			str.Format(L"(%d, %d)", x + 50, y + 50);
			pDC->SetBkColor(TRANSPARENT);
			pDC->DrawText(str, CRect(x, y, x + 100, y + 100), 
				DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
}

void C스크롤뷰View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// C스크롤뷰View 인쇄

BOOL C스크롤뷰View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void C스크롤뷰View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void C스크롤뷰View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// C스크롤뷰View 진단

#ifdef _DEBUG
void C스크롤뷰View::AssertValid() const
{
	CScrollView::AssertValid();
}

void C스크롤뷰View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

C스크롤뷰Doc* C스크롤뷰View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C스크롤뷰Doc)));
	return (C스크롤뷰Doc*)m_pDocument;
}
#endif //_DEBUG


// C스크롤뷰View 메시지 처리기


void C스크롤뷰View::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	CSize sizeTotal(4000, 4000);
	CSize sizePage(cx - 50, cy - 50);
	CSize sizeLine(50, 50);
	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);
}


// x, y 중심으로 한 변의 길이가 100픽셀인 정사각형을 그린다.
void C스크롤뷰View::MyDraw(CDC * pDC, int x, int y)
{
	CPen pen(PS_SOLID, 1, RGB(x % 256, y % 256, (x + y) % 128));
	pDC->SelectObject(&pen);
	pDC->SelectStockObject(NULL_BRUSH);
	for (int i = 50; i > 0; i--){
		// 같은 코드를 두 번 실행함으로써 속도가 더욱 느려지도록 한다.
		// 빠른 컴퓨터를 사용할 경우 몇 줄 더 추가해서 실습해 본다.
		pDC->Rectangle(x - i, y - i, x + i, y + i);
		pDC->Rectangle(x - i, y - i, x + i, y + i);
	}
}
