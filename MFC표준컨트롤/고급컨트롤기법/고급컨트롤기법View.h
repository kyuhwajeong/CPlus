
// 고급컨트롤기법View.h : C고급컨트롤기법View 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "MyEdit.h"
#include "MyListBox.h"


class C고급컨트롤기법View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	C고급컨트롤기법View();
	DECLARE_DYNCREATE(C고급컨트롤기법View)

public:
	enum{ IDD = IDD_MY_FORM };

// 특성입니다.
public:
	C고급컨트롤기법Doc* GetDocument() const;

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
	virtual ~C고급컨트롤기법View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CMyEdit m_edit1;
	CMyEdit m_edit2;
	CMyListBox m_list;
};

#ifndef _DEBUG  // 고급컨트롤기법View.cpp의 디버그 버전
inline C고급컨트롤기법Doc* C고급컨트롤기법View::GetDocument() const
   { return reinterpret_cast<C고급컨트롤기법Doc*>(m_pDocument); }
#endif

