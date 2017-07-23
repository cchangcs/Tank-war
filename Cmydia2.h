#pragma once


// Cmydia2 对话框

class Cmydia2 : public CDialogEx
{
	DECLARE_DYNAMIC(Cmydia2)

public:
	Cmydia2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cmydia2();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton1();
};
