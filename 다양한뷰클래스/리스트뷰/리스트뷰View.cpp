
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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CListView::PreCreateWindow(cs);
}

void C����Ʈ��View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: GetListCtrl()�� ȣ���Ͽ� �ش� list ��Ʈ���� ���� �׼��������ν�
	//  ListView�� �׸����� ä�� �� �ֽ��ϴ�.
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
