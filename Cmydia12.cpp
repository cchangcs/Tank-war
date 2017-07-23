// Cmydia12.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战界面3.0.h"
#include "Cmydia12.h"
#include "afxdialogex.h"
#include"Cmydia10.h"

// Cmydia12 对话框

IMPLEMENT_DYNAMIC(Cmydia12, CDialogEx)

Cmydia12::Cmydia12(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmydia12::IDD, pParent)
{

}

Cmydia12::~Cmydia12()
{
}

void Cmydia12::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cmydia12, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmydia12::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cmydia12 消息处理程序


void Cmydia12::OnBnClickedButton1()
{
	  Cmydia10* pOneDlgObj9 = new  Cmydia10; 
	if (  pOneDlgObj9) 
	{ 
	BOOL ret = pOneDlgObj9->Create(IDD_DIALOG8,this); 
	} 
	pOneDlgObj9->ShowWindow(SW_SHOW);
	 Cmydia12::OnOK();
	// TODO: 在此添加控件通知处理程序代码
}
