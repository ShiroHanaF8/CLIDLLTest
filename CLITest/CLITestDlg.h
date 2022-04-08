
// CLITestDlg.h
//

#pragma once


// CCLITestDlg
class CCLITestDlg : public CDialogEx
{
public:
	CCLITestDlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLITEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	HICON m_hIcon;
	CEdit m_editLog;
	CButton m_checkerIsFolderPicker;
	CString m_stringLog;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOpenFile();
	afx_msg void OnBnClickedButtonShBrowse();
	afx_msg void OnBnClickedButtonIfileDialog();
	afx_msg void OnBnClickedButtonCsWrapper1();
	afx_msg void OnBnClickedButtonCsWrapper2();
	afx_msg void OnBnClickedButtonCsWrapper3();
	afx_msg void OnBnClickedButtonCsWrapper4();
	afx_msg void OnBnClickedButtonCsWrapper5();
	afx_msg void OnBnClickedButtonCsWrapper6();
	afx_msg void OnBnClickedButtonCsWrapper7();
	afx_msg void OnBnClickedButtonCsWrapper8();

	afx_msg void OnBnClickedButtonCoinitialize();
	afx_msg void OnBnClickedButtonCouninitialize();
};
