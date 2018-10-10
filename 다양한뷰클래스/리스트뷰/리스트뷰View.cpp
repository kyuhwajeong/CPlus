
// ����Ʈ��View.cpp : C����Ʈ��View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "����Ʈ��.h"
#endif

#include "����Ʈ��Doc.h"
#include "����Ʈ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����Ʈ��View

IMPLEMENT_DYNCREATE(C����Ʈ��View, CListView)

BEGIN_MESSAGE_MAP(C����Ʈ��View, CListView)
	ON_COMMAND(ID_ICONVIEW, &C����Ʈ��View::OnIconview)
	ON_COMMAND(ID_SMALLICONVIEW, &C����Ʈ��View::OnSmalliconview)
	ON_COMMAND(ID_LISTVIEW, &C����Ʈ��View::OnListview)
	ON_COMMAND(ID_REPORTVIEW, &C����Ʈ��View::OnReportview)
END_MESSAGE_MAP()

// C����Ʈ��View ����/�Ҹ�

C����Ʈ��View::C����Ʈ��View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C����Ʈ��View::~C����Ʈ��View()
{
}

BOOL C����Ʈ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style &= ~LVS_TYPEMASK;	// �� ���� ���� ��Ÿ���� ��� ����
	cs.style |= LVS_REPORT;		// ���� ���� ��Ÿ���� ����

	return CListView::PreCreateWindow(cs);
}

void C����Ʈ��View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// �̹��� ����Ʈ ����
	CImageList ilLarge, ilSmall;
	ilLarge.Create(32, 32, ILC_COLOR4, 1, 1);
	ilSmall.Create(16, 16, ILC_COLOR4, 1, 1);
	ilLarge.Add(AfxGetApp()->LoadIconW(IDI_MYITEM));
	ilSmall.Add(AfxGetApp()->LoadIconW(IDI_MYITEM));

	// �̹��� ����Ʈ ����
	CListCtrl& list = GetListCtrl();
	list.SetImageList(&ilLarge, LVSIL_NORMAL);
	list.SetImageList(&ilSmall, LVSIL_SMALL);
	ilLarge.Detach();
	ilSmall.Detach();

	// ��� �ʱ�ȭ
	list.InsertColumn(0, L"��ǰ��", LVCFMT_LEFT, 100, 0);
	list.InsertColumn(1, L"����", LVCFMT_LEFT, 100, 2);
	list.InsertColumn(2, L"����", LVCFMT_LEFT, 100, 1);


	C����Ʈ��Doc *pDoc = GetDocument();
	CString str;
	for (int i = 0; i < NUMITEM; i++)
	{
		// �׸� �߰�
		list.InsertItem(i, pDoc->m_item[i].name, 0);
		// ���� �׸� �߰�
		str.Format(L"%d", pDoc->m_item[i].price);
		list.SetItemText(i, 1, str);
		str.Format(L"%d", pDoc->m_item[i].quantity);
		list.SetItemText(i, 2, str);
	}
}


// C����Ʈ��View ����

#ifdef _DEBUG
void C����Ʈ��View::AssertValid() const
{
	CListView::AssertValid();
}

void C����Ʈ��View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

C����Ʈ��Doc* C����Ʈ��View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����Ʈ��Doc)));
	return (C����Ʈ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C����Ʈ��View �޽��� ó����


void C����Ʈ��View::OnIconview()
{
	ModifyStyle(LVS_TYPEMASK, LVS_ICON);
}


void C����Ʈ��View::OnSmalliconview()
{
	ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);
}


void C����Ʈ��View::OnListview()
{
	ModifyStyle(LVS_TYPEMASK, LVS_LIST);
}


void C����Ʈ��View::OnReportview()
{
	ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
}
