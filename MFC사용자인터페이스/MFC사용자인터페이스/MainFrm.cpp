
// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "MFC������������̽�.h"

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
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_POS, &CMainFrame::OnUpdateIndicatorPos)	// ���¹� ����ϱ�
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_POS,		// ���¹� ����ϱ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// �������� Ŭ���̾�Ʈ ������ �����ϴ� �並 ����ϴ�.
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("�� â�� ������ ���߽��ϴ�.\n");
		return -1;
	}
	//[ ���¹� ����
	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
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

	//// [ Page 247 ���α׷� ������ �޴� �߰�
	//CMenu menuMain;
	//menuMain.CreateMenu();

	//CMenu menuPopup;
	//menuPopup.CreatePopupMenu();
	//menuPopup.AppendMenuW(MF_STRING, 201, L"����(&R)");
	//menuPopup.AppendMenuW(MF_STRING, 202, L"�ʷ�(&G)");
	//menuPopup.AppendMenuW(MF_STRING, 203, L"�ľ�(&B)");

	//menuMain.AppendMenuW(MF_POPUP, (UINT_PTR)menuPopup.Detach(), L"����(&C)");

	//SetMenu(&menuMain); // �޴��� �����쿡 ���� 
	//menuMain.Detach();  // �޴� ��ü�� �޴��� �и�
	//// ] Page 247 ���α׷� ������ �޴� �߰�

	////[ Page 249 ���α׷� ������ �޴� �߰� ����
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

	//CMenu *pTopLevel = GetMenu(); // �ֻ��� �޴��� �ּҸ� ��´�.
	//pTopLevel->AppendMenuW(MF_POPUP, (UINT_PTR)Popup2.Detach(), L"����(&X)");
	////] Page 249 ���α׷� ������ �޴� �߰� ����


	//[ Page 261 �ý��� �޴�
	// �ý��� �޴� ���� �� WM_SYSCOMMAND �޽����� �߻�
	CMenu *pSysMenu = GetSystemMenu(FALSE); // �ý��۸޴� ���� �� FALSE
	pSysMenu->AppendMenuW(MF_SEPARATOR);
	pSysMenu->AppendMenuW(MF_STRING, 16, L"�� ���α׷���...");
	//] Page 261 �ý��� �޴�

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame ����

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


// CMainFrame �޽��� ó����

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// �� â���� ��Ŀ���� �̵��մϴ�.
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// �信�� ù° ũ���� �ش� ��ɿ� ��Ÿ������ �մϴ�.
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// �׷��� ������ �⺻ ó���մϴ�.
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


//[ Page 261 �ý��� �޴�
void CMainFrame::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if ((nID & 0xFFF0) == 16){
		MessageBox(L"�ý��� �޴��� �����մϴ�.", L"dd");
		return;
	}
	CFrameWnd::OnSysCommand(nID, lParam);
}
//] Page 261 �ý��� �޴�


void CMainFrame::OnUpdateIndicatorPos(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(); 	//[ ���¹� ����ϱ�(���¹� ���� �ڵ鷯)
}
