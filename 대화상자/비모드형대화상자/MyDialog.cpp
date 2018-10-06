// MyDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "��������ȭ����.h"
#include "MyDialog.h"
#include "afxdialogex.h"
#include "��������ȭ����View.h"

// CMyDialog ��ȭ �����Դϴ�.

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


// CMyDialog �޽��� ó�����Դϴ�.


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
//	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
//
//	CDialog::OnOK();
//}


void CMyDialog::OnApply()
{
	UpdateData(TRUE);// DDX�� ���� ���۽�Ų��.
	m_pView->m_str = m_str;
	m_pView->m_color = m_color;
	m_pView->Invalidate();
}
