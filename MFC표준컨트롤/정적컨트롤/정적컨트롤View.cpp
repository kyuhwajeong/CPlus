
// ������Ʈ��View.cpp : C������Ʈ��View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "������Ʈ��.h"
#endif

#include "������Ʈ��Doc.h"
#include "������Ʈ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������Ʈ��View

IMPLEMENT_DYNCREATE(C������Ʈ��View, CFormView)

BEGIN_MESSAGE_MAP(C������Ʈ��View, CFormView)
	ON_STN_CLICKED(IDC_ENHMETA, &C������Ʈ��View::OnClickedEnhmeta)
END_MESSAGE_MAP()

// C������Ʈ��View ����/�Ҹ�

C������Ʈ��View::C������Ʈ��View()
	: CFormView(C������Ʈ��View::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C������Ʈ��View::~C������Ʈ��View()
{
}

void C������Ʈ��View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ENHMETA, m_enhmeta);
}

BOOL C������Ʈ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void C������Ʈ��View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_enhmeta.SetEnhMetaFile(::GetEnhMetaFile(L"Example.emf"));
}


// C������Ʈ��View ����

#ifdef _DEBUG
void C������Ʈ��View::AssertValid() const
{
	CFormView::AssertValid();
}

void C������Ʈ��View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C������Ʈ��Doc* C������Ʈ��View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������Ʈ��Doc)));
	return (C������Ʈ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C������Ʈ��View �޽��� ó����


void C������Ʈ��View::OnClickedEnhmeta()
{
	MessageBox(L"��Ÿ���Ϸ� �׸� �׸��� Ŭ���߽��ϴ�.");
}
