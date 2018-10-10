
// ��ũ�Ѻ�View.cpp : C��ũ�Ѻ�View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "��ũ�Ѻ�.h"
#endif

#include "��ũ�Ѻ�Doc.h"
#include "��ũ�Ѻ�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ũ�Ѻ�View

IMPLEMENT_DYNCREATE(C��ũ�Ѻ�View, CScrollView)

BEGIN_MESSAGE_MAP(C��ũ�Ѻ�View, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// C��ũ�Ѻ�View ����/�Ҹ�

C��ũ�Ѻ�View::C��ũ�Ѻ�View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C��ũ�Ѻ�View::~C��ũ�Ѻ�View()
{
}

BOOL C��ũ�Ѻ�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// C��ũ�Ѻ�View �׸���

void C��ũ�Ѻ�View::OnDraw(CDC* pDC)
{
	C��ũ�Ѻ�Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect rect;
	pDC->GetClipBox(&rect);
	rect.InflateRect(100, 100, 100, 100);

	CString str;
	for (int x = 0; x < 4000; x += 100)
		for (int y = 0; y < 4000; y += 100){
			// ��ȿ ���� �簢���� ���Ե��� ������ ������� �ʴ´�.
			// ���� �� �ڵ带 �����ϸ� ��ũ�� �ӵ��� �ſ� ��������.
			if (!rect.PtInRect(CPoint(x, y))) continue;

			// ���� �ӵ��� �簢���� �׸���.
			MyDraw(pDC, x + 50, y + 50);

			// �簢�� �߽� ��ǥ�� ����Ѵ�.
			str.Format(L"(%d, %d)", x + 50, y + 50);
			pDC->SetBkColor(TRANSPARENT);
			pDC->DrawText(str, CRect(x, y, x + 100, y + 100), 
				DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
}

void C��ũ�Ѻ�View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// C��ũ�Ѻ�View �μ�

BOOL C��ũ�Ѻ�View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void C��ũ�Ѻ�View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void C��ũ�Ѻ�View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// C��ũ�Ѻ�View ����

#ifdef _DEBUG
void C��ũ�Ѻ�View::AssertValid() const
{
	CScrollView::AssertValid();
}

void C��ũ�Ѻ�View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

C��ũ�Ѻ�Doc* C��ũ�Ѻ�View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ũ�Ѻ�Doc)));
	return (C��ũ�Ѻ�Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ũ�Ѻ�View �޽��� ó����


void C��ũ�Ѻ�View::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	CSize sizeTotal(4000, 4000);
	CSize sizePage(cx - 50, cy - 50);
	CSize sizeLine(50, 50);
	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);
}


// x, y �߽����� �� ���� ���̰� 100�ȼ��� ���簢���� �׸���.
void C��ũ�Ѻ�View::MyDraw(CDC * pDC, int x, int y)
{
	CPen pen(PS_SOLID, 1, RGB(x % 256, y % 256, (x + y) % 128));
	pDC->SelectObject(&pen);
	pDC->SelectStockObject(NULL_BRUSH);
	for (int i = 50; i > 0; i--){
		// ���� �ڵ带 �� �� ���������ν� �ӵ��� ���� ���������� �Ѵ�.
		// ���� ��ǻ�͸� ����� ��� �� �� �� �߰��ؼ� �ǽ��� ����.
		pDC->Rectangle(x - i, y - i, x + i, y + i);
		pDC->Rectangle(x - i, y - i, x + i, y + i);
	}
}
