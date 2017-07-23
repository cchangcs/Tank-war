// Cmydia11.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战界面3.0.h"
#include "Cmydia11.h"
#include "afxdialogex.h"
#include"Cmydia9.h"
#include"Cmydia12.h"
#include"坦克大战界面3.0Dlg.h"
// Cmydia11 对话框

IMPLEMENT_DYNAMIC(Cmydia11, CDialogEx)

Cmydia11::Cmydia11(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmydia11::IDD, pParent)
{

}

Cmydia11::~Cmydia11()
{
}

void Cmydia11::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cmydia11, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmydia11::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cmydia11 消息处理程序


void Cmydia11::OnBnClickedButton1()
{
	 Cmydia9* pOneDlgObj10 = new  Cmydia9; 
	if (  pOneDlgObj10) 
	{ 
	BOOL ret = pOneDlgObj10->Create(IDD_DIALOG7,this); 
	} 
	pOneDlgObj10->ShowWindow(SW_SHOW);
	 Cmydia11::OnOK();
	// TODO: 在此添加控件通知处理程序代码
}
