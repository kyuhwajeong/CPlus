#pragma once


// CMyDialog 대화 상자입니다.

class CMyDialog : public CDialog
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMyDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedBtnclrscr();
	virtual BOOL OnInitDialog();
	CString m_str;
	int m_color;
	virtual void OnOK();
};
