// Cmydia1.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战界面3.0.h"
#include "Cmydia1.h"
#include "afxdialogex.h"
#include"Cmydia6.h"
#include"Cmydia11.h"
#include"坦克大战界面3.0Dlg.h"
// Cmydia1 对话框

IMPLEMENT_DYNAMIC(Cmydia1, CDialogEx)

Cmydia1::Cmydia1(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmydia1::IDD, pParent)
{

}

Cmydia1::~Cmydia1()
{
}

void Cmydia1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cmydia1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmydia1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmydia1::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cmydia1 消息处理程序


void Cmydia1::OnBnClickedButton2()
{
	 C坦克大战界面30Dlg* pOneDlgObj6 = new   C坦克大战界面30Dlg; 
	if (  pOneDlgObj6) 
	{ 
	BOOL ret = pOneDlgObj6->Create(IDD_MY30_DIALOG,this); 
	} 
	pOneDlgObj6->ShowWindow(SW_SHOW);
	
	// TODO: 在此添加控件通知处理程序代码
}


void Cmydia1::OnBnClickedButton1()
{
	  Cmydia11* pOneDlgObj6 = new  Cmydia11; 
	if (  pOneDlgObj6) 
	{ 
	BOOL ret = pOneDlgObj6->Create(IDD_DIALOG10,this); 
	} 
	pOneDlgObj6->ShowWindow(SW_SHOW);

	// TODO: 在此添加控件通知处理程序代码
}
