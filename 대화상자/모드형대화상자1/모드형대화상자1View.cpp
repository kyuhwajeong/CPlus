
// �������ȭ����1View.cpp : C�������ȭ����1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "�������ȭ����1.h"
#endif

#include "�������ȭ����1Doc.h"
#include "�������ȭ����1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�������ȭ����1View

IMPLEMENT_DYNCREATE(C�������ȭ����1View, CView)

BEGIN_MESSAGE_MAP(C�������ȭ����1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C�������ȭ����1View ����/�Ҹ�

C�������ȭ����1View::C�������ȭ����1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C�������ȭ����1View::~C�������ȭ����1View()
{
}

BOOL C�������ȭ����1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// C�������ȭ����1View �׸���

void C�������ȭ����1View::OnDraw(CDC* /*pDC*/)
{
	C�������ȭ����1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// C�������ȭ����1View �μ�

BOOL C�������ȭ����1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void C�������ȭ����1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void C�������ȭ����1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// C�������ȭ����1View ����

#ifdef _DEBUG
void C�������ȭ����1View::AssertValid() const
{
	CView::AssertValid();
}

void C�������ȭ����1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�������ȭ����1Doc* C�������ȭ����1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�������ȭ����1Doc)));
	return (C�������ȭ����1Doc*)m_pDocument;
}
#endif //_DEBUG


// C�������ȭ����1View �޽��� ó����


void C�������ȭ����1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CDialog dlg(IDD_DIALOG1);
	if (dlg.DoModal() == IDOK)
		MessageBox(L"OK ��ư�� �������ϴ�.");
	else
		MessageBox(L"Cancel ��ư�� �������ϴ�.");

	CView::OnLButtonDblClk(nFlags, point);
}
