
// �Ϲݿ����츸���View.h : C�Ϲݿ����츸���View Ŭ������ �������̽�
//

#pragma once
#include "afxwin.h"


class C�Ϲݿ����츸���View : public CView
{
protected: // serialization������ ��������ϴ�.
	C�Ϲݿ����츸���View();
	DECLARE_DYNCREATE(C�Ϲݿ����츸���View)

// Ư���Դϴ�.
public:
	C�Ϲݿ����츸���Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~C�Ϲݿ����츸���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CButton m_pushbutton;
	CButton m_checkbox;
	CButton m_radio1;
	CButton m_radio2;
	CButton m_groupbox;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // �Ϲݿ����츸���View.cpp�� ����� ����
inline C�Ϲݿ����츸���Doc* C�Ϲݿ����츸���View::GetDocument() const
   { return reinterpret_cast<C�Ϲݿ����츸���Doc*>(m_pDocument); }
#endif

