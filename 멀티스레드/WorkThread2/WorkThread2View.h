
// WorkThread2View.h : CWorkThread2View Ŭ������ �������̽�
//

#pragma once
struct ThreadArg
{
	HWND hwnd;	// ������ �ڵ�
	int type;	// 1�̸� ���ʿ�, 2�� �Ʒ��ʿ� ���븦 �׸���.
};

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
	CWinThread *pThread1, *pThread2;
	ThreadArg arg1, arg2;
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
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // WorkThread2View.cpp�� ����� ����
inline CWorkThread2Doc* CWorkThread2View::GetDocument() const
   { return reinterpret_cast<CWorkThread2Doc*>(m_pDocument); }
#endif

