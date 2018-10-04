// MyListBox.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "고급컨트롤기법.h"
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



// CMyListBox 메시지 처리기입니다.




void CMyListBox::OnLbnDblclk()
{
	CString str;
	int nIndex = GetCurSel();
	GetText(nIndex, str);
	MessageBox(str);
}
