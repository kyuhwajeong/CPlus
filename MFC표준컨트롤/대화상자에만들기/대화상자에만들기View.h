
// ��ȭ���ڿ������View.h : C��ȭ���ڿ������View Ŭ������ �������̽�
//

#pragma once


class C��ȭ���ڿ������View : public CView
{
protected: // serialization������ ��������ϴ�.
	C��ȭ���ڿ������View();
	DECLARE_DYNCREATE(C��ȭ���ڿ������View)

// Ư���Դϴ�.
public:
	C��ȭ���ڿ������Doc* GetDocument() const;

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
	virtual ~C��ȭ���ڿ������View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��ȭ���ڿ������View.cpp�� ����� ����
inline C��ȭ���ڿ������Doc* C��ȭ���ڿ������View::GetDocument() const
   { return reinterpret_cast<C��ȭ���ڿ������Doc*>(m_pDocument); }
#endif

