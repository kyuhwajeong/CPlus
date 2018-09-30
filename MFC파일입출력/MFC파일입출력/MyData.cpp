// MyData.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFC파일입출력.h"
#include "MyData.h"


// CMyData
IMPLEMENT_SERIAL(CMyData, CObject, 1)

CMyData::CMyData()
	: m_str(_T(""))
{
}

CMyData::~CMyData()
{
}


// CMyData 멤버 함수
void CMyData::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << m_str << m_color;
	}
	else
	{	
		ar >> m_str >> m_color;
	}
}
