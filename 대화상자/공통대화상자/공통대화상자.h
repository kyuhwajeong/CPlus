
// �����ȭ����.h : �����ȭ���� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C�����ȭ����App:
// �� Ŭ������ ������ ���ؼ��� �����ȭ����.cpp�� �����Ͻʽÿ�.
//

class C�����ȭ����App : public CWinApp
{
public:
	C�����ȭ����App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�����ȭ����App theApp;
