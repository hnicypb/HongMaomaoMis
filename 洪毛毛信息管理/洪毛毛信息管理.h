
// ��ëë��Ϣ����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ëë��Ϣ����App:
// �йش����ʵ�֣������ ��ëë��Ϣ����.cpp
//

class C��ëë��Ϣ����App : public CWinAppEx
{
public:
	C��ëë��Ϣ����App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ëë��Ϣ����App theApp;