
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CƮ����View

IMPLEMENT_DYNCREATE(CƮ����View, CTreeView)

BEGIN_MESSAGE_MAP(CƮ����View, CTreeView)
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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CTreeView::PreCreateWindow(cs);
}

void CƮ����View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

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
