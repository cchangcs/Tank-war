#pragma once


// CChildCla1 对话框

class CChildCla1 : public CDialogEx
{
	DECLARE_DYNAMIC(CChildCla1)

public:
	CChildCla1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChildCla1();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	HICON m_hIcon;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CRect rect;
	afx_msg void OnIddDialog3();
	virtual BOOL OnInitDialog();
	POINT oSize;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
