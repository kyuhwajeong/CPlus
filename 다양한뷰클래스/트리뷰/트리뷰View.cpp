
// Ʈ����View.cpp : CƮ����View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Ʈ����.h"
#endif

#include "Ʈ����Doc.h"
#include "Ʈ����View.h"

#include "Resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CƮ����View

IMPLEMENT_DYNCREATE(CƮ����View, CTreeView)

BEGIN_MESSAGE_MAP(CƮ����View, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CƮ����View::OnTvnSelchanged)
//	ON_NOTIFY_REFLECT(TVN_DELETEITEM, &CƮ����View::OnTvnDeleteitem)
ON_COMMAND(ID_TEST_DELETEITEM, &CƮ����View::OnTestDeleteitem)
END_MESSAGE_MAP()

// CƮ����View ����/�Ҹ�

CƮ����View::CƮ����View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CƮ����View::~CƮ����View()
{
}

BOOL CƮ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= TVS_HASBUTTONS;
	cs.style |= TVS_HASLINES;
	cs.style |= TVS_LINESATROOT;
	cs.style |= TVS_TRACKSELECT;

	return CTreeView::PreCreateWindow(cs);
}

void CƮ����View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// �̹��� ����Ʈ ����
	CImageList il;
	il.Create(IDB_BITMAP1, 16, 1, RGB(255, 255, 255));

	CTreeCtrl &tree = GetTreeCtrl();
	tree.SetImageList(&il, TVSIL_NORMAL);
	il.Detach();

	HTREEITEM hSun = tree.InsertItem(L"�¾�", 0, 0, TVI_ROOT, TVI_LAST);

	HTREEITEM hPlannet[9];
	CString planet[] = {
		L"����", L"�ݼ�", L"����", L"ȭ��", L"��", L"�伺", L"õ�ռ�", L"�ؿռ�", L"��ռ�"
	};
	for (int i = 0; i < 9; i++)
	{
		hPlannet[i] = tree.InsertItem(planet[i], 1, 1, hSun, TVI_LAST);
	}

	tree.InsertItem(L"��", 2, 2, hPlannet[2], TVI_LAST);
	tree.InsertItem(L"������", 2, 2, hPlannet[2], TVI_LAST);
	tree.InsertItem(L"���̸�", 2, 2, hPlannet[3], TVI_LAST);
	tree.InsertItem(L"�̿�", 2, 2, hPlannet[4], TVI_LAST);
	tree.InsertItem(L"�������", 2, 2, hPlannet[4], TVI_LAST);
	tree.InsertItem(L"���ϸ޵�", 2, 2, hPlannet[4], TVI_LAST);
	tree.InsertItem(L"��������", 2, 2, hPlannet[4], TVI_LAST);
}


// CƮ����View ����

#ifdef _DEBUG
void CƮ����View::AssertValid() const
{
	CTreeView::AssertValid();
}

void CƮ����View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CƮ����Doc* CƮ����View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CƮ����Doc)));
	return (CƮ����Doc*)m_pDocument;
}
#endif //_DEBUG


// CƮ����View �޽��� ó����


void CƮ����View::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	TVITEM tvi = pNMTreeView->itemNew;
	CTreeCtrl& tree = GetTreeCtrl();
	CString str = tree.GetItemText(tvi.hItem);
	AfxGetMainWnd()->SetWindowTextW(str);

	*pResult = 0;
}


void CƮ����View::OnTestDeleteitem()
{
	CTreeCtrl& tree = GetTreeCtrl();
	HTREEITEM hItem = tree.GetSelectedItem();
	if (hItem != NULL)
	{
		tree.DeleteItem(hItem);
	}
}
