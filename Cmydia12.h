#pragma once


// Cmydia12 对话框

class Cmydia12 : public CDialogEx
{
	DECLARE_DYNAMIC(Cmydia12)

public:
	Cmydia12(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cmydia12();

// 对话框数据
	enum { IDD = IDD_DIALOG9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
