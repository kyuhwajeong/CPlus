
// �̹�������ƮView.cpp : C�̹�������ƮView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "�̹�������Ʈ.h"
#endif

#include "�̹�������ƮDoc.h"
#include "�̹�������ƮView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�̹�������ƮView

IMPLEMENT_DYNCREATE(C�̹�������ƮView, CView)

BEGIN_MESSAGE_MAP(C�̹�������ƮView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C�̹�������ƮView ����/�Ҹ�

C�̹�������ƮView::C�̹�������ƮView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C�̹�������ƮView::~C�̹�������ƮView()
{
}

BOOL C�̹�������ƮView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// C�̹�������ƮView �׸���

void C�̹�������ƮView::OnDraw(CDC* /*pDC*/)
{
	C�̹�������ƮDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// C�̹�������ƮView �μ�

BOOL C�̹�������ƮView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void C�̹�������ƮView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void C�̹�������ƮView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// C�̹�������ƮView ����

#ifdef _DEBUG
void C�̹�������ƮView::AssertValid() const
{
	CView::AssertValid();
}

void C�̹�������ƮView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�̹�������ƮDoc* C�̹�������ƮView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�̹�������ƮDoc)));
	return (C�̹�������ƮDoc*)m_pDocument;
}
#endif //_DEBUG


// C�̹�������ƮView �޽��� ó����
