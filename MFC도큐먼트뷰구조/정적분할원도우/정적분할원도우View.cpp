
// �������ҿ�����View.cpp : C�������ҿ�����View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "�������ҿ�����.h"
#endif

#include "�������ҿ�����Doc.h"
#include "�������ҿ�����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�������ҿ�����View

IMPLEMENT_DYNCREATE(C�������ҿ�����View, CView)

BEGIN_MESSAGE_MAP(C�������ҿ�����View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C�������ҿ�����View ����/�Ҹ�

C�������ҿ�����View::C�������ҿ�����View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C�������ҿ�����View::~C�������ҿ�����View()
{
}

BOOL C�������ҿ�����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// C�������ҿ�����View �׸���

void C�������ҿ�����View::OnDraw(CDC* /*pDC*/)
{
	C�������ҿ�����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// C�������ҿ�����View �μ�

BOOL C�������ҿ�����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void C�������ҿ�����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void C�������ҿ�����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// C�������ҿ�����View ����

#ifdef _DEBUG
void C�������ҿ�����View::AssertValid() const
{
	CView::AssertValid();
}

void C�������ҿ�����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�������ҿ�����Doc* C�������ҿ�����View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�������ҿ�����Doc)));
	return (C�������ҿ�����Doc*)m_pDocument;
}
#endif //_DEBUG


// C�������ҿ�����View �޽��� ó����


void C�������ҿ�����View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20);

	CView::OnLButtonDblClk(nFlags, point);
}
