
// �̹�������Ʈ.h : �̹�������Ʈ ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C�̹�������ƮApp:
// �� Ŭ������ ������ ���ؼ��� �̹�������Ʈ.cpp�� �����Ͻʽÿ�.
//

class C�̹�������ƮApp : public CWinApp
{
public:
	C�̹�������ƮApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�̹�������ƮApp theApp;
