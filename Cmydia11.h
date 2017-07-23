#pragma once


// Cmydia11 对话框

class Cmydia11 : public CDialogEx
{
	DECLARE_DYNAMIC(Cmydia11)

public:
	Cmydia11(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cmydia11();

// 对话框数据
	enum { IDD = IDD_DIALOG10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
