
// MFC���콺�ٷ��.h : MFC���콺�ٷ�� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFC���콺�ٷ��App:
// �� Ŭ������ ������ ���ؼ��� MFC���콺�ٷ��.cpp�� �����Ͻʽÿ�.
//

class CMFC���콺�ٷ��App : public CWinApp
{
public:
	CMFC���콺�ٷ��App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC���콺�ٷ��App theApp;
