#pragma once


// Cmydia15 对话框

class Cmydia15 : public CDialogEx
{
	DECLARE_DYNAMIC(Cmydia15)

public:
	Cmydia15(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cmydia15();

// 对话框数据
	enum { IDD = IDD_DIALOG13 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
