
// ��ȭ���ڱ���������α׷�Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// C��ȭ���ڱ���������α׷�Dlg ��ȭ ����
class C��ȭ���ڱ���������α׷�Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	C��ȭ���ڱ���������α׷�Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCalc();
	double m_op1;
	double m_op2;
	double m_op3;
	double m_op4;
	CEdit m_result1;
	CEdit m_result2;
};
