
// 일반원도우만들기View.h : C일반원도우만들기View 클래스의 인터페이스
//

#pragma once
#include "afxwin.h"


class C일반원도우만들기View : public CView
{
protected: // serialization에서만 만들어집니다.
	C일반원도우만들기View();
	DECLARE_DYNCREATE(C일반원도우만들기View)

// 특성입니다.
public:
	C일반원도우만들기Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~C일반원도우만들기View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CButton m_pushbutton;
	CButton m_checkbox;
	CButton m_radio1;
	CButton m_radio2;
	CButton m_groupbox;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // 일반원도우만들기View.cpp의 디버그 버전
inline C일반원도우만들기Doc* C일반원도우만들기View::GetDocument() const
   { return reinterpret_cast<C일반원도우만들기Doc*>(m_pDocument); }
#endif

