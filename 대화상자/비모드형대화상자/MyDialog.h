#pragma once

#include "��������ȭ����View.h"
// CMyDialog ��ȭ �����Դϴ�.
class C��������ȭ����View;

class CMyDialog : public CDialog
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMyDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MYDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_str;
	int m_color;
	C��������ȭ����View *m_pView;
	virtual void OnCancel();
	virtual void PostNcDestroy();
//	virtual void OnOK();
	afx_msg void OnApply();
};
