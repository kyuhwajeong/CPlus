// DrawView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "정적분할원도우.h"
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


// CDrawView 그리기입니다.

void CDrawView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
}


// CDrawView 진단입니다.

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


// CDrawView 메시지 처리기입니다.
