
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
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnFilePrintSetup();
};

extern CMFC���������App theApp;
