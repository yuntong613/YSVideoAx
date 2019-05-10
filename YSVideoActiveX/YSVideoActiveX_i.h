

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu May 12 16:36:18 2016
 */
/* Compiler settings for YSVideoActiveX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
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


#ifndef __YSVideoActiveX_i_h__
#define __YSVideoActiveX_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DYSVideoActiveX_FWD_DEFINED__
#define ___DYSVideoActiveX_FWD_DEFINED__
typedef interface _DYSVideoActiveX _DYSVideoActiveX;
#endif 	/* ___DYSVideoActiveX_FWD_DEFINED__ */


#ifndef ___DYSVideoActiveXEvents_FWD_DEFINED__
#define ___DYSVideoActiveXEvents_FWD_DEFINED__
typedef interface _DYSVideoActiveXEvents _DYSVideoActiveXEvents;
#endif 	/* ___DYSVideoActiveXEvents_FWD_DEFINED__ */


#ifndef __YSVideoActiveX_FWD_DEFINED__
#define __YSVideoActiveX_FWD_DEFINED__

#ifdef __cplusplus
typedef class YSVideoActiveX YSVideoActiveX;
#else
typedef struct YSVideoActiveX YSVideoActiveX;
#endif /* __cplusplus */

#endif 	/* __YSVideoActiveX_FWD_DEFINED__ */


/* header files for imported files */
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __YSVideoActiveXLib_LIBRARY_DEFINED__
#define __YSVideoActiveXLib_LIBRARY_DEFINED__

/* library YSVideoActiveXLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_YSVideoActiveXLib;

#ifndef ___DYSVideoActiveX_DISPINTERFACE_DEFINED__
#define ___DYSVideoActiveX_DISPINTERFACE_DEFINED__

/* dispinterface _DYSVideoActiveX */
/* [uuid] */ 


EXTERN_C const IID DIID__DYSVideoActiveX;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A8501FB9-7F99-43F7-993D-81002B14E070")
    _DYSVideoActiveX : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DYSVideoActiveXVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DYSVideoActiveX * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DYSVideoActiveX * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DYSVideoActiveX * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DYSVideoActiveX * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DYSVideoActiveX * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DYSVideoActiveX * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DYSVideoActiveX * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DYSVideoActiveXVtbl;

    interface _DYSVideoActiveX
    {
        CONST_VTBL struct _DYSVideoActiveXVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DYSVideoActiveX_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DYSVideoActiveX_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DYSVideoActiveX_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DYSVideoActiveX_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DYSVideoActiveX_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DYSVideoActiveX_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DYSVideoActiveX_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DYSVideoActiveX_DISPINTERFACE_DEFINED__ */


#ifndef ___DYSVideoActiveXEvents_DISPINTERFACE_DEFINED__
#define ___DYSVideoActiveXEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DYSVideoActiveXEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DYSVideoActiveXEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B4C1259F-078E-4C2C-AD45-9FC35BD7B78C")
    _DYSVideoActiveXEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DYSVideoActiveXEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DYSVideoActiveXEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DYSVideoActiveXEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DYSVideoActiveXEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DYSVideoActiveXEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DYSVideoActiveXEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DYSVideoActiveXEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DYSVideoActiveXEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DYSVideoActiveXEventsVtbl;

    interface _DYSVideoActiveXEvents
    {
        CONST_VTBL struct _DYSVideoActiveXEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DYSVideoActiveXEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DYSVideoActiveXEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DYSVideoActiveXEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DYSVideoActiveXEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DYSVideoActiveXEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DYSVideoActiveXEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DYSVideoActiveXEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DYSVideoActiveXEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_YSVideoActiveX;

#ifdef __cplusplus

class DECLSPEC_UUID("E4082E53-370D-49F6-8DFD-900EFD60AA34")
YSVideoActiveX;
#endif
#endif /* __YSVideoActiveXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


