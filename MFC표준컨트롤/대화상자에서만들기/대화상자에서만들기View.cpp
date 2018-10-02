
// 대화상자에서만들기View.cpp : C대화상자에서만들기View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "대화상자에서만들기.h"
#endif

#include "대화상자에서만들기Doc.h"
#include "대화상자에서만들기View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C대화상자에서만들기View

IMPLEMENT_DYNCREATE(C대화상자에서만들기View, CFormView)

BEGIN_MESSAGE_MAP(C대화상자에서만들기View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &C대화상자에서만들기View::OnClickedButton1)
END_MESSAGE_MAP()

// C대화상자에서만들기View 생성/소멸

C대화상자에서만들기View::C대화상자에서만들기View()
	: CFormView(C대화상자에서만들기View::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C대화상자에서만들기View::~C대화상자에서만들기View()
{
}

void C대화상자에서만들기View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON1, m_pushbutton);
	DDX_Control(pDX, IDC_CHECK1, m_checkbox);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
}

BOOL C대화상자에서만들기View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void C대화상자에서만들기View::OnInitialUpdate() // 컨트롤을 초기화하는 코드를 추가(뷰가 화면에 보이기 전에 호출됨)
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_checkbox.SetCheck(BST_CHECKED);
	m_radio1.SetCheck(BST_CHECKED);
}


// C대화상자에서만들기View 진단

#ifdef _DEBUG
void C대화상자에서만들기View::AssertValid() const
{
	CFormView::AssertValid();
}

void C대화상자에서만들기View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C대화상자에서만들기Doc* C대화상자에서만들기View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C대화상자에서만들기Doc)));
	return (C대화상자에서만들기Doc*)m_pDocument;
}
#endif //_DEBUG


// C대화상자에서만들기View 메시지 처리기


void C대화상자에서만들기View::OnClickedButton1()
{
	BOOL bCheckBox, bRadio1, bRadio2;
	bCheckBox = bRadio1 = bRadio2 = FALSE;

	if (m_checkbox.GetCheck() == BST_CHECKED)
		bCheckBox = TRUE;
	if (m_radio1.GetCheck() == BST_CHECKED)
		bRadio1 = TRUE;
	if (m_radio2.GetCheck() == BST_CHECKED)
		bRadio2 = TRUE;

	CString str1, str2, str3;
	if (bCheckBox) str1 = "체크 박스가 체크되었습니다.";
	else str1 = "체크 박스가 체크되지 않았습니다.";

	if (bRadio1) str2 = "라디오 버튼1이 선택되었습니다.";
	else str2 = "라디오 버튼1이 선택되지 않았습니다.";

	if (bRadio2) str3 = "라디오 버튼2가 선택되었습니다.";
	else str3 = "라디오 버튼2가 선택되지 않았습니다.";

	MessageBox(str1 + '\n' + str2 + '\n' + str3);
}
