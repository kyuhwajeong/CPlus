
// MFC���������View.h : CMFC���������View Ŭ������ �������̽�
//

#pragma once


class CMFC���������View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFC���������View();
	DECLARE_DYNCREATE(CMFC���������View)

// Ư���Դϴ�.
public:
	CMFC���������Doc* GetDocument() const;

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
	virtual ~CMFC���������View();
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
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
};

#ifndef _DEBUG  // MFC���������View.cpp�� ����� ����
inline CMFC���������Doc* CMFC���������View::GetDocument() const
   { return reinterpret_cast<CMFC���������Doc*>(m_pDocument); }
#endif

