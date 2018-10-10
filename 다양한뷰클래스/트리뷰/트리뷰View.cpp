
// 트리뷰View.cpp : C트리뷰View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "트리뷰.h"
#endif

#include "트리뷰Doc.h"
#include "트리뷰View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C트리뷰View

IMPLEMENT_DYNCREATE(C트리뷰View, CTreeView)

BEGIN_MESSAGE_MAP(C트리뷰View, CTreeView)
END_MESSAGE_MAP()

// C트리뷰View 생성/소멸

C트리뷰View::C트리뷰View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C트리뷰View::~C트리뷰View()
{
}

BOOL C트리뷰View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CTreeView::PreCreateWindow(cs);
}

void C트리뷰View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

}


// C트리뷰View 진단

#ifdef _DEBUG
void C트리뷰View::AssertValid() const
{
	CTreeView::AssertValid();
}

void C트리뷰View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

C트리뷰Doc* C트리뷰View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C트리뷰Doc)));
	return (C트리뷰Doc*)m_pDocument;
}
#endif //_DEBUG


// C트리뷰View 메시지 처리기
