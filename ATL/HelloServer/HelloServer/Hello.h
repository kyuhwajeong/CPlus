// Hello.h : CHello의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.



#include "HelloServer_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "단일 스레드 COM 개체는 전체 DCOM 지원을 포함하지 않는 Windows Mobile 플랫폼과 같은 Windows CE 플랫폼에서 제대로 지원되지 않습니다. ATL이 단일 스레드 COM 개체의 생성을 지원하고 단일 스레드 COM 개체 구현을 사용할 수 있도록 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA를 정의하십시오. rgs 파일의 스레딩 모델은 DCOM Windows CE가 아닌 플랫폼에서 지원되는 유일한 스레딩 모델이므로 'Free'로 설정되어 있습니다."
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
