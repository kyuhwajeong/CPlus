
// ������Ʈ��View.h : C������Ʈ��View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"


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
};

#ifndef _DEBUG  // ������Ʈ��View.cpp�� ����� ����
inline C������Ʈ��Doc* C������Ʈ��View::GetDocument() const
   { return reinterpret_cast<C������Ʈ��Doc*>(m_pDocument); }
#endif

