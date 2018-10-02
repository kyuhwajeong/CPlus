
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
	ON_WM_CREATE()
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


int C�Ϲݿ����츸���View::OnCreate(LPCREATESTRUCT lpCreateStruct) // Ŭ���� ������ - �޽���(��) - WM_CREATE ���� �� ����(�θ� �����찡 ������ �� ������)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pushbutton.Create(L"Ǫ�� ��ư",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(20, 20, 150, 50), this, 101);

	m_checkbox.Create(L"üũ �ڽ�",
		WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		CRect(20, 70, 150, 100), this, 102);

	m_radio1.Create(L"���� ��ư1",
		WS_CHILD | WS_VISIBLE | WS_GROUP|BS_AUTORADIOBUTTON,
		CRect(20, 140, 150, 170), this, 103);

	m_radio2.Create(L"���� ��ư2",
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(20, 180, 150, 210), this, 104);

	m_groupbox.Create(L"�׷� �ڽ�",
		WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		CRect(10, 110, 160, 220), this, 105);

	m_checkbox.SetCheck(BST_CHECKED);
	m_radio1.SetCheck(BST_CHECKED);

	return 0;
}
