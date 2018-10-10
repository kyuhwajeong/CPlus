
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

#include "Resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C트리뷰View

IMPLEMENT_DYNCREATE(C트리뷰View, CTreeView)

BEGIN_MESSAGE_MAP(C트리뷰View, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &C트리뷰View::OnTvnSelchanged)
//	ON_NOTIFY_REFLECT(TVN_DELETEITEM, &C트리뷰View::OnTvnDeleteitem)
ON_COMMAND(ID_TEST_DELETEITEM, &C트리뷰View::OnTestDeleteitem)
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
	cs.style |= TVS_HASBUTTONS;
	cs.style |= TVS_HASLINES;
	cs.style |= TVS_LINESATROOT;
	cs.style |= TVS_TRACKSELECT;

	return CTreeView::PreCreateWindow(cs);
}

void C트리뷰View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// 이미지 리스트 생성
	CImageList il;
	il.Create(IDB_BITMAP1, 16, 1, RGB(255, 255, 255));

	CTreeCtrl &tree = GetTreeCtrl();
	tree.SetImageList(&il, TVSIL_NORMAL);
	il.Detach();

	HTREEITEM hSun = tree.InsertItem(L"태양", 0, 0, TVI_ROOT, TVI_LAST);

	HTREEITEM hPlannet[9];
	CString planet[] = {
		L"수정", L"금성", L"지구", L"화성", L"목성", L"토성", L"천왕성", L"해왕성", L"명왕성"
	};
	for (int i = 0; i < 9; i++)
	{
		hPlannet[i] = tree.InsertItem(planet[i], 1, 1, hSun, TVI_LAST);
	}

	tree.InsertItem(L"달", 2, 2, hPlannet[2], TVI_LAST);
	tree.InsertItem(L"포보스", 2, 2, hPlannet[2], TVI_LAST);
	tree.InsertItem(L"데이모스", 2, 2, hPlannet[3], TVI_LAST);
	tree.InsertItem(L"이오", 2, 2, hPlannet[4], TVI_LAST);
	tree.InsertItem(L"에우로파", 2, 2, hPlannet[4], TVI_LAST);
	tree.InsertItem(L"가니메데", 2, 2, hPlannet[4], TVI_LAST);
	tree.InsertItem(L"갈리스토", 2, 2, hPlannet[4], TVI_LAST);
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


void C트리뷰View::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	TVITEM tvi = pNMTreeView->itemNew;
	CTreeCtrl& tree = GetTreeCtrl();
	CString str = tree.GetItemText(tvi.hItem);
	AfxGetMainWnd()->SetWindowTextW(str);

	*pResult = 0;
}


void C트리뷰View::OnTestDeleteitem()
{
	CTreeCtrl& tree = GetTreeCtrl();
	HTREEITEM hItem = tree.GetSelectedItem();
	if (hItem != NULL)
	{
		tree.DeleteItem(hItem);
	}
}
