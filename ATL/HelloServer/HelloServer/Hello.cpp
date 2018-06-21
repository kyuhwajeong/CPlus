// Hello.cpp : CHello의 구현입니다.

#include "stdafx.h"
#include "Hello.h"


// CHello



STDMETHODIMP CHello::sayHello(wchar_t** message, wchar_t** name)
{
	// TODO: 여기에 구현 코드를 추가합니다.
	wchar_t * buffer = (wchar_t *) ::CoTaskMemAlloc(256);
	if (buffer == NULL) return E_FAIL;
	::wsprintf(buffer, L"%s 나는 한글\n", name);
	*message = (wchar_t*)buffer;
	return S_OK;
}
