
// MFC파일입출력View.h : CMFC파일입출력View 클래스의 인터페이스
//

#pragma once


class CMFC파일입출력View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFC파일입출력View();
	DECLARE_DYNCREATE(CMFC파일입출력View)

// 특성입니다.
public:
	CMFC파일입출력Doc* GetDocument() const;

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
	virtual ~CMFC파일입출력View();
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
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
};

#ifndef _DEBUG  // MFC파일입출력View.cpp의 디버그 버전
inline CMFC파일입출력Doc* CMFC파일입출력View::GetDocument() const
   { return reinterpret_cast<CMFC파일입출력Doc*>(m_pDocument); }
#endif

