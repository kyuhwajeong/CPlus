// MyDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HTML뷰.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// CMyDialog 대화 상자입니다.

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


// CMyDialog 메시지 처리기입니다.
