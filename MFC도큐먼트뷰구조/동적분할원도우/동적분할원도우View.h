
// �������ҿ�����View.h : C�������ҿ�����View Ŭ������ �������̽�
//

#pragma once


class C�������ҿ�����View : public CView
{
protected: // serialization������ ��������ϴ�.
	C�������ҿ�����View();
	DECLARE_DYNCREATE(C�������ҿ�����View)

// Ư���Դϴ�.
public:
	C�������ҿ�����Doc* GetDocument() const;

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
	virtual ~C�������ҿ�����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // �������ҿ�����View.cpp�� ����� ����
inline C�������ҿ�����Doc* C�������ҿ�����View::GetDocument() const
   { return reinterpret_cast<C�������ҿ�����Doc*>(m_pDocument); }
#endif

