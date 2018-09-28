
// MFC���������View.cpp : CMFC���������View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFC���������.h"
#endif

#include "MFC���������Doc.h"
#include "MFC���������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC���������View

IMPLEMENT_DYNCREATE(CMFC���������View, CView)

BEGIN_MESSAGE_MAP(CMFC���������View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC���������View ����/�Ҹ�

CMFC���������View::CMFC���������View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMFC���������View::~CMFC���������View()
{
}

BOOL CMFC���������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFC���������View �׸���

void CMFC���������View::OnDraw(CDC* /*pDC*/)
{
	CMFC���������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMFC���������View �μ�

BOOL CMFC���������View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMFC���������View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMFC���������View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMFC���������View ����

#ifdef _DEBUG
void CMFC���������View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC���������View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC���������Doc* CMFC���������View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC���������Doc)));
	return (CMFC���������Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC���������View �޽��� ó����


void CMFC���������View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CFile file;
	CFileException e;
	if (!file.Open(L"mytest.dat",
		CFile::modeReadWrite | CFile::modeCreate, &e))
	{
		e.ReportError();
		return;
	}

	int a = 100;
	int b = 100;
	file.Write(&a, sizeof(a));
	file.Write(&b, sizeof(b));
}


void CMFC���������View::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	CFile file;
	CFileException e;
	if (!file.Open(L"mytest.dat", CFile::modeRead, &e))
	{
		e.ReportError();
		return;
	}

	int a, b;
	file.Read(&a, sizeof(a));
	file.Read(&b, sizeof(b));

	TRACE("a = %d, b = %d", a, b);
}
