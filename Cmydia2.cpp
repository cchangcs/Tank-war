// Cmydia2.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战界面3.0.h"
#include "Cmydia2.h"
#include "afxdialogex.h"
#include"Cmydia4.h"
#include"坦克大战界面3.0Dlg.h"

// Cmydia2 对话框

IMPLEMENT_DYNAMIC(Cmydia2, CDialogEx)

Cmydia2::Cmydia2(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmydia2::IDD, pParent)
{

}

Cmydia2::~Cmydia2()
{
}

void Cmydia2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cmydia2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON8, &Cmydia2::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmydia2::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cmydia2 消息处理程序


void Cmydia2::OnBnClickedButton8()
{
	Cmydia4* pOneDlgObj6 = new  Cmydia4; 
	if (  pOneDlgObj6) 
	{ 
	BOOL ret = pOneDlgObj6->Create(IDD_DIALOG4,this); 
	} 
	pOneDlgObj6->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}


void Cmydia2::OnBnClickedButton1()
{
	C坦克大战界面30Dlg* pOneDlgObj6 = new  C坦克大战界面30Dlg; 
	if (  pOneDlgObj6) 
	{ 
	BOOL ret = pOneDlgObj6->Create(IDD_MY30_DIALOG,this); 
	} 
	pOneDlgObj6->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}
