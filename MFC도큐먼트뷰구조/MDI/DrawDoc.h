#pragma once

// CDrawDoc �����Դϴ�.

class CDrawDoc : public CDocument
{
	DECLARE_DYNCREATE(CDrawDoc)

public:
	CDrawDoc();
	virtual ~CDrawDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // ���� ��/����� ���� �����ǵǾ����ϴ�.
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
};
