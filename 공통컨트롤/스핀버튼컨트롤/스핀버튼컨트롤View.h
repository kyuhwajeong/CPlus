
// ���ɹ�ư��Ʈ��View.h : C���ɹ�ư��Ʈ��View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxcmn.h"


class C���ɹ�ư��Ʈ��View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	C���ɹ�ư��Ʈ��View();
	DECLARE_DYNCREATE(C���ɹ�ư��Ʈ��View)

public:
	enum{ IDD = IDD_MY_FORM };

// Ư���Դϴ�.
public:
	C���ɹ�ư��Ʈ��Doc* GetDocument() const;

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
	virtual ~C���ɹ�ư��Ʈ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CSpinButtonCtrl m_spin;
};

#ifndef _DEBUG  // ���ɹ�ư��Ʈ��View.cpp�� ����� ����
inline C���ɹ�ư��Ʈ��Doc* C���ɹ�ư��Ʈ��View::GetDocument() const
   { return reinterpret_cast<C���ɹ�ư��Ʈ��Doc*>(m_pDocument); }
#endif

