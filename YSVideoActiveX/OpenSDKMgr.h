#ifndef _OPENSDKMGR_H_
#define _OPENSDKMGR_H_

#include "OpenNetStreamInterFace.h"
#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>
typedef FARPROC SDK_PROC;

#elif defined(__linux__)

#define __stdcall
typedef void*	SDK_PROC;
typedef void*   HINSTANCE;
typedef unsigned int HWND;

#else

# error os not support!

#endif

class OpenSDKMgr
{
public:
	OpenSDKMgr(void);
	~OpenSDKMgr(void);

	int InitLib(CString strAppKey);
	int FiniLib();
	int AllocSession(OpenSDK_MessageHandler pHandle, void* pUser, CString &strSession);
	int FreeSession(CString strSessionId);
	int SetDataCallBack(CString strSessionId, OpenSDK_DataCallBack pDataCallBack, void* pUser);
	int StartRealPlay(CString strSessionId, HWND hPlayWnd, CString strCameraId, CString strAccessToken, int iVideoLevel, CString strSafeKey, CString strAppKey);
	int StopRealPlay(CString strSessionId);
	int StartPlayBack(CString strSessionId, HWND hPlayWnd, CString strCameraId, CString strAccessToken, CString strSafeKey, CString strStartTime, CString strStopTime, CString strAppKey);
	int PlayBackResume(CString strSessionId);
	int PlayBackPause(CString strSessionId);
	int StopPlayBack(CString strSessionId);
	int StartSearch(CString strSessionId, CString strCameraId, CString strAccessToken, CString strStartTime, CString strStopTime);
	int GetOSDTime(CString strSessionId, STREAM_TIME *pTime);
	int OpenSound(CString strSessionId);
	int CloseSound(CString strSessionId);
	unsigned short GetVolume(CString strSessionId);
	int SetVolume(CString strSessionId, unsigned short uVolume);
	int StartVoiceTalk(CString strSessionId, CString strAccessToken, CString strCameraId);
	int StopVoiceTalk(CString strSessionId);
	int CapturePicture(CString strSessionId, CString strFileName);
	int Mid_Login( char** szAccessToken, int* iAccessTokenLen );
	int Mid_Device_Add(const char* szAccessToken);
	int Mid_Device_Oper(const char* szAccessToken, const char* szDeviceId);
	int Data_GetDevList(CString strAccessToken, int iPageStart, int iPageSize, void** pBuf, int* iLength);
	int Data_GetAlarmList(CString strAccessToken, CString strCameraId, CString strStartTime, CString strEndTime, AlarmType iAlarmType, int iStatus, int iPageStart, int iPageSize, void** pBuf, int* iLength);
	int Data_DeleteDevice(const char* szAccessToken, const char* szDeviceId);
	int Data_Free(void* pBuf);
	int Alarm_SetMsgCallBack(OpenSDK_Alarm_MessageHandler handle, OpenSDK_Publish_MessageHandler publishHandle, void* pUser);
	int Alarm_StartRecv(CString strAccessToken);
	int Alarm_StopRecv();
	int PTZCtrl(CString strSessionId, CString strAccessToken, CString strCameraId, PTZCommand enCommand, PTZAction enAction, int iSpeed);
	int DevDefence(CString strSessionId, CString strAccessToken, CString strCameraId, DefenceType enType, DefenceStatus enStatus, DefenceActor enActor);
	int HttpSendWithWait(const char* szUri, const char* szHeaderParam, const char* szBody, char** pBuf, int* iLength);

	int UpdateCameraInfoToLocal(const char* szCameraId, const char* szAccessToken, bool& isEncrypt);
	int Data_GetDeviceInfo(const char* szAccessToken, const char* szDeviceSerial, void** pBuf, int* iLength);
	int Data_SetAlarmRead(const char* szAccessToken, const char* szAlarmId);

	static OpenSDKMgr* GetInstance();

private:
	unsigned int m_iInitCount;
};


#endif