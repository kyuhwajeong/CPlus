
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFC키보드다루기.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
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
	dc.SelectStockObject(GRAY_BRUSH);
	dc.Rectangle(m_xPos - 10, m_yPos - 10, m_xPos + 10, m_yPos + 10);

	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str, &rect, DT_LEFT);

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnSetFocus(CWnd* pOldWnd)
{
	CWnd::OnSetFocus(pOldWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//[ Page 225 예제
	CreateSolidCaret(20, 20);
	SetCaretPos(CPoint(50, 50));
	ShowCaret();
	//] Page 225 예제
}


void CChildView::OnKillFocus(CWnd* pNewWnd)
{
	CWnd::OnKillFocus(pNewWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//[ Page 225 예제
	HideCaret();
	::DestroyCaret();
	//] Page 225 예제

}


void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_xPos = cx / 2;
	m_yPos = cy / 2;
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar)
	{
	case VK_LEFT:
		m_xPos -= 10;
		break;
	case VK_RIGHT:
		m_xPos += 10;
		break;
	case VK_UP:
		m_yPos -= 10;
		break;
	case VK_DOWN:
		m_yPos += 10;
		break;
	case VK_RETURN:
		m_str += (TCHAR)nChar;
		break;
	}

	Invalidate();

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar >= 32)
	{
		m_str += (TCHAR)nChar;
		Invalidate();
	}

	CWnd::OnChar(nChar, nRepCnt, nFlags);
}
