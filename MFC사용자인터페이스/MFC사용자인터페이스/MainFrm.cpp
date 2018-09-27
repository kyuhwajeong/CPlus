
// MainFrm.cpp : CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "MFC사용자인터페이스.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_SYSCOMMAND()
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_POS, &CMainFrame::OnUpdateIndicatorPos)	// 상태바 사용하기
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_POS,		// 상태바 사용하기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 프레임의 클라이언트 영역을 차지하는 뷰를 만듭니다.
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("뷰 창을 만들지 못했습니다.\n");
		return -1;
	}
	//[ 상태바 생성
	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	//]

	//if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
	//	!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	//{
	//	TRACE("Failed to create toolbar\n");
	//	return -1;
	//}

	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);

	//// [ Page 247 프로그램 실행중 메뉴 추가
	//CMenu menuMain;
	//menuMain.CreateMenu();

	//CMenu menuPopup;
	//menuPopup.CreatePopupMenu();
	//menuPopup.AppendMenuW(MF_STRING, 201, L"빨강(&R)");
	//menuPopup.AppendMenuW(MF_STRING, 202, L"초록(&G)");
	//menuPopup.AppendMenuW(MF_STRING, 203, L"파알(&B)");

	//menuMain.AppendMenuW(MF_POPUP, (UINT_PTR)menuPopup.Detach(), L"색상(&C)");

	//SetMenu(&menuMain); // 메뉴를 원도우에 붙임 
	//menuMain.Detach();  // 메뉴 객체와 메뉴를 분리
	//// ] Page 247 프로그램 실행중 메뉴 추가

	////[ Page 249 프로그램 실행중 메뉴 추가 예제
	//CMenu Popup1;
	//Popup1.CreatePopupMenu();
	//Popup1.AppendMenuW(MF_STRING, 301, L"&1");
	//Popup1.AppendMenuW(MF_STRING, 302, L"&2");	
	//Popup1.AppendMenuW(MF_STRING, 303, L"&3");
	//Popup1.AppendMenuW(MF_STRING, 304, L"&4");

	//CMenu Popup2;
	//Popup2.CreatePopupMenu();
	//Popup2.AppendMenuW(MF_STRING | MF_CHECKED, 201, L"Item&1");
	//Popup2.AppendMenuW(MF_POPUP, (UINT_PTR)Popup1.Detach(), L"Item&2");
	//Popup2.AppendMenuW(MF_STRING, 203, L"Item&3");

	//CMenu *pTopLevel = GetMenu(); // 최상위 메뉴이 주소를 얻는다.
	//pTopLevel->AppendMenuW(MF_POPUP, (UINT_PTR)Popup2.Detach(), L"연습(&X)");
	////] Page 249 프로그램 실행중 메뉴 추가 예제


	//[ Page 261 시스템 메뉴
	// 시스템 메뉴 선택 시 WM_SYSCOMMAND 메시지가 발생
	CMenu *pSysMenu = GetSystemMenu(FALSE); // 시스템메뉴 변경 시 FALSE
	pSysMenu->AppendMenuW(MF_SEPARATOR);
	pSysMenu->AppendMenuW(MF_STRING, 16, L"이 프로그램은...");
	//] Page 261 시스템 메뉴

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// 뷰 창으로 포커스를 이동합니다.
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// 뷰에서 첫째 크랙이 해당 명령에 나타나도록 합니다.
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// 그렇지 않으면 기본 처리합니다.
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


//[ Page 261 시스템 메뉴
void CMainFrame::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if ((nID & 0xFFF0) == 16){
		MessageBox(L"시스템 메뉴를 연습합니다.", L"dd");
		return;
	}
	CFrameWnd::OnSysCommand(nID, lParam);
}
//] Page 261 시스템 메뉴


void CMainFrame::OnUpdateIndicatorPos(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(); 	//[ 상태바 사용하기(상태바 갱신 핸들러)
}
