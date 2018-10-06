
// 비모드형대화상자View.h : C비모드형대화상자View 클래스의 인터페이스
//

#pragma once
#include "MyDialog.h"
#include "비모드형대화상자Doc.h"

class CMyDialog;

class C비모드형대화상자View : public CView
{
protected: // serialization에서만 만들어집니다.
	C비모드형대화상자View();
	DECLARE_DYNCREATE(C비모드형대화상자View)

// 특성입니다.
public:
	C비모드형대화상자Doc* GetDocument() const;

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
	virtual ~C비모드형대화상자View();
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
	CMyDialog *m_pDlg;
	CString m_str;
	int m_color;
};

#ifndef _DEBUG  // 비모드형대화상자View.cpp의 디버그 버전
inline C비모드형대화상자Doc* C비모드형대화상자View::GetDocument() const
   { return reinterpret_cast<C비모드형대화상자Doc*>(m_pDocument); }
#endif

