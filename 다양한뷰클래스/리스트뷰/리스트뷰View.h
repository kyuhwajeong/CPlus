
// 리스트뷰View.h : C리스트뷰View 클래스의 인터페이스
//

#pragma once


class C리스트뷰View : public CListView
{
protected: // serialization에서만 만들어집니다.
	C리스트뷰View();
	DECLARE_DYNCREATE(C리스트뷰View)

// 특성입니다.
public:
	C리스트뷰Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~C리스트뷰View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnIconview();
	afx_msg void OnSmalliconview();
	afx_msg void OnListview();
	afx_msg void OnReportview();
};

#ifndef _DEBUG  // 리스트뷰View.cpp의 디버그 버전
inline C리스트뷰Doc* C리스트뷰View::GetDocument() const
   { return reinterpret_cast<C리스트뷰Doc*>(m_pDocument); }
#endif

