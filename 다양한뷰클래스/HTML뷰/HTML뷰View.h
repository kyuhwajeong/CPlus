
// HTML뷰View.h : CHTML뷰View 클래스의 인터페이스
//

#pragma once


class CHTML뷰View : public CHtmlView
{
protected: // serialization에서만 만들어집니다.
	CHTML뷰View();
	DECLARE_DYNCREATE(CHTML뷰View)

// 특성입니다.
public:
	CHTML뷰Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CHTML뷰View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // HTML뷰View.cpp의 디버그 버전
inline CHTML뷰Doc* CHTML뷰View::GetDocument() const
   { return reinterpret_cast<CHTML뷰Doc*>(m_pDocument); }
#endif

