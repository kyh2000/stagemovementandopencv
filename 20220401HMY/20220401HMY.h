
// 20220401HMY.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMy20220401HMYApp:
// �� Ŭ������ ������ ���ؼ��� 20220401HMY.cpp�� �����Ͻʽÿ�.
//

class CMy20220401HMYApp : public CWinApp
{
public:
	CMy20220401HMYApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMy20220401HMYApp theApp;