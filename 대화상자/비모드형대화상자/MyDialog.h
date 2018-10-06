#pragma once

#include "비모드형대화상자View.h"
// CMyDialog 대화 상자입니다.
class C비모드형대화상자View;

class CMyDialog : public CDialog
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMyDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MYDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_str;
	int m_color;
	C비모드형대화상자View *m_pView;
	virtual void OnCancel();
	virtual void PostNcDestroy();
//	virtual void OnOK();
	afx_msg void OnApply();
};
