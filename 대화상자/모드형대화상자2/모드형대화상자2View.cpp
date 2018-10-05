
// �������ȭ����2View.cpp : C�������ȭ����2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "�������ȭ����2.h"
#endif

#include "�������ȭ����2Doc.h"
#include "�������ȭ����2View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�������ȭ����2View

IMPLEMENT_DYNCREATE(C�������ȭ����2View, CView)

BEGIN_MESSAGE_MAP(C�������ȭ����2View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C�������ȭ����2View ����/�Ҹ�

C�������ȭ����2View::C�������ȭ����2View()
	: m_str(_T(""))
	, m_color(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C�������ȭ����2View::~C�������ȭ����2View()
{
}

BOOL C�������ȭ����2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// C�������ȭ����2View �׸���

void C�������ȭ����2View::OnDraw(CDC* pDC)
{
	C�������ȭ����2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont font;
	font.CreatePointFont(300, L"Arial");
	pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(m_color, 0, 0));
	pDC->TextOut(10, 10, m_str);
}


// C�������ȭ����2View �μ�

BOOL C�������ȭ����2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void C�������ȭ����2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void C�������ȭ����2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// C�������ȭ����2View ����

#ifdef _DEBUG
void C�������ȭ����2View::AssertValid() const
{
	CView::AssertValid();
}

void C�������ȭ����2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�������ȭ����2Doc* C�������ȭ����2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�������ȭ����2Doc)));
	return (C�������ȭ����2Doc*)m_pDocument;
}
#endif //_DEBUG


// C�������ȭ����2View �޽��� ó����


void C�������ȭ����2View::OnLButtonDblClk(UINT nFlags, CPoint point)  // �� ���� ����Ŭ�� ��
{
	CMyDialog dlg;
	dlg.m_str = m_str;
	dlg.m_color = m_color;

	int result = dlg.DoModal();
	if (result == IDOK){
		m_str = dlg.m_str;
		m_color = dlg.m_color;
		Invalidate();
	}
	else if (result == 100){  // ���̾�α�(IDD_DIALOG1) ����� ��ư ���� �� 
		m_str = "";
		m_color = 0;
		Invalidate();
	}

	CView::OnLButtonDblClk(nFlags, point);
}
