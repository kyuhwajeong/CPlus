
// �����ȭ����View.cpp : C�����ȭ����View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "�����ȭ����.h"
#endif

#include "�����ȭ����Doc.h"
#include "�����ȭ����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static UINT WM_FINDREPLACE =
::RegisterWindowMessage(FINDMSGSTRING);

// C�����ȭ����View

IMPLEMENT_DYNCREATE(C�����ȭ����View, CView)

BEGIN_MESSAGE_MAP(C�����ȭ����View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FINDREPLACE, &C�����ȭ����View::OnFindreplace)
	ON_REGISTERED_MESSAGE(WM_FINDREPLACE, &C�����ȭ����View::OnFindReplaceCmd)
END_MESSAGE_MAP()

// C�����ȭ����View ����/�Ҹ�

C�����ȭ����View::C�����ȭ����View()
	: pFindReplaceDlg(NULL)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C�����ȭ����View::~C�����ȭ����View()
{
}

BOOL C�����ȭ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// C�����ȭ����View �׸���

void C�����ȭ����View::OnDraw(CDC* /*pDC*/)
{
	C�����ȭ����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// C�����ȭ����View �μ�

BOOL C�����ȭ����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void C�����ȭ����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void C�����ȭ����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// C�����ȭ����View ����

#ifdef _DEBUG
void C�����ȭ����View::AssertValid() const
{
	CView::AssertValid();
}

void C�����ȭ����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�����ȭ����Doc* C�����ȭ����View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����ȭ����Doc)));
	return (C�����ȭ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C�����ȭ����View �޽��� ó����


void C�����ȭ����View::OnFindreplace()
{
	if (pFindReplaceDlg != NULL)
		pFindReplaceDlg->SetFocus();
	else{
		pFindReplaceDlg = new CFindReplaceDialog();
		pFindReplaceDlg->Create(FALSE, L"", L"", FR_DOWN, this);
	}

}


HRESULT C�����ȭ����View::OnFindReplaceCmd(WPARAM wParam, LPARAM lParam)
{
	CString str;

	if (pFindReplaceDlg->IsTerminating()) // ��ȭ���� ����
	{
		pFindReplaceDlg = NULL;
		return 0;
	}
	else if (pFindReplaceDlg->FindNext())
	{
		str.Format(L"ã�� ���ڿ�: %s", pFindReplaceDlg->GetFindString());
		MessageBox(str);
	}
	else if (pFindReplaceDlg->ReplaceCurrent())
	{
		str.Format(L"ã�� ���ڿ�: %s\n\r�ٲ� ���ڿ�: %s", pFindReplaceDlg->GetFindString(), pFindReplaceDlg->GetReplaceString());
		MessageBox(str);
	}
	else if (pFindReplaceDlg->ReplaceAll())
	{
		str.Format(L"ã�� ���ڿ�: %s\n\r�ٲ� ���ڿ�: %s", pFindReplaceDlg->GetFindString(), pFindReplaceDlg->GetReplaceString());
		MessageBox(str);
	}

	return E_NOTIMPL;
}
