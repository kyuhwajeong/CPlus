
// 정적컨트롤View.cpp : C정적컨트롤View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "정적컨트롤.h"
#endif

#include "정적컨트롤Doc.h"
#include "정적컨트롤View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C정적컨트롤View

IMPLEMENT_DYNCREATE(C정적컨트롤View, CFormView)

BEGIN_MESSAGE_MAP(C정적컨트롤View, CFormView)
	ON_STN_CLICKED(IDC_ENHMETA, &C정적컨트롤View::OnClickedEnhmeta)
	ON_BN_CLICKED(IDC_BTNCLR, &C정적컨트롤View::OnBnClickedBtnclr)
	ON_BN_CLICKED(IDC_BTNCUT, &C정적컨트롤View::OnBnClickedBtncut)
	ON_BN_CLICKED(IDC_BTNPASTE, &C정적컨트롤View::OnBnClickedBtnpaste)
	ON_BN_CLICKED(IDC_BTNUNDO, &C정적컨트롤View::OnBnClickedBtnundo)
	ON_BN_CLICKED(IDC_BTNREPLACE, &C정적컨트롤View::OnBnClickedBtnreplace)
	ON_BN_CLICKED(IDC_BTNTXTDSP, &C정적컨트롤View::OnBnClickedBtntxtdsp)
	ON_BN_CLICKED(IDC_BTNREPLACE2, &C정적컨트롤View::OnBnClickedBtnreplace2)
	ON_EN_CHANGE(IDC_EDIT1, &C정적컨트롤View::OnChangeEdit1)
	ON_LBN_DBLCLK(IDC_LIST1, &C정적컨트롤View::OnDblclkList1)
	ON_LBN_SELCHANGE(IDC_LIST1, &C정적컨트롤View::OnSelchangeList1)
	ON_LBN_SELCANCEL(IDC_LIST1, &C정적컨트롤View::OnSelcancelList1)
	ON_LBN_SETFOCUS(IDC_LIST1, &C정적컨트롤View::OnSetfocusList1)
	ON_LBN_KILLFOCUS(IDC_LIST1, &C정적컨트롤View::OnKillfocusList1)
	ON_BN_CLICKED(IDC_BTNADD, &C정적컨트롤View::OnBnClickedBtnadd)
	ON_BN_CLICKED(IDC_BTNDEL, &C정적컨트롤View::OnBnClickedBtndel)
	ON_CBN_CLOSEUP(IDC_COMBO1, &C정적컨트롤View::OnCloseupCombo1)
	ON_CBN_DBLCLK(IDC_COMBO1, &C정적컨트롤View::OnDblclkCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO1, &C정적컨트롤View::OnDropdownCombo1)
	ON_CBN_EDITUPDATE(IDC_COMBO1, &C정적컨트롤View::OnEditupdateCombo1)
	ON_CBN_KILLFOCUS(IDC_COMBO1, &C정적컨트롤View::OnKillfocusCombo1)
	ON_CBN_SELENDCANCEL(IDC_COMBO1, &C정적컨트롤View::OnSelendcancelCombo1)
	ON_CBN_SELENDOK(IDC_COMBO1, &C정적컨트롤View::OnSelendokCombo1)
	ON_CBN_SETFOCUS(IDC_COMBO1, &C정적컨트롤View::OnSetfocusCombo1)
	ON_BN_CLICKED(IDC_BTNCOMBOADD, &C정적컨트롤View::OnBnClickedBtncomboadd)
	ON_BN_CLICKED(IDC_BTNCOMBODEL, &C정적컨트롤View::OnBnClickedBtncombodel)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

// C정적컨트롤View 생성/소멸

C정적컨트롤View::C정적컨트롤View()
	: CFormView(C정적컨트롤View::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C정적컨트롤View::~C정적컨트롤View()
{
}

void C정적컨트롤View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ENHMETA, m_enhmeta);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_scrollbar1);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_scrollbar2);
}

