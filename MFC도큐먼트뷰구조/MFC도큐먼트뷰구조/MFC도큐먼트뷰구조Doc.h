
// MFC��ť��Ʈ�䱸��Doc.h : CMFC��ť��Ʈ�䱸��Doc Ŭ������ �������̽�
//


#pragma once


class CMFC��ť��Ʈ�䱸��Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMFC��ť��Ʈ�䱸��Doc();
	DECLARE_DYNCREATE(CMFC��ť��Ʈ�䱸��Doc)

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
	virtual ~CMFC��ť��Ʈ�䱸��Doc();
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
