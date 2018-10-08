
// 정적분할원도우View.h : C정적분할원도우View 클래스의 인터페이스
//

#pragma once

#include "정적분할원도우Doc.h"

class C정적분할원도우View : public CView
{
protected: // serialization에서만 만들어집니다.
	C정적분할원도우View();
	DECLARE_DYNCREATE(C정적분할원도우View)

// 특성입니다.
public:
	C정적분할원도우Doc* GetDocument() const;

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
	virtual ~C정적분할원도우View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 정적분할원도우View.cpp의 디버그 버전
inline C정적분할원도우Doc* C정적분할원도우View::GetDocument() const
   { return reinterpret_cast<C정적분할원도우Doc*>(m_pDocument); }
#endif

