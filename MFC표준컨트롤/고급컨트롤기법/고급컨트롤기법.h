
// �����Ʈ�ѱ��.h : �����Ʈ�ѱ�� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C�����Ʈ�ѱ��App:
// �� Ŭ������ ������ ���ؼ��� �����Ʈ�ѱ��.cpp�� �����Ͻʽÿ�.
//

class C�����Ʈ�ѱ��App : public CWinApp
{
public:
	C�����Ʈ�ѱ��App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�����Ʈ�ѱ��App theApp;
