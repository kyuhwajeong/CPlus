
// ����Ʈ��Doc.h : C����Ʈ��Doc Ŭ������ �������̽�
//


#pragma once
struct MYITEM
{
	CString name;
	int price;
	int quantity;
};

const int NUMITEM = 100; // 100���� �׸�

class C����Ʈ��Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	C����Ʈ��Doc();
	DECLARE_DYNCREATE(C����Ʈ��Doc)

// Ư���Դϴ�.
public:
	MYITEM m_item[NUMITEM];
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
	virtual ~C����Ʈ��Doc();
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
