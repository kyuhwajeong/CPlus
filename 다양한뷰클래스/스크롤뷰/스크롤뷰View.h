
// ��ũ�Ѻ�View.h : C��ũ�Ѻ�View Ŭ������ �������̽�
//

#pragma once


class C��ũ�Ѻ�View : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	C��ũ�Ѻ�View();
	DECLARE_DYNCREATE(C��ũ�Ѻ�View)

// Ư���Դϴ�.
public:
	C��ũ�Ѻ�Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~C��ũ�Ѻ�View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	// x, y �߽����� �� ���� ���̰� 100�ȼ��� ���簢���� �׸���.
	void MyDraw(CDC * pDC, int x, int y);
};

#ifndef _DEBUG  // ��ũ�Ѻ�View.cpp�� ����� ����
inline C��ũ�Ѻ�Doc* C��ũ�Ѻ�View::GetDocument() const
   { return reinterpret_cast<C��ũ�Ѻ�Doc*>(m_pDocument); }
#endif

