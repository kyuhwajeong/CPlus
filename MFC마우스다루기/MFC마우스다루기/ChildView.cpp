
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "MFC���콺�ٷ��.h"
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
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Rectangle(100, 100, 300, 300);

	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	//// [ Page 207 ����
	//CClientDC dc(this);
	//dc.SetMapMode(MM_LOMETRIC);
	//CPoint pt = point;
	//dc.DPtoLP(&pt); // ��ġ�·Ḧ ����ǥ�� ��ȯ
	//dc.Rectangle(pt.x - 100, pt.y + 100, pt.x + 100, pt.y - 100);
	//// ] Page 207 ����

	SetCapture(); // Page 209 ���콺 ĸ�� �߰�
	m_bDrawMode = TRUE;
	m_ptStart = m_ptEnd = point;

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bDrawMode){
		CClientDC dc(this);
		// ������ �׸� ������ �����.
		dc.SetROP2(R2_NOT);
		dc.MoveTo(m_ptStart);
		dc.LineTo(m_ptEnd);

		// ���ο� ������ �׸���.
		dc.SetROP2(R2_NOT);
		dc.MoveTo(m_ptStart);
		dc.LineTo(point);

		m_ptEnd = point;

	}
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	// �������� ���� �׸���.
	dc.SetROP2(R2_COPYPEN);
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);

	// �׸��� ��带 �����Ѵ�.
	m_bDrawMode = FALSE;
	::ReleaseCapture();// Page 209 ���콺 ĸ�� �߰�
	CWnd::OnLButtonUp(nFlags, point);
}
