
// MFC�׸����Լ�.h : MFC�׸����Լ� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFC�׸����Լ�App:
// �� Ŭ������ ������ ���ؼ��� MFC�׸����Լ�.cpp�� �����Ͻʽÿ�.
//

class CMFC�׸����Լ�App : public CWinApp
{
public:
	CMFC�׸����Լ�App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC�׸����Լ�App theApp;
