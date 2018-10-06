
// ��������ȭ����View.cpp : C��������ȭ����View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "��������ȭ����.h"
#endif

#include "��������ȭ����Doc.h"
#include "��������ȭ����View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C��������ȭ����View

IMPLEMENT_DYNCREATE(C��������ȭ����View, CView)

BEGIN_MESSAGE_MAP(C��������ȭ����View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C��������ȭ����View ����/�Ҹ�

C��������ȭ����View::C��������ȭ����View()
	: m_str(_T(""))
	, m_color(0)
{
	m_pDlg = NULL;

}

C��������ȭ����View::~C��������ȭ����View()
{
}

BOOL C��������ȭ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// C��������ȭ����View �׸���

void C��������ȭ����View::OnDraw(CDC* pDC)
{
	C��������ȭ����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont font;
	font.CreatePointFont(300, L"Arial");
	pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(m_color, 0, 0));
	pDC->TextOut(10, 10, m_str);
}


// C��������ȭ����View �μ�

BOOL C��������ȭ����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void C��������ȭ����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void C��������ȭ����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// C��������ȭ����View ����

#ifdef _DEBUG
void C��������ȭ����View::AssertValid() const
{
	CView::AssertValid();
}

void C��������ȭ����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��������ȭ����Doc* C��������ȭ����View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��������ȭ����Doc)));
	return (C��������ȭ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C��������ȭ����View �޽��� ó����


void C��������ȭ����View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	if (m_pDlg != NULL)
		m_pDlg->SetFocus();
	else{
		m_pDlg = new CMyDialog();
		m_pDlg->m_pView = this;
		m_pDlg->m_str = m_str;
		m_pDlg->m_color = m_color;
		m_pDlg->Create(IDD_MYDIALOG);
		m_pDlg->ShowWindow(SW_SHOW);
	}

	CView::OnLButtonDblClk(nFlags, point);
}
