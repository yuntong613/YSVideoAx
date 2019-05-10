// YSVideoActiveXPropPage.cpp : CYSVideoActiveXPropPage 属性页类的实现。

#include "stdafx.h"
#include "YSVideoActiveX.h"
#include "YSVideoActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CYSVideoActiveXPropPage, COlePropertyPage)



// 消息映射

BEGIN_MESSAGE_MAP(CYSVideoActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CYSVideoActiveXPropPage, "YSVIDEOACTIVEX.YSVideoActiveXPropPage.1",
	0x7e86af1c, 0x5393, 0x498c, 0x8e, 0xab, 0xbd, 0x71, 0x60, 0x63, 0x64, 0x62)



// CYSVideoActiveXPropPage::CYSVideoActiveXPropPageFactory::UpdateRegistry -
// 添加或移除 CYSVideoActiveXPropPage 的系统注册表项

BOOL CYSVideoActiveXPropPage::CYSVideoActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_YSVIDEOACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CYSVideoActiveXPropPage::CYSVideoActiveXPropPage - 构造函数

CYSVideoActiveXPropPage::CYSVideoActiveXPropPage() :
	COlePropertyPage(IDD, IDS_YSVIDEOACTIVEX_PPG_CAPTION)
{
}



// CYSVideoActiveXPropPage::DoDataExchange - 在页和属性间移动数据

void CYSVideoActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CYSVideoActiveXPropPage 消息处理程序
