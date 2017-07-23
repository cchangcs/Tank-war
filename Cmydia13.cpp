// Cmydia13.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战界面3.0.h"
#include "Cmydia13.h"
#include "afxdialogex.h"
#include"Cmydia12.h"
#include"坦克大战界面3.0Dlg.h"

// Cmydia13 对话框

IMPLEMENT_DYNAMIC(Cmydia13, CDialogEx)

Cmydia13::Cmydia13(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmydia13::IDD, pParent)
{

}

Cmydia13::~Cmydia13()
{
}

void Cmydia13::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cmydia13, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmydia13::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmydia13::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cmydia13 消息处理程序


void Cmydia13::OnBnClickedButton2()
{
	 Cmydia12* pOneDlgObj6 = new  Cmydia12; 
	if (  pOneDlgObj6) 
	{ 
	BOOL ret = pOneDlgObj6->Create(IDD_DIALOG9,this); 
	} 
	pOneDlgObj6->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}


void Cmydia13::OnBnClickedButton1()
{
	 C坦克大战界面30Dlg* pOneDlgObj6 = new   C坦克大战界面30Dlg; 
	if (  pOneDlgObj6) 
	{ 
	BOOL ret = pOneDlgObj6->Create(IDD_MY30_DIALOG,this); 
	} 
	pOneDlgObj6->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}
