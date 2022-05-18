
// CLITestDlg.cpp
//

#include "pch.h"
#include "framework.h"
#include "CLITest.h"
#include "CLITestDlg.h"
#include "afxdialogex.h"
#include <memory>

#include "Wrapper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CCLITestDlg::CCLITestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLITEST_DIALOG, pParent)
	, m_stringLog(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCLITestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_FOLDER_PICKER, m_checkerIsFolderPicker);
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_LOG, m_stringLog);
}

BEGIN_MESSAGE_MAP(CCLITestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPEN_FILE, &CCLITestDlg::OnBnClickedButtonOpenFile)
	ON_BN_CLICKED(IDC_BUTTON_SH_BROWSE, &CCLITestDlg::OnBnClickedButtonShBrowse)
	ON_BN_CLICKED(IDC_BUTTON_IFILE_DIALOG, &CCLITestDlg::OnBnClickedButtonIfileDialog)
	ON_BN_CLICKED(IDC_BUTTON_CS_WRAPPER1, &CCLITestDlg::OnBnClickedButtonCsWrapper1)
	ON_BN_CLICKED(IDC_BUTTON_CS_WRAPPER2, &CCLITestDlg::OnBnClickedButtonCsWrapper2)
	ON_BN_CLICKED(IDC_BUTTON_CS_WRAPPER3, &CCLITestDlg::OnBnClickedButtonCsWrapper3)
	ON_BN_CLICKED(IDC_BUTTON_CS_WRAPPER4, &CCLITestDlg::OnBnClickedButtonCsWrapper4)
	ON_BN_CLICKED(IDC_BUTTON_CS_WRAPPER5, &CCLITestDlg::OnBnClickedButtonCsWrapper5)
	ON_BN_CLICKED(IDC_BUTTON_CS_WRAPPER6, &CCLITestDlg::OnBnClickedButtonCsWrapper6)
	ON_BN_CLICKED(IDC_BUTTON_CS_WRAPPER7, &CCLITestDlg::OnBnClickedButtonCsWrapper7)
	ON_BN_CLICKED(IDC_BUTTON_CS_WRAPPER8, &CCLITestDlg::OnBnClickedButtonCsWrapper8)
	ON_BN_CLICKED(IDC_BUTTON_COINITIALIZE, &CCLITestDlg::OnBnClickedButtonCoinitialize)
	ON_BN_CLICKED(IDC_BUTTON_COUNINITIALIZE, &CCLITestDlg::OnBnClickedButtonCouninitialize)
END_MESSAGE_MAP()


BOOL CCLITestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	
	return TRUE;
}


void CCLITestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CCLITestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCLITestDlg::OnBnClickedButtonOpenFile()
{
	std::unique_ptr<CFileDialog> fileDlg(new CFileDialog(TRUE));
	fileDlg->DoModal();

	m_stringLog = m_stringLog + "\r\n" + CString(_T(__FUNCTION__));
	UpdateData(FALSE);
}


void CCLITestDlg::OnBnClickedButtonShBrowse()
{
	BROWSEINFO info = {	};
	auto result = SHBrowseForFolder(&info);

	TCHAR path[MAX_PATH] = {};
	SHGetPathFromIDList(result, path);

	m_stringLog = m_stringLog + "\r\n" + CString(_T(__FUNCTION__));
	UpdateData(FALSE);
}


void CCLITestDlg::OnBnClickedButtonIfileDialog()
{
	IFileDialog* pDialog = NULL;
	HRESULT hr;
	DWORD options;

	hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pDialog));

	pDialog->GetOptions(&options);
	if (m_checkerIsFolderPicker.GetCheck() == BST_CHECKED) {
		pDialog->SetOptions(options | FOS_PICKFOLDERS);
	}

	hr = pDialog->Show(this->GetSafeHwnd());
	if (SUCCEEDED(hr))
	{
		WCHAR* pszName;
		IShellItem* pIShellItem;

		pszName = NULL;
		pIShellItem = NULL;
		hr = pDialog->GetResult(&pIShellItem);
		if (SUCCEEDED(hr))
			hr = pIShellItem->GetDisplayName(SIGDN_FILESYSPATH, &pszName);
		if (SUCCEEDED(hr))
		{
			::CoTaskMemFree(pszName);
		}

		if (pIShellItem)
			pIShellItem->Release();
	}

	pDialog->Release();

	m_stringLog = m_stringLog + "\r\n" + CString(_T(__FUNCTION__));
	UpdateData(FALSE);
}


