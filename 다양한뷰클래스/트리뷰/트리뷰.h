
// Ʈ����.h : Ʈ���� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CƮ����App:
// �� Ŭ������ ������ ���ؼ��� Ʈ����.cpp�� �����Ͻʽÿ�.
//

class CƮ����App : public CWinApp
{
public:
	CƮ����App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CƮ����App theApp;
