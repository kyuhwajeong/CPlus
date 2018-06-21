
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "MFC��������.h"
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
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
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

// WM_PAINT �޽����� 
// 1. �����츦 ������ �� 
// 2. �������� ũ�Ⱑ ����� �� 
// 3. �ּ�ȭ �Ǵ� �ִ�ȭ �Ǿ����� 
// 4. �ٸ� �����찡 ���ȴٰ� �巯����
void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�. // CPaintDC WM_PAINT ���� �ø� 
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//1
	//dc.TextOutW(100, 100, L"�ȳ��ϼ���.");

	//2
	//WCHAR *msg = L"Hello, MFC";
	//dc.TextOutW(100, 100, msg, lstrlen(msg));

	dc.Rectangle(0, 0, 200, 200);

	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}

// CPaintDC - Ŭ���̾�Ʈ ������ ����Ҷ�(WM_PAINT �޽��� �ڵ鷯������ ���)
// CClinetDC - Ŭ���̾�Ʈ ������ ����Ҷ�(WM_PAINT �޽��� �ڵ鷯 ������ �ٸ� ��� ������ ���)
// CWindowDC - ������ ��ü ����(Ŭ���̾�Ʈ ���� + ��Ŭ���̾�Ʈ ����)�� ���
// CMetaFileDC - ��Ÿ ���Ͽ� ����Ҷ�

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	////[ 3 ClientDC Ȯ�� ����
	//CClientDC dc(this);
	//dc.Ellipse(point.x - 30, point.y - 30, point
	//	.x + 30, point.y + 30);
	////] 3 

	//[ 4 MetaFileDC Ȯ�� ����
	::DeleteMetaFile(m_hmf);  // ������ ������ ��Ÿ������ �޸𸮿��� �����Ѵ�.
	CMetaFileDC dc;			  // ��Ÿ ���� ��ü�� ����
	dc.Create();			  // ��Ÿ ���� ����̽� ���ؽ�Ʈ�� �����.
	dc.Ellipse(point.x - 30, point.y - 30, point.x + 30, point.y + 30); // ��Ÿ���Ͽ� ���
	m_hmf = dc.Close();		  // ��Ÿ ���� �ڵ��� ������ �д�.
	//] 4
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	////[ 4 MetaFileDC Ȯ�� ����
	CClientDC dc(this);
	dc.PlayMetaFile(m_hmf);	// ��Ÿ ������ �����Ѵ�.
	////] 4

	CWnd::OnRButtonDown(nFlags, point);
}
