
// 일반원도우만들기.h : 일반원도우만들기 응용 프로그램에 대한 주 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// C일반원도우만들기App:
// 이 클래스의 구현에 대해서는 일반원도우만들기.cpp을 참조하십시오.
//

class C일반원도우만들기App : public CWinAppEx
{
public:
	C일반원도우만들기App();


// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C일반원도우만들기App theApp;
