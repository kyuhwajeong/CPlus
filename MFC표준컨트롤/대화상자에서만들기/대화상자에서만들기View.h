
// 대화상자에서만들기View.h : C대화상자에서만들기View 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class C대화상자에서만들기View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	C대화상자에서만들기View();
	DECLARE_DYNCREATE(C대화상자에서만들기View)

public:
	enum{ IDD = IDD_MY_FORM };

// 특성입니다.
public:
	C대화상자에서만들기Doc* GetDocument() const;

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
	virtual ~C대화상자에서만들기View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
//	CButton m_pushbutton;
	CButton m_checkbox;
	CButton m_radio1;
	CButton m_radio2;
};

#ifndef _DEBUG  // 대화상자에서만들기View.cpp의 디버그 버전
inline C대화상자에서만들기Doc* C대화상자에서만들기View::GetDocument() const
   { return reinterpret_cast<C대화상자에서만들기Doc*>(m_pDocument); }
#endif

