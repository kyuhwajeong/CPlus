
// MFC도큐먼트뷰구조View.h : CMFC도큐먼트뷰구조View 클래스의 인터페이스
//

#pragma once


class CMFC도큐먼트뷰구조View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFC도큐먼트뷰구조View();
	DECLARE_DYNCREATE(CMFC도큐먼트뷰구조View)

// 특성입니다.
public:
	CMFC도큐먼트뷰구조Doc* GetDocument() const;

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
	virtual ~CMFC도큐먼트뷰구조View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC도큐먼트뷰구조View.cpp의 디버그 버전
inline CMFC도큐먼트뷰구조Doc* CMFC도큐먼트뷰구조View::GetDocument() const
   { return reinterpret_cast<CMFC도큐먼트뷰구조Doc*>(m_pDocument); }
#endif

