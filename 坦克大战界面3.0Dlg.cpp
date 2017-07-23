
// 坦克大战界面3.0Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战界面3.0.h"
#include "坦克大战界面3.0Dlg.h"
#include "afxdialogex.h"
#include"resource.h"
#include"windows.h"
#include"Cmydia4.h"
#include"Cmydia5.h"
#include "mmsystem.h"
#include<stdio.h>
#pragma  comment(lib,"WinMM.Lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Cmydia4 Cm;
BOOL np=false;
int nm=0;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX};

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C坦克大战界面30Dlg 对话框



C坦克大战界面30Dlg::C坦克大战界面30Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C坦克大战界面30Dlg::IDD, pParent)
{

	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
	//  rect = 0;
}

void C坦克大战界面30Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON7, m_win);
}

BEGIN_MESSAGE_MAP(C坦克大战界面30Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &C坦克大战界面30Dlg::OnClickedButton5)
ON_WM_SIZE()
ON_NOTIFY(BCN_DROPDOWN, IDC_BUTTON7, &C坦克大战界面30Dlg::OnDropdownButton7)
ON_BN_CLICKED(8, &C坦克大战界面30Dlg::OnBnClicked8)
ON_BN_CLICKED(IDC_BUTTON4, &C坦克大战界面30Dlg::OnBnClickedButton4)
ON_BN_CLICKED(8, &C坦克大战界面30Dlg::OnBnClicked8)
ON_BN_CLICKED(IDC_BUTTON2, &C坦克大战界面30Dlg::OnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON6, &C坦克大战界面30Dlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON7, &C坦克大战界面30Dlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// C坦克大战界面30Dlg 消息处理程序

BOOL C坦克大战界面30Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetTimer(1,1000,NULL);
	GetClientRect(&rect);
    oSize.x=rect.right-rect.left;
	oSize.y=rect.bottom-rect.top;
//...
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C坦克大战界面30Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C坦克大战界面30Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C坦克大战界面30Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void C坦克大战界面30Dlg::OnClickedButton5()
{
	Cmydia4* pOneDlgObj1 = new Cmydia4; 
	if ( pOneDlgObj1) 
	{ 
	BOOL ret = pOneDlgObj1->Create(IDD_DIALOG3,this); 
	} 
	pOneDlgObj1->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}
void C坦克大战界面30Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	 if (nType==SIZE_RESTORED || nType==SIZE_MAXIMIZED)  
    {  
                 
                float   ratio[2];  
                POINT   newDialogSize;  
                CRect   newRect;  
                GetClientRect(&newRect);  
                newDialogSize.x = newRect.right - newRect.left;  
                newDialogSize.y = newRect.bottom - newRect.top;  
                ratio[0]    = (float)newDialogSize.x / oSize.x;  
                ratio[1]    = (float)newDialogSize.y / oSize.y;  
                CRect Rect;  
                int woc;  
                CPoint OldTLPoint, NewTLPint;  
                CPoint OldBRPoint, NewBRPint;  
                HWND  hwndChild = ::GetWindow(m_hWnd,GW_CHILD);  
                while(hwndChild)  
                {   
                       woc  = ::GetDlgCtrlID(hwndChild);  
                       GetDlgItem(woc)->GetWindowRect(Rect);  
                       ScreenToClient(Rect);  
                       OldTLPoint = Rect.TopLeft();  
                       NewTLPint.x  = long(OldTLPoint.x*ratio[0]);  
                       NewTLPint.y  = long(OldTLPoint.y*ratio[1]);  
                       OldBRPoint   = Rect.BottomRight();  
                       NewBRPint.x  = long(OldBRPoint.x*ratio[0]);  
                       NewBRPint.y  = long(OldBRPoint.y*ratio[1]);  
                       Rect.SetRect(NewTLPint,NewBRPint);  
                       GetDlgItem(woc)->MoveWindow(Rect,TRUE);  
                       hwndChild=::GetWindow(hwndChild, GW_HWNDNEXT);  
               }   
  
                oSize   = newDialogSize;      
  
    }
	// TODO: 在此处添加消息处理程序代码
}


void C坦克大战界面30Dlg::OnDropdownButton7(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMBCDROPDOWN pDropDown = reinterpret_cast<LPNMBCDROPDOWN>(pNMHDR);
		*pResult = 0;
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}



void C坦克大战界面30Dlg::OnBnClickedButton4()
{
		 Cmydia4* pOneDlgObj2= new  Cmydia4; 
	if (  pOneDlgObj2) 
	{ 
	BOOL ret = pOneDlgObj2->Create(IDD_DIALOG4,this); 
	} 
	pOneDlgObj2->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
	//PlaySound(NULL ,NULL,SND_LOOP|SND_ASYNC);
}



/*void C坦克大战界面30Dlg::OnClickedButton1()
{
	PlaySound(L"C:\\Users\\Seavan_CC\\Desktop\\Tank\\res\\sulian" ,NULL,SND_FILENAME|SND_ASYNC); //开启音乐
	// TODO: 在此添加控件通知处理程序代码
}*/


/*void C坦克大战界面30Dlg::OnBnClickedButton8()
{
	PlaySound(NULL ,NULL,SND_LOOP|SND_ASYNC);//关闭音乐
	// TODO: 在此添加控件通知处理程序代码
}*/


void C坦克大战界面30Dlg::OnBnClicked8()
{
		 Cmydia4* pOneDlgObj3 = new  Cmydia4; 
	if (  pOneDlgObj3) 
	{ 
	BOOL ret = pOneDlgObj3->Create(IDD_DIALOG4,this); 
	} 
	pOneDlgObj3->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}


void C坦克大战界面30Dlg::OnClickedButton2()
{
	 Cmydia4* pOneDlgObj4 = new  Cmydia4; 
	if (  pOneDlgObj4) 
	{ 
	BOOL ret = pOneDlgObj4->Create(IDD_DIALOG4,this); 
	} 
	pOneDlgObj4->ShowWindow(SW_SHOW);

	// TODO: 在此添加控件通知处理程序代码
}
C坦克大战界面30Dlg::~C坦克大战界面30Dlg(){
		
}



void C坦克大战界面30Dlg::OnBnClickedButton6()
{
	 C坦克大战界面30Dlg::OnOK();
	// TODO: 在此添加控件通知处理程序代码
}


void C坦克大战界面30Dlg::OnBnClickedButton7()
{
	 Cmydia5* pOneDlgObj5 = new  Cmydia5; 
	if (  pOneDlgObj5) 
	{ 
	BOOL ret = pOneDlgObj5->Create(IDD_DIALOG5,this); 
	} 
	pOneDlgObj5->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}
