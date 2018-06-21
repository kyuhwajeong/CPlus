// UseOdbc.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "windows.h"
#include "iostream"


using namespace std;

#include "sql.h"
#include "sqlext.h"

//SQL OCBC Conn
SQLHENV hEnv;
SQLHDBC hDbc;
SQLHSTMT hStmt;

SQLWCHAR *ODBC_Name = (SQLWCHAR*)L"mysql_odbc";
SQLWCHAR *ODBC_ID = (SQLWCHAR*)L"root";
SQLWCHAR *ODBC_PW = (SQLWCHAR*)L"1q2w3e4r";

bool DBConnect();
void DBDisConnect();
bool DBExcuteSQL();

int _tmain(int argc, _TCHAR* argv[])
{
	if (DBConnect() == false)
	{
		cout << "접속에러종료!" << endl;
		exit(1);
	}

	if (DBExcuteSQL() == false)
	{
		cout << "ExcuteQuery Error!" << endl;
		exit(1);
	}


	DBDisConnect();
	return 0;
}

// CDBC사용 핸들 할당 및 SQL접속 부분
bool DBConnect()
{
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS)
		return false;

	if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)
		return false;

	if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS)
		return false;

	if (SQLConnect(hDbc, ODBC_Name, SQL_NTS, ODBC_ID, SQL_NTS, ODBC_PW, SQL_NTS) != SQL_SUCCESS)
		return false;

	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) != SQL_SUCCESS)
		return false;

	return true;
}

void DBDisConnect()
{
	if (hStmt) SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	if (hStmt) SQLDisconnect(hDbc);
	if (hStmt) SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
	if (hStmt) SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

}

// 해당되는 쿼리 구문 실행 및 출력
bool DBExcuteSQL()
{
	int member_id;
	SQLWCHAR member_name[50];
	SQLINTEGER imember_id,imember_name;


	SQLBindCol(hStmt, 1, SQL_INTEGER, &member_id, sizeof(member_id), &imember_id);
	SQLBindCol(hStmt, 2, SQL_WCHAR, member_name, sizeof(member_name), &imember_name);

	if (SQLExecDirect(hStmt, (SQLWCHAR*)L"select member_id, member_name from member", SQL_NTS) != SQL_SUCCESS)
	{
		return false;
	}

	char strMultibyte[50] = { 0, };

	while (SQLFetch(hStmt) != SQL_NO_DATA)
	{
		int len = WideCharToMultiByte(CP_ACP, 0, member_name, -1, NULL, 0, NULL, NULL);
		WideCharToMultiByte(CP_ACP, 0, member_name, -1, strMultibyte, len, NULL, NULL);

		printf("%d %s\n", member_id, strMultibyte);
	}

	if (hStmt) SQLCloseCursor(hStmt);

	return true;
}