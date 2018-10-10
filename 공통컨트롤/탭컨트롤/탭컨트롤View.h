
// 탭컨트롤View.h : C탭컨트롤View 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "afxwin.h"


class C탭컨트롤View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	C탭컨트롤View();
	DECLARE_DYNCREATE(C탭컨트롤View)

public:
	enum{ IDD = IDD_MY_FORM };

// 특성입니다.
public:
	C탭컨트롤Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~C탭컨트롤View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl m_tab;
	CEdit m_edit;
	afx_msg void OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // 탭컨트롤View.cpp의 디버그 버전
inline C탭컨트롤Doc* C탭컨트롤View::GetDocument() const
   { return reinterpret_cast<C탭컨트롤Doc*>(m_pDocument); }
#endif

