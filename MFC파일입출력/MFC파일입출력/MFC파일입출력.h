
// MFC���������.h : MFC��������� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFC���������App:
// �� Ŭ������ ������ ���ؼ��� MFC���������.cpp�� �����Ͻʽÿ�.
//

class CMFC���������App : public CWinApp
{
public:
	CMFC���������App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC���������App theApp;
