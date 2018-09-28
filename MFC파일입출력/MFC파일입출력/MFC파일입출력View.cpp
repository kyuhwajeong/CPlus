
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
	ON_WM_CHAR()
	ON_COMMAND(ID_COLOR_RED, &CMFC���������View::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CMFC���������View::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CMFC���������View::OnColorBlue)
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

void CMFC���������View::OnDraw(CDC* pDC)
{
	CMFC���������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CFont font;
	font.CreatePointFont(200, L"Arial");
	pDC->SelectObject(&font);
	pDC->SetTextColor(pDoc->m_color);
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(pDoc->m_str, &rect, DT_LEFT);
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

	int a = 200;
	int b = 200;
	CArchive ar(&file, CArchive::store);  // CArchive�� ����
	ar << a << b;
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
	CArchive ar(&file, CArchive::load);  // CArchive�� ����
	ar >> a >> b;

	TRACE("a = %d, b = %d", a, b);
}


void CMFC���������View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CMFC���������Doc* pDoc = GetDocument();
	int nCharIndex;
	nCharIndex = pDoc->m_str.GetLength();		// �Էµ� �������� ���̸� ��´�
	if (nChar == VK_BACK)
	{
		pDoc->m_str.Delete(nCharIndex - 1, 1);	// �ѹ��� �ϳ��� �����.
	}
	else{
		pDoc->m_str += (TCHAR)nChar;
	}
	pDoc->SetModifiedFlag();	// ��ť��Ʈ ��ü�� ������ �����Ǿ����� ��ť��Ʈ ��ü���� �˸���.
	Invalidate();				// CWnd::Invalidate()�Լ��� �̿��ؼ� WM_PRINT �޽����� �߻���Ų��.

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC���������View::OnColorRed()
{
	CMFC���������Doc* pDoc = GetDocument();
	pDoc->m_color = RGB(255, 0, 0);
	pDoc->SetModifiedFlag();
	Invalidate();
}


void CMFC���������View::OnColorGreen()
{
	CMFC���������Doc* pDoc = GetDocument();
	pDoc->m_color = RGB(0, 255, 0);
	pDoc->SetModifiedFlag();
	Invalidate();
}


void CMFC���������View::OnColorBlue()
{
	CMFC���������Doc* pDoc = GetDocument();
	pDoc->m_color = RGB(0, 0, 255);
	pDoc->SetModifiedFlag();
	Invalidate();
}
