
// ����Ʈ��.h : ����Ʈ�� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C����Ʈ��App:
// �� Ŭ������ ������ ���ؼ��� ����Ʈ��.cpp�� �����Ͻʽÿ�.
//

class C����Ʈ��App : public CWinApp
{
public:
	C����Ʈ��App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C����Ʈ��App theApp;
