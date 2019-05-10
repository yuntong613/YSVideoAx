// YSVideoActiveXCtrl.cpp : CYSVideoActiveXCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "YSVideoActiveX.h"
#include "YSVideoActiveXCtrl.h"
#include "YSVideoActiveXPropPage.h"
#include "afxdialogex.h"
#include "OpenSDKMgr.h"
#include "opensslwrap/sslApi.h"
#include <comutil.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define SELECTED_COLOR RGB(0,0,128)

IMPLEMENT_DYNCREATE(CYSVideoActiveXCtrl, COleControl)



// 消息映射

BEGIN_MESSAGE_MAP(CYSVideoActiveXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(1001,OnClickOne)
	ON_BN_CLICKED(2001,OnClick1Four)
	ON_BN_CLICKED(2002,OnClick2Four)
	ON_BN_CLICKED(2003,OnClick3Four)
	ON_BN_CLICKED(2004,OnClick4Four)
	ON_WM_PAINT()
END_MESSAGE_MAP()

//***************************************************************add begin
BEGIN_INTERFACE_MAP( CYSVideoActiveXCtrl, COleControl )
	INTERFACE_PART(CYSVideoActiveXCtrl, IID_IObjectSafety, ObjSafe)
END_INTERFACE_MAP()
//***************************************************************add end


// 调度映射

BEGIN_DISPATCH_MAP(CYSVideoActiveXCtrl, COleControl)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "InitLib", dispidInitLib, InitLib, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "FiniLib", dispidFiniLib, FiniLib, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "AllocSession", dispidAllocSession, AllocSession, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "FreeSession", dispidFreeSession, FreeSession, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "StartRealPlay", dispidStartRealPlay, StartRealPlay, VT_EMPTY, VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "StopRealPlay", dispidStopRealPlay, StopRealPlay, VT_EMPTY, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "StartPlayBack", dispidStartPlayBack, StartPlayBack, VT_I4, VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "PlayBackResume", dispidPlayBackResume, PlayBackResume, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "PlayBackPause", dispidPlayBackPause, PlayBackPause, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "StopPlayBack", dispidStopPlayBack, StopPlayBack, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "StartSearch", dispidStartSearch, StartSearch, VT_I4, VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "GetOSDTime", dispidGetOSDTime, GetOSDTime, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "OpenSound", dispidOpenSound, OpenSound, VT_UNKNOWN, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "CloseSound", dispidCloseSound, CloseSound, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "GetVolume", dispidGetVolume, GetVolume, VT_UI2, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "CapturePicture", dispidCapturePicture, CapturePicture, VT_I4, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "Mid_Login", dispidMid_Login, Mid_Login, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "Mid_Device_Add", dispidMid_Device_Add, Mid_Device_Add, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "Mid_Device_Oper", dispidMid_Device_Oper, Mid_Device_Oper, VT_I4, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "Data_GetDevList", dispidData_GetDevList, Data_GetDevList, VT_BSTR, VTS_BSTR VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "HttpSendWithWait", dispidHttpSendWithWait, HttpSendWithWait, VT_BSTR, VTS_BSTR VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "ShowStyle", dispidShowStyle, ShowStyle, VT_EMPTY, VTS_I4)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "SetVolume", dispidSetVolume, SetVolume, VT_I4, VTS_BSTR VTS_UI2)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "Data_GetAlarmList", dispidData_GetAlarmList, Data_GetAlarmList, VT_BSTR, VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "Data_Free", dispidData_Free, Data_Free, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "Alarm_StartRecv", dispidAlarm_StartRecv, Alarm_StartRecv, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "Alarm_StopRecv", dispidAlarm_StopRecv, Alarm_StopRecv, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "PTZCtrl", dispidPTZCtrl, PTZCtrl, VT_I4, VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "Alarm_SetMsgCallBack", dispidAlarm_SetMsgCallBack, Alarm_SetMsgCallBack, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "DevDefence", dispidDevDefence, DevDefence, VT_I4, VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "StartVoiceTalk", dispidStartVoiceTalk, StartVoiceTalk, VT_I4, VTS_BSTR VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "StopVoiceTalk", dispidStopVoiceTalk, StopVoiceTalk, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "Data_DeleteDevice", dispidData_DeleteDevice, Data_DeleteDevice, VT_I4, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "UpdateCameraInfoToLocal", dispidUpdateCameraInfoToLocal, UpdateCameraInfoToLocal, VT_I4, VTS_BSTR VTS_BSTR VTS_PI2)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "Data_GetDeviceInfo", dispidData_GetDeviceInfo, Data_GetDeviceInfo, VT_BSTR, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "Data_SetAlarmRead", dispidData_SetAlarmRead, Data_SetAlarmRead, VT_I4, VTS_BSTR VTS_BSTR)	
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "GetFocusWnd", dispidGetFocusWnd, GetFocusWnd, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CYSVideoActiveXCtrl, "ResetWindow", dispidResetWindow, ResetWindow, VT_EMPTY, VTS_UI2)
END_DISPATCH_MAP()



// 事件映射

BEGIN_EVENT_MAP(CYSVideoActiveXCtrl, COleControl)

	EVENT_CUSTOM_ID("OpenSDK_MessageTold", eventidOpenSDK_MessageTold, OpenSDK_MessageTold, VTS_BSTR VTS_UI4 VTS_UI4 VTS_BSTR VTS_PI4)
	EVENT_CUSTOM_ID("Alarm_Message", eventidAlarm_Message, Alarm_Message, VTS_BSTR VTS_BSTR VTS_BSTR)
	EVENT_CUSTOM_ID("Publish_Message", eventidPublish_Message, Publish_Message, VTS_BSTR)
END_EVENT_MAP()



// 属性页

// TODO: 按需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CYSVideoActiveXCtrl, 1)
	PROPPAGEID(CYSVideoActiveXPropPage::guid)
END_PROPPAGEIDS(CYSVideoActiveXCtrl)



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CYSVideoActiveXCtrl, "YSVIDEOACTIVEX.YSVideoActiveXCtrl.1",
	0xe4082e53, 0x370d, 0x49f6, 0x8d, 0xfd, 0x90, 0xe, 0xfd, 0x60, 0xaa, 0x34)



// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CYSVideoActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)



// 接口 ID

const IID IID_DYSVideoActiveX = { 0xA8501FB9, 0x7F99, 0x43F7, { 0x99, 0x3D, 0x81, 0x0, 0x2B, 0x14, 0xE0, 0x70 } };
const IID IID_DYSVideoActiveXEvents = { 0xB4C1259F, 0x78E, 0x4C2C, { 0xAD, 0x45, 0x9F, 0xC3, 0x5B, 0xD7, 0xB7, 0x8C } };


// 控件类型信息

static const DWORD _dwYSVideoActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CYSVideoActiveXCtrl, IDS_YSVIDEOACTIVEX, _dwYSVideoActiveXOleMisc)



// CYSVideoActiveXCtrl::CYSVideoActiveXCtrlFactory::UpdateRegistry -
// 添加或移除 CYSVideoActiveXCtrl 的系统注册表项

BOOL CYSVideoActiveXCtrl::CYSVideoActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_YSVIDEOACTIVEX,
			IDB_YSVIDEOACTIVEX,
			afxRegApartmentThreading,
			_dwYSVideoActiveXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CYSVideoActiveXCtrl::CYSVideoActiveXCtrl - 构造函数

CYSVideoActiveXCtrl::CYSVideoActiveXCtrl()
	: m_nFocusWnd(0)
{
	InitializeIIDs(&IID_DYSVideoActiveX, &IID_DYSVideoActiveXEvents);
	// TODO: 在此初始化控件的实例数据。

	m_hbrBk = ::CreateSolidBrush(RGB(0,0,0));
	m_hbrBkSelected = ::CreateSolidBrush(SELECTED_COLOR);
	m_nStyle = 0;
	CStatic* pStatic = NULL;
	for (int i=0; i<9;i++)
	{
		pStatic = new CStatic;
		m_WndArray.Add(pStatic);
	}
}



// CYSVideoActiveXCtrl::~CYSVideoActiveXCtrl - 析构函数

CYSVideoActiveXCtrl::~CYSVideoActiveXCtrl()
{
	// TODO: 在此清理控件的实例数据。
	DeleteObject(m_hbrBk);
	DeleteObject(m_hbrBkSelected);
	CloseAllStatic();
	CStatic* pStatic = NULL;
	for (int i=0; i<9;i++)
	{
		pStatic = (CStatic*)m_WndArray.GetAt(i);
		if(pStatic)
			delete pStatic;
		pStatic = NULL;
	}
	m_WndArray.RemoveAll();
	m_mapPlaying.RemoveAll();
}



// CYSVideoActiveXCtrl::OnDraw - 绘图函数

void CYSVideoActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: 用您自己的绘图代码替换下面的代码。
// 	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
// 	pdc->Ellipse(rcBounds);
}



// CYSVideoActiveXCtrl::DoPropExchange - 持久性支持

void CYSVideoActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}



// CYSVideoActiveXCtrl::OnResetState - 将控件重置为默认状态

void CYSVideoActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO: 在此重置任意其他控件状态。
}



// CYSVideoActiveXCtrl::AboutBox - 向用户显示“关于”框

void CYSVideoActiveXCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_YSVIDEOACTIVEX);
	dlgAbout.DoModal();
}

// CYSVideoActiveXCtrl 消息处理程序

void CALLBACK CYSVideoActiveXCtrl::MY_OpenSDK_MessageHandler(const char* szSessionId, unsigned int iMsgType, unsigned int iErrorCode,const char *pMessageInfo, void *pUser)
{
	CYSVideoActiveXCtrl* pCtrl = (CYSVideoActiveXCtrl*)pUser;
	pCtrl->OpenSDK_MessageTold(szSessionId,iMsgType,iErrorCode,pMessageInfo);
}

void CALLBACK CYSVideoActiveXCtrl::Alarm_MessageHandler(const char* szCameraId,const char* szContent,const char* szAlarmTime,void* pUser)
{
	CYSVideoActiveXCtrl* pCtrl = (CYSVideoActiveXCtrl*)pUser;
	pCtrl->Alarm_Message(szCameraId,szContent,szAlarmTime);
}

void CALLBACK CYSVideoActiveXCtrl::Publish_MessageHandler(const char* szContent, void* pUser)
{
	CYSVideoActiveXCtrl* pCtrl = (CYSVideoActiveXCtrl*)pUser;
	pCtrl->Publish_Message(szContent);
}

LONG CYSVideoActiveXCtrl::InitLib(LPCTSTR strAppKey)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int iRet = OpenSDKMgr::GetInstance()->InitLib(strAppKey);

	return iRet;
}


LONG CYSVideoActiveXCtrl::FiniLib(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int iRet = OpenSDKMgr::GetInstance()->FiniLib();
	return iRet;
}


BSTR CYSVideoActiveXCtrl::AllocSession(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	int iRet = OpenSDKMgr::GetInstance()->AllocSession(MY_OpenSDK_MessageHandler,this,strResult);
	return strResult.AllocSysString();
}


LONG CYSVideoActiveXCtrl::FreeSession(LPCTSTR strSession)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	int iRet = OpenSDKMgr::GetInstance()->FreeSession(strSession);
	return iRet;
}


LONG CYSVideoActiveXCtrl::StartRealPlay(LPCTSTR strSessionId, LONG WindowNumber, LPCTSTR strCameraId, LPCTSTR strAccessToken, LONG iVideoLevel, LPCTSTR strSafeKey, LPCTSTR strAppKey)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HWND pWnd = NULL;
	switch(m_nStyle)
	{
	case 1:
		{
			CStatic* pStatic = (CStatic*)m_WndArray.GetAt(0);
			if(pStatic && WindowNumber==1)
			{
				pWnd = pStatic->GetSafeHwnd();
			}
		}
		break;
	case 4:
		{
			CStatic* pStatic1 = (CStatic*)m_WndArray.GetAt(0);
			CStatic* pStatic2 = (CStatic*)m_WndArray.GetAt(1);
			CStatic* pStatic3 = (CStatic*)m_WndArray.GetAt(2);
			CStatic* pStatic4 = (CStatic*)m_WndArray.GetAt(3);
			if(pStatic1 && WindowNumber ==1)
				pWnd = pStatic1->GetSafeHwnd();
			else if(pStatic2 && WindowNumber==2)
				pWnd = pStatic2->GetSafeHwnd();
			else if(pStatic3 && WindowNumber==3)
				pWnd = pStatic3->GetSafeHwnd();
			else if(pStatic4 && WindowNumber==4)
				pWnd = pStatic4->GetSafeHwnd();
		}
		break;
	case 9:
		break;
	default:
		break;
	}
	if(pWnd==NULL)
		return -1;

	CString strWndNumber;
	strWndNumber.Format("%d",WindowNumber);
	m_mapPlaying.SetAt(strWndNumber,strSessionId);

	int iRet = OpenSDKMgr::GetInstance()->StartRealPlay(strSessionId,pWnd,strCameraId,strAccessToken,iVideoLevel,strSafeKey,strAppKey);
	return iRet;
}


LONG CYSVideoActiveXCtrl::StopRealPlay(LPCTSTR strSessionId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString strTemp = strSessionId;
	CString strWndNumber,strValue;
	POSITION nPos = m_mapPlaying.GetStartPosition();
	while(nPos)
	{
		m_mapPlaying.GetNextAssoc(nPos,strWndNumber,strValue);
		if(strValue==strSessionId)
			m_mapPlaying.RemoveKey(strWndNumber);
	}

	int iRet = OpenSDKMgr::GetInstance()->StopRealPlay(strSessionId);
	return iRet;
}


LONG CYSVideoActiveXCtrl::StartPlayBack(LPCTSTR strSessionId, LONG WindowNumber, LPCTSTR strCameraId, LPCTSTR strAccessToken, LPCTSTR strSafeKey, LPCTSTR strStartTime, LPCTSTR strStopTime, LPCTSTR strAppKey)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HWND pWnd = NULL;
	switch(m_nStyle)
	{
	case 1:
		{
			CStatic* pStatic = (CStatic*)m_WndArray.GetAt(0);
			if(pStatic && WindowNumber==1)
			{
				pWnd = pStatic->GetSafeHwnd();
			}
		}
		break;
	case 4:
		{
			CStatic* pStatic1 = (CStatic*)m_WndArray.GetAt(0);
			CStatic* pStatic2 = (CStatic*)m_WndArray.GetAt(1);
			CStatic* pStatic3 = (CStatic*)m_WndArray.GetAt(2);
			CStatic* pStatic4 = (CStatic*)m_WndArray.GetAt(3);
			if(pStatic1 && WindowNumber ==1)
				pWnd = pStatic1->GetSafeHwnd();
			else if(pStatic2 && WindowNumber==2)
				pWnd = pStatic2->GetSafeHwnd();
			else if(pStatic3 && WindowNumber==3)
				pWnd = pStatic3->GetSafeHwnd();
			else if(pStatic4 && WindowNumber==4)
				pWnd = pStatic4->GetSafeHwnd();
		}
		break;
	case 9:
		break;
	default:
		break;
	}
	if(pWnd==NULL)
		return -1;

	CString strWndNumber;
	strWndNumber.Format("%d",WindowNumber);
	m_mapPlaying.SetAt(strWndNumber,strSessionId);

	int iRet = OpenSDKMgr::GetInstance()->StartPlayBack(strSessionId,pWnd,strCameraId,strAccessToken,strSafeKey,strStartTime,strStopTime,strAppKey);
	return iRet;
}


LONG CYSVideoActiveXCtrl::PlayBackResume(LPCTSTR strSessionId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int iRet = OpenSDKMgr::GetInstance()->PlayBackResume(strSessionId);
	return iRet;
}


LONG CYSVideoActiveXCtrl::PlayBackPause(LPCTSTR strSessionId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int iRet = OpenSDKMgr::GetInstance()->PlayBackPause(strSessionId);
	return iRet;
}


LONG CYSVideoActiveXCtrl::StopPlayBack(LPCTSTR strSessionId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strTemp = strSessionId;
	CString strWndNumber,strValue;
	POSITION nPos = m_mapPlaying.GetStartPosition();
	while(nPos)
	{
		m_mapPlaying.GetNextAssoc(nPos,strWndNumber,strValue);
		if(strValue==strSessionId)
			m_mapPlaying.RemoveKey(strWndNumber);
	}

	int iRet = OpenSDKMgr::GetInstance()->StopPlayBack(strSessionId);
	return iRet;
}


LONG CYSVideoActiveXCtrl::StartSearch(LPCTSTR strSessionId, LPCTSTR strCameraId, LPCTSTR strAccessToken, LPCTSTR strStartTime, LPCTSTR strStopTime)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int iRet = OpenSDKMgr::GetInstance()->StartSearch(strSessionId,strCameraId,strAccessToken,strStartTime,strStopTime);
	return iRet;
}


BSTR CYSVideoActiveXCtrl::GetOSDTime(LPCTSTR strSessionId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	STREAM_TIME tmItem;
	ZeroMemory(&tmItem,sizeof(STREAM_TIME));

	int iRet = OpenSDKMgr::GetInstance()->GetOSDTime(strSessionId,&tmItem);
	CString strTime;
	strTime.Format("%04d-%02d-%02d %02d:%02d:%02d",tmItem.iYear,tmItem.iMonth,tmItem.iDay,tmItem.iHour,tmItem.iMinute,tmItem.iSecond);
	return strTime.AllocSysString();
}


LONG CYSVideoActiveXCtrl::OpenSound(LPCTSTR strSessionId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	int iRet = OpenSDKMgr::GetInstance()->OpenSound(strSessionId);
	return iRet;
}


LONG CYSVideoActiveXCtrl::CloseSound(LPCTSTR strSessionId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int iRet = OpenSDKMgr::GetInstance()->CloseSound(strSessionId);
	return iRet;
}


USHORT CYSVideoActiveXCtrl::GetVolume(LPCTSTR strSessionId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	USHORT iRet = OpenSDKMgr::GetInstance()->GetVolume(strSessionId);
	return iRet;
}


LONG CYSVideoActiveXCtrl::CapturePicture(LPCTSTR strSessionId, LPCTSTR strFileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int iRet = OpenSDKMgr::GetInstance()->CapturePicture(strSessionId,strFileName);
	return iRet;
}


BSTR CYSVideoActiveXCtrl::Mid_Login(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	char* pToken = NULL;
	int iLength  = 0; 
	int iRet = OpenSDKMgr::GetInstance()->Mid_Login(&pToken,&iLength);

	CString strResult; 
	strResult = CString(pToken);
	OpenSDKMgr::GetInstance()->Data_Free(pToken);

	return strResult.AllocSysString();
}


LONG CYSVideoActiveXCtrl::Mid_Device_Add(LPCTSTR szAccessToken)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int iRet = OpenSDKMgr::GetInstance()->Mid_Device_Add(szAccessToken);
	return iRet;
}


LONG CYSVideoActiveXCtrl::Mid_Device_Oper(LPCTSTR szAccessToken, LPCTSTR szDeviceId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int iRet = OpenSDKMgr::GetInstance()->Mid_Device_Oper(szAccessToken,szDeviceId);
	return iRet;
}


