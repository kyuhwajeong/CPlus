// MyDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HTML��.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// CMyDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDialog::IDD, pParent)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_url);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	
END_MESSAGE_MAP()


// CMyDialog �޽��� ó�����Դϴ�.
