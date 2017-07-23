#pragma once


// Cmydia1 对话框

class Cmydia1 : public CDialogEx
{
	DECLARE_DYNAMIC(Cmydia1)

public:
	Cmydia1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cmydia1();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
