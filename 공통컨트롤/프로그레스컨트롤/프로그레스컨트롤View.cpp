
// ���α׷�����Ʈ��View.cpp : C���α׷�����Ʈ��View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "���α׷�����Ʈ��.h"
#endif

#include "���α׷�����Ʈ��Doc.h"
#include "���α׷�����Ʈ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C���α׷�����Ʈ��View

IMPLEMENT_DYNCREATE(C���α׷�����Ʈ��View, CFormView)

BEGIN_MESSAGE_MAP(C���α׷�����Ʈ��View, CFormView)
END_MESSAGE_MAP()

// C���α׷�����Ʈ��View ����/�Ҹ�

C���α׷�����Ʈ��View::C���α׷�����Ʈ��View()
	: CFormView(C���α׷�����Ʈ��View::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C���α׷�����Ʈ��View::~C���α׷�����Ʈ��View()
{
}

void C���α׷�����Ʈ��View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL C���α׷�����Ʈ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void C���α׷�����Ʈ��View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// C���α׷�����Ʈ��View ����

#ifdef _DEBUG
void C���α׷�����Ʈ��View::AssertValid() const
{
	CFormView::AssertValid();
}

void C���α׷�����Ʈ��View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C���α׷�����Ʈ��Doc* C���α׷�����Ʈ��View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C���α׷�����Ʈ��Doc)));
	return (C���α׷�����Ʈ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C���α׷�����Ʈ��View �޽��� ó����
