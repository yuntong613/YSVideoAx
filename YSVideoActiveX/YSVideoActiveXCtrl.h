#pragma once

// YSVideoActiveXCtrl.h : CYSVideoActiveXCtrl ActiveX 控件类的声明。

// CYSVideoActiveXCtrl : 有关实现的信息，请参阅 YSVideoActiveXCtrl.cpp。
#include <objsafe.h>

typedef enum {
	OpenSDK_GetAccessToken = 0,
	OpenSDK_GetMsg,
	OpenSDK_GetMsgCode
}OpenSDKHttpRequestType;


const char* ReqMethodStringNew[] = {
	"token/getAccessToken",
	"msg/get",
	"msg/getMsgCode"
};

class CYSVideoActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CYSVideoActiveXCtrl)

// 构造函数
public:
	CYSVideoActiveXCtrl();

	//***************************************************************add begin
	//ISafeObject
	DECLARE_INTERFACE_MAP()

	BEGIN_INTERFACE_PART(ObjSafe, IObjectSafety)


		STDMETHOD_(HRESULT, GetInterfaceSafetyOptions) ( 
		/* [in] */ REFIID riid,
		/* [out] */ DWORD __RPC_FAR *pdwSupportedOptions,
		/* [out] */ DWORD __RPC_FAR *pdwEnabledOptions
		);

		STDMETHOD_(HRESULT, SetInterfaceSafetyOptions) ( 
			/* [in] */ REFIID riid,
			/* [in] */ DWORD dwOptionSetMask,
			/* [in] */ DWORD dwEnabledOptions
			);
	END_INTERFACE_PART(ObjSafe);

	//ISafeObject
	//***************************************************************add end

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
// 实现
protected:
	~CYSVideoActiveXCtrl();

	DECLARE_OLECREATE_EX(CYSVideoActiveXCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CYSVideoActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CYSVideoActiveXCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CYSVideoActiveXCtrl)		// 类型名称和杂项状态

	static void CALLBACK MY_OpenSDK_MessageHandler(const char* szSessionId, unsigned int iMsgType, unsigned int iErrorCode,const char *pMessageInfo, void *pUser);
	static void CALLBACK Alarm_MessageHandler(const char* szCameraId,const char* szContent,const char* szAlarmTime,void* pUser);
	static void CALLBACK Publish_MessageHandler(const char* szContent, void* pUser);
public:
// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID

	enum 
	{
		dispidResetWindow = 38L,
		dispidGetFocusWnd = 37L,
		dispidData_SetAlarmRead = 36L,
		dispidData_GetDeviceInfo = 35L,
		dispidUpdateCameraInfoToLocal = 34L,
		eventidPublish_Message = 3L,
		eventidAlarm_Message = 2L,
		dispidData_DeleteDevice = 33L,
		dispidStopVoiceTalk = 32L,
		dispidStartVoiceTalk = 31L,
		dispidDevDefence = 30L,
		dispidAlarm_SetMsgCallBack = 29L,
		dispidPTZCtrl = 28L,
		dispidAlarm_StopRecv = 27L,
		dispidAlarm_StartRecv = 26L,
		dispidData_Free = 25L,
		dispidData_GetAlarmList = 24L,
		dispidSetVolume = 23L,
		dispidShowStyle = 22L,
		dispidHttpSendWithWait = 21L,
		dispidData_GetDevList = 20L,
		dispidMid_Device_Oper = 19L,
		dispidMid_Device_Add = 18L,
		dispidMid_Login = 17L,
		dispidCapturePicture = 16L,
		dispidGetVolume = 15L,
		dispidCloseSound = 14L,
		dispidOpenSound = 13L,
		dispidGetOSDTime = 12L,
		dispidStartSearch = 11L,
		dispidStopPlayBack = 10L,
		dispidPlayBackPause = 9L,
		dispidPlayBackResume = 8L,
		dispidStartPlayBack = 7L,
		dispidStopRealPlay = 6L,
		dispidStartRealPlay = 5L,
		dispidGetAccessToken = 6L,
		dispidSetParams = 5L,
		dispidSetSecretKey = 6L,
		dispidSetPhoneNumber = 5L,
		eventidOpenSDK_MessageTold = 1L,
		dispidFreeSession = 4L,
		dispidAllocSession = 3L,
		dispidFiniLib = 2L,
		dispidInitLib = 1L
	};
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	int m_nStyle;
	void CloseAllStatic(void);
	CPtrArray m_WndArray;

protected:
	void OpenSDK_MessageTold(LPCTSTR szSessionId, ULONG iMsgType, ULONG iErrorCode, LPCTSTR pMessageInfo)
	{
		FireEvent(eventidOpenSDK_MessageTold, EVENT_PARAM(VTS_BSTR VTS_UI4 VTS_UI4 VTS_BSTR VTS_PI4), szSessionId, iMsgType, iErrorCode, pMessageInfo);
	}
	void Alarm_Message(LPCTSTR szCameraId, LPCTSTR szContent, LPCTSTR szAlarmTime)
	{
		FireEvent(eventidAlarm_Message, EVENT_PARAM(VTS_BSTR VTS_BSTR VTS_BSTR), szCameraId, szContent, szAlarmTime);
	}
	void Publish_Message(LPCTSTR szContent)
	{
		FireEvent(eventidPublish_Message, EVENT_PARAM(VTS_BSTR), szContent);
	}
protected:
	LONG InitLib(LPCTSTR strAppKey);
	LONG FiniLib(void);
	BSTR AllocSession(void);
	LONG FreeSession(LPCTSTR strSession);
	LONG StartRealPlay(LPCTSTR strSessionId, LONG WindowNumber, LPCTSTR strCameraId, LPCTSTR strAccessToken, LONG iVideoLevel, LPCTSTR strSafeKey, LPCTSTR strAppKey);
	LONG StopRealPlay(LPCTSTR strSessionId);
	LONG StartPlayBack(LPCTSTR strSessionId, LONG WindowNumber, LPCTSTR strCameraId, LPCTSTR strAccessToken, LPCTSTR strSafeKey, LPCTSTR strStartTime, LPCTSTR strStopTime, LPCTSTR strAppKey);
	LONG PlayBackResume(LPCTSTR strSessionId);
	LONG PlayBackPause(LPCTSTR strSessionId);
	LONG StopPlayBack(LPCTSTR strSessionId);
	LONG StartSearch(LPCTSTR strSessionId, LPCTSTR strCameraId, LPCTSTR strAccessToken, LPCTSTR strStartTime, LPCTSTR strStopTime);
	BSTR GetOSDTime(LPCTSTR strSessionId);
	LONG OpenSound(LPCTSTR strSessionId);
	LONG CloseSound(LPCTSTR strSessionId);
	USHORT GetVolume(LPCTSTR strSessionId);
	LONG CapturePicture(LPCTSTR strSessionId, LPCTSTR strFileName);
	BSTR Mid_Login(void);
	LONG Mid_Device_Add(LPCTSTR szAccessToken);
	LONG Mid_Device_Oper(LPCTSTR szAccessToken, LPCTSTR szDeviceId);
	BSTR Data_GetDevList(LPCTSTR strAccessToken, LONG iPageStart, LONG iPageSize);
	BSTR HttpSendWithWait(LPCTSTR szUri, LPCTSTR szHeaderParam, LPCTSTR szBody);
	void ShowStyle(LONG nStyle);
	LONG SetVolume(LPCTSTR strSessionId, USHORT uVolume);
	BSTR Data_GetAlarmList(LPCTSTR strAccessToken, LPCTSTR strCameraId, LPCTSTR strStartTime, LPCTSTR strEndTime, LONG iAlarmType, LONG iStatus, LONG iPageStart, LONG iPageSize);
	LONG Data_Free(BSTR pBuf);
	LONG Alarm_StartRecv(LPCTSTR strAccessToken);
	LONG Alarm_StopRecv(void);
	LONG PTZCtrl(LPCTSTR strSessionId, LPCTSTR strAccessToken, LPCTSTR strCameraId, LONG enCommand, LONG enAction, LONG iSpeed);
	LONG Alarm_SetMsgCallBack(void);
	LONG DevDefence(LPCTSTR strSessionId, LPCTSTR strAccessToken, LPCTSTR strCameraId, LONG enType, LONG enStatus, LONG enActor);
	LONG StartVoiceTalk(LPCTSTR strSessionId, LPCTSTR strAccessToken, LPCTSTR strCameraId);
	LONG StopVoiceTalk(LPCTSTR strSessionId);
	LONG Data_DeleteDevice(LPCTSTR szAccessToken, LPCTSTR szDeviceId);
	LONG UpdateCameraInfoToLocal(LPCTSTR szCameraId, LPCTSTR szAccessToken);
	BSTR Data_GetDeviceInfo(LPCTSTR szAccessToken, LPCTSTR szDeviceSerial);
	LONG Data_SetAlarmRead(LPCTSTR szAccessToken, LPCTSTR szAlarmId);
	
public:
	int m_nFocusWnd;
	//保存是否正在播放，供窗口选中时使用<窗口序号，SessionID>
	CMapStringToString m_mapPlaying;
protected:
	LONG GetFocusWnd(void);
	void ResetWindow(USHORT nWindowNumber);
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	HBRUSH m_hbrBk;
	HBRUSH m_hbrBkSelected;
public:
	//单画面模式
	void OnClickOne();
	//4画面模式
	void OnClick1Four();
	void OnClick2Four();
	void OnClick3Four();
	void OnClick4Four();
	void AdjustSelected();
	void RepaintThick();
	afx_msg void OnPaint();
};

