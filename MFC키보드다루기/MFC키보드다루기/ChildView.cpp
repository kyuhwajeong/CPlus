
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "MFCŰ����ٷ��.h"
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



// CChildView �޽��� ó����

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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	dc.SelectStockObject(GRAY_BRUSH);
	dc.Rectangle(m_xPos - 10, m_yPos - 10, m_xPos + 10, m_yPos + 10);

	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str, &rect, DT_LEFT);

	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnSetFocus(CWnd* pOldWnd)
{
	CWnd::OnSetFocus(pOldWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//[ Page 225 ����
	CreateSolidCaret(20, 20);
	SetCaretPos(CPoint(50, 50));
	ShowCaret();
	//] Page 225 ����
}


void CChildView::OnKillFocus(CWnd* pNewWnd)
{
	CWnd::OnKillFocus(pNewWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//[ Page 225 ����
	HideCaret();
	::DestroyCaret();
	//] Page 225 ����

}


void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	m_xPos = cx / 2;
	m_yPos = cy / 2;
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nChar >= 32)
	{
		m_str += (TCHAR)nChar;
		Invalidate();
	}

	CWnd::OnChar(nChar, nRepCnt, nFlags);
}
