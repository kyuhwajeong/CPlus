
// WorkThread2View.h : CWorkThread2View Ŭ������ �������̽�
//

#pragma once


class CWorkThread2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CWorkThread2View();
	DECLARE_DYNCREATE(CWorkThread2View)

// Ư���Դϴ�.
public:
	CWorkThread2Doc* GetDocument() const;

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
	virtual ~CWorkThread2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // WorkThread2View.cpp�� ����� ����
inline CWorkThread2Doc* CWorkThread2View::GetDocument() const
   { return reinterpret_cast<CWorkThread2Doc*>(m_pDocument); }
#endif

