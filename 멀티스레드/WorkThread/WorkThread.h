
// WorkThread.h : WorkThread ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CWorkThreadApp:
// �� Ŭ������ ������ ���ؼ��� WorkThread.cpp�� �����Ͻʽÿ�.
//

class CWorkThreadApp : public CWinApp
{
public:
	CWorkThreadApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWorkThreadApp theApp;