BSTR CYSVideoActiveXCtrl::Data_GetDevList(LPCTSTR strAccessToken, LONG iPageStart, LONG iPageSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	void* pRecv = NULL;
	int iLen = 0;
	int iRet = OpenSDKMgr::GetInstance()->Data_GetDevList(strAccessToken,iPageStart,iPageSize,&pRecv,&iLen);

	CString strResult;
	strResult = CString(static_cast<char*>(pRecv));
	OpenSDKMgr::GetInstance()->Data_Free(pRecv);

	return strResult.AllocSysString();
}


BSTR CYSVideoActiveXCtrl::HttpSendWithWait(LPCTSTR szUri, LPCTSTR szHeaderParam, LPCTSTR szBody)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	char* pRecv = NULL;
	int iLen = 0;
	int iRet = OpenSDKMgr::GetInstance()->HttpSendWithWait(szUri,szHeaderParam,szBody,&pRecv,&iLen);

	CString strResult;
	strResult = CString(pRecv);
	OpenSDKMgr::GetInstance()->Data_Free(pRecv);

	return strResult.AllocSysString();
}

int CYSVideoActiveXCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}


void CYSVideoActiveXCtrl::OnDestroy()
{

	COleControl::OnDestroy();
}

void CYSVideoActiveXCtrl::CloseAllStatic(void)
{
	switch(m_nStyle)
	{
	case 1:	
		{
			CStatic* pStatic = (CStatic*)m_WndArray.GetAt(0);
			if(pStatic->GetSafeHwnd())
				pStatic->DestroyWindow();
		}
		break;
	case 4:
		{
			CStatic* pStatic = NULL;
			for (int i=0;i<4;i++)
			{
				pStatic = (CStatic*)m_WndArray.GetAt(i);
				if(pStatic->GetSafeHwnd())
					pStatic->DestroyWindow();
			}
		}
		break;
	case 9:
		break;
	default:
		break;
	}
}

LONG CYSVideoActiveXCtrl::SetVolume(LPCTSTR strSessionId, USHORT uVolume)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	int nRet = OpenSDKMgr::GetInstance()->SetVolume(strSessionId,uVolume);
	return nRet;
}


BSTR CYSVideoActiveXCtrl::Data_GetAlarmList(LPCTSTR strAccessToken, LPCTSTR strCameraId, LPCTSTR strStartTime, LPCTSTR strEndTime, LONG iAlarmType, LONG iStatus, LONG iPageStart, LONG iPageSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	void *pRecv = NULL;
	int iLen = 0;
	int nRet = OpenSDKMgr::GetInstance()->Data_GetAlarmList(strAccessToken,strCameraId,strStartTime,strEndTime,(AlarmType)iAlarmType,iStatus,iPageStart,iPageSize,&pRecv,&iLen);

	CString strResult;
	strResult = CString(static_cast<char*>(pRecv));
	OpenSDKMgr::GetInstance()->Data_Free(pRecv);

	return strResult.AllocSysString();
}


LONG CYSVideoActiveXCtrl::Data_Free(BSTR pBuf)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	char* p =  _com_util::ConvertBSTRToString(pBuf);
	int nRet = OpenSDKMgr::GetInstance()->Data_Free(p);
	return nRet;
}


LONG CYSVideoActiveXCtrl::Alarm_StartRecv(LPCTSTR strAccessToken)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int nRet = OpenSDKMgr::GetInstance()->Alarm_StartRecv(strAccessToken);
	return nRet;
}


LONG CYSVideoActiveXCtrl::Alarm_StopRecv(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int nRet = OpenSDKMgr::GetInstance()->Alarm_StopRecv();
	return nRet;
}


LONG CYSVideoActiveXCtrl::PTZCtrl(LPCTSTR strSessionId, LPCTSTR strAccessToken, LPCTSTR strCameraId, LONG enCommand, LONG enAction, LONG iSpeed)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int nRet = OpenSDKMgr::GetInstance()->PTZCtrl(strSessionId,strAccessToken,strCameraId,(PTZCommand)enCommand,(PTZAction)enAction,iSpeed);
	return nRet;
}


LONG CYSVideoActiveXCtrl::Alarm_SetMsgCallBack(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int nRet = OpenSDKMgr::GetInstance()->Alarm_SetMsgCallBack(Alarm_MessageHandler,Publish_MessageHandler,this);
	return nRet;
}


LONG CYSVideoActiveXCtrl::DevDefence(LPCTSTR strSessionId, LPCTSTR strAccessToken, LPCTSTR strCameraId, LONG enType, LONG enStatus, LONG enActor)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	int nRet = OpenSDKMgr::GetInstance()->DevDefence(strSessionId,strAccessToken,strCameraId,(DefenceType)enType,(DefenceStatus)enStatus,(DefenceActor)enActor);
	return nRet;
}


LONG CYSVideoActiveXCtrl::StartVoiceTalk(LPCTSTR strSessionId, LPCTSTR strAccessToken, LPCTSTR strCameraId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int nRet = OpenSDKMgr::GetInstance()->StartVoiceTalk(strSessionId,strAccessToken,strCameraId);
	return nRet;
}


