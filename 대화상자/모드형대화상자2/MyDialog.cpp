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
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDC_BTNCLRSCR, &CMyDialog::OnClickedBtnclrscr)
END_MESSAGE_MAP()


// CMyDialog �޽��� ó�����Դϴ�.


void CMyDialog::OnClickedBtnclrscr()
{
	EndDialog(100); // ȣ���� ��Ŭ�������� 100 ���ڸ� Ȯ���ؼ� ����� ó��
}


BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetDlgItemText(IDC_STR, m_str);
	SetDlgItemInt(IDC_COLOR, m_color);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CMyDialog::OnOK()
{
	GetDlgItemText(IDC_STR, m_str);
	m_color = GetDlgItemInt(IDC_COLOR);

	CDialog::OnOK();
}

// DDX(Dialog Data Exchange)
// DDX�� �ٽ��Լ��� CWnd::UpdateData()�̸� CDialog::OnInitDialog(), CDialog::OnOK()�Լ����� �ڵ����� ȣ���Ѵ�
// �ܼ��� DDX����� ���� ���̶�� �� �Լ��� �������� �ʿ� ����.


// C���::OnLButtonDblClk -> CMyDialog::OnInitDialog -> CMyDialog::OnOK -> C���::OnLButtonDblClk
