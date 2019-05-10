// OpenSDKMgr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OpenSDKMgr.h"
#include "opensslwrap/sslApi.h"
#include "time.h"


#if defined(_WIN32) || defined(_WIN64)

#elif defined(__linux__)

#include <string.h>
#include <stddef.h>
#include <dlfcn.h>

#else

# error os not support!

#endif

#include <string>

extern CString g_strAuthAddress;
extern CString g_strPlatformAddress;
extern CString g_strAppKey;									//需要配置
extern CString g_strAppSecret;								//需要配置
extern CString g_strPhone;									//需要配置
extern CString g_strAccessToken;
extern CString g_strSignature;


OpenSDKMgr::OpenSDKMgr(void)
{
	m_iInitCount = 0;
}

OpenSDKMgr::~OpenSDKMgr(void)
{
}

int OpenSDKMgr::InitLib(CString strAppKey)
{
	if (m_iInitCount > 0)
	{
		++m_iInitCount;
		return 0;
	}

	if (OpenSDK_Init(strAppKey) != 0)
	{
		return -1;
	}

	++m_iInitCount;
	return 0;
}

int OpenSDKMgr::FiniLib()
{
	if (0 == m_iInitCount)
	{
		return -1;
	}

	m_iInitCount--;
	if (m_iInitCount > 0)
	{
		return 0;
	}
	OpenSDK_FiniLib();
	return 0;
}

int OpenSDKMgr::AllocSession(OpenSDK_MessageHandler pHandle, void* pUser, CString &strSession)
{	
	char *pSession = NULL;
	int iLen = 0;
	int iRet = OpenSDK_AllocSession(pHandle, pUser, &pSession, &iLen);
	if(pSession)
	{
		strSession = pSession;
		OpenSDK_Data_Free(pSession);
	}
	return iRet;
}

int OpenSDKMgr::FreeSession(CString strSessionId)
{
	int iRet = OpenSDK_FreeSession(strSessionId);
	return iRet;
}

int OpenSDKMgr::StartRealPlay(CString strSessionId, HWND hPlayWnd, CString strCameraId, CString strAccessToken, int iVideoLevel, CString strSafeKey, CString strAppKey)
{
	NSCBMsg ncsbMsg;
	ZeroMemory(&ncsbMsg,sizeof(NSCBMsg));
	int iRet = OpenSDK_StartRealPlay(strSessionId, hPlayWnd, strCameraId, strAccessToken, iVideoLevel, strSafeKey, strAppKey,&ncsbMsg);
	return iRet;
}

int OpenSDKMgr::StopRealPlay(CString strSessionId)
{
	NSCBMsg ncsbMsg;
	ZeroMemory(&ncsbMsg,sizeof(NSCBMsg));
	int iRet = OpenSDK_StopRealPlay(strSessionId,&ncsbMsg);
	return iRet;
}

int OpenSDKMgr::StartPlayBack(CString strSessionId, HWND hPlayWnd, CString strCameraId, CString strAccessToken, CString strSafeKey, CString strStartTime, CString strStopTime, CString strAppKey)
{
	NSCBMsg ncsbMsg;
	ZeroMemory(&ncsbMsg,sizeof(NSCBMsg));
	int iRet = OpenSDK_StartPlayBack(strSessionId, hPlayWnd, strCameraId, strAccessToken, strSafeKey, strStartTime, strStopTime, strAppKey,&ncsbMsg);
	return iRet;
}

int OpenSDKMgr::PlayBackResume(CString strSessionId)
{
	int iRet = OpenSDK_PlayBackResume(strSessionId);
	return iRet;
}

int OpenSDKMgr::PlayBackPause(CString strSessionId)
{
	int iRet = OpenSDK_PlayBackPause(strSessionId);
	return iRet;
}

int OpenSDKMgr::StopPlayBack(CString strSessionId)
{
	NSCBMsg ncsbMsg;
	ZeroMemory(&ncsbMsg,sizeof(NSCBMsg));
	int iRet = OpenSDK_StopPlayBack(strSessionId,&ncsbMsg);
	return iRet;
}

int OpenSDKMgr::SetDataCallBack(CString strSessionId, OpenSDK_DataCallBack pDataCallBack, void* pUser)
{
	int iRet = OpenSDK_SetDataCallBack(strSessionId, pDataCallBack, pUser);
	return iRet;
}

int OpenSDKMgr::StartSearch(CString strSessionId, CString strCameraId, CString strAccessToken, CString strStartTime, CString strStopTime)
{
	NSCBMsg ncsbMsg;
	ZeroMemory(&ncsbMsg,sizeof(NSCBMsg));
	int iRet = OpenSDK_StartSearch(strSessionId, strCameraId, strAccessToken, strStartTime, strStopTime,&ncsbMsg);
	return iRet;
}

int OpenSDKMgr::GetOSDTime(CString strSessionId, STREAM_TIME *pTime)
{
	int iRet = OpenSDK_GetOSDTime(strSessionId, pTime);
	return iRet;
}

int OpenSDKMgr::OpenSound(CString strSessionId)
{
	int iRet = OpenSDK_OpenSound(strSessionId);
	return iRet;
}

int OpenSDKMgr::CloseSound(CString strSessionId)
{
	int iRet = OpenSDK_CloseSound(strSessionId);
	return iRet;
}

unsigned short OpenSDKMgr::GetVolume(CString strSessionId)
{
	return OpenSDK_GetVolume(strSessionId);
}

int OpenSDKMgr::SetVolume(CString strSessionId, unsigned short uVolume)
{
	int iRet = OpenSDK_SetVolume(strSessionId, uVolume);
	return iRet;
}

int OpenSDKMgr::StartVoiceTalk(CString strSessionId, CString strAccessToken, CString strCameraId)
{
	int iRet = OpenSDK_StartVoiceTalk(strSessionId, strAccessToken, strCameraId);
	return iRet;
}

int OpenSDKMgr::StopVoiceTalk(CString strSessionId)
{
	int iRet = OpenSDK_StopVoiceTalk(strSessionId);
	return iRet;
}

int OpenSDKMgr::CapturePicture(CString strSessionId, CString strFileName)
{
	int iRet = OpenSDK_CapturePicture(strSessionId, strFileName);
	return iRet;
}

int OpenSDKMgr::Mid_Login(char** szAccessToken, int* iAccessTokenLen)
{
	int iRet = OpenSDK_Mid_Login(szAccessToken, iAccessTokenLen);
	return iRet;
}

int OpenSDKMgr::Mid_Device_Add(const char* szAccessToken)
{
	int iRet = OpenSDK_Mid_Device_Add(szAccessToken);
	return iRet;
}

int OpenSDKMgr::Mid_Device_Oper(const char* szAccessToken, const char* szDeviceId)
{
	int iRet = OpenSDK_Mid_Device_Oper(szAccessToken, szDeviceId);
	return iRet;
}

int OpenSDKMgr::Data_GetDevList(CString strAccessToken, int iPageStart, int iPageSize, void** pBuf, int* iLength)
{
	int iRet = OpenSDK_Data_GetDevList((LPCTSTR)strAccessToken, iPageStart, iPageSize, pBuf, iLength);
	return iRet;
}

int OpenSDKMgr::Data_GetAlarmList(CString strAccessToken, CString strCameraId, CString strStartTime, CString strEndTime, AlarmType iAlarmType, int iStatus, int iPageStart, int iPageSize, void** pBuf, int* iLength)
{
	int iRet = OpenSDK_Data_GetAlarmList((LPCTSTR)strAccessToken, (LPCTSTR)strCameraId, (LPCTSTR)strStartTime, (LPCTSTR)strEndTime, iAlarmType, iStatus, iPageStart, iPageSize, pBuf, iLength);
	return iRet;
}

int OpenSDKMgr::Data_DeleteDevice(const char* szAccessToken, const char* szDeviceId)
{
	int iRet = OpenSDK_Data_DeleteDevice(szAccessToken, szDeviceId);
	return iRet;
}

int OpenSDKMgr::Data_Free(void* pBuf)
{
	int iRet = OpenSDK_Data_Free(pBuf);
	return iRet;
}

int OpenSDKMgr::Alarm_SetMsgCallBack(OpenSDK_Alarm_MessageHandler handle, OpenSDK_Publish_MessageHandler publishHandle, void* pUser)
{
	int iRet = OpenSDK_Alarm_SetMsgCallBack(handle, publishHandle, pUser);
	return iRet;
}

int OpenSDKMgr::Alarm_StartRecv(CString strAccessToken)
{
	int iRet = OpenSDK_Alarm_StartRecv(strAccessToken);
	return iRet;
}

int OpenSDKMgr::Alarm_StopRecv()
{
	int iRet = OpenSDK_Alarm_StopRecv();
	return iRet;
}

int OpenSDKMgr::PTZCtrl(CString strSessionId, CString strAccessToken, CString strCameraId, PTZCommand enCommand, PTZAction enAction, int iSpeed)
{
	int iRet = OpenSDK_PTZCtrl((LPCTSTR)strSessionId, (LPCTSTR)strAccessToken, (LPCTSTR)strCameraId, enCommand, enAction, iSpeed);
	return iRet;
}

int OpenSDKMgr::DevDefence(CString strSessionId, CString strAccessToken, CString strCameraId, DefenceType enType, DefenceStatus enStatus, DefenceActor enActor)
{
//	LOG_PRINT_INFO("strSession=%s, strAccessToken=%s, strCameraId=%s, enType=%d, enStatus=%d, enActor=%d",strSessionId, strAccessToken, strCameraId, enType, enStatus, enActor);
	int iRet = OpenSDK_DevDefence(strSessionId, strAccessToken, strCameraId, enType, enStatus, enActor);
	return iRet;
}

int OpenSDKMgr::HttpSendWithWait(const char* szUri, const char* szHeaderParam, const char* szBody, char** pBuf, int* iLength)
{
	int iRet = OpenSDK_HttpSendWithWait(szUri, szHeaderParam, szBody, pBuf, iLength);
	return iRet;
}

int OpenSDKMgr::UpdateCameraInfoToLocal(const char* szCameraId, const char* szAccessToken, bool& isEncrypt)
{
	int iRet = OpenSDK_UpdateCameraInfoToLocal(szCameraId, szAccessToken, isEncrypt);
	return iRet;
}

int OpenSDKMgr::Data_GetDeviceInfo(const char* szAccessToken, const char* szDeviceSerial, void** pBuf, int* iLength)
{
	int iRet = OpenSDK_Data_GetDeviceInfo(szAccessToken, szDeviceSerial, pBuf,iLength);
	return iRet;
}

int OpenSDKMgr::Data_SetAlarmRead(const char* szAccessToken, const char* szAlarmId)
{
	int iRet = OpenSDK_Data_SetAlarmRead(szAccessToken, szAlarmId);
	return iRet;
}

OpenSDKMgr* OpenSDKMgr::GetInstance()
{
	static OpenSDKMgr dt;
	return &dt;
}