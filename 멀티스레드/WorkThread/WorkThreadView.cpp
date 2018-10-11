
// WorkThreadView.cpp : CWorkThreadView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "WorkThread.h"
#endif

#include "WorkThreadDoc.h"
#include "WorkThreadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWorkThreadView

IMPLEMENT_DYNCREATE(CWorkThreadView, CView)

BEGIN_MESSAGE_MAP(CWorkThreadView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CWorkThreadView ����/�Ҹ�

CWorkThreadView::CWorkThreadView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CWorkThreadView::~CWorkThreadView()
{
}

BOOL CWorkThreadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CWorkThreadView �׸���

void CWorkThreadView::OnDraw(CDC* /*pDC*/)
{
	CWorkThreadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CWorkThreadView �μ�

BOOL CWorkThreadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CWorkThreadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CWorkThreadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CWorkThreadView ����

#ifdef _DEBUG
void CWorkThreadView::AssertValid() const
{
	CView::AssertValid();
}

void CWorkThreadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWorkThreadDoc* CWorkThreadView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWorkThreadDoc)));
	return (CWorkThreadDoc*)m_pDocument;
}
#endif //_DEBUG


// CWorkThreadView �޽��� ó����

UINT CalcIt(LPVOID arg)
{
	int val = (int)arg;

	int result = 0;
	for (int i = 1; i < val; i++)
	{
		result += i;
		Sleep(10);  //��� �ӵ��� ������ �Ѵ�.
	}

	CString str;
	str.Format(L"��� ��� = %d", result);
	AfxMessageBox(str);

	return 0;
}

void CWorkThreadView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	int val = 600;

	// �����带 ����ϴ� ���
	AfxBeginThread(CalcIt,(LPVOID)val);

	CView::OnLButtonDblClk(nFlags, point);
}

