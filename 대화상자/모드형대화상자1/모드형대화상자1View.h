
// �������ȭ����1View.h : C�������ȭ����1View Ŭ������ �������̽�
//

#pragma once


class C�������ȭ����1View : public CView
{
protected: // serialization������ ��������ϴ�.
	C�������ȭ����1View();
	DECLARE_DYNCREATE(C�������ȭ����1View)

// Ư���Դϴ�.
public:
	C�������ȭ����1Doc* GetDocument() const;

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
	virtual ~C�������ȭ����1View();
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
};

#ifndef _DEBUG  // �������ȭ����1View.cpp�� ����� ����
inline C�������ȭ����1Doc* C�������ȭ����1View::GetDocument() const
   { return reinterpret_cast<C�������ȭ����1Doc*>(m_pDocument); }
#endif

