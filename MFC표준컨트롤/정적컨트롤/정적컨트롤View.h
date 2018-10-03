
// 정적컨트롤View.h : C정적컨트롤View 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class C정적컨트롤View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	C정적컨트롤View();
	DECLARE_DYNCREATE(C정적컨트롤View)

public:
	enum{ IDD = IDD_MY_FORM };

// 특성입니다.
public:
	C정적컨트롤Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~C정적컨트롤View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_enhmeta;
	afx_msg void OnClickedEnhmeta();
	CEdit m_edit;
	afx_msg void OnBnClickedBtnclr();
	afx_msg void OnBnClickedBtncut();
	afx_msg void OnBnClickedBtnpaste();
	afx_msg void OnBnClickedBtnundo();
	afx_msg void OnBnClickedBtnreplace();
	afx_msg void OnBnClickedBtntxtdsp();
	afx_msg void OnBnClickedBtnreplace2();
	afx_msg void OnChangeEdit1();
	CListBox m_list;
	afx_msg void OnDblclkList1();
	afx_msg void OnSelchangeList1();
	afx_msg void OnSelcancelList1();
	afx_msg void OnSetfocusList1();
	afx_msg void OnKillfocusList1();
	afx_msg void OnBnClickedBtnadd();
	afx_msg void OnBnClickedBtndel();
	afx_msg void OnCloseupCombo1();
	afx_msg void OnDblclkCombo1();
	afx_msg void OnDropdownCombo1();
	afx_msg void OnEditupdateCombo1();
	afx_msg void OnKillfocusCombo1();
	afx_msg void OnSelendcancelCombo1();
	afx_msg void OnSelendokCombo1();
	afx_msg void OnSetfocusCombo1();
	CComboBox m_combo;
	afx_msg void OnBnClickedBtncomboadd();
	afx_msg void OnBnClickedBtncombodel();
};

#ifndef _DEBUG  // 정적컨트롤View.cpp의 디버그 버전
inline C정적컨트롤Doc* C정적컨트롤View::GetDocument() const
   { return reinterpret_cast<C정적컨트롤Doc*>(m_pDocument); }
#endif

