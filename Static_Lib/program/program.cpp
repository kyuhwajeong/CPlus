// program.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include "..\Static_Lib\Plus.h"

using namespace std;
#pragma comment(lib, "Static_Lib.lib")
int _tmain(int argc, _TCHAR* argv[])
{
	int a = 10, b = 5;
	cout << Plus(a, b) << endl;
	return 0;
}

