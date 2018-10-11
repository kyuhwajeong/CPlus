
// WorkThread2View.cpp : CWorkThread2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "WorkThread2.h"
#endif

#include "WorkThread2Doc.h"
#include "WorkThread2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWorkThread2View

IMPLEMENT_DYNCREATE(CWorkThread2View, CView)

BEGIN_MESSAGE_MAP(CWorkThread2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CWorkThread2View 생성/소멸

CWorkThread2View::CWorkThread2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CWorkThread2View::~CWorkThread2View()
{
}

BOOL CWorkThread2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CWorkThread2View 그리기

void CWorkThread2View::OnDraw(CDC* /*pDC*/)
{
	CWorkThread2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CWorkThread2View 인쇄

BOOL CWorkThread2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CWorkThread2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CWorkThread2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CWorkThread2View 진단

#ifdef _DEBUG
void CWorkThread2View::AssertValid() const
{
	CView::AssertValid();
}

void CWorkThread2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWorkThread2Doc* CWorkThread2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWorkThread2Doc)));
	return (CWorkThread2Doc*)m_pDocument;
}
#endif //_DEBUG


// CWorkThread2View 메시지 처리기
UINT MyDraw(LPVOID arg)
{
	ThreadArg *pArg = (ThreadArg *)arg;

	// CDC 객체를 선언하고 디바이스 컨텍스트 핸들과 연결시킨다.
	CDC dc;
	HDC hdc = ::GetDC(pArg->hwnd);
	dc.Attach(hdc);

	int i, x, y;
	CBrush brush1(RGB(255, 0, 0));
	CBrush brush2(RGB(0, 0, 255));
	
	// 화면에 느린 속도로 막대를 출력한다.
	switch (pArg->type){
	case 1:
		dc.SelectObject(&brush1);
		x = 100;
		y = 100;
		for (i = 0; i<100000; i++){
			int inc = i / 200;
			dc.Rectangle(x, y, x + inc, y + 20);
		}
		break;
	case 2:
		dc.SelectObject(&brush2);
		x = 100;
		y = 200;
		for (i = 0; i<100000; i++){
			int inc = i / 200;
			dc.Rectangle(x, y, x + inc, y + 20);
		}
		break;
	}

	dc.Detach();
	::ReleaseDC(pArg->hwnd, hdc);

	return 0;
}

void CWorkThread2View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// 화면을 지운다.
	CClientDC dc(this);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	CRect rect;
	GetClientRect(&rect);
	dc.Rectangle(&rect);

	//첫번째 스레드 생성(정지 상태)
	arg1.hwnd = this->m_hWnd;
	arg1.type = 1;
	pThread1 = AfxBeginThread(MyDraw, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	//두번째 스레드 생성(정지 상태)
	arg2.hwnd = this->m_hWnd;
	arg2.type = 2;
	pThread2 = AfxBeginThread(MyDraw, &arg2, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	// 스레드 우선순위 레벨 변경
	pThread2->SetThreadPriority(THREAD_PRIORITY_ABOVE_NORMAL);

	// 두 스레드를 실행한다.
	pThread1->ResumeThread();
	pThread2->ResumeThread();

	CView::OnLButtonDblClk(nFlags, point);
}
