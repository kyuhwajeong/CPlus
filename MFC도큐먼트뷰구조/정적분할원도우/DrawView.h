#pragma once


// CDrawView ���Դϴ�.

class CDrawView : public CView
{
	DECLARE_DYNCREATE(CDrawView)

protected:
	CDrawView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CDrawView();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


