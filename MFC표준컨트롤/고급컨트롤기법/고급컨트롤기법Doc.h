
// �����Ʈ�ѱ��Doc.h : C�����Ʈ�ѱ��Doc Ŭ������ �������̽�
//


#pragma once


class C�����Ʈ�ѱ��Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	C�����Ʈ�ѱ��Doc();
	DECLARE_DYNCREATE(C�����Ʈ�ѱ��Doc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~C�����Ʈ�ѱ��Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
