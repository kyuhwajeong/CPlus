
// ���ɹ�ư��Ʈ��View.cpp : C���ɹ�ư��Ʈ��View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "���ɹ�ư��Ʈ��.h"
#endif

#include "���ɹ�ư��Ʈ��Doc.h"
#include "���ɹ�ư��Ʈ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C���ɹ�ư��Ʈ��View

IMPLEMENT_DYNCREATE(C���ɹ�ư��Ʈ��View, CFormView)

BEGIN_MESSAGE_MAP(C���ɹ�ư��Ʈ��View, CFormView)
END_MESSAGE_MAP()

// C���ɹ�ư��Ʈ��View ����/�Ҹ�

C���ɹ�ư��Ʈ��View::C���ɹ�ư��Ʈ��View()
	: CFormView(C���ɹ�ư��Ʈ��View::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C���ɹ�ư��Ʈ��View::~C���ɹ�ư��Ʈ��View()
{
}

void C���ɹ�ư��Ʈ��View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, m_spin);
}

BOOL C���ɹ�ư��Ʈ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void C���ɹ�ư��Ʈ��View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_spin.SetRange(0, 100);
	m_spin.SetPos(0);
}


// C���ɹ�ư��Ʈ��View ����

#ifdef _DEBUG
void C���ɹ�ư��Ʈ��View::AssertValid() const
{
	CFormView::AssertValid();
}

void C���ɹ�ư��Ʈ��View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C���ɹ�ư��Ʈ��Doc* C���ɹ�ư��Ʈ��View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C���ɹ�ư��Ʈ��Doc)));
	return (C���ɹ�ư��Ʈ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C���ɹ�ư��Ʈ��View �޽��� ó����
