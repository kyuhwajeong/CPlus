
// MFC��ť��Ʈ�䱸��.h : MFC��ť��Ʈ�䱸�� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFC��ť��Ʈ�䱸��App:
// �� Ŭ������ ������ ���ؼ��� MFC��ť��Ʈ�䱸��.cpp�� �����Ͻʽÿ�.
//

class CMFC��ť��Ʈ�䱸��App : public CWinAppEx
{
public:
	CMFC��ť��Ʈ�䱸��App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC��ť��Ʈ�䱸��App theApp;
