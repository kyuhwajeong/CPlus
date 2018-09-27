
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFC사용자인터페이스.h"
#include "ChildView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_color = RGB(255, 0, 0);
}

CChildView::~CChildView()
{
}

#define WM_TRAY_NOTIFICATION WM_APP + 1

BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_COLOR_BLUE, &CChildView::OnColorBlue)
	ON_COMMAND(ID_COLOR_GREEN, &CChildView::OnColorGreen)
	ON_COMMAND(ID_COLOR_RED, &CChildView::OnColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CChildView::OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CChildView::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CChildView::OnUpdateColorRed)
	ON_WM_CONTEXTMENU()
	ON_MESSAGE(WM_TRAY_NOTIFICATION, &CChildView::OnTrayNotification)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_MOUSEMOVE()
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
	CRect rect;
	GetClientRect(&rect);
	dc.SelectStockObject(NULL_PEN);
	CBrush brush(m_color);
	dc.SelectObject(&brush);
	dc.Rectangle(&rect);

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnColorBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_color = RGB(0, 0, 255);
	Invalidate();
}


void CChildView::OnColorGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_color = RGB(0, 255, 0);
	Invalidate();
}


void CChildView::OnColorRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_color = RGB(255, 0, 0);
	Invalidate();
}


void CChildView::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_color == RGB(0, 0, 255));
}


void CChildView::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_color == RGB(0, 255, 0));
}


void CChildView::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_color == RGB(255, 0, 0));
}

// Page 259 컨텍스트 메뉴
// 클라이언트 영역 또는 비 클라이언트 영역에서 마우스 오른쪽 버튼을 클릭했을 경우
// Shift + F10 키 조합을 누른 경우
// 가상키 코드 VK_APPS에 해당되는 키를 누를 경우
void CChildView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CMenu menu;
	menu.LoadMenuW(IDR_MAINFRAME);
	CMenu *pMenu = menu.GetSubMenu(5);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
}


afx_msg LRESULT CChildView::OnTrayNotification(WPARAM wParam, LPARAM lParam)
{
	switch (lParam)
	{
	case WM_RBUTTONDOWN:
			{
				CPoint ptMouse;
				::GetCursorPos(&ptMouse);

				CMenu menu;
				menu.LoadMenuW(IDR_MAINFRAME);
				CMenu *pMenu = menu.GetSubMenu(5);
				pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, ptMouse.x, ptMouse.y, AfxGetMainWnd());
			}
			break;

	case WM_LBUTTONDBLCLK:
			{
				NOTIFYICONDATA nid;
				ZeroMemory(&nid, sizeof(nid));
				nid.cbSize = sizeof(nid);
				nid.uID = 0;
				nid.hWnd = GetSafeHwnd();
				BOOL bRet = ::Shell_NotifyIcon(NIM_DELETE, &nid); //트레이아이콘 제거
				if (!bRet)
				{
					AfxMessageBox(L"트레이 아이콘 제거 실패");
					return -1;
				}
				AfxGetApp()->m_pMainWnd->ShowWindow(SW_SHOW); //윈도우 활성화
			}

	}
	return 1;
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	NOTIFYICONDATA nid;
	ZeroMemory(&nid, sizeof(nid));
	nid.cbSize = sizeof(nid);
	nid.uID = 0;
	nid.hWnd = GetSafeHwnd();

	nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
	nid.hIcon = AfxGetApp()->LoadIconW(IDR_MAINFRAME);
	lstrcpy(nid.szTip, L"내 트레이");
	nid.uCallbackMessage = WM_TRAY_NOTIFICATION;

	BOOL bRet = ::Shell_NotifyIcon(NIM_ADD, &nid);

	return 0;
}


void CChildView::OnDestroy()
{
	CWnd::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	NOTIFYICONDATA nid;
	ZeroMemory(&nid, sizeof(nid));
	nid.cbSize = sizeof(nid);
	nid.uID = 0;
	nid.hWnd = GetSafeHwnd();
	BOOL bRet = ::Shell_NotifyIcon(NIM_DELETE, &nid);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	//[ 상태바 사용하기
	CString str;
	str.Format(L"마우스 좌표 (%4d,%4d)", point.x, point.y);
	CMainFrame *pMainFrame = (CMainFrame *)AfxGetMainWnd();
	pMainFrame->m_wndStatusBar.SetPaneText(1, str);
	//]

	CWnd::OnMouseMove(nFlags, point);
}
