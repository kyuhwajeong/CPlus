
// ���ɹ�ư��Ʈ��.h : ���ɹ�ư��Ʈ�� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C���ɹ�ư��Ʈ��App:
// �� Ŭ������ ������ ���ؼ��� ���ɹ�ư��Ʈ��.cpp�� �����Ͻʽÿ�.
//

class C���ɹ�ư��Ʈ��App : public CWinApp
{
public:
	C���ɹ�ư��Ʈ��App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C���ɹ�ư��Ʈ��App theApp;
