
// MFC_GDI��ü.h : MFC_GDI��ü ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFC_GDI��üApp:
// �� Ŭ������ ������ ���ؼ��� MFC_GDI��ü.cpp�� �����Ͻʽÿ�.
//

class CMFC_GDI��üApp : public CWinApp
{
public:
	CMFC_GDI��üApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_GDI��üApp theApp;
