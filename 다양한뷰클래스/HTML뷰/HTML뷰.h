
// HTML��.h : HTML�� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CHTML��App:
// �� Ŭ������ ������ ���ؼ��� HTML��.cpp�� �����Ͻʽÿ�.
//

class CHTML��App : public CWinApp
{
public:
	CHTML��App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHTML��App theApp;
