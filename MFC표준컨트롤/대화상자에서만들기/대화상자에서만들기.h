
// ��ȭ���ڿ��������.h : ��ȭ���ڿ�������� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C��ȭ���ڿ��������App:
// �� Ŭ������ ������ ���ؼ��� ��ȭ���ڿ��������.cpp�� �����Ͻʽÿ�.
//

class C��ȭ���ڿ��������App : public CWinAppEx
{
public:
	C��ȭ���ڿ��������App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ȭ���ڿ��������App theApp;
