
// WorkThread2View.cpp : CWorkThread2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "WorkThread2.h"
#endif

#include "WorkThread2Doc.h"
#include "WorkThread2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWorkThread2View

IMPLEMENT_DYNCREATE(CWorkThread2View, CView)

BEGIN_MESSAGE_MAP(CWorkThread2View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CWorkThread2View ����/�Ҹ�

CWorkThread2View::CWorkThread2View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CWorkThread2View::~CWorkThread2View()
{
}

BOOL CWorkThread2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CWorkThread2View �׸���

void CWorkThread2View::OnDraw(CDC* /*pDC*/)
{
	CWorkThread2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CWorkThread2View �μ�

BOOL CWorkThread2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CWorkThread2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CWorkThread2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CWorkThread2View ����

#ifdef _DEBUG
void CWorkThread2View::AssertValid() const
{
	CView::AssertValid();
}

void CWorkThread2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWorkThread2Doc* CWorkThread2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWorkThread2Doc)));
	return (CWorkThread2Doc*)m_pDocument;
}
#endif //_DEBUG


// CWorkThread2View �޽��� ó����
