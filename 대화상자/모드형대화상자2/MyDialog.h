#pragma once


// CMyDialog ��ȭ �����Դϴ�.

class CMyDialog : public CDialog
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMyDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedBtnclrscr();
	virtual BOOL OnInitDialog();
	CString m_str;
	int m_color;
	virtual void OnOK();
};
