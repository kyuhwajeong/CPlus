
// 리스트뷰View.cpp : C리스트뷰View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "리스트뷰.h"
#endif

#include "리스트뷰Doc.h"
#include "리스트뷰View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C리스트뷰View

IMPLEMENT_DYNCREATE(C리스트뷰View, CListView)

BEGIN_MESSAGE_MAP(C리스트뷰View, CListView)
END_MESSAGE_MAP()

// C리스트뷰View 생성/소멸

C리스트뷰View::C리스트뷰View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C리스트뷰View::~C리스트뷰View()
{
}

BOOL C리스트뷰View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CListView::PreCreateWindow(cs);
}

void C리스트뷰View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: GetListCtrl()을 호출하여 해당 list 컨트롤을 직접 액세스함으로써
	//  ListView를 항목으로 채울 수 있습니다.
}


// C리스트뷰View 진단

#ifdef _DEBUG
void C리스트뷰View::AssertValid() const
{
	CListView::AssertValid();
}

void C리스트뷰View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

C리스트뷰Doc* C리스트뷰View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C리스트뷰Doc)));
	return (C리스트뷰Doc*)m_pDocument;
}
#endif //_DEBUG


// C리스트뷰View 메시지 처리기
