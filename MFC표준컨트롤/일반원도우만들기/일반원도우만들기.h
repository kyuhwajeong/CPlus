
// �Ϲݿ����츸���.h : �Ϲݿ����츸��� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C�Ϲݿ����츸���App:
// �� Ŭ������ ������ ���ؼ��� �Ϲݿ����츸���.cpp�� �����Ͻʽÿ�.
//

class C�Ϲݿ����츸���App : public CWinAppEx
{
public:
	C�Ϲݿ����츸���App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�Ϲݿ����츸���App theApp;
