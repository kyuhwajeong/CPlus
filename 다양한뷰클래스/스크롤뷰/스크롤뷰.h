
// ��ũ�Ѻ�.h : ��ũ�Ѻ� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C��ũ�Ѻ�App:
// �� Ŭ������ ������ ���ؼ��� ��ũ�Ѻ�.cpp�� �����Ͻʽÿ�.
//

class C��ũ�Ѻ�App : public CWinAppEx
{
public:
	C��ũ�Ѻ�App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ũ�Ѻ�App theApp;
