
// ���α׷�����Ʈ��View.h : C���α׷�����Ʈ��View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"


class C���α׷�����Ʈ��View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	C���α׷�����Ʈ��View();
	DECLARE_DYNCREATE(C���α׷�����Ʈ��View)

public:
	enum{ IDD = IDD_MY_FORM };

// Ư���Դϴ�.
public:
	C���α׷�����Ʈ��Doc* GetDocument() const;

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
	virtual ~C���α׷�����Ʈ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���α׷�����Ʈ��View.cpp�� ����� ����
inline C���α׷�����Ʈ��Doc* C���α׷�����Ʈ��View::GetDocument() const
   { return reinterpret_cast<C���α׷�����Ʈ��Doc*>(m_pDocument); }
#endif

