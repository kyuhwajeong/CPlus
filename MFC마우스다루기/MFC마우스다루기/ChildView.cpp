
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFC마우스다루기.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_bDrawMode = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Rectangle(100, 100, 300, 300);

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//// [ Page 207 예제
	//CClientDC dc(this);
	//dc.SetMapMode(MM_LOMETRIC);
	//CPoint pt = point;
	//dc.DPtoLP(&pt); // 장치좌료를 논리좌표로 변환
	//dc.Rectangle(pt.x - 100, pt.y + 100, pt.x + 100, pt.y - 100);
	//// ] Page 207 예제

	SetCapture(); // Page 209 마우스 캡쳐 추가
	m_bDrawMode = TRUE;
	m_ptStart = m_ptEnd = point;

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrawMode){
		CClientDC dc(this);
		// 이전에 그린 직석을 지운다.
		dc.SetROP2(R2_NOT);
		dc.MoveTo(m_ptStart);
		dc.LineTo(m_ptEnd);

		// 새로운 직선을 그린다.
		dc.SetROP2(R2_NOT);
		dc.MoveTo(m_ptStart);
		dc.LineTo(point);

		m_ptEnd = point;

	}
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	// 최종적인 선을 그린다.
	dc.SetROP2(R2_COPYPEN);
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);

	// 그리기 모드를 해제한다.
	m_bDrawMode = FALSE;
	::ReleaseCapture();// Page 209 마우스 캡쳐 추가
	CWnd::OnLButtonUp(nFlags, point);
}
