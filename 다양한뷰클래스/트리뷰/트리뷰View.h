
// Ʈ����View.h : CƮ����View Ŭ������ �������̽�
//

#pragma once


class CƮ����View : public CTreeView
{
protected: // serialization������ ��������ϴ�.
	CƮ����View();
	DECLARE_DYNCREATE(CƮ����View)

// Ư���Դϴ�.
public:
	CƮ����Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CƮ����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnTvnDeleteitem(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTestDeleteitem();
};

#ifndef _DEBUG  // Ʈ����View.cpp�� ����� ����
inline CƮ����Doc* CƮ����View::GetDocument() const
   { return reinterpret_cast<CƮ����Doc*>(m_pDocument); }
#endif

