
// 고급컨트롤기법View.cpp : C고급컨트롤기법View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "고급컨트롤기법.h"
#endif

#include "고급컨트롤기법Doc.h"
#include "고급컨트롤기법View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C고급컨트롤기법View

IMPLEMENT_DYNCREATE(C고급컨트롤기법View, CFormView)

BEGIN_MESSAGE_MAP(C고급컨트롤기법View, CFormView)
END_MESSAGE_MAP()

// C고급컨트롤기법View 생성/소멸

C고급컨트롤기법View::C고급컨트롤기법View()
	: CFormView(C고급컨트롤기법View::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C고급컨트롤기법View::~C고급컨트롤기법View()
{
}

void C고급컨트롤기법View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
}

BOOL C고급컨트롤기법View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void C고급컨트롤기법View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_edit2.SubclassDlgItem(IDC_EDIT2, this);
}


// C고급컨트롤기법View 진단

#ifdef _DEBUG
void C고급컨트롤기법View::AssertValid() const
{
	CFormView::AssertValid();
}

void C고급컨트롤기법View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C고급컨트롤기법Doc* C고급컨트롤기법View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C고급컨트롤기법Doc)));
	return (C고급컨트롤기법Doc*)m_pDocument;
}
#endif //_DEBUG


// C고급컨트롤기법View 메시지 처리기
