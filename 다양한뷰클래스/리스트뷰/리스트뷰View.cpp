
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
	ON_COMMAND(ID_ICONVIEW, &C리스트뷰View::OnIconview)
	ON_COMMAND(ID_SMALLICONVIEW, &C리스트뷰View::OnSmalliconview)
	ON_COMMAND(ID_LISTVIEW, &C리스트뷰View::OnListview)
	ON_COMMAND(ID_REPORTVIEW, &C리스트뷰View::OnReportview)
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
	cs.style &= ~LVS_TYPEMASK;	// 네 가지 보기 스타일을 모두 제거
	cs.style |= LVS_REPORT;		// 보고서 보기 스타일을 설정

	return CListView::PreCreateWindow(cs);
}

void C리스트뷰View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// 이미지 리스트 생성
	CImageList ilLarge, ilSmall;
	ilLarge.Create(32, 32, ILC_COLOR4, 1, 1);
	ilSmall.Create(16, 16, ILC_COLOR4, 1, 1);
	ilLarge.Add(AfxGetApp()->LoadIconW(IDI_MYITEM));
	ilSmall.Add(AfxGetApp()->LoadIconW(IDI_MYITEM));

	// 이미지 리스트 설정
	CListCtrl& list = GetListCtrl();
	list.SetImageList(&ilLarge, LVSIL_NORMAL);
	list.SetImageList(&ilSmall, LVSIL_SMALL);
	ilLarge.Detach();
	ilSmall.Detach();

	// 헤더 초기화
	list.InsertColumn(0, L"상품명", LVCFMT_LEFT, 100, 0);
	list.InsertColumn(1, L"가격", LVCFMT_LEFT, 100, 2);
	list.InsertColumn(2, L"수량", LVCFMT_LEFT, 100, 1);


	C리스트뷰Doc *pDoc = GetDocument();
	CString str;
	for (int i = 0; i < NUMITEM; i++)
	{
		// 항목 추가
		list.InsertItem(i, pDoc->m_item[i].name, 0);
		// 하위 항목 추가
		str.Format(L"%d", pDoc->m_item[i].price);
		list.SetItemText(i, 1, str);
		str.Format(L"%d", pDoc->m_item[i].quantity);
		list.SetItemText(i, 2, str);
	}
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


void C리스트뷰View::OnIconview()
{
	ModifyStyle(LVS_TYPEMASK, LVS_ICON);
}


void C리스트뷰View::OnSmalliconview()
{
	ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);
}


void C리스트뷰View::OnListview()
{
	ModifyStyle(LVS_TYPEMASK, LVS_LIST);
}


void C리스트뷰View::OnReportview()
{
	ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
}
