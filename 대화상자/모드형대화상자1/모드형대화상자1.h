
// �������ȭ����1.h : �������ȭ����1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C�������ȭ����1App:
// �� Ŭ������ ������ ���ؼ��� �������ȭ����1.cpp�� �����Ͻʽÿ�.
//

class C�������ȭ����1App : public CWinApp
{
public:
	C�������ȭ����1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�������ȭ����1App theApp;
