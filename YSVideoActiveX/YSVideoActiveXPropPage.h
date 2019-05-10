#pragma once
#include "afxwin.h"

// YSVideoActiveXPropPage.h : CYSVideoActiveXPropPage 属性页类的声明。


// CYSVideoActiveXPropPage : 有关实现的信息，请参阅 YSVideoActiveXPropPage.cpp。

class CYSVideoActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CYSVideoActiveXPropPage)
	DECLARE_OLECREATE_EX(CYSVideoActiveXPropPage)

// 构造函数
public:
	CYSVideoActiveXPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_YSVIDEOACTIVEX };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

