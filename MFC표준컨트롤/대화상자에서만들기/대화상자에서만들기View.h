
// ��ȭ���ڿ��������View.h : C��ȭ���ڿ��������View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class C��ȭ���ڿ��������View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	C��ȭ���ڿ��������View();
	DECLARE_DYNCREATE(C��ȭ���ڿ��������View)

public:
	enum{ IDD = IDD_MY_FORM };

// Ư���Դϴ�.
public:
	C��ȭ���ڿ��������Doc* GetDocument() const;

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
	virtual ~C��ȭ���ڿ��������View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
//	CButton m_pushbutton;
	CButton m_checkbox;
	CButton m_radio1;
	CButton m_radio2;
};

#ifndef _DEBUG  // ��ȭ���ڿ��������View.cpp�� ����� ����
inline C��ȭ���ڿ��������Doc* C��ȭ���ڿ��������View::GetDocument() const
   { return reinterpret_cast<C��ȭ���ڿ��������Doc*>(m_pDocument); }
#endif

