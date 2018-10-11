
// WorkThread2View.h : CWorkThread2View 클래스의 인터페이스
//

#pragma once
struct ThreadArg
{
	HWND hwnd;	// 원도우 핸들
	int type;	// 1이면 위쪽에, 2면 아래쪽에 막대를 그린다.
};

class CWorkThread2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CWorkThread2View();
	DECLARE_DYNCREATE(CWorkThread2View)

// 특성입니다.
public:
	CWorkThread2Doc* GetDocument() const;

// 작업입니다.
public:
	CWinThread *pThread1, *pThread2;
	ThreadArg arg1, arg2;
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
	virtual ~CWorkThread2View();
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

#ifndef _DEBUG  // WorkThread2View.cpp의 디버그 버전
inline CWorkThread2Doc* CWorkThread2View::GetDocument() const
   { return reinterpret_cast<CWorkThread2Doc*>(m_pDocument); }
#endif

