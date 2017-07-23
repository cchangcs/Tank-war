
// 坦克大战界面3.0Dlg.h : 头文件
//

#pragma once
#include"ChildCla1.h"
#include"Cmydia4.h"
#include "afxwin.h"

// C坦克大战界面30Dlg 对话框
class C坦克大战界面30Dlg : public CDialogEx
{
// 构造
public:
	C坦克大战界面30Dlg(CWnd* pParent = NULL);
	~C坦克大战界面30Dlg();// 标准构造函数
// 对话框数据
	enum { IDD = IDD_MY30_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	//HWND hDlg;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CChildCla1 m_Cc1;
	CRect m_DC;
//	CRect m_rect;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClickedButton7();
	private:  

public:
	afx_msg void OnClickedButton5();
	afx_msg void OnBnClickedButton2();
//	afx_msg void OnSizeClipboard(CWnd* pClipAppWnd, HGLOBAL hRect);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
//	CRect m_rect;
//	afx_msg void OnSize(UINT nType, int cx, int cy);
//	int rect;
	CRect rect;
	POINT oSize;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDropdownButton7(NMHDR *pNMHDR, LRESULT *pResult);
//	CButton m_win;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClicked8();
	afx_msg void OnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};
