// program.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

