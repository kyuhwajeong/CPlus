
// HTML��View.cpp : CHTML��View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "HTML��.h"
#endif

#include "HTML��Doc.h"
#include "HTML��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHTML��View

IMPLEMENT_DYNCREATE(CHTML��View, CHtmlView)

BEGIN_MESSAGE_MAP(CHTML��View, CHtmlView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

// CHTML��View ����/�Ҹ�

CHTML��View::CHTML��View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CHTML��View::~CHTML��View()
{
}

BOOL CHTML��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CHtmlView::PreCreateWindow(cs);
}

void CHTML��View::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	//Navigate2(_T("http://www.msdn.microsoft.com/korea/visualc/"),NULL,NULL);;
}


// CHTML��View �μ�



// CHTML��View ����

#ifdef _DEBUG
void CHTML��View::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CHTML��View::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CHTML��Doc* CHTML��View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHTML��Doc)));
	return (CHTML��Doc*)m_pDocument;
}
#endif //_DEBUG


// CHTML��View �޽��� ó����
