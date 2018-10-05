
// 모드형대화상자2View.cpp : C모드형대화상자2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "모드형대화상자2.h"
#endif

#include "모드형대화상자2Doc.h"
#include "모드형대화상자2View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C모드형대화상자2View

IMPLEMENT_DYNCREATE(C모드형대화상자2View, CView)

BEGIN_MESSAGE_MAP(C모드형대화상자2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C모드형대화상자2View 생성/소멸

C모드형대화상자2View::C모드형대화상자2View()
	: m_str(_T(""))
	, m_color(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C모드형대화상자2View::~C모드형대화상자2View()
{
}

BOOL C모드형대화상자2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// C모드형대화상자2View 그리기

void C모드형대화상자2View::OnDraw(CDC* pDC)
{
	C모드형대화상자2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont font;
	font.CreatePointFont(300, L"Arial");
	pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(m_color, 0, 0));
	pDC->TextOut(10, 10, m_str);
}


// C모드형대화상자2View 인쇄

BOOL C모드형대화상자2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void C모드형대화상자2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void C모드형대화상자2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// C모드형대화상자2View 진단

#ifdef _DEBUG
void C모드형대화상자2View::AssertValid() const
{
	CView::AssertValid();
}

void C모드형대화상자2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C모드형대화상자2Doc* C모드형대화상자2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C모드형대화상자2Doc)));
	return (C모드형대화상자2Doc*)m_pDocument;
}
#endif //_DEBUG


// C모드형대화상자2View 메시지 처리기


void C모드형대화상자2View::OnLButtonDblClk(UINT nFlags, CPoint point)  // 뷰 바탕 더블클릭 시
{
	CMyDialog dlg;
	dlg.m_str = m_str;
	dlg.m_color = m_color;

	int result = dlg.DoModal();
	if (result == IDOK){
		m_str = dlg.m_str;
		m_color = dlg.m_color;
		Invalidate();
	}
	else if (result == 100){  // 다이어로그(IDD_DIALOG1) 지우기 버튼 실행 시 
		m_str = "";
		m_color = 0;
		Invalidate();
	}

	CView::OnLButtonDblClk(nFlags, point);
}
