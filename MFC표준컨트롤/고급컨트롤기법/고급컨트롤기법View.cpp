
// �����Ʈ�ѱ��View.cpp : C�����Ʈ�ѱ��View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "�����Ʈ�ѱ��.h"
#endif

#include "�����Ʈ�ѱ��Doc.h"
#include "�����Ʈ�ѱ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����Ʈ�ѱ��View

IMPLEMENT_DYNCREATE(C�����Ʈ�ѱ��View, CFormView)

BEGIN_MESSAGE_MAP(C�����Ʈ�ѱ��View, CFormView)
END_MESSAGE_MAP()

// C�����Ʈ�ѱ��View ����/�Ҹ�

C�����Ʈ�ѱ��View::C�����Ʈ�ѱ��View()
	: CFormView(C�����Ʈ�ѱ��View::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C�����Ʈ�ѱ��View::~C�����Ʈ�ѱ��View()
{
}

void C�����Ʈ�ѱ��View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
}

BOOL C�����Ʈ�ѱ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void C�����Ʈ�ѱ��View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_edit2.SubclassDlgItem(IDC_EDIT2, this);
}


// C�����Ʈ�ѱ��View ����

#ifdef _DEBUG
void C�����Ʈ�ѱ��View::AssertValid() const
{
	CFormView::AssertValid();
}

void C�����Ʈ�ѱ��View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C�����Ʈ�ѱ��Doc* C�����Ʈ�ѱ��View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����Ʈ�ѱ��Doc)));
	return (C�����Ʈ�ѱ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C�����Ʈ�ѱ��View �޽��� ó����
