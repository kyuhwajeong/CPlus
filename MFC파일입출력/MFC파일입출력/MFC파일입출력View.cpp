
// MFC파일입출력View.cpp : CMFC파일입출력View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC파일입출력.h"
#endif

#include "MFC파일입출력Doc.h"
#include "MFC파일입출력View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC파일입출력View

IMPLEMENT_DYNCREATE(CMFC파일입출력View, CView)

BEGIN_MESSAGE_MAP(CMFC파일입출력View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_CHAR()
	ON_COMMAND(ID_COLOR_RED, &CMFC파일입출력View::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CMFC파일입출력View::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CMFC파일입출력View::OnColorBlue)
END_MESSAGE_MAP()

// CMFC파일입출력View 생성/소멸

CMFC파일입출력View::CMFC파일입출력View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFC파일입출력View::~CMFC파일입출력View()
{
}

BOOL CMFC파일입출력View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFC파일입출력View 그리기

void CMFC파일입출력View::OnDraw(CDC* pDC)
{
	CMFC파일입출력Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CFont font;
	font.CreatePointFont(200, L"Arial");
	pDC->SelectObject(&font);
#ifdef _NOT_SERIAL_CLS_
	pDC->SetTextColor(pDoc->m_color);
#else
	pDC->SetTextColor(pDoc->m_data.m_color);
#endif
	CRect rect;
	GetClientRect(&rect);
#ifdef _NOT_SERIAL_CLS_
	pDC->DrawText(pDoc->m_str, &rect, DT_LEFT);
#else
	pDC->DrawText(pDoc->m_data.m_str, &rect, DT_LEFT);
#endif
}


// CMFC파일입출력View 인쇄

BOOL CMFC파일입출력View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFC파일입출력View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFC파일입출력View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFC파일입출력View 진단

#ifdef _DEBUG
void CMFC파일입출력View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC파일입출력View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC파일입출력Doc* CMFC파일입출력View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC파일입출력Doc)));
	return (CMFC파일입출력Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC파일입출력View 메시지 처리기


void CMFC파일입출력View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CFile file;
	CFileException e;
	if (!file.Open(L"mytest.dat",
		CFile::modeReadWrite | CFile::modeCreate, &e))
	{
		e.ReportError();
		return;
	}

	int a = 200;
	int b = 200;
	CArchive ar(&file, CArchive::store);  // CArchive로 변경
	ar << a << b;
}


void CMFC파일입출력View::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	CFile file;
	CFileException e;
	if (!file.Open(L"mytest.dat", CFile::modeRead, &e))
	{
		e.ReportError();
		return;
	}

	int a, b;
	CArchive ar(&file, CArchive::load);  // CArchive로 변경
	ar >> a >> b;

	TRACE("a = %d, b = %d", a, b);
}


void CMFC파일입출력View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CMFC파일입출력Doc* pDoc = GetDocument();
	int nCharIndex;
#ifdef _NOT_SERIAL_CLS_
	nCharIndex = pDoc->m_str.GetLength();		// 입력된 데이터의 길이를 얻는다
#else
	nCharIndex = pDoc->m_data.m_str.GetLength();		// 입력된 데이터의 길이를 얻는다
#endif
	if (nChar == VK_BACK)
	{
#ifdef _NOT_SERIAL_CLS_
		pDoc->m_str.Delete(nCharIndex - 1, 1);	// 한번에 하나씩 지운다.
#else
		pDoc->m_data.m_str.Delete(nCharIndex - 1, 1);	// 한번에 하나씩 지운다.
#endif
	}
	else{
#ifdef _NOT_SERIAL_CLS_
		pDoc->m_str += (TCHAR)nChar;
#else
		pDoc->m_data.m_str += (TCHAR)nChar;
#endif
	}
	pDoc->SetModifiedFlag();	// 도큐먼트 객체의 내용이 수정되었음을 도큐먼트 객체에게 알린다.
	Invalidate();				// CWnd::Invalidate()함수를 이용해서 WM_PRINT 메시지를 발생시킨다.

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC파일입출력View::OnColorRed()
{
	CMFC파일입출력Doc* pDoc = GetDocument();
#ifdef _NOT_SERIAL_CLS_
	pDoc->m_color = RGB(255, 0, 0);
#else
	pDoc->m_data.m_color = RGB(255, 0, 0);
#endif
	pDoc->SetModifiedFlag();
	Invalidate();
}


void CMFC파일입출력View::OnColorGreen()
{
	CMFC파일입출력Doc* pDoc = GetDocument();
#ifdef _NOT_SERIAL_CLS_
	pDoc->m_color = RGB(0, 255, 0);
#else
	pDoc->m_data.m_color = RGB(0, 255, 0);
#endif
	pDoc->SetModifiedFlag();
	Invalidate();
}


void CMFC파일입출력View::OnColorBlue()
{
	CMFC파일입출력Doc* pDoc = GetDocument();
#ifdef _NOT_SERIAL_CLS_
	pDoc->m_color = RGB(0, 0, 255);
#else
	pDoc->m_data.m_color = RGB(0, 0, 255);
#endif
	pDoc->SetModifiedFlag();
	Invalidate();
}
