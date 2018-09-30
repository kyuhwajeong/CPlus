
// MFC���������Doc.cpp : CMFC���������Doc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFC���������.h"
#endif

#include "MFC���������Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC���������Doc

IMPLEMENT_DYNCREATE(CMFC���������Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFC���������Doc, CDocument)
END_MESSAGE_MAP()


// CMFC���������Doc ����/�Ҹ�

CMFC���������Doc::CMFC���������Doc()
#ifdef _NOT_SERIAL_CLS_
	: m_str(_T(""))
#endif
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMFC���������Doc::~CMFC���������Doc()
{
}

BOOL CMFC���������Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
#ifdef _NOT_SERIAL_CLS_
	m_str = "";
	m_color = RGB(255, 0, 0);
#else

#endif
	return TRUE;
}




// CMFC���������Doc serialization

void CMFC���������Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
#ifdef _NOT_SERIAL_CLS_
		ar << m_str << m_color;
#else
		m_data.Serialize(ar);
#endif
	}
	else
	{
#ifdef _NOT_SERIAL_CLS_
		ar >> m_str >> m_color;
#else
		m_data.Serialize(ar);
#endif
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMFC���������Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CMFC���������Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFC���������Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFC���������Doc ����

#ifdef _DEBUG
void CMFC���������Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC���������Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC���������Doc ���
