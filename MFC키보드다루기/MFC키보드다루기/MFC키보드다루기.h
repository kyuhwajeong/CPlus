
// MFCŰ����ٷ��.h : MFCŰ����ٷ�� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFCŰ����ٷ��App:
// �� Ŭ������ ������ ���ؼ��� MFCŰ����ٷ��.cpp�� �����Ͻʽÿ�.
//

class CMFCŰ����ٷ��App : public CWinApp
{
public:
	CMFCŰ����ٷ��App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCŰ����ٷ��App theApp;
