
// �������ҿ�����.h : �������ҿ����� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C�������ҿ�����App:
// �� Ŭ������ ������ ���ؼ��� �������ҿ�����.cpp�� �����Ͻʽÿ�.
//

class C�������ҿ�����App : public CWinApp
{
public:
	C�������ҿ�����App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�������ҿ�����App theApp;
