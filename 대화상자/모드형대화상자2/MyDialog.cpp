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
	DDX_Text(pDX, IDC_STR, m_str);
	DDV_MaxChars(pDX, m_str, 10);
	DDX_Text(pDX, IDC_COLOR, m_color);
	DDV_MinMaxInt(pDX, m_color, 0, 255);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDC_BTNCLRSCR, &CMyDialog::OnClickedBtnclrscr)
END_MESSAGE_MAP()


// CMyDialog 메시지 처리기입니다.


void CMyDialog::OnClickedBtnclrscr()
{
	EndDialog(100); // 호출한 뷰클래스에서 100 인자를 확인해서 지우기 처리
}


// DDX(Dialog Data Exchange)
// DDX의 핵심함수는 CWnd::UpdateData()이며 CDialog::OnInitDialog(), CDialog::OnOK()함수에서 자동으로 호출한다
// 단순히 DDX기능을 위한 것이라면 두 함수를 재정의할 필요 없다.


// 호출경로 C뷰어::OnLButtonDblClk -> CMyDialog::OnInitDialog -> CMyDialog::OnOK -> C뷰어::OnLButtonDblClk
