
// ��ȭ���ڿ��������View.cpp : C��ȭ���ڿ��������View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "��ȭ���ڿ��������.h"
#endif

#include "��ȭ���ڿ��������Doc.h"
#include "��ȭ���ڿ��������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ȭ���ڿ��������View

IMPLEMENT_DYNCREATE(C��ȭ���ڿ��������View, CFormView)

BEGIN_MESSAGE_MAP(C��ȭ���ڿ��������View, CFormView)
END_MESSAGE_MAP()

// C��ȭ���ڿ��������View ����/�Ҹ�

C��ȭ���ڿ��������View::C��ȭ���ڿ��������View()
	: CFormView(C��ȭ���ڿ��������View::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C��ȭ���ڿ��������View::~C��ȭ���ڿ��������View()
{
}

void C��ȭ���ڿ��������View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON1, m_pushbutton);
	DDX_Control(pDX, IDC_CHECK1, m_checkbox);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
}

BOOL C��ȭ���ڿ��������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void C��ȭ���ڿ��������View::OnInitialUpdate() // ��Ʈ���� �ʱ�ȭ�ϴ� �ڵ带 �߰�(�䰡 ȭ�鿡 ���̱� ���� ȣ���)
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_checkbox.SetCheck(BST_CHECKED);
	m_radio1.SetCheck(BST_CHECKED);
}


// C��ȭ���ڿ��������View ����

#ifdef _DEBUG
void C��ȭ���ڿ��������View::AssertValid() const
{
	CFormView::AssertValid();
}

void C��ȭ���ڿ��������View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C��ȭ���ڿ��������Doc* C��ȭ���ڿ��������View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ȭ���ڿ��������Doc)));
	return (C��ȭ���ڿ��������Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ȭ���ڿ��������View �޽��� ó����
