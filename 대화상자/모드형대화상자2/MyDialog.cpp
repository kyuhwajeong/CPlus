// MyDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "�������ȭ����2.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// CMyDialog ��ȭ �����Դϴ�.

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


// CMyDialog �޽��� ó�����Դϴ�.


void CMyDialog::OnClickedBtnclrscr()
{
	EndDialog(100); // ȣ���� ��Ŭ�������� 100 ���ڸ� Ȯ���ؼ� ����� ó��
}


// DDX(Dialog Data Exchange)
// DDX�� �ٽ��Լ��� CWnd::UpdateData()�̸� CDialog::OnInitDialog(), CDialog::OnOK()�Լ����� �ڵ����� ȣ���Ѵ�
// �ܼ��� DDX����� ���� ���̶�� �� �Լ��� �������� �ʿ� ����.


// ȣ���� C���::OnLButtonDblClk -> CMyDialog::OnInitDialog -> CMyDialog::OnOK -> C���::OnLButtonDblClk