LONG CYSVideoActiveXCtrl::StopVoiceTalk(LPCTSTR strSessionId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int nRet = OpenSDKMgr::GetInstance()->StopVoiceTalk(strSessionId);
	return nRet;
}


LONG CYSVideoActiveXCtrl::Data_DeleteDevice(LPCTSTR szAccessToken, LPCTSTR szDeviceId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int nRet = OpenSDKMgr::GetInstance()->Data_DeleteDevice(szAccessToken,szDeviceId);
	return nRet;
}


LONG CYSVideoActiveXCtrl::UpdateCameraInfoToLocal(LPCTSTR szCameraId, LPCTSTR szAccessToken)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	int iisEncrypt = 0;
	bool bEncrypt = false;
	int nRet = OpenSDKMgr::GetInstance()->UpdateCameraInfoToLocal(szCameraId,szAccessToken,bEncrypt);
	if(bEncrypt)
		iisEncrypt = 1;
	else
		iisEncrypt = 0;

	return iisEncrypt;
}


BSTR CYSVideoActiveXCtrl::Data_GetDeviceInfo(LPCTSTR szAccessToken, LPCTSTR szDeviceSerial)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	void *pRecv = NULL;
	int iLen = 0;
	int nRet = OpenSDKMgr::GetInstance()->Data_GetDeviceInfo(szAccessToken,szDeviceSerial,&pRecv,&iLen);

	CString strResult;
	strResult = CString(static_cast<char*>(pRecv));
	OpenSDKMgr::GetInstance()->Data_Free(pRecv);

	return strResult.AllocSysString();
}


LONG CYSVideoActiveXCtrl::Data_SetAlarmRead(LPCTSTR szAccessToken, LPCTSTR szAlarmId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int nRet = OpenSDKMgr::GetInstance()->Data_SetAlarmRead(szAccessToken,szAlarmId);
	return nRet;
}

LONG CYSVideoActiveXCtrl::GetFocusWnd(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	return m_nFocusWnd;
}


////***************************************************************add begin

// IObjectSafety member functions

// Delegate AddRef, Release, QueryInterface

ULONG FAR EXPORT CYSVideoActiveXCtrl::XObjSafe::AddRef()
{
    METHOD_PROLOGUE(CYSVideoActiveXCtrl, ObjSafe)
	return pThis->ExternalAddRef();
}

ULONG FAR EXPORT CYSVideoActiveXCtrl::XObjSafe::Release()
{
	METHOD_PROLOGUE(CYSVideoActiveXCtrl, ObjSafe)
	return pThis->ExternalRelease();
}

HRESULT FAR EXPORT CYSVideoActiveXCtrl::XObjSafe::QueryInterface(REFIID iid, void FAR* FAR* ppvObj)
{
	METHOD_PROLOGUE(CYSVideoActiveXCtrl, ObjSafe)
	return (HRESULT)pThis->ExternalQueryInterface(&iid, ppvObj);
}

const DWORD dwSupportedBits = INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA;

const DWORD dwNotSupportedBits = ~ dwSupportedBits;

//.............................................................................

// CStopLiteCtrl::XObjSafe::GetInterfaceSafetyOptions

// Allows Container to query what interfaces are safe for what. We're

// optimizing significantly by ignoring which interface the caller is

// asking for.

HRESULT STDMETHODCALLTYPE CYSVideoActiveXCtrl::XObjSafe::GetInterfaceSafetyOptions( 
 /* [in] */ REFIID riid,
 /* [out] */ DWORD __RPC_FAR *pdwSupportedOptions,
 /* [out] */ DWORD __RPC_FAR *pdwEnabledOptions)
{
	METHOD_PROLOGUE(CYSVideoActiveXCtrl, ObjSafe)
	HRESULT retval = ResultFromScode(S_OK);
	// does interface exist?
	IUnknown FAR* punkInterface;
	retval = pThis->ExternalQueryInterface(&riid,(void * *)&punkInterface);
	if (retval != E_NOINTERFACE) { // interface exists
		punkInterface->Release(); // release it--just checking!
	}
	// we support both kinds of safety and have always both set,
	// regardless of interface
	*pdwSupportedOptions = *pdwEnabledOptions = dwSupportedBits;
	return retval; // E_NOINTERFACE if QI failed
}

/////////////////////////////////////////////////////////////////////////////

// CStopLiteCtrl::XObjSafe::SetInterfaceSafetyOptions

// Since we're always safe, this is a no-brainer--but we do check to make

// sure the interface requested exists and that the options we're asked to

// set exist and are set on (we don't support unsafe mode).

HRESULT STDMETHODCALLTYPE CYSVideoActiveXCtrl::XObjSafe::SetInterfaceSafetyOptions(
 /* [in] */ REFIID riid,
 /* [in] */ DWORD dwOptionSetMask,
 /* [in] */ DWORD dwEnabledOptions)

