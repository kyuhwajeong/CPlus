// DrawView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "�������ҿ�����.h"
#include "DrawView.h"


// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

CDrawView::CDrawView()
{

}

CDrawView::~CDrawView()
{
}

BEGIN_MESSAGE_MAP(CDrawView, CView)
END_MESSAGE_MAP()


// CDrawView �׸����Դϴ�.

void CDrawView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CDrawView �����Դϴ�.

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDrawView �޽��� ó�����Դϴ�.
