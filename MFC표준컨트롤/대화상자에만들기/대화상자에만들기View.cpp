
// ��ȭ���ڿ������View.cpp : C��ȭ���ڿ������View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "��ȭ���ڿ������.h"
#endif

#include "��ȭ���ڿ������Doc.h"
#include "��ȭ���ڿ������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ȭ���ڿ������View

IMPLEMENT_DYNCREATE(C��ȭ���ڿ������View, CView)

BEGIN_MESSAGE_MAP(C��ȭ���ڿ������View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C��ȭ���ڿ������View ����/�Ҹ�

C��ȭ���ڿ������View::C��ȭ���ڿ������View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C��ȭ���ڿ������View::~C��ȭ���ڿ������View()
{
}

BOOL C��ȭ���ڿ������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// C��ȭ���ڿ������View �׸���

void C��ȭ���ڿ������View::OnDraw(CDC* /*pDC*/)
{
	C��ȭ���ڿ������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// C��ȭ���ڿ������View �μ�

BOOL C��ȭ���ڿ������View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void C��ȭ���ڿ������View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void C��ȭ���ڿ������View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// C��ȭ���ڿ������View ����

#ifdef _DEBUG
void C��ȭ���ڿ������View::AssertValid() const
{
	CView::AssertValid();
}

void C��ȭ���ڿ������View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ȭ���ڿ������Doc* C��ȭ���ڿ������View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ȭ���ڿ������Doc)));
	return (C��ȭ���ڿ������Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ȭ���ڿ������View �޽��� ó����
