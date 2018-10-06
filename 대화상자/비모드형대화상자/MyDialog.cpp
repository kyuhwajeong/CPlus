// MyDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "비모드형대화상자.h"
#include "MyDialog.h"
#include "afxdialogex.h"
#include "비모드형대화상자View.h"

// CMyDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDialog::IDD, pParent)
	, m_str(_T(""))
	, m_color(0)
	, m_pView(NULL)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STR, m_str);
	DDX_Text(pDX, IDC_COLOR, m_color);
	DDV_MinMaxInt(pDX, m_color, 0, 255);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDAPPLY, &CMyDialog::OnApply)
END_MESSAGE_MAP()


// CMyDialog 메시지 처리기입니다.


void CMyDialog::OnCancel()
{
	DestroyWindow();
}


void CMyDialog::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	m_pView->m_pDlg = NULL;
	delete this;
}


//void CMyDialog::OnOK()
//{
//	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
//
//	CDialog::OnOK();
//}


void CMyDialog::OnApply()
{
	UpdateData(TRUE);// DDX를 직접 동작시킨다.
	m_pView->m_str = m_str;
	m_pView->m_color = m_color;
	m_pView->Invalidate();
}
