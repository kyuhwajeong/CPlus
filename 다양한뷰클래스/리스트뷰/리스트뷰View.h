
// ����Ʈ��View.h : C����Ʈ��View Ŭ������ �������̽�
//

#pragma once


class C����Ʈ��View : public CListView
{
protected: // serialization������ ��������ϴ�.
	C����Ʈ��View();
	DECLARE_DYNCREATE(C����Ʈ��View)

// Ư���Դϴ�.
public:
	C����Ʈ��Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~C����Ʈ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnIconview();
	afx_msg void OnSmalliconview();
	afx_msg void OnListview();
	afx_msg void OnReportview();
};

#ifndef _DEBUG  // ����Ʈ��View.cpp�� ����� ����
inline C����Ʈ��Doc* C����Ʈ��View::GetDocument() const
   { return reinterpret_cast<C����Ʈ��Doc*>(m_pDocument); }
#endif

