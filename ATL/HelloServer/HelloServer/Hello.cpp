// Hello.cpp : CHello�� �����Դϴ�.

#include "stdafx.h"
#include "Hello.h"


// CHello



STDMETHODIMP CHello::sayHello(wchar_t** message, wchar_t** name)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	wchar_t * buffer = (wchar_t *) ::CoTaskMemAlloc(256);
	if (buffer == NULL) return E_FAIL;
	::wsprintf(buffer, L"%s ���� �ѱ�\n", name);
	*message = (wchar_t*)buffer;
	return S_OK;
}