BOOL C정적컨트롤View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void C정적컨트롤View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_enhmeta.SetEnhMetaFile(::GetEnhMetaFile(L"Example.emf"));

	// 텍스트를 변경
	m_edit.SetWindowTextW(L"초기값입니다.");


	// 입력 가능한 문자열의 길이를 제한하기
	//m_edit.SetLimitText(20);

	m_list.AddString(L"딸기");
	m_list.AddString(L"바나나");
	m_list.AddString(L"사과");
	m_list.AddString(L"수박");
	m_list.AddString(L"참외");
	m_list.AddString(L"포도");

	m_list.SetSel(3);// 4번째 항목 선택(다중 선택 리스트 박스 컨트롤인 경우)

	//m_list.SetCurSel(3);// 단일 선택 리스트 박스 컨트롤인 경우

	m_combo.SetCurSel(0);

	m_scrollbar1.SetScrollRange(0, 360, FALSE);
	m_scrollbar1.SetScrollPos(0);
	m_scrollbar2.SetScrollRange(0, 360, FALSE);
	m_scrollbar2.SetScrollPos(0);

}


// C정적컨트롤View 진단

#ifdef _DEBUG
void C정적컨트롤View::AssertValid() const
{
	CFormView::AssertValid();
}

void C정적컨트롤View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C정적컨트롤Doc* C정적컨트롤View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C정적컨트롤Doc)));
	return (C정적컨트롤Doc*)m_pDocument;
}
#endif //_DEBUG


// C정적컨트롤View 메시지 처리기


void C정적컨트롤View::OnClickedEnhmeta()
{
	MessageBox(L"메타파일로 그린 그림을 클릭했습니다.");
}


void C정적컨트롤View::OnBnClickedBtnclr()// 현재 선택된 문자열을 삭제한다.
{
	m_edit.Clear();
}


void C정적컨트롤View::OnBnClickedBtncut()// 클립보드에 저장한다. 
{
	m_edit.Cut();
}


void C정적컨트롤View::OnBnClickedBtnpaste()// 클립보드에 저장된 내용을 붙여넣는다.
{
	m_edit.Paste();
}


void C정적컨트롤View::OnBnClickedBtnundo() // 이전으로 되돌리기
{
	m_edit.Undo();
}


void C정적컨트롤View::OnBnClickedBtnreplace()  // 시작과 끝지점의 내용을 치환한다.
{
	m_edit.SetSel(5, 7);
	m_edit.ReplaceSel(L"ABC");
}


void C정적컨트롤View::OnBnClickedBtntxtdsp()  // 표시된 텍스트의 내용을 메시지 표시
{
	// 입력된 텍스트를 알아내기
	CString str;
	//m_edit.GetWindowTextW(str);
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(str);

	MessageBox(str);
}


void C정적컨트롤View::OnBnClickedBtnreplace2()
{
	int len = m_edit.GetWindowTextLengthW();
	m_edit.SetSel(len, len);
	m_edit.ReplaceSel(L"새로 추가한 문자열입니다.");
}


void C정적컨트롤View::OnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	TRACE(L"OnChangeEdit1(내용을 변경하면 화면에 컨트롤이 다시 그려지는데 그 후에 메시지 발생");
}


void C정적컨트롤View::OnDblclkList1()
{
	TRACE(L"\n사용자가 항목을 더블 클릭");

	// 선택한 항목 알아내기(단일 선택 리스트 박스 컨트롤인 경우)
	//int nIndex = m_list.GetCurSel();

	// 선택한 항목 알아내기(다중 선택 리스트 박스 컨트롤인 경우)
	int nIndex = m_list.GetCaretIndex();
	if (nIndex != LB_ERR){
		CString str;
		m_list.GetText(nIndex, str);

		MessageBox(str);
	}
}


void C정적컨트롤View::OnSelchangeList1()
{
	TRACE(L"\n사용자가 선택을 변경했다.");
	int nIndex = m_list.GetCaretIndex();
	if (nIndex != LB_ERR){
		CString str;
		m_list.GetText(nIndex, str);
		GetDlgItem(IDC_EDIT2)->SetWindowTextW(str);
	}
}


