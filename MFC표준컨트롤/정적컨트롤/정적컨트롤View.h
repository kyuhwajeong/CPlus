
// ������Ʈ��View.h : C������Ʈ��View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class C������Ʈ��View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	C������Ʈ��View();
	DECLARE_DYNCREATE(C������Ʈ��View)

public:
	enum{ IDD = IDD_MY_FORM };

// Ư���Դϴ�.
public:
	C������Ʈ��Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~C������Ʈ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // ������Ʈ��View.cpp�� ����� ����
inline C������Ʈ��Doc* C������Ʈ��View::GetDocument() const
   { return reinterpret_cast<C������Ʈ��Doc*>(m_pDocument); }
#endif

