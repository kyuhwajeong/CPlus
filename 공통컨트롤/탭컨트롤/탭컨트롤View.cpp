
// 탭컨트롤View.cpp : C탭컨트롤View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "탭컨트롤.h"
#endif

#include "탭컨트롤Doc.h"
#include "탭컨트롤View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C탭컨트롤View

IMPLEMENT_DYNCREATE(C탭컨트롤View, CFormView)

BEGIN_MESSAGE_MAP(C탭컨트롤View, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &C탭컨트롤View::OnSelchangeTab1)
END_MESSAGE_MAP()

// C탭컨트롤View 생성/소멸

C탭컨트롤View::C탭컨트롤View()
	: CFormView(C탭컨트롤View::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C탭컨트롤View::~C탭컨트롤View()
{
}

void C탭컨트롤View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BOOL C탭컨트롤View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void C탭컨트롤View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	// 탭 컨트롤에 사용할 이미지 리스트를 설정한다
	CImageList m_il;
	m_il.Create(IDB_BITMAP1, 16, 1, RGB(255, 255, 255));
	m_tab.SetImageList(&m_il);
	m_il.Detach();

	// 세 개의 탭을 추가한다.
	m_tab.InsertItem(0, L"Tab #0", 0);
	m_tab.InsertItem(1, L"Tab #1", 0);
	m_tab.InsertItem(2, L"Tab #2", 0);

	// 두 번째 탭이 선택된 상태로 시작한다.
	m_tab.SetCurSel(1);
	m_edit.SetWindowTextW(L"1번째 탭을 선택했습니다.");

}


// C탭컨트롤View 진단

#ifdef _DEBUG
void C탭컨트롤View::AssertValid() const
{
	CFormView::AssertValid();
}

void C탭컨트롤View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C탭컨트롤Doc* C탭컨트롤View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C탭컨트롤Doc)));
	return (C탭컨트롤Doc*)m_pDocument;
}
#endif //_DEBUG


// C탭컨트롤View 메시지 처리기


void C탭컨트롤View::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int nIndex = m_tab.GetCurSel();
	CString str;
	str.Format(L"%d번째 탭을 선택했습니다.", nIndex);
	m_edit.SetWindowTextW(str);

	*pResult = 0;
}
