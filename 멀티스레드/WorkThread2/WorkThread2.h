
// WorkThread2.h : WorkThread2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CWorkThread2App:
// �� Ŭ������ ������ ���ؼ��� WorkThread2.cpp�� �����Ͻʽÿ�.
//

class CWorkThread2App : public CWinApp
{
public:
	CWorkThread2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWorkThread2App theApp;
