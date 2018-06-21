

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Jun 21 23:32:18 2018
 */
/* Compiler settings for HelloServer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __HelloServer_i_h__
#define __HelloServer_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHello_FWD_DEFINED__
#define __IHello_FWD_DEFINED__
typedef interface IHello IHello;

#endif 	/* __IHello_FWD_DEFINED__ */


#ifndef __Hello_FWD_DEFINED__
#define __Hello_FWD_DEFINED__

#ifdef __cplusplus
typedef class Hello Hello;
#else
typedef struct Hello Hello;
#endif /* __cplusplus */

#endif 	/* __Hello_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IHello_INTERFACE_DEFINED__
#define __IHello_INTERFACE_DEFINED__

/* interface IHello */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IHello;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B831B149-A001-4A5F-A262-F0B14222DE89")
    IHello : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE sayHello( 
            /* [in] */ wchar_t **message,
            /* [out] */ wchar_t **name) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHelloVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHello * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHello * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHello * This);
        
        HRESULT ( STDMETHODCALLTYPE *sayHello )( 
            IHello * This,
            /* [in] */ wchar_t **message,
            /* [out] */ wchar_t **name);
        
        END_INTERFACE
    } IHelloVtbl;

    interface IHello
    {
        CONST_VTBL struct IHelloVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHello_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHello_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHello_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHello_sayHello(This,message,name)	\
    ( (This)->lpVtbl -> sayHello(This,message,name) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHello_INTERFACE_DEFINED__ */



#ifndef __HelloServerLib_LIBRARY_DEFINED__
#define __HelloServerLib_LIBRARY_DEFINED__

/* library HelloServerLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_HelloServerLib;

EXTERN_C const CLSID CLSID_Hello;

#ifdef __cplusplus

class DECLSPEC_UUID("8F0AA2B3-2F07-49AA-A79F-C8CA16455D8A")
Hello;
#endif
#endif /* __HelloServerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