void C정적컨트롤View::OnSelcancelList1()
{
	TRACE(L"\n사용자가 선택을 취소했다.");
}


void C정적컨트롤View::OnSetfocusList1()
{
	TRACE(L"\n키보드 포커스를 얻었다.");
}


void C정적컨트롤View::OnKillfocusList1()
{
	TRACE(L"\n키보드 포커스를 잃었다.");
}


void C정적컨트롤View::OnBnClickedBtnadd()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(str);
	m_list.AddString(str);
}


void C정적컨트롤View::OnBnClickedBtndel()
{
	int nIndex = m_list.GetCaretIndex();
	if (nIndex != LB_ERR){
		m_list.DeleteString(nIndex);
	}
}


void C정적컨트롤View::OnCloseupCombo1()
{
	TRACE(L"\n리스트 박스가 닫혔다.");
}


void C정적컨트롤View::OnDblclkCombo1()
{
	TRACE(L"\n사용자가 항목을 더블 클릭했다."); 
}


void C정적컨트롤View::OnDropdownCombo1()
{
	TRACE(L"\n리스트 박스가 열리기 직전이다.");
}


void C정적컨트롤View::OnEditupdateCombo1()
{
	TRACE(L"\nEN_EDITUPDATE.");
}


void C정적컨트롤View::OnKillfocusCombo1()
{
	TRACE(L"\n키보드 포커스를 잃었다.");
}


void C정적컨트롤View::OnSelendcancelCombo1()
{
	TRACE(L"\nLBN_SELENDCANCEL");
}


void C정적컨트롤View::OnSelendokCombo1()
{
	TRACE(L"\n사용자가 항목을 선택했다.");
	int nIndex = m_combo.GetCurSel();
	if (nIndex != LB_ERR){
		CString str;
		m_combo.GetLBText(nIndex, str);

		MessageBox(str);
	}
}


void C정적컨트롤View::OnSetfocusCombo1()
{
	TRACE(L"\n키보드 포커스를 얻었다.");
}


void C정적컨트롤View::OnBnClickedBtncomboadd()
{
	CString str;
	GetDlgItem(IDC_EDIT3)->GetWindowTextW(str);
	m_combo.AddString(str);
}


void C정적컨트롤View::OnBnClickedBtncombodel()
{
	int nIndex = m_combo.GetCurSel();
	if (nIndex != LB_ERR){
		m_combo.DeleteString(nIndex);
	}
}



void C정적컨트롤View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int nScrollPos;

	if (pScrollBar->GetSafeHwnd() == m_scrollbar1.GetSafeHwnd()){
		switch (nSBCode){
		case SB_LINELEFT:
			nScrollPos = pScrollBar->GetScrollPos();
			if (nScrollPos > 0){
				pScrollBar->SetScrollPos(--nScrollPos);
				SetDlgItemInt(IDC_EDIT4, nScrollPos);
				Invalidate();
			}
			break;
		case SB_THUMBTRACK:
			pScrollBar->SetScrollPos(nPos);
			SetDlgItemInt(IDC_EDIT4, nPos);
			Invalidate();
			break;
		}
	}
	else if (pScrollBar->GetSafeHwnd() == m_scrollbar2.GetSafeHwnd()){
		switch (nSBCode){
		case SB_THUMBTRACK:
			pScrollBar->SetScrollPos(nPos);
			SetDlgItemInt(IDC_EDIT5, nPos);
			Invalidate();
			break;
		}
	}

	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}


void C정적컨트롤View::OnDraw(CDC* pDC)
{
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 300;
	lf.lfEscapement = 10 * m_scrollbar1.GetScrollPos();
	lf.lfOrientation = 10 * m_scrollbar1.GetScrollPos();
	::lstrcpy(lf.lfFaceName, L"Arial");
	CFont font;
	font.CreatePointFontIndirect(&lf);
	pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(m_scrollbar2.GetScrollPos(), 0, 0));
	pDC->TextOut(700, 180, L"MFC");
}
