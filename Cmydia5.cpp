// Cmydia5.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战界面3.0.h"
#include "Cmydia5.h"
#include "afxdialogex.h"
#include"resource.h"
#include"windows.h"
#include "mmsystem.h"
#include<stdio.h>
#pragma  comment(lib,"WinMM.Lib")
#pragma comment( lib, "Winmm.lib" )

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cmydia5 对话框
int nEditFlag=0;

IMPLEMENT_DYNAMIC(Cmydia5, CDialogEx)

Cmydia5::Cmydia5(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmydia5::IDD, pParent)
{

}

Cmydia5::~Cmydia5()
{
}

void Cmydia5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cmydia5, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON9, &Cmydia5::OnBnClickedButton9)

	ON_BN_CLICKED(IDC_BUTTON25, &Cmydia5::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &Cmydia5::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &Cmydia5::OnBnClickedButton27)
END_MESSAGE_MAP()


// Cmydia5 消息处理程序


/*void Cmydia5::OnBnClickedButton22()
{
	//
	MessageBox(_T("error"));
	// TODO: 在此添加控件通知处理程序代码
}

*/
void Cmydia5::OnBnClickedButton9()
{
	PlaySound(NULL ,NULL,SND_LOOP|SND_ASYNC);//关闭音乐
	// TODO: 在此添加控件通知处理程序代码
}




void Cmydia5::OnBnClickedButton25()
{
	PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC); //开启音乐
	// TODO: 在此添加控件通知处理程序代码
}


void Cmydia5::OnBnClickedButton26()
{
	nEditFlag=1;
	// TODO: 在此添加控件通知处理程序代码
}


void Cmydia5::OnBnClickedButton27()
{
	nEditFlag=2;
	// TODO: 在此添加控件通知处理程序代码
}
