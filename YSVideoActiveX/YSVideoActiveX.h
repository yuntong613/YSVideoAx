#pragma once

// YSVideoActiveX.h : YSVideoActiveX.DLL ����ͷ�ļ�

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������
#include "YSVideoActiveX_i.h"


// CYSVideoActiveXApp : �й�ʵ�ֵ���Ϣ������� YSVideoActiveX.cpp��

class CYSVideoActiveXApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

