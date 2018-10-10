
// 스크롤뷰View.h : C스크롤뷰View 클래스의 인터페이스
//

#pragma once


class C스크롤뷰View : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	C스크롤뷰View();
	DECLARE_DYNCREATE(C스크롤뷰View)

// 특성입니다.
public:
	C스크롤뷰Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~C스크롤뷰View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	// x, y 중심으로 한 변의 길이가 100픽셀인 정사각형을 그린다.
	void MyDraw(CDC * pDC, int x, int y);
};

#ifndef _DEBUG  // 스크롤뷰View.cpp의 디버그 버전
inline C스크롤뷰Doc* C스크롤뷰View::GetDocument() const
   { return reinterpret_cast<C스크롤뷰Doc*>(m_pDocument); }
#endif

