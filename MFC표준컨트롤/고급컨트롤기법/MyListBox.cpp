// MyListBox.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "�����Ʈ�ѱ��.h"
#include "MyListBox.h"


// CMyListBox

IMPLEMENT_DYNAMIC(CMyListBox, CListBox)

CMyListBox::CMyListBox()
{

}

CMyListBox::~CMyListBox()
{
}


BEGIN_MESSAGE_MAP(CMyListBox, CListBox)
	ON_CONTROL_REFLECT(LBN_DBLCLK, &CMyListBox::OnLbnDblclk)
END_MESSAGE_MAP()



// CMyListBox �޽��� ó�����Դϴ�.




void CMyListBox::OnLbnDblclk()
{
	CString str;
	int nIndex = GetCurSel();
	GetText(nIndex, str);
	MessageBox(str);
}
