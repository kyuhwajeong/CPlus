
// 공통대화상자View.h : C공통대화상자View 클래스의 인터페이스
//

#pragma once


class C공통대화상자View : public CView
{
protected: // serialization에서만 만들어집니다.
	C공통대화상자View();
	DECLARE_DYNCREATE(C공통대화상자View)

// 특성입니다.
public:
	C공통대화상자Doc* GetDocument() const;

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
	virtual ~C공통대화상자View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFindreplace();
	CFindReplaceDialog *pFindReplaceDlg;
};

#ifndef _DEBUG  // 공통대화상자View.cpp의 디버그 버전
inline C공통대화상자Doc* C공통대화상자View::GetDocument() const
   { return reinterpret_cast<C공통대화상자Doc*>(m_pDocument); }
#endif