{
    METHOD_PROLOGUE(CYSVideoActiveXCtrl, ObjSafe)
	// does interface exist?
	IUnknown FAR* punkInterface;
	pThis->ExternalQueryInterface(&riid, (void * *)&punkInterface);
	if (punkInterface) { // interface exists
		punkInterface->Release(); // release it--just checking!
	}
	else
	{ // interface doesn't exist
		return ResultFromScode(E_NOINTERFACE);
	} 
	// can't set bits we don't support
	if (dwOptionSetMask & dwNotSupportedBits) { 
		return ResultFromScode(E_FAIL);
	} 
	// can't set bits we do support to zero
	dwEnabledOptions &= dwSupportedBits;
	// (we already know there are no extra bits in mask )
	if ((dwOptionSetMask & dwEnabledOptions) !=	dwOptionSetMask) {
		return ResultFromScode(E_FAIL);
	}         
	// don't need to change anything since we're always safe
	return ResultFromScode(S_OK);

}

//***************************************************************add end

void CYSVideoActiveXCtrl::ResetWindow(USHORT nWindowNumber)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CRect rcSize;
	GetClientRect(rcSize);
	m_nFocusWnd = 0;
	switch(m_nStyle)
	{
	case 1:	
		{
			if(nWindowNumber==1)
			{
				CStatic* pStatic = (CStatic*)m_WndArray.GetAt(0);
				if(pStatic->GetSafeHwnd())
				{
					pStatic->DestroyWindow();
					pStatic->Create(NULL,WS_CHILD|WS_VISIBLE|SS_NOTIFY,rcSize,this,1001);
				}
			}
		}
		break;
	case 4:
		{
			CRect rectAll[4];
			//1
			rectAll[0] = CRect(rcSize.left, //x
				rcSize.top, 
				rcSize.left+(rcSize.Width()/2-1),  //x
				rcSize.top + (rcSize.Height() / 2-1));
			//2
			rectAll[1] = CRect(rcSize.left+rcSize.Width()/2+1, //x
				rcSize.top , 
				rcSize.left+ rcSize.Width(), //x
				rcSize.top + rcSize.Height()/2-1);
			//3
			rectAll[2] = CRect(rcSize.left, //x
				rcSize.top + rcSize.Height() / 2+1, 
				rcSize.left + rcSize.Width()/2-1, //x
				rcSize.top + rcSize.Height());
			//4
			rectAll[3] = CRect(rcSize.left+rcSize.Width()/2+1, //x
				rcSize.top + rcSize.Height()/2+1, 
				rcSize.left + rcSize.Width(), //x
				rcSize.top + rcSize.Height());


			CStatic* pStatic = NULL;
			int i = nWindowNumber-1;
			pStatic = (CStatic*)m_WndArray.GetAt(i);
			if(pStatic->GetSafeHwnd())
			{
				pStatic->DestroyWindow();
				pStatic->Create(NULL,WS_CHILD|WS_VISIBLE|SS_NOTIFY,rectAll[i],this,2001+i);
				pStatic->MoveWindow(rectAll[i]);
			}
		}
		break;
	case 9:
		break;
	default:
		break;
	}
}


HBRUSH CYSVideoActiveXCtrl::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = COleControl::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(0,0,0)); //设置字体颜色
		int nId = pWnd->GetDlgCtrlID();
		int nS = nId%1000;
		if(nS==m_nFocusWnd)
			return m_hbrBkSelected;

		return m_hbrBk;
	}
	return hbr;
}

void CYSVideoActiveXCtrl::OnClickOne()
{
	m_nFocusWnd = 1;
	AdjustSelected();
}

void CYSVideoActiveXCtrl::OnClick1Four()
{
	m_nFocusWnd = 1;
	AdjustSelected();
}

void CYSVideoActiveXCtrl::OnClick2Four()
{
	m_nFocusWnd = 2;
	AdjustSelected();
}

void CYSVideoActiveXCtrl::OnClick3Four()
{
	m_nFocusWnd = 3;
	AdjustSelected();
}

void CYSVideoActiveXCtrl::OnClick4Four()
{
	m_nFocusWnd = 4;
	AdjustSelected();
}

void CYSVideoActiveXCtrl::AdjustSelected()
{
	int nWndNumber = 0;
	for (int i=1;i<=9;i++)
	{
		nWndNumber = i;
		CString strValue,strWndNumber;
		strWndNumber.Format("%d",nWndNumber);
		BOOL bFind = m_mapPlaying.Lookup(strWndNumber,strValue);
		if(bFind)
		{
			//正在播放什么也不做
			continue;
		}else{
			int nStaticID = nWndNumber-1;
			if (nStaticID<0)return;

			CRect rectStatic;
			CStatic* pStatic = (CStatic*)m_WndArray.GetAt(nStaticID);
			if(pStatic->GetSafeHwnd()==NULL)return;
			pStatic->GetClientRect(rectStatic);
			//没播放且被选中	
			if(m_nFocusWnd==nWndNumber)
			{
				pStatic->GetDC()->FillSolidRect(rectStatic,SELECTED_COLOR);
			}else{//没播放且没选中	
				pStatic->GetDC()->FillSolidRect(rectStatic,RGB(0,0,0));
			}
		}
	}
}

