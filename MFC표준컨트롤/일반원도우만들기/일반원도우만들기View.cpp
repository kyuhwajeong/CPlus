
// �Ϲݿ����츸���View.cpp : C�Ϲݿ����츸���View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "�Ϲݿ����츸���.h"
#endif

#include "�Ϲݿ����츸���Doc.h"
#include "�Ϲݿ����츸���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�Ϲݿ����츸���View

IMPLEMENT_DYNCREATE(C�Ϲݿ����츸���View, CView)

BEGIN_MESSAGE_MAP(C�Ϲݿ����츸���View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C�Ϲݿ����츸���View ����/�Ҹ�

C�Ϲݿ����츸���View::C�Ϲݿ����츸���View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C�Ϲݿ����츸���View::~C�Ϲݿ����츸���View()
{
}

BOOL C�Ϲݿ����츸���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// C�Ϲݿ����츸���View �׸���

void C�Ϲݿ����츸���View::OnDraw(CDC* /*pDC*/)
{
	C�Ϲݿ����츸���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// C�Ϲݿ����츸���View �μ�

BOOL C�Ϲݿ����츸���View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void C�Ϲݿ����츸���View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void C�Ϲݿ����츸���View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// C�Ϲݿ����츸���View ����

#ifdef _DEBUG
void C�Ϲݿ����츸���View::AssertValid() const
{
	CView::AssertValid();
}

void C�Ϲݿ����츸���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�Ϲݿ����츸���Doc* C�Ϲݿ����츸���View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�Ϲݿ����츸���Doc)));
	return (C�Ϲݿ����츸���Doc*)m_pDocument;
}
#endif //_DEBUG


// C�Ϲݿ����츸���View �޽��� ó����
