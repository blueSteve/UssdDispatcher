
// UssdDispatcher.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUssdDispatcherApp:
// �йش����ʵ�֣������ UssdDispatcher.cpp
//

class CUssdDispatcherApp : public CWinApp
{
public:
	CUssdDispatcherApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CUssdDispatcherApp theApp;