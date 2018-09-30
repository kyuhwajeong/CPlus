
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
#ifdef _NOT_SERIAL_CLS_
	pDC->SetTextColor(pDoc->m_color);
#else
	pDC->SetTextColor(pDoc->m_data.m_color);
#endif
	CRect rect;
	GetClientRect(&rect);
#ifdef _NOT_SERIAL_CLS_
	pDC->DrawText(pDoc->m_str, &rect, DT_LEFT);
#else
	pDC->DrawText(pDoc->m_data.m_str, &rect, DT_LEFT);
#endif
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
#ifdef _NOT_SERIAL_CLS_
	nCharIndex = pDoc->m_str.GetLength();		// �Էµ� �������� ���̸� ��´�
#else
	nCharIndex = pDoc->m_data.m_str.GetLength();		// �Էµ� �������� ���̸� ��´�
#endif
	if (nChar == VK_BACK)
	{
#ifdef _NOT_SERIAL_CLS_
		pDoc->m_str.Delete(nCharIndex - 1, 1);	// �ѹ��� �ϳ��� �����.
#else
		pDoc->m_data.m_str.Delete(nCharIndex - 1, 1);	// �ѹ��� �ϳ��� �����.
#endif
	}
	else{
#ifdef _NOT_SERIAL_CLS_
		pDoc->m_str += (TCHAR)nChar;
#else
		pDoc->m_data.m_str += (TCHAR)nChar;
#endif
	}
	pDoc->SetModifiedFlag();	// ��ť��Ʈ ��ü�� ������ �����Ǿ����� ��ť��Ʈ ��ü���� �˸���.
	Invalidate();				// CWnd::Invalidate()�Լ��� �̿��ؼ� WM_PRINT �޽����� �߻���Ų��.

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC���������View::OnColorRed()
{
	CMFC���������Doc* pDoc = GetDocument();
#ifdef _NOT_SERIAL_CLS_
	pDoc->m_color = RGB(255, 0, 0);
#else
	pDoc->m_data.m_color = RGB(255, 0, 0);
#endif
	pDoc->SetModifiedFlag();
	Invalidate();
}


void CMFC���������View::OnColorGreen()
{
	CMFC���������Doc* pDoc = GetDocument();
#ifdef _NOT_SERIAL_CLS_
	pDoc->m_color = RGB(0, 255, 0);
#else
	pDoc->m_data.m_color = RGB(0, 255, 0);
#endif
	pDoc->SetModifiedFlag();
	Invalidate();
}


void CMFC���������View::OnColorBlue()
{
	CMFC���������Doc* pDoc = GetDocument();
#ifdef _NOT_SERIAL_CLS_
	pDoc->m_color = RGB(0, 0, 255);
#else
	pDoc->m_data.m_color = RGB(0, 0, 255);
#endif
	pDoc->SetModifiedFlag();
	Invalidate();
}
