
// 모드형대화상자1View.cpp : C모드형대화상자1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "모드형대화상자1.h"
#endif

#include "모드형대화상자1Doc.h"
#include "모드형대화상자1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C모드형대화상자1View

IMPLEMENT_DYNCREATE(C모드형대화상자1View, CView)

BEGIN_MESSAGE_MAP(C모드형대화상자1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C모드형대화상자1View 생성/소멸

C모드형대화상자1View::C모드형대화상자1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C모드형대화상자1View::~C모드형대화상자1View()
{
}

BOOL C모드형대화상자1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// C모드형대화상자1View 그리기

void C모드형대화상자1View::OnDraw(CDC* /*pDC*/)
{
	C모드형대화상자1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// C모드형대화상자1View 인쇄

BOOL C모드형대화상자1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void C모드형대화상자1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void C모드형대화상자1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// C모드형대화상자1View 진단

#ifdef _DEBUG
void C모드형대화상자1View::AssertValid() const
{
	CView::AssertValid();
}

void C모드형대화상자1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C모드형대화상자1Doc* C모드형대화상자1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C모드형대화상자1Doc)));
	return (C모드형대화상자1Doc*)m_pDocument;
}
#endif //_DEBUG


// C모드형대화상자1View 메시지 처리기


void C모드형대화상자1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CDialog dlg(IDD_DIALOG1);
	if (dlg.DoModal() == IDOK)
		MessageBox(L"OK 버튼을 눌렀습니다.");
	else
		MessageBox(L"Cancel 버튼을 눌렀습니다.");

	CView::OnLButtonDblClk(nFlags, point);
}
