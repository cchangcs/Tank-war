#pragma once


// Cmydia13 对话框

class Cmydia13 : public CDialogEx
{
	DECLARE_DYNAMIC(Cmydia13)

public:
	Cmydia13(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cmydia13();

// 对话框数据
	enum { IDD = IDD_DIALOG11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
