// Cmydia4.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战界面3.0.h"
#include "Cmydia4.h"
#include "afxdialogex.h"
#include "afxmt.h"
#include"Cmydia6.h"
#include"坦克大战界面3.0Dlg.h"// Cmydia4 对话框
IMPLEMENT_DYNAMIC(Cmydia4, CDialogEx)


Cmydia4::Cmydia4(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmydia4::IDD, pParent)
{

}

Cmydia4::~Cmydia4()
{
}

void Cmydia4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON2, a);
	
}

BEGIN_MESSAGE_MAP(Cmydia4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmydia4::OnBnClickedButton21)
END_MESSAGE_MAP()

 void Cmydia4::OnBnClickedButton21()
 { 
	  Cmydia6* pOneDlgObj6 = new  Cmydia6; 
	if (  pOneDlgObj6) 
	{ 
	BOOL ret = pOneDlgObj6->Create(IDD_DIALOG6,this); 
	} 
	pOneDlgObj6->ShowWindow(SW_SHOW);
	 Cmydia4::OnOK();
	 // TODO: 在此添加控件通知处理程序代码
 }
