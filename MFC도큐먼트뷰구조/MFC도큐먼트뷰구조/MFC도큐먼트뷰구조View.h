
// MFC��ť��Ʈ�䱸��View.h : CMFC��ť��Ʈ�䱸��View Ŭ������ �������̽�
//

#pragma once


class CMFC��ť��Ʈ�䱸��View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFC��ť��Ʈ�䱸��View();
	DECLARE_DYNCREATE(CMFC��ť��Ʈ�䱸��View)

// Ư���Դϴ�.
public:
	CMFC��ť��Ʈ�䱸��Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMFC��ť��Ʈ�䱸��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC��ť��Ʈ�䱸��View.cpp�� ����� ����
inline CMFC��ť��Ʈ�䱸��Doc* CMFC��ť��Ʈ�䱸��View::GetDocument() const
   { return reinterpret_cast<CMFC��ť��Ʈ�䱸��Doc*>(m_pDocument); }
#endif

