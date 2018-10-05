// MyDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "모드형대화상자2.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// CMyDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDialog::IDD, pParent)
	, m_str(_T(""))
	, m_color(0)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDC_BTNCLRSCR, &CMyDialog::OnClickedBtnclrscr)
END_MESSAGE_MAP()


// CMyDialog 메시지 처리기입니다.


void CMyDialog::OnClickedBtnclrscr()
{
	EndDialog(100); // 호출한 뷰클래스에서 100 인자를 확인해서 지우기 처리
}


BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetDlgItemText(IDC_STR, m_str);
	SetDlgItemInt(IDC_COLOR, m_color);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CMyDialog::OnOK()
{
	GetDlgItemText(IDC_STR, m_str);
	m_color = GetDlgItemInt(IDC_COLOR);

	CDialog::OnOK();
}

// DDX(Dialog Data Exchange)
// DDX의 핵심함수는 CWnd::UpdateData()이며 CDialog::OnInitDialog(), CDialog::OnOK()함수에서 자동으로 호출한다
// 단순히 DDX기능을 위한 것이라면 두 함수를 재정의할 필요 없다.


// C뷰어::OnLButtonDblClk -> CMyDialog::OnInitDialog -> CMyDialog::OnOK -> C뷰어::OnLButtonDblClk
