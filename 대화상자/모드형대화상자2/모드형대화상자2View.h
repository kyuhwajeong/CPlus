
// �������ȭ����2View.h : C�������ȭ����2View Ŭ������ �������̽�
//

#pragma once
#include "MyDialog.h"

class C�������ȭ����2View : public CView
{
protected: // serialization������ ��������ϴ�.
	C�������ȭ����2View();
	DECLARE_DYNCREATE(C�������ȭ����2View)

// Ư���Դϴ�.
public:
	C�������ȭ����2Doc* GetDocument() const;

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
	virtual ~C�������ȭ����2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	CString & m_str;
	int & m_color;
	CMyDialog m_dlg;

};

#ifndef _DEBUG  // �������ȭ����2View.cpp�� ����� ����
inline C�������ȭ����2Doc* C�������ȭ����2View::GetDocument() const
   { return reinterpret_cast<C�������ȭ����2Doc*>(m_pDocument); }
#endif

