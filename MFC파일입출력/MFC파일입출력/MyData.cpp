// MyData.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFC���������.h"
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


// CMyData ��� �Լ�
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
