
// �̹�������ƮView.cpp : C�̹�������ƮView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "�̹�������Ʈ.h"
#endif

#include "�̹�������ƮDoc.h"
#include "�̹�������ƮView.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�̹�������ƮView

IMPLEMENT_DYNCREATE(C�̹�������ƮView, CView)

BEGIN_MESSAGE_MAP(C�̹�������ƮView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// C�̹�������ƮView ����/�Ҹ�

C�̹�������ƮView::C�̹�������ƮView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C�̹�������ƮView::~C�̹�������ƮView()
{
}

BOOL C�̹�������ƮView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// C�̹�������ƮView �׸���

void C�̹�������ƮView::OnDraw(CDC* pDC)
{
	C�̹�������ƮDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// ����� ĥ�Ѵ�.
	CBrush brush(HS_DIAGCROSS, RGB(0, 255, 0));
	pDC->SelectObject(&brush);
	CRect rect;
	GetClientRect(&rect);
	pDC->Rectangle(&rect);

	// ����� ��������� �����Ѵ�.
	m_il.SetBkColor(CLR_NONE);
	m_il.Draw(pDC, 0, CPoint(100, 100), ILD_NORMAL);
	m_il.Draw(pDC, 0, CPoint(200, 100), ILD_TRANSPARENT);
	m_il.Draw(pDC, 0, CPoint(300, 100), ILD_BLEND25);
	m_il.Draw(pDC, 0, CPoint(400, 100), ILD_BLEND50);
	m_il.Draw(pDC, 0, CPoint(500, 100), ILD_MASK);

	// ����� ���������� �����Ѵ�
	m_il.SetBkColor(RGB(0,0,0));
	m_il.Draw(pDC, 1, CPoint(100, 200), ILD_NORMAL);
	m_il.Draw(pDC, 1, CPoint(200, 200), ILD_TRANSPARENT);
	m_il.Draw(pDC, 1, CPoint(300, 200), ILD_BLEND25);
	m_il.Draw(pDC, 1, CPoint(400, 200), ILD_BLEND50);
	m_il.Draw(pDC, 1, CPoint(500, 200), ILD_MASK);
}


// C�̹�������ƮView �μ�

BOOL C�̹�������ƮView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void C�̹�������ƮView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void C�̹�������ƮView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// C�̹�������ƮView ����

#ifdef _DEBUG
void C�̹�������ƮView::AssertValid() const
{
	CView::AssertValid();
}

void C�̹�������ƮView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�̹�������ƮDoc* C�̹�������ƮView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�̹�������ƮDoc)));
	return (C�̹�������ƮDoc*)m_pDocument;
}
#endif //_DEBUG


// C�̹�������ƮView �޽��� ó����


int C�̹�������ƮView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_il.Create(IDB_BITMAP1, 48, 1, RGB(255, 255, 255));

	return 0;
}
