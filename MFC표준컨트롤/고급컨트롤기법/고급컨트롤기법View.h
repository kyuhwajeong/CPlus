
// �����Ʈ�ѱ��View.h : C�����Ʈ�ѱ��View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "MyEdit.h"
#include "MyListBox.h"


class C�����Ʈ�ѱ��View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	C�����Ʈ�ѱ��View();
	DECLARE_DYNCREATE(C�����Ʈ�ѱ��View)

public:
	enum{ IDD = IDD_MY_FORM };

// Ư���Դϴ�.
public:
	C�����Ʈ�ѱ��Doc* GetDocument() const;

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
	virtual ~C�����Ʈ�ѱ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CMyEdit m_edit1;
	CMyEdit m_edit2;
	CMyListBox m_list;
};

#ifndef _DEBUG  // �����Ʈ�ѱ��View.cpp�� ����� ����
inline C�����Ʈ�ѱ��Doc* C�����Ʈ�ѱ��View::GetDocument() const
   { return reinterpret_cast<C�����Ʈ�ѱ��Doc*>(m_pDocument); }
#endif

