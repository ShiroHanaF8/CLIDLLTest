﻿
// CLITest.h
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"


// CCLITestApp:
//

class CCLITestApp : public CWinApp
{
public:
	CCLITestApp();

public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CCLITestApp theApp;
