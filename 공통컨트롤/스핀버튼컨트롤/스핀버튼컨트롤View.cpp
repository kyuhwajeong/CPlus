
// 스핀버튼컨트롤View.cpp : C스핀버튼컨트롤View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "스핀버튼컨트롤.h"
#endif

#include "스핀버튼컨트롤Doc.h"
#include "스핀버튼컨트롤View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C스핀버튼컨트롤View

IMPLEMENT_DYNCREATE(C스핀버튼컨트롤View, CFormView)

BEGIN_MESSAGE_MAP(C스핀버튼컨트롤View, CFormView)
END_MESSAGE_MAP()

// C스핀버튼컨트롤View 생성/소멸

C스핀버튼컨트롤View::C스핀버튼컨트롤View()
	: CFormView(C스핀버튼컨트롤View::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C스핀버튼컨트롤View::~C스핀버튼컨트롤View()
{
}

void C스핀버튼컨트롤View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, m_spin);
}

BOOL C스핀버튼컨트롤View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void C스핀버튼컨트롤View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_spin.SetRange(0, 100);
	m_spin.SetPos(0);
}


// C스핀버튼컨트롤View 진단

#ifdef _DEBUG
void C스핀버튼컨트롤View::AssertValid() const
{
	CFormView::AssertValid();
}

void C스핀버튼컨트롤View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C스핀버튼컨트롤Doc* C스핀버튼컨트롤View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C스핀버튼컨트롤Doc)));
	return (C스핀버튼컨트롤Doc*)m_pDocument;
}
#endif //_DEBUG


// C스핀버튼컨트롤View 메시지 처리기
