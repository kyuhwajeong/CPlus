//
// HelloClient.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

// ATL �н�
// http://seungngil.tistory.com/entry/%EC%A0%9C-3%EA%B0%95COM-ATLActive-Template-Library-%EC%98%88%EC%A0%9C-%EB%94%B0%EB%9D%BC%ED%95%98%EA%B8%B0

#include "stdafx.h"
#include "wctype.h"
#include "locale.h"
//#import "progid:HelloServer.Hello.1" no_namespace
#import "..\HelloServer\Debug\HelloServer.tlb" no_namespace

//using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	try {
		IHelloPtr pIHello(__uuidof(Hello));
		_wsetlocale(LC_ALL, L"korean");
		wchar_t * message = NULL;
		wchar_t * name;
		wchar_t buffer[256];
		cout << "�̸��� �Է��ϼ��� : " ;
		//cin >> buffer;
		wscanf(L"%s", buffer);
		name = (wchar_t *)buffer;

		//pIHello->sayHello(name, &message);
		pIHello->sayHello((unsigned short *)name, (unsigned short **)&message);
		//wsetlocale(LC_ALL, _T("korean"));
		//_tprintf("�ѱ�\n");
		wcout << (wchar_t *)message << endl;
		//wprintf(L"%s\n", message);
		//cout << (wcharmessage << endl;
		/*
		cout << "�̸��� �����մϴ�." << endl;
		pIHello->name = _com_util::ConvertStringToBSTR((char*)name);
		cout << "�̸��� �н��ϴ�." << endl;
		name = (wchar_t*)_com_util::ConvertBSTRToString(pIHello->name);
		cout << "�о�� �̸� : " << (char*)name << endl;
		*/
		::CoTaskMemFree((LPVOID)message);
	}
	catch (_com_error& e) {
		cout << e.ErrorMessage() << endl;
	}

	::CoUninitialize();
	return 0;
}

