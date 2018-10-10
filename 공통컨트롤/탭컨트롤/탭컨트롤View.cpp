
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

IMPLEMENT_DYNCREATE(C����Ʈ��View, CFormView)

BEGIN_MESSAGE_MAP(C����Ʈ��View, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &C����Ʈ��View::OnSelchangeTab1)
END_MESSAGE_MAP()

// C����Ʈ��View ����/�Ҹ�

C����Ʈ��View::C����Ʈ��View()
	: CFormView(C����Ʈ��View::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C����Ʈ��View::~C����Ʈ��View()
{
}

void C����Ʈ��View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BOOL C����Ʈ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void C����Ʈ��View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	// �� ��Ʈ�ѿ� ����� �̹��� ����Ʈ�� �����Ѵ�
	CImageList m_il;
	m_il.Create(IDB_BITMAP1, 16, 1, RGB(255, 255, 255));
	m_tab.SetImageList(&m_il);
	m_il.Detach();

	// �� ���� ���� �߰��Ѵ�.
	m_tab.InsertItem(0, L"Tab #0", 0);
	m_tab.InsertItem(1, L"Tab #1", 0);
	m_tab.InsertItem(2, L"Tab #2", 0);

	// �� ��° ���� ���õ� ���·� �����Ѵ�.
	m_tab.SetCurSel(1);
	m_edit.SetWindowTextW(L"1��° ���� �����߽��ϴ�.");

}


// C����Ʈ��View ����

#ifdef _DEBUG
void C����Ʈ��View::AssertValid() const
{
	CFormView::AssertValid();
}

void C����Ʈ��View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C����Ʈ��Doc* C����Ʈ��View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����Ʈ��Doc)));
	return (C����Ʈ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C����Ʈ��View �޽��� ó����


void C����Ʈ��View::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int nIndex = m_tab.GetCurSel();
	CString str;
	str.Format(L"%d��° ���� �����߽��ϴ�.", nIndex);
	m_edit.SetWindowTextW(str);

	*pResult = 0;
}
