// Cmydia15.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战界面3.0.h"
#include "Cmydia15.h"
#include "afxdialogex.h"
#include"Cmydia12.h"
#include"坦克大战界面3.0Dlg.h"

// Cmydia15 对话框

IMPLEMENT_DYNAMIC(Cmydia15, CDialogEx)

Cmydia15::Cmydia15(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmydia15::IDD, pParent)
{

}

Cmydia15::~Cmydia15()
{
}

void Cmydia15::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cmydia15, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmydia15::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmydia15::OnBnClickedButton2)
END_MESSAGE_MAP()


// Cmydia15 消息处理程序


void Cmydia15::OnBnClickedButton1()
{
	 Cmydia12* pOneDlgObj6 = new  Cmydia12; 
	if (  pOneDlgObj6) 
	{ 
	BOOL ret = pOneDlgObj6->Create(IDD_DIALOG9,this); 
	} 
	pOneDlgObj6->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}


void Cmydia15::OnBnClickedButton2()
{
	 C坦克大战界面30Dlg* pOneDlgObj6 = new   C坦克大战界面30Dlg; 
	if (  pOneDlgObj6) 
	{ 
	BOOL ret = pOneDlgObj6->Create(IDD_MY30_DIALOG,this); 
	} 
	pOneDlgObj6->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}
