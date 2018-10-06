
// 비모드형대화상자View.cpp : C비모드형대화상자View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "비모드형대화상자.h"
#endif

#include "비모드형대화상자Doc.h"
#include "비모드형대화상자View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C비모드형대화상자View

IMPLEMENT_DYNCREATE(C비모드형대화상자View, CView)

BEGIN_MESSAGE_MAP(C비모드형대화상자View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C비모드형대화상자View 생성/소멸

C비모드형대화상자View::C비모드형대화상자View()
	: m_str(_T(""))
	, m_color(0)
{
	m_pDlg = NULL;

}

C비모드형대화상자View::~C비모드형대화상자View()
{
}

BOOL C비모드형대화상자View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// C비모드형대화상자View 그리기

void C비모드형대화상자View::OnDraw(CDC* pDC)
{
	C비모드형대화상자Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont font;
	font.CreatePointFont(300, L"Arial");
	pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(m_color, 0, 0));
	pDC->TextOut(10, 10, m_str);
}


// C비모드형대화상자View 인쇄

BOOL C비모드형대화상자View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void C비모드형대화상자View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void C비모드형대화상자View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// C비모드형대화상자View 진단

#ifdef _DEBUG
void C비모드형대화상자View::AssertValid() const
{
	CView::AssertValid();
}

void C비모드형대화상자View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C비모드형대화상자Doc* C비모드형대화상자View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C비모드형대화상자Doc)));
	return (C비모드형대화상자Doc*)m_pDocument;
}
#endif //_DEBUG


// C비모드형대화상자View 메시지 처리기


void C비모드형대화상자View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	if (m_pDlg != NULL)
		m_pDlg->SetFocus();
	else{
		m_pDlg = new CMyDialog();
		m_pDlg->m_pView = this;
		m_pDlg->m_str = m_str;
		m_pDlg->m_color = m_color;
		m_pDlg->Create(IDD_MYDIALOG);
		m_pDlg->ShowWindow(SW_SHOW);
	}

	CView::OnLButtonDblClk(nFlags, point);
}
