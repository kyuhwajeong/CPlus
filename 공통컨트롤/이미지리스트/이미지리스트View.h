
// �̹�������ƮView.h : C�̹�������ƮView Ŭ������ �������̽�
//

#pragma once


class C�̹�������ƮView : public CView
{
protected: // serialization������ ��������ϴ�.
	C�̹�������ƮView();
	DECLARE_DYNCREATE(C�̹�������ƮView)

// Ư���Դϴ�.
public:
	C�̹�������ƮDoc* GetDocument() const;

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
	virtual ~C�̹�������ƮView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // �̹�������ƮView.cpp�� ����� ����
inline C�̹�������ƮDoc* C�̹�������ƮView::GetDocument() const
   { return reinterpret_cast<C�̹�������ƮDoc*>(m_pDocument); }
#endif

