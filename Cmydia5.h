#pragma once


// Cmydia5 对话框

class Cmydia5 : public CDialogEx
{
	DECLARE_DYNAMIC(Cmydia5)

public:
	Cmydia5(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cmydia5();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton27();
};
