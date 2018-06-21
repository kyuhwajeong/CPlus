
// MFC구조이해.h : MFC구조이해 응용 프로그램에 대한 주 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// CMFC구조이해App:
// 이 클래스의 구현에 대해서는 MFC구조이해.cpp을 참조하십시오.
//
// 응용프로그램 클래스 (WIN SDK 프로그램의 WinMain()함수의 역할
// 주된 역할은 프레임 원도우를 생성하는 것과 메시지 루프를 제공하는 것
// 메시지 루프를 제공하는 역할을 하는 CWinApp:Run()함수는 내부적으로 자동으로 호출
class CMFC구조이해App : public CWinApp
{
public:
	CMFC구조이해App();


// 재정의입니다.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 구현입니다.

public:
	afx_msg void OnAppAbout(); // [도움말]-?[..정보] 메뉴를 선택
	DECLARE_MESSAGE_MAP()
};

extern CMFC구조이해App theApp;
