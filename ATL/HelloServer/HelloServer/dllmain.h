// dllmain.h : 모듈 클래스의 선언입니다.

class CHelloServerModule : public ATL::CAtlDllModuleT< CHelloServerModule >
{
public :
	DECLARE_LIBID(LIBID_HelloServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_HELLOSERVER, "{503B21CA-4197-4242-A1FE-847FCCC4466C}")
};

extern class CHelloServerModule _AtlModule;
