
// HTML뷰View.cpp : CHTML뷰View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HTML뷰.h"
#endif

#include "HTML뷰Doc.h"
#include "HTML뷰View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHTML뷰View

IMPLEMENT_DYNCREATE(CHTML뷰View, CHtmlView)

BEGIN_MESSAGE_MAP(CHTML뷰View, CHtmlView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND(ID_INTERNET_OPEN, &CHTML뷰View::OnInternetOpen)
	ON_COMMAND(ID_INTERNET_BACK, &CHTML뷰View::OnInternetBack)
	ON_COMMAND(ID_INTERNET_FORWARD, &CHTML뷰View::OnInternetForward)
END_MESSAGE_MAP()

// CHTML뷰View 생성/소멸

CHTML뷰View::CHTML뷰View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CHTML뷰View::~CHTML뷰View()
{
}

BOOL CHTML뷰View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CHtmlView::PreCreateWindow(cs);
}

void CHTML뷰View::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();
	GoHome();
//	Navigate2(_T("http://www.msdn.microsoft.com/korea/visualc/"),NULL,NULL);
}


// CHTML뷰View 인쇄



// CHTML뷰View 진단

#ifdef _DEBUG
void CHTML뷰View::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CHTML뷰View::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CHTML뷰Doc* CHTML뷰View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHTML뷰Doc)));
	return (CHTML뷰Doc*)m_pDocument;
}
#endif //_DEBUG


// CHTML뷰View 메시지 처리기


void CHTML뷰View::OnInternetOpen()
{
	CMyDialog dlg;
	if (dlg.DoModal() == IDOK)
		Navigate2(dlg.m_url, NULL, NULL);
}


void CHTML뷰View::OnInternetBack()
{
	GoBack();
}


void CHTML뷰View::OnInternetForward()
{
	GoForward();
}
