
#include "stdafx.h"
#pragma once
#include "afxwin.h"
#include"Cmydia10.h"
// Cmydia4 对话框
  
class Cmydia4 : public CDialogEx
{
	DECLARE_DYNAMIC(Cmydia4)

public:
	Cmydia4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cmydia4();
	HBITMAP hBitmap ;
// 对话框数据
	enum { IDD = IDD_DIALOG4 };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton21();
};
