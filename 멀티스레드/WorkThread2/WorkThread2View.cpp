
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
	ON_WM_LBUTTONDBLCLK()
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
UINT MyDraw(LPVOID arg)
{
	ThreadArg *pArg = (ThreadArg *)arg;

	// CDC ��ü�� �����ϰ� ����̽� ���ؽ�Ʈ �ڵ�� �����Ų��.
	CDC dc;
	HDC hdc = ::GetDC(pArg->hwnd);
	dc.Attach(hdc);

	int i, x, y;
	CBrush brush1(RGB(255, 0, 0));
	CBrush brush2(RGB(0, 0, 255));
	
	// ȭ�鿡 ���� �ӵ��� ���븦 ����Ѵ�.
	switch (pArg->type){
	case 1:
		dc.SelectObject(&brush1);
		x = 100;
		y = 100;
		for (i = 0; i<100000; i++){
			int inc = i / 200;
			dc.Rectangle(x, y, x + inc, y + 20);
		}
		break;
	case 2:
		dc.SelectObject(&brush2);
		x = 100;
		y = 200;
		for (i = 0; i<100000; i++){
			int inc = i / 200;
			dc.Rectangle(x, y, x + inc, y + 20);
		}
		break;
	}

	dc.Detach();
	::ReleaseDC(pArg->hwnd, hdc);

	return 0;
}

void CWorkThread2View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// ȭ���� �����.
	CClientDC dc(this);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	CRect rect;
	GetClientRect(&rect);
	dc.Rectangle(&rect);

	//ù��° ������ ����(���� ����)
	arg1.hwnd = this->m_hWnd;
	arg1.type = 1;
	pThread1 = AfxBeginThread(MyDraw, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	//�ι�° ������ ����(���� ����)
	arg2.hwnd = this->m_hWnd;
	arg2.type = 2;
	pThread2 = AfxBeginThread(MyDraw, &arg2, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	// ������ �켱���� ���� ����
	pThread2->SetThreadPriority(THREAD_PRIORITY_ABOVE_NORMAL);

	// �� �����带 �����Ѵ�.
	pThread1->ResumeThread();
	pThread2->ResumeThread();

	CView::OnLButtonDblClk(nFlags, point);
}
