
// ���α׷�����Ʈ��.h : ���α׷�����Ʈ�� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C���α׷�����Ʈ��App:
// �� Ŭ������ ������ ���ؼ��� ���α׷�����Ʈ��.cpp�� �����Ͻʽÿ�.
//

class C���α׷�����Ʈ��App : public CWinApp
{
public:
	C���α׷�����Ʈ��App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C���α׷�����Ʈ��App theApp;
