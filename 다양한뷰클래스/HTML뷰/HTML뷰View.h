
// HTML��View.h : CHTML��View Ŭ������ �������̽�
//

#pragma once


class CHTML��View : public CHtmlView
{
protected: // serialization������ ��������ϴ�.
	CHTML��View();
	DECLARE_DYNCREATE(CHTML��View)

// Ư���Դϴ�.
public:
	CHTML��Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CHTML��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // HTML��View.cpp�� ����� ����
inline CHTML��Doc* CHTML��View::GetDocument() const
   { return reinterpret_cast<CHTML��Doc*>(m_pDocument); }
#endif