void CYSVideoActiveXCtrl::RepaintThick()
{
	CRect rcSize;
	GetClientRect(rcSize);
	CRect rectThick[2];
	rectThick[0] = CRect(rcSize.left+rcSize.Width()/2-1,
		rcSize.top,
		rcSize.left+rcSize.Width()/2+1,
		rcSize.bottom);
	rectThick[1] = CRect(rcSize.left,
		rcSize.top + rcSize.Height()/2-1,
		rcSize.right,
		rcSize.top + rcSize.Height() / 2+1);
	this->GetDC()->FillSolidRect(rectThick[0],RGB(255,255,255));
	this->GetDC()->FillSolidRect(rectThick[1],RGB(255,255,255));
}

void CYSVideoActiveXCtrl::ShowStyle(LONG nStyle)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CloseAllStatic();
	m_nStyle = nStyle;

	CRect rcSize;
	GetClientRect(rcSize);

	switch(m_nStyle)
	{
	case 1:	
		{
			CStatic* pStatic = (CStatic*)m_WndArray.GetAt(0);
			pStatic->Create(NULL,WS_CHILD|WS_VISIBLE|SS_NOTIFY,rcSize,this,1001);
		}
		break;
	case 4:
		{
			CRect rectAll[4];
			//1
			rectAll[0] = CRect(rcSize.left, //x
				rcSize.top, 
				rcSize.left+(rcSize.Width()/2-1),  //x
				rcSize.top + (rcSize.Height() / 2-1));
			//2
			rectAll[1] = CRect(rcSize.left+rcSize.Width()/2+1, //x
				rcSize.top , 
				rcSize.left+ rcSize.Width(), //x
				rcSize.top + rcSize.Height()/2-1);
			//3
			rectAll[2] = CRect(rcSize.left, //x
				rcSize.top + rcSize.Height() / 2+1, 
				rcSize.left + rcSize.Width()/2-1, //x
				rcSize.top + rcSize.Height());
			//4
			rectAll[3] = CRect(rcSize.left+rcSize.Width()/2+1, //x
				rcSize.top + rcSize.Height()/2+1, 
				rcSize.left + rcSize.Width(), //x
				rcSize.top + rcSize.Height());

			CStatic* pStatic = NULL;
			for (int i=0;i<4;i++)
			{
				pStatic = (CStatic*)m_WndArray.GetAt(i);
				pStatic->Create(NULL,WS_CHILD|WS_VISIBLE|SS_NOTIFY,rectAll[i],this,2001+i);	
			}
			RepaintThick();
		}
		break;
	case 9:
		break;
	default:
		break;
	}

}


void CYSVideoActiveXCtrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);
	CRect rcSize;
	GetClientRect(rcSize);
	switch(m_nStyle)
	{
	case 1:	
		{
			CStatic* pStatic = (CStatic*)m_WndArray.GetAt(0);
			if(pStatic->GetSafeHwnd())
				pStatic->MoveWindow(rcSize);
/*			AdjustSelected();*/
		}
		break;
	case 4:
		{
			CRect rectAll[4];
			//1
			rectAll[0] = CRect(rcSize.left, //x
				rcSize.top, 
				rcSize.left+(rcSize.Width()/2-1),  //x
				rcSize.top + (rcSize.Height() / 2-1));
			//2
			rectAll[1] = CRect(rcSize.left+rcSize.Width()/2+1, //x
				rcSize.top , 
				rcSize.right, //x
				rcSize.top + rcSize.Height()/2-1);
			//3
			rectAll[2] = CRect(rcSize.left, //x
				rcSize.top + rcSize.Height() / 2+1, 
				rcSize.left + rcSize.Width()/2-1, //x
				rcSize.bottom);
			//4
			rectAll[3] = CRect(rcSize.left+rcSize.Width()/2+1, //x
				rcSize.top + rcSize.Height()/2+1, 
				rcSize.right, //x
				rcSize.bottom);

			CStatic* pStatic = NULL;
			for (int i=0; i<4;i++)
			{
				pStatic = (CStatic*)m_WndArray.GetAt(i);
				if(pStatic->GetSafeHwnd())
					pStatic->MoveWindow(rectAll[i]);
/*				AdjustSelected();*/
			}
/*			RepaintThick();*/
		}
		break;
	case 9:
		break;
	default:
		break;
	}
}



void CYSVideoActiveXCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rcSize;
	GetClientRect(rcSize);
	switch(m_nStyle)
	{
	case 1:	
		{
			AdjustSelected();
		}
		break;
	case 4:
		{
			for (int i=0; i<4;i++)
			{
				AdjustSelected();
			}
			RepaintThick();
		}
		break;
	case 9:
		break;
	default:
		break;
	}

}
