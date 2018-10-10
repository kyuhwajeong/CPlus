
// 트리뷰View.h : C트리뷰View 클래스의 인터페이스
//

#pragma once


class C트리뷰View : public CTreeView
{
protected: // serialization에서만 만들어집니다.
	C트리뷰View();
	DECLARE_DYNCREATE(C트리뷰View)

// 특성입니다.
public:
	C트리뷰Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~C트리뷰View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnTvnDeleteitem(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTestDeleteitem();
};

#ifndef _DEBUG  // 트리뷰View.cpp의 디버그 버전
inline C트리뷰Doc* C트리뷰View::GetDocument() const
   { return reinterpret_cast<C트리뷰Doc*>(m_pDocument); }
#endif

