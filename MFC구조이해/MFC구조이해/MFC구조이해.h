
// MFC��������.h : MFC�������� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFC��������App:
// �� Ŭ������ ������ ���ؼ��� MFC��������.cpp�� �����Ͻʽÿ�.
//
// �������α׷� Ŭ���� (WIN SDK ���α׷��� WinMain()�Լ��� ����
// �ֵ� ������ ������ �����츦 �����ϴ� �Ͱ� �޽��� ������ �����ϴ� ��
// �޽��� ������ �����ϴ� ������ �ϴ� CWinApp:Run()�Լ��� ���������� �ڵ����� ȣ��
class CMFC��������App : public CWinApp
{
public:
	CMFC��������App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout(); // [����]-?[..����] �޴��� ����
	DECLARE_MESSAGE_MAP()
};

extern CMFC��������App theApp;
