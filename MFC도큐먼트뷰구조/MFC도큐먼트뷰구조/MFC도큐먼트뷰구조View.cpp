
// MFC��ť��Ʈ�䱸��View.cpp : CMFC��ť��Ʈ�䱸��View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFC��ť��Ʈ�䱸��.h"
#endif

#include "MFC��ť��Ʈ�䱸��Doc.h"
#include "MFC��ť��Ʈ�䱸��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC��ť��Ʈ�䱸��View

IMPLEMENT_DYNCREATE(CMFC��ť��Ʈ�䱸��View, CView)

BEGIN_MESSAGE_MAP(CMFC��ť��Ʈ�䱸��View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC��ť��Ʈ�䱸��View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC��ť��Ʈ�䱸��View ����/�Ҹ�

CMFC��ť��Ʈ�䱸��View::CMFC��ť��Ʈ�䱸��View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMFC��ť��Ʈ�䱸��View::~CMFC��ť��Ʈ�䱸��View()
{
}

BOOL CMFC��ť��Ʈ�䱸��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFC��ť��Ʈ�䱸��View �׸���

void CMFC��ť��Ʈ�䱸��View::OnDraw(CDC* /*pDC*/)
{
	CMFC��ť��Ʈ�䱸��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMFC��ť��Ʈ�䱸��View �μ�


void CMFC��ť��Ʈ�䱸��View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC��ť��Ʈ�䱸��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMFC��ť��Ʈ�䱸��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMFC��ť��Ʈ�䱸��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMFC��ť��Ʈ�䱸��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC��ť��Ʈ�䱸��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC��ť��Ʈ�䱸��View ����

#ifdef _DEBUG
void CMFC��ť��Ʈ�䱸��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC��ť��Ʈ�䱸��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC��ť��Ʈ�䱸��Doc* CMFC��ť��Ʈ�䱸��View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC��ť��Ʈ�䱸��Doc)));
	return (CMFC��ť��Ʈ�䱸��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC��ť��Ʈ�䱸��View �޽��� ó����
