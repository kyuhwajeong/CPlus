
// WorkThreadView.h : CWorkThreadView Ŭ������ �������̽�
//

#pragma once


class CWorkThreadView : public CView
{
protected: // serialization������ ��������ϴ�.
	CWorkThreadView();
	DECLARE_DYNCREATE(CWorkThreadView)

// Ư���Դϴ�.
public:
	CWorkThreadDoc* GetDocument() const;

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
	virtual ~CWorkThreadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // WorkThreadView.cpp�� ����� ����
inline CWorkThreadDoc* CWorkThreadView::GetDocument() const
   { return reinterpret_cast<CWorkThreadDoc*>(m_pDocument); }
#endif