void CCLITestDlg::OnBnClickedButtonCsWrapper1()
{
	CSWrapper::Wrapper::WrapperMethod1();

	CString logItem;
	GetDlgItem(IDC_BUTTON_CS_WRAPPER1)->GetWindowText(logItem);
	m_stringLog = m_stringLog + "\r\n" + logItem;
	UpdateData(FALSE);
}


void CCLITestDlg::OnBnClickedButtonCsWrapper2()
{
	CSWrapper::Wrapper::WrapperMethod2();

	CString logItem;
	GetDlgItem(IDC_BUTTON_CS_WRAPPER2)->GetWindowText(logItem);
	m_stringLog = m_stringLog + "\r\n" + logItem;
	UpdateData(FALSE);
}


void CCLITestDlg::OnBnClickedButtonCsWrapper3()
{
	CSWrapper::Wrapper::WrapperMethod3();

	CString logItem;
	GetDlgItem(IDC_BUTTON_CS_WRAPPER3)->GetWindowText(logItem);
	m_stringLog = m_stringLog + "\r\n" + logItem;
	UpdateData(FALSE);
}


void CCLITestDlg::OnBnClickedButtonCsWrapper4()
{
	CSWrapper::Wrapper::WrapperMethod4();

	CString logItem;
	GetDlgItem(IDC_BUTTON_CS_WRAPPER4)->GetWindowText(logItem);
	m_stringLog = m_stringLog + "\r\n" + logItem;
	UpdateData(FALSE);
}


void CCLITestDlg::OnBnClickedButtonCsWrapper5()
{
	CSWrapper::Wrapper::WrapperMethod5();

	CString logItem;
	GetDlgItem(IDC_BUTTON_CS_WRAPPER5)->GetWindowText(logItem);
	m_stringLog = m_stringLog + "\r\n" + logItem;
	UpdateData(FALSE);
}


void CCLITestDlg::OnBnClickedButtonCsWrapper6()
{
	CSWrapper::Wrapper::WrapperMethod6();

	CString logItem;
	GetDlgItem(IDC_BUTTON_CS_WRAPPER6)->GetWindowText(logItem);
	m_stringLog = m_stringLog + "\r\n" + logItem;
	UpdateData(FALSE);
}


void CCLITestDlg::OnBnClickedButtonCsWrapper7()
{
	int year, month, day, hour, minute, second;

	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	CSWrapper::Wrapper::GetTime(year, month, day, hour, minute, second);
	CoUninitialize();

	CString logItem;
	GetDlgItem(IDC_BUTTON_CS_WRAPPER7)->GetWindowText(logItem);
	m_stringLog = m_stringLog + "\r\n" + logItem;

	CTime time(year, month, day, hour, minute, second);
	m_stringLog = m_stringLog + "\r\n" + time.Format(_T("%Y-%m-%d %H:%M:%S"));

	UpdateData(FALSE);
}


void CCLITestDlg::OnBnClickedButtonCsWrapper8()
{
	CSWrapper::Wrapper::WrapperMethod8();

	m_stringLog = m_stringLog + "\r\n" + CString(_T("Show WPF Window"));
	UpdateData(FALSE);
}


void CCLITestDlg::OnBnClickedButtonCoinitialize()
{
	auto ret = CoInitialize(NULL);

	m_stringLog = m_stringLog + CString("\r\n") + _T("Do Coinitialize");
	UpdateData(FALSE);
}


void CCLITestDlg::OnBnClickedButtonCouninitialize()
{
	CoUninitialize();

	m_stringLog = m_stringLog + CString("\r\n") + _T("Do CoUninitialize");
	UpdateData(FALSE);
}
