
// ��������ȭ����View.h : C��������ȭ����View Ŭ������ �������̽�
//

#pragma once
#include "MyDialog.h"
#include "��������ȭ����Doc.h"

class CMyDialog;

class C��������ȭ����View : public CView
{
protected: // serialization������ ��������ϴ�.
	C��������ȭ����View();
	DECLARE_DYNCREATE(C��������ȭ����View)

// Ư���Դϴ�.
public:
	C��������ȭ����Doc* GetDocument() const;

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
	virtual ~C��������ȭ����View();
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
	CMyDialog *m_pDlg;
	CString m_str;
	int m_color;
};

#ifndef _DEBUG  // ��������ȭ����View.cpp�� ����� ����
inline C��������ȭ����Doc* C��������ȭ����View::GetDocument() const
   { return reinterpret_cast<C��������ȭ����Doc*>(m_pDocument); }
#endif

