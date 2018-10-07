
// 대화상자기반응용프로그램Dlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// C대화상자기반응용프로그램Dlg 대화 상자
class C대화상자기반응용프로그램Dlg : public CDialogEx
{
// 생성입니다.
public:
	C대화상자기반응용프로그램Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
