#pragma once
#include <afx.h>
// CMyData 명령 대상입니다.

class CMyData : public CObject
{
	DECLARE_SERIAL(CMyData)
public:
	CMyData();
	CMyData(CString &str, COLORREF &color){ m_str = str; m_color = color; }
	virtual ~CMyData();
	void Serialize(CArchive& ar);
	CString m_str;
	COLORREF m_color;
};


