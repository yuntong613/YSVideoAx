#pragma once
#include "afxwin.h"

// YSVideoActiveXPropPage.h : CYSVideoActiveXPropPage ����ҳ���������


// CYSVideoActiveXPropPage : �й�ʵ�ֵ���Ϣ������� YSVideoActiveXPropPage.cpp��

class CYSVideoActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CYSVideoActiveXPropPage)
	DECLARE_OLECREATE_EX(CYSVideoActiveXPropPage)

// ���캯��
public:
	CYSVideoActiveXPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_YSVIDEOACTIVEX };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

