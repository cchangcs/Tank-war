// Cmydia6.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战界面3.0.h"
#include "Cmydia6.h"
#include "afxdialogex.h"
#include "Cmydia2.h"
#include "Cmydia1.h"
#include"Thing.h"
#include<windows.h>
#include "mmsystem.h"
#include<stdio.h>
#pragma  comment(lib,"WinMM.Lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cmydia6 对话框

IMPLEMENT_DYNAMIC(Cmydia6, CDialogEx)

Cmydia6::Cmydia6(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmydia6::IDD, pParent)
{
	
}

Cmydia6::~Cmydia6()
{
}

void Cmydia6::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cmydia6, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_QUERYDRAGICON() 
END_MESSAGE_MAP()


// Cmydia6 消息处理程序
BOOL Cmydia6::OnInitDialog()
{
	CDialogEx::OnInitDialog();
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
	int nFullWidth=GetSystemMetrics(SM_CXSCREEN);
	int nFullHeight=GetSystemMetrics(SM_CYSCREEN);
	MoveWindow(0,0,nFullWidth,nFullHeight);//窗口最大化
	CreateThread(NULL,0,InitTank,this,0,NULL);
	CreateThread(NULL,0,MyPaint,this,0,NULL);//启动线程*
	CreateThread(NULL,0,Fail,this,0,NULL);
	CreateThread(NULL,0,PlayerButtle,this,0,NULL);
	CreateThread(NULL,0,PlayerMove,this,0,NULL);
	CreateThread(NULL,0,EnemyMove0,this,0,NULL);
	CreateThread(NULL,0,EnemyMove1,this,0,NULL);
	CreateThread(NULL,0,EnemyMove2,this,0,NULL);
	CreateThread(NULL,0,EnemyMove3,this,0,NULL);
	CreateThread(NULL,0,EnemyMove4,this,0,NULL);
	CreateThread(NULL,0,EnemyMove5,this,0,NULL);
	CreateThread(NULL,0,EnemyMove6,this,0,NULL);
	CreateThread(NULL,0,EnemyMove7,this,0,NULL);
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cmydia6::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		
		
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。


//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cmydia6::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

DWORD WINAPI MyPaint(LPVOID lpParam)			//贴图线程
{
	Cmydia6 *c=(Cmydia6*)lpParam;

	HWND hWnd= c->GetSafeHwnd();//获取屏幕的句柄

	
	c->hdc = ::GetDC(hWnd);						//获取屏幕的DC
	c->mdc = ::CreateCompatibleDC(c->hdc);		//关联和屏幕兼容的内存DC
	c->bufdc = ::CreateCompatibleDC(c->hdc);	//关联和屏幕兼容的缓冲DC
	RECT rect;
	::GetWindowRect(hWnd,&rect);				//获取屏幕的大小
	c->hBitmap =::CreateCompatibleBitmap(c->hdc,rect.right,rect.bottom); //让内存DC关联的位图设置大小
	SelectObject(c->mdc,c->hBitmap);//进行关联
	c->Back.LoadBitmap(IDB_BITMAP14);//进入关卡的地图
	c->BackGround=HBITMAP(c->Back);	//转换关卡的地图的格式
	
	while(c->control)
	{
		SelectObject(c->bufdc,c->BackGround);
		BitBlt(c->mdc,0,0,rect.right,rect.bottom,c->bufdc,0,0,SRCCOPY);
		if (1==c->Player.Attribute)
		{
				SelectObject(c->bufdc,c->Player.HImage);
				switch (c->Player.Direct)
				{
				case 1:TransparentBlt(c->mdc,c->Player.Site.x,c->Player.Site.y,60,60,c->bufdc,0,0,60,60,RGB(200,200,200));break;
				case 2:TransparentBlt(c->mdc,c->Player.Site.x,c->Player.Site.y,60,60,c->bufdc,60,0,60,60,RGB(200,200,200));break;
				case 3:TransparentBlt(c->mdc,c->Player.Site.x,c->Player.Site.y,60,60,c->bufdc,120,0,60,60,RGB(200,200,200));break;
				case 4:TransparentBlt(c->mdc,c->Player.Site.x,c->Player.Site.y,60,60,c->bufdc,180,0,60,60,RGB(200,200,200));break;
				}
		}
		for(int i=0;i<3;i++)
		{
			if(1==c->BPlayer[i].Attribute)
			{
				SelectObject(c->bufdc,c->BPlayer[i].HBImage);
				TransparentBlt(c->mdc,c->BPlayer[i].Site.x,c->BPlayer[i].Site.y,10,10,c->bufdc,10,0,10,10,RGB(200,200,200));
			}
		}

		for(int i=0;i<8;i++)
		{
			if(1==c->Enemy[i].Attribute)
			{
				SelectObject(c->bufdc,c->Enemy[i].HImage);
				switch(c->Enemy[i].Direct)
				{
				case 1:TransparentBlt(c->mdc,c->Enemy[i].Site.x,c->Enemy[i].Site.y,60,60,c->bufdc,0,0,60,60,RGB(200,200,200));break;
				case 2:TransparentBlt(c->mdc,c->Enemy[i].Site.x,c->Enemy[i].Site.y,60,60,c->bufdc,60,0,60,60,RGB(200,200,200));break;
				case 3:TransparentBlt(c->mdc,c->Enemy[i].Site.x,c->Enemy[i].Site.y,60,60,c->bufdc,120,0,60,60,RGB(200,200,200));break;
				case 4:TransparentBlt(c->mdc,c->Enemy[i].Site.x,c->Enemy[i].Site.y,60,60,c->bufdc,180,0,60,60,RGB(200,200,200));break;
				}
			}
			if(1==c->BEnemy[i].Attribute)
			{
				SelectObject(c->bufdc,c->BEnemy[i].HBImage);
				TransparentBlt(c->mdc,c->BEnemy[i].Site.x,c->BEnemy[i].Site.y,10,10,c->bufdc,0,0,10,10,RGB(200,200,200));
			}
		}
		/*
		for(int j=0;j<4;j++)
		{
			if(1==c->WGame[j].Attribute)
			{
				SelectObject(c->bufdc,c->WGame[j].HWImage);
				switch(c->WGame[j].Mark)
				{
			    case 0:TransparentBlt(c->mdc,c->WGame[j].Site.x,c->WGame[j].Site.y,60,60,c->bufdc,0,0,60,60,RGB(200,200,200));break;
			    case 1:TransparentBlt(c->mdc,c->WGame[j].Site.x,c->WGame[j].Site.y,60,60,c->bufdc,60,0,60,60,RGB(200,200,200));break;
			    case 2:TransparentBlt(c->mdc,c->WGame[j].Site.x,c->WGame[j].Site.y,60,60,c->bufdc,120,0,60,60,RGB(200,200,200));break;
			    case 3:TransparentBlt(c->mdc,c->WGame[j].Site.x,c->WGame[j].Site.y,60,60,c->bufdc,180,0,60,60,RGB(200,200,200));break;
				}
			}
		}
		*/
		//BitBlt(c->mdc,100,200,200,200,c->bufdc,0,0,SRCCOPY);

		BitBlt(c->hdc,0,0,rect.right,rect.bottom,c->mdc,0,0,SRCCOPY);

		::Sleep(1);
	}
	//::ReleaseDC(c->hdc);
	::ReleaseDC(hWnd,c->hdc);
	::DeleteDC(c->mdc);
	::DeleteDC(c->bufdc);
	return TRUE;
}
	
DWORD WINAPI InitTank(LPVOID lpParam)
{
	Cmydia6 *c=(Cmydia6*)lpParam;

	c->TotalEnemy=8;
	c->p.x=0,c->p.y=650;
	c->Player.InitTank(3,1,8,1,1,0,c->p);
	c->Player.LoadImage();

	c->p.x=1100,c->p.y=50;
	c->Enemy[0].InitTank(3,4,6,1,2,1,c->p);
	c->Enemy[0].LoadImage();
	c->p.x-=10,c->p.y+=25;
	c->BEnemy[0].InitBullet(4,1,10,2,c->p);
	c->BEnemy[0].LoadImage();

	c->p.x=1100,c->p.y=250;
	c->Enemy[1].InitTank(3,4,6,1,2,2,c->p);
	c->Enemy[1].LoadImage();
	c->p.x-=10,c->p.y+=25;
	c->BEnemy[1].InitBullet(4,1,10,2,c->p);
	c->BEnemy[1].LoadImage();
	
	c->p.x=1100,c->p.y=450;
	c->Enemy[2].InitTank(3,4,6,1,2,3,c->p);
	c->Enemy[2].LoadImage();
	c->p.x-=10,c->p.y+=25;
	c->BEnemy[2].InitBullet(4,1,10,2,c->p);
	c->BEnemy[2].LoadImage();

	c->p.x=1100,c->p.y=650;
	c->Enemy[3].InitTank(3,4,6,1,2,4,c->p);
	c->Enemy[3].LoadImage();
	c->p.x-=10,c->p.y+=25;
	c->BEnemy[3].InitBullet(4,1,10,2,c->p);
	c->BEnemy[3].LoadImage();

	c->p.x=700,c->p.y=50;
	c->Enemy[4].InitTank(3,4,6,1,2,5,c->p);
	c->Enemy[4].LoadImage();
	c->p.x-=10,c->p.y+=25;
	c->BEnemy[4].InitBullet(4,1,10,2,c->p);
	c->BEnemy[4].LoadImage();

	c->p.x=700,c->p.y=250;
	c->Enemy[5].InitTank(3,3,6,1,2,6,c->p);
	c->Enemy[5].LoadImage();
	c->p.x+=25,c->p.y+=60;
	c->BEnemy[5].InitBullet(3,1,10,2,c->p);
	c->BEnemy[5].LoadImage();

	c->p.x=700,c->p.y=450;
	c->Enemy[6].InitTank(3,2,6,1,2,7,c->p);
	c->Enemy[6].LoadImage();
	c->p.x+=60,c->p.y+=25;
	c->BEnemy[6].InitBullet(2,1,10,2,c->p);
	c->BEnemy[6].LoadImage();

	c->p.x=700,c->p.y=650;
	c->Enemy[7].InitTank(3,1,6,1,2,8,c->p);
	c->Enemy[7].LoadImage();
	c->p.x+=25,c->p.y-=10;
	c->BEnemy[7].InitBullet(1,1,10,2,c->p);
	c->BEnemy[7].LoadImage();
	/*
	c->p.x=300,c->p.y=50;
	c->WGame[0].InitWall(3,1,0,c->p);
	c->WGame[0].LoadImage();

	c->p.x=300,c->p.y=250;
	c->WGame[1].InitWall(3,1,1,c->p);
	c->WGame[1].LoadImage();

	c->p.x=300,c->p.y=450;
	c->WGame[2].InitWall(2,1,2,c->p);
	c->WGame[2].LoadImage();

	c->p.x=300,c->p.y=650;
	c->WGame[3].InitWall(3,1,3,c->p);
	c->WGame[3].LoadImage();
	*/
	c->BPlayer[0].InitBullet(1,0,10,1,c->p);
	c->BPlayer[0].LoadImage();
	c->BPlayer[1].InitBullet(1,0,10,1,c->p);
	c->BPlayer[1].LoadImage();
	c->BPlayer[2].InitBullet(1,0,10,1,c->p);
	c->BPlayer[2].LoadImage();
	c->pi=0;


	c->KeyDown=false;
	c->KeyLeft=false;
	c->KeyUp=false;
	c->KeyRight=false;
	c->KeySpace=false;

	return TRUE;
}

void Cmydia6::InitCompareTank()
{
	tank[0]=Player.Site;
	CPoint pn;
	pn.x=-20,pn.y=-20;
	for(int i=1;i<9;i++)
	{
		if(1==Enemy[i-1].Attribute)
		{
		   tank[i]=Enemy[i-1].Site;
		}
		else
		{
			tank[i]=pn;
		}
	}
}

BOOL Cmydia6::PreTranslateMessage(MSG* pMsg)
{
	bool Judge=false;
	if (pMsg-> message == WM_KEYDOWN)
	{

		if(pMsg-> wParam== VK_UP)
		{
			KeyUp=true;
		}
		if(pMsg-> wParam== VK_DOWN)
		{
			KeyDown=true;
		}
		if(pMsg-> wParam== VK_LEFT)
		{
			KeyLeft=true;
		}
		if(pMsg-> wParam== VK_RIGHT)
		{
			KeyRight=true;
		}
		if(pMsg->wParam==VK_SPACE)
		{  PlaySound(L"zidan" ,NULL,SND_NOSTOP|SND_ASYNC);
			if(0==BPlayer[pi].Attribute)
			{
				BPlayer[pi].InitAgain(Player.Site,Player.Direct);
			
			}
			pi++;
			if(3==pi)
			{
				pi=0;
			}
		
		}
		if(pMsg->wParam==VK_ESCAPE)
		{
			control=false;
			for(int j=0;j<9;j++)
			{
				ControlEnd[j]=false;
			}
			for(int k=0;k<3;k++)
			{
				ControlEnd2[k]=false;
			}
			::Sleep(100);
		}
	 }
	if(pMsg-> message == WM_KEYUP)
	{
		if(pMsg-> wParam== VK_UP)
		{
			KeyUp=false;
		}
		if(pMsg-> wParam== VK_DOWN)
		{
			KeyDown=false;
		}
		if(pMsg-> wParam== VK_LEFT)
		{
			KeyLeft=false;
		}
		if(pMsg-> wParam== VK_RIGHT)
		{
			KeyRight=false;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

DWORD WINAPI PlayerMove(LPVOID lpParam)
{
	Cmydia6 *c=(Cmydia6*)lpParam;
	while(c->ControlEnd[0])
	{
		if(true==c->KeyUp)
		{
			c->Player.Direct=1;
			c->InitCompareTank();
			if(!c->Player.Collision(c->tank,9))
			{
				c->Player.Site.y-=c->Player.Speed;
			}
			::Sleep(40);
			continue;
		}
		if(true==c->KeyDown)
		{
			c->Player.Direct=3;
			c->InitCompareTank();
			if(!c->Player.Collision(c->tank,9))
			{
				c->Player.Site.y+=c->Player.Speed;
			}
			::Sleep(40);
			continue;
		}
		if(true==c->KeyLeft)
		{
			c->Player.Direct=4;
			c->InitCompareTank();
			if(!c->Player.Collision(c->tank,9))
			{
				c->Player.Site.x-=c->Player.Speed;
			}
			::Sleep(40);
			continue;
		}
		if(true==c->KeyRight)
		{
			c->Player.Direct=2;
			c->InitCompareTank();
			if(!c->Player.Collision(c->tank,9))
			{
				c->Player.Site.x+=c->Player.Speed;
			}
			::Sleep(40);
			continue;
		}
		::Sleep(1);
	}
	return TRUE;
}

DWORD WINAPI PlayerButtle(LPVOID lpParam)
{
	Cmydia6 *c=(Cmydia6*)lpParam;
	int j,k;
	while(c->ControlEnd[0])
	{
		for(int i=0;i<3;i++)
		{
			if(1==c->BPlayer[i].Attribute)
			{
				c->InitCompareTank();
				j=c->BPlayer[i].Collision(c->tank,9);
				
				if(0==j)
				{
					c->BPlayer[i].BulletMove();
				}
				if(j>0&&j<9)
				{
					c->Enemy[j-1].HP--;
				
					if(0==c->Enemy[j-1].HP)
					{
						c->Enemy[j-1].Attribute=0;
						c->BEnemy[j-1].Attribute=0;

					    c->ControlEnd[j]=false;
						c->TotalEnemy--;
						if(c->TotalEnemy==0)
						{
							Cmydia1 pOneDlgObj8;
							pOneDlgObj8.DoModal();

						}
						
					}
				}
				k=c->BPlayer[i].Conflict(c->wall,5);
				if(0==k)
				{
					c->BPlayer[i].BulletMove();
				}
				if(k>0&&k<5)
				{
					c->WGame[k-1].HP-=1;
				
					if(0==c->WGame[k-1].HP)
					{
						c->WGame[k-1].Attribute=0;
						 c->ControlEnd2[k]=false;
					
						
						
						
					}
				}
			}
		}
		::Sleep(25);
	}
	return TRUE;
}


DWORD WINAPI EnemyMove0(LPVOID lpParam)
{
	Cmydia6 *c=(Cmydia6*)lpParam;
	int i;
	while(c->ControlEnd[1])
	{
		if(c->ControlTime[0])
		{
			if(0==c->BEnemy[0].Attribute)
			{
				c->BEnemy[0].InitAgain(c->Enemy[0].Site,c->Enemy[0].Direct);
				
			}
			else
			{
				c->InitCompareTank();
				i=c->BEnemy[0].Collision(c->tank,9);
				if(0==i)
				{
					c->BEnemy[0].BulletMove();
				}
				if(1==i)
				{
					c->Player.HP--;
				
					if(0==c->Player.HP)
					{
						c->Player.Attribute=0;
						Cmydia2 pOneDlgObj7;
						pOneDlgObj7.DoModal();
						for(int j=0;j<9;j++)
						{
							c->ControlEnd[j]=false;
						}
					}
				}
			}

			if(false==c->Enemy[0].move)
			{
				c->Enemy[0].ChaseMode(c->Player.Site);
			}
			if(1==c->Enemy[0].Attribute)
			{
				c->InitCompareTank();
				if(!c->Enemy[0].Collision(c->tank,9))
				{
					switch(c->Enemy[0].Direct)
					{
					case 1:c->Enemy[0].Site.y-=c->Enemy[0].Speed;break;
					case 2:c->Enemy[0].Site.x+=c->Enemy[0].Speed;break;
					case 3:c->Enemy[0].Site.y+=c->Enemy[0].Speed;break;
					case 4:c->Enemy[0].Site.x-=c->Enemy[0].Speed;break;
					}
					if(c->Enemy[0].move==true)
					{
						c->mtank[0]++;
					}
					if(15==c->mtank[0])
					{
						c->Enemy[0].move=false;
						c->mtank[0]=0;
					}
				}
			}
		}
		::Sleep(30);
	}
	return TRUE;
}


DWORD WINAPI EnemyMove1(LPVOID lpParam)
{
	Cmydia6 *c=(Cmydia6*)lpParam;
	int i;
	while(c->ControlEnd[2])
	{
		if(c->ControlTime[1])
		{
			if(0==c->BEnemy[1].Attribute)
			{
				c->BEnemy[1].InitAgain(c->Enemy[1].Site,c->Enemy[1].Direct);
				
			}
			else
			{
				c->InitCompareTank();
				i=c->BEnemy[1].Collision(c->tank,9);
				if(0==i)
				{
					c->BEnemy[1].BulletMove();
				}
				if(1==i)
				{
					c->Player.HP--;
				
					if(0==c->Player.HP)
					{
						c->Player.Attribute=0;
						Cmydia2 pOneDlgObj7;
						pOneDlgObj7.DoModal();
						for(int j=0;j<9;j++)
						{
							c->ControlEnd[j]=false;
						}
					}
				}
			}

			if(false==c->Enemy[1].move)
			{
				c->Enemy[1].ChaseMode(c->Player.Site);
			}
			if(1==c->Enemy[1].Attribute)
			{
				c->InitCompareTank();
				if(!c->Enemy[1].Collision(c->tank,9))
				{
					switch(c->Enemy[1].Direct)
					{
					case 1:c->Enemy[1].Site.y-=c->Enemy[1].Speed;break;
					case 2:c->Enemy[1].Site.x+=c->Enemy[1].Speed;break;
					case 3:c->Enemy[1].Site.y+=c->Enemy[1].Speed;break;
					case 4:c->Enemy[1].Site.x-=c->Enemy[1].Speed;break;
					}
					if(c->Enemy[1].move==true)
					{
						c->mtank[1]++;
					}
					if(15==c->mtank[1])
					{
						c->Enemy[1].move=false;
						c->mtank[1]=0;
					}
				}
			}
		}
		::Sleep(30);
	}
	return TRUE;
}

DWORD WINAPI EnemyMove2(LPVOID lpParam)
{
	Cmydia6 *c=(Cmydia6*)lpParam;
	int i;
	while(c->ControlEnd[3])
	{
		if(c->ControlTime[2])
		{
			if(0==c->BEnemy[2].Attribute)
			{
				c->BEnemy[2].InitAgain(c->Enemy[2].Site,c->Enemy[2].Direct);
				
			}
			else
			{
				c->InitCompareTank();
				i=c->BEnemy[2].Collision(c->tank,9);
				if(0==i)
				{
					c->BEnemy[2].BulletMove();
				}
				if(1==i)
				{
					c->Player.HP--;
				
					if(0==c->Player.HP)
					{
						c->Player.Attribute=0;
						Cmydia2 pOneDlgObj7;
						pOneDlgObj7.DoModal();
						for(int j=0;j<9;j++)
						{
							c->ControlEnd[j]=false;
						}
					}
				}
			}

			if(false==c->Enemy[2].move)
			{
				c->Enemy[2].ChaseMode(c->Player.Site);
			}
			if(1==c->Enemy[2].Attribute)
			{
				c->InitCompareTank();
				if(!c->Enemy[2].Collision(c->tank,9))
				{
					switch(c->Enemy[2].Direct)
					{
					case 1:c->Enemy[2].Site.y-=c->Enemy[2].Speed;break;
					case 2:c->Enemy[2].Site.x+=c->Enemy[2].Speed;break;
					case 3:c->Enemy[2].Site.y+=c->Enemy[2].Speed;break;
					case 4:c->Enemy[2].Site.x-=c->Enemy[2].Speed;break;
					}
					if(c->Enemy[2].move==true)
					{
						c->mtank[2]++;
					}
					if(15==c->mtank[2])
					{
						c->Enemy[2].move=false;
						c->mtank[2]=0;
					}
				}
			}
		}
		::Sleep(30);
	}
	return TRUE;
}


DWORD WINAPI EnemyMove3(LPVOID lpParam)
{
	Cmydia6 *c=(Cmydia6*)lpParam;
	int i;
	while(c->ControlEnd[4])
	{
		if(c->ControlTime[3])
		{
			if(0==c->BEnemy[3].Attribute)
			{
				c->BEnemy[3].InitAgain(c->Enemy[3].Site,c->Enemy[3].Direct);
				
			}
			else
			{
				c->InitCompareTank();
				i=c->BEnemy[3].Collision(c->tank,9);
				if(0==i)
				{
					c->BEnemy[3].BulletMove();
				}
				if(1==i)
				{
					c->Player.HP--;
					
					if(0==c->Player.HP)
					{
						c->Player.Attribute=0;
						Cmydia2 pOneDlgObj7;
						pOneDlgObj7.DoModal();
						for(int j=0;j<9;j++)
						{
							c->ControlEnd[j]=false;
						}
					}
				}
			}

			if(false==c->Enemy[3].move)
			{
				c->Enemy[3].ChaseMode(c->Player.Site);
			}
			if(1==c->Enemy[3].Attribute)
			{
				c->InitCompareTank();
				if(!c->Enemy[3].Collision(c->tank,9))
				{
					switch(c->Enemy[3].Direct)
					{
					case 1:c->Enemy[3].Site.y-=c->Enemy[3].Speed;break;
					case 2:c->Enemy[3].Site.x+=c->Enemy[3].Speed;break;
					case 3:c->Enemy[3].Site.y+=c->Enemy[3].Speed;break;
					case 4:c->Enemy[3].Site.x-=c->Enemy[3].Speed;break;
					}
					if(c->Enemy[3].move==true)
					{
						c->mtank[3]++;
					}
					if(15==c->mtank[3])
					{
						c->Enemy[3].move=false;
						c->mtank[3]=0;
					}
				}
			}
		}
		::Sleep(30);
	}

	return TRUE;
}

DWORD WINAPI EnemyMove4(LPVOID lpParam)
{
	Cmydia6 *c=(Cmydia6*)lpParam;
	int i;
	while(c->ControlEnd[5])
	{
		if(c->ControlTime[4])
		{
			if(0==c->BEnemy[4].Attribute)
			{
				c->BEnemy[4].InitAgain(c->Enemy[4].Site,c->Enemy[4].Direct);
				
			}
			else
			{
				c->InitCompareTank();
				i=c->BEnemy[4].Collision(c->tank,9);
				if(0==i)
				{
					c->BEnemy[4].BulletMove();
				}
				if(1==i)
				{
					c->Player.HP--;
					;
					if(0==c->Player.HP)
					{
						c->Player.Attribute=0;
						Cmydia2 pOneDlgObj7;
						pOneDlgObj7.DoModal();
						for(int j=0;j<9;j++)
						{
							c->ControlEnd[j]=false;
						}
					}
				}
			}

			c->Enemy[4].RandomMode();
			if(1==c->Enemy[4].Attribute)
			{
				c->InitCompareTank();
				if(!c->Enemy[4].Collision(c->tank,9))
				{
					switch(c->Enemy[4].Direct)
					{
					case 1:c->Enemy[4].Site.y-=c->Enemy[4].Speed;break;
					case 2:c->Enemy[4].Site.x+=c->Enemy[4].Speed;break;
					case 3:c->Enemy[4].Site.y+=c->Enemy[4].Speed;break;
					case 4:c->Enemy[4].Site.x-=c->Enemy[4].Speed;break;
					}
				}
			}
		}
		::Sleep(30);
	}

	return TRUE;
}

DWORD WINAPI EnemyMove5(LPVOID lpParam)
{
	Cmydia6 *c=(Cmydia6*)lpParam;
	int i;
	while(c->ControlEnd[6])
	{
		if(c->ControlTime[5])
		{
			if(0==c->BEnemy[5].Attribute)
			{
				c->BEnemy[5].InitAgain(c->Enemy[5].Site,c->Enemy[5].Direct);
				
			}
			else
			{
				c->InitCompareTank();
				i=c->BEnemy[5].Collision(c->tank,9);
				if(0==i)
				{
					c->BEnemy[5].BulletMove();
				}
				if(1==i)
				{
					c->Player.HP--;
					
					if(0==c->Player.HP)
					{
						c->Player.Attribute=0;
						Cmydia2 pOneDlgObj7;
						pOneDlgObj7.DoModal();
						for(int j=0;j<9;j++)
						{
							c->ControlEnd[j]=false;
						}
					}
				}
			}

			c->Enemy[5].RandomMode();
			if(1==c->Enemy[5].Attribute)
			{
				c->InitCompareTank();
				if(!c->Enemy[5].Collision(c->tank,9))
				{
					switch(c->Enemy[5].Direct)
					{
					case 1:c->Enemy[5].Site.y-=c->Enemy[5].Speed;break;
					case 2:c->Enemy[5].Site.x+=c->Enemy[5].Speed;break;
					case 3:c->Enemy[5].Site.y+=c->Enemy[5].Speed;break;
					case 4:c->Enemy[5].Site.x-=c->Enemy[5].Speed;break;
					}
				}
			}
		}
		::Sleep(30);
	}

	return TRUE;
}

DWORD WINAPI EnemyMove6(LPVOID lpParam)
{
	Cmydia6 *c=(Cmydia6*)lpParam;
	int i;
	while(c->ControlEnd[7])
	{
		if(c->ControlTime[6])
		{
			if(0==c->BEnemy[6].Attribute)
			{
				c->BEnemy[6].InitAgain(c->Enemy[6].Site,c->Enemy[6].Direct);
				
			}
			else
			{
				c->InitCompareTank();
				i=c->BEnemy[6].Collision(c->tank,9);
				if(0==i)
				{
					c->BEnemy[6].BulletMove();
				}
				if(1==i)
				{
					c->Player.HP--;
					
					if(0==c->Player.HP)
					{
						c->Player.Attribute=0;
						Cmydia2 pOneDlgObj7;
						pOneDlgObj7.DoModal();
						for(int j=0;j<9;j++)
						{
							c->ControlEnd[j]=false;
						}
					}
				}
			}

			c->Enemy[6].RandomMode();
			if(1==c->Enemy[6].Attribute)
			{
				c->InitCompareTank();
				if(!c->Enemy[6].Collision(c->tank,9))
				{
					switch(c->Enemy[6].Direct)
					{
					case 1:c->Enemy[6].Site.y-=c->Enemy[6].Speed;break;
					case 2:c->Enemy[6].Site.x+=c->Enemy[6].Speed;break;
					case 3:c->Enemy[6].Site.y+=c->Enemy[6].Speed;break;
					case 4:c->Enemy[6].Site.x-=c->Enemy[6].Speed;break;
					}
				}
			}
		}
		::Sleep(30);
	}

	return TRUE;
}

DWORD WINAPI EnemyMove7(LPVOID lpParam)
{
	Cmydia6 *c=(Cmydia6*)lpParam;
	int i;
	while(c->ControlEnd[8])
	{
		if(c->ControlTime[7])
		{
			if(0==c->BEnemy[7].Attribute)
			{
				c->BEnemy[7].InitAgain(c->Enemy[7].Site,c->Enemy[7].Direct);
				
			}
			else
			{
				c->InitCompareTank();
				i=c->BEnemy[7].Collision(c->tank,9);
				if(0==i)
				{
					c->BEnemy[7].BulletMove();
				}
				if(1==i)
				{
					c->Player.HP--;
					
					if(0==c->Player.HP)
					{
						c->Player.Attribute=0;
						Cmydia2 pOneDlgObj7;
						pOneDlgObj7.DoModal();
						for(int j=0;j<9;j++)
						{
							c->ControlEnd[j]=false;
						}
					}
				}
			}
			c->Enemy[7].RandomMode();
			if(1==c->Enemy[7].Attribute)
			{
				c->InitCompareTank();
				if(!c->Enemy[7].Collision(c->tank,9))
				{
					switch(c->Enemy[7].Direct)
					{
					case 1:c->Enemy[7].Site.y-=c->Enemy[7].Speed;break;
					case 2:c->Enemy[7].Site.x+=c->Enemy[7].Speed;break;
					case 3:c->Enemy[7].Site.y+=c->Enemy[7].Speed;break;
					case 4:c->Enemy[7].Site.x-=c->Enemy[7].Speed;break;
					}
				}
			}
		}
		::Sleep(30);
	}

	return TRUE;
}
DWORD WINAPI Fail(LPVOID lpParam)
{
	Cmydia6 *c=(Cmydia6*)lpParam;
	BOOL i=c->Player.Attribute;
	while(!i)
	{
	
		Cmydia2 pOneDlgObj7;
		pOneDlgObj7.DoModal();
	}
	return true;
}
