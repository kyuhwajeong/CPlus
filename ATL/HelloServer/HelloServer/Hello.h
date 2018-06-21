// Hello.h : CHello�� �����Դϴ�.

#pragma once
#include "resource.h"       // �� ��ȣ�Դϴ�.



#include "HelloServer_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "���� ������ COM ��ü�� ��ü DCOM ������ �������� �ʴ� Windows Mobile �÷����� ���� Windows CE �÷������� ����� �������� �ʽ��ϴ�. ATL�� ���� ������ COM ��ü�� ������ �����ϰ� ���� ������ COM ��ü ������ ����� �� �ֵ��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA�� �����Ͻʽÿ�. rgs ������ ������ ���� DCOM Windows CE�� �ƴ� �÷������� �����Ǵ� ������ ������ ���̹Ƿ� 'Free'�� �����Ǿ� �ֽ��ϴ�."
#endif

using namespace ATL;


// CHello

class ATL_NO_VTABLE CHello :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHello, &CLSID_Hello>,
	public IHello
{
public:
	CHello()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HELLO2)


BEGIN_COM_MAP(CHello)
	COM_INTERFACE_ENTRY(IHello)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(sayHello)(wchar_t** message, wchar_t** name);
};

OBJECT_ENTRY_AUTO(__uuidof(Hello), CHello)
