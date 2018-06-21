
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFC구조이해.h"
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

// WM_PAINT 메시지는 
// 1. 원도우를 생성될 때 
// 2. 원도우의 크기가 변경될 때 
// 3. 최소화 또는 최대화 되었을때 
// 4. 다른 원도우가 가렸다가 드러날때
void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다. // CPaintDC WM_PAINT 수신 시만 
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//1
	//dc.TextOutW(100, 100, L"안녕하세요.");

	//2
	//WCHAR *msg = L"Hello, MFC";
	//dc.TextOutW(100, 100, msg, lstrlen(msg));

	dc.Rectangle(0, 0, 200, 200);

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

// CPaintDC - 클라이언트 영역에 출력할때(WM_PAINT 메시지 핸들러에서만 사용)
// CClinetDC - 클라이언트 영역에 출력할때(WM_PAINT 메시지 핸들러 제외한 다른 모든 곳에서 사용)
// CWindowDC - 원도우 전체 영역(클라이언트 영역 + 비클라이언트 영역)에 출력
// CMetaFileDC - 메타 파일에 출력할때

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	////[ 3 ClientDC 확인 샘플
	//CClientDC dc(this);
	//dc.Ellipse(point.x - 30, point.y - 30, point
	//	.x + 30, point.y + 30);
	////] 3 

	//[ 4 MetaFileDC 확인 샘플
	::DeleteMetaFile(m_hmf);  // 이전에 생성된 메타파일을 메모리에서 제거한다.
	CMetaFileDC dc;			  // 메타 파일 객체를 생성
	dc.Create();			  // 메타 파일 디바이스 컨텍스트를 만든다.
	dc.Ellipse(point.x - 30, point.y - 30, point.x + 30, point.y + 30); // 메타파일에 출력
	m_hmf = dc.Close();		  // 메타 파일 핸들을 저장해 둔다.
	//] 4
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	////[ 4 MetaFileDC 확인 샘플
	CClientDC dc(this);
	dc.PlayMetaFile(m_hmf);	// 메타 파일을 실행한다.
	////] 4

	CWnd::OnRButtonDown(nFlags, point);
}
