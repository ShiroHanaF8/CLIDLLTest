
// CLITest.cpp
//

#include "pch.h"
#include "framework.h"
#include "CLITest.h"
#include "CLITestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCLITestApp

BEGIN_MESSAGE_MAP(CCLITestApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCLITestApp

CCLITestApp::CCLITestApp()
{
}

CCLITestApp theApp;


BOOL CCLITestApp::InitInstance()
{
	CWinApp::InitInstance();

	CShellManager *pShellManager = new CShellManager;

	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	SetRegistryKey(_T(""));

	CCLITestDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}
	else if (nResponse == -1)
	{
	}

	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	return FALSE;
}

