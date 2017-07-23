#pragma once


// Cmydia14 对话框

class Cmydia14 : public CDialogEx
{
	DECLARE_DYNAMIC(Cmydia14)

public:
	Cmydia14(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cmydia14();

// 对话框数据
	enum { IDD = IDD_DIALOG12 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
