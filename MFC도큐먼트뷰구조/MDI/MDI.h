
// MDI.h : MDI ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMDIApp:
// �� Ŭ������ ������ ���ؼ��� MDI.cpp�� �����Ͻʽÿ�.
//

class CMDIApp : public CWinApp
{
public:
	CMDIApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMDIApp theApp;
