// ChildCla1.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战界面3.0.h"
#include "ChildCla1.h"
#include "afxdialogex.h"

// CChildCla1 对话框

IMPLEMENT_DYNAMIC(CChildCla1, CDialogEx)

CChildCla1::CChildCla1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChildCla1::IDD, pParent)
{

}

CChildCla1::~CChildCla1()
{
}

void CChildCla1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChildCla1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CChildCla1::OnBnClickedButton1)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CChildCla1 消息处理程序


void CChildCla1::OnBnClickedButton1()
{
	CDialog::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CChildCla1::OnInitDialog()
{
	CDialogEx::OnInitDialog();
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

	



void CChildCla1::OnSize(UINT nType, int cx, int cy)
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
