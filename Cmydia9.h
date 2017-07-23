#include"Thing.h"
// TankGame2Dlg.h : 头文件
DWORD WINAPI MyPaint2(LPVOID lpParam);
DWORD WINAPI InitTank2(LPVOID lpParam);
DWORD WINAPI EnemyMove02(LPVOID lpParam);
DWORD WINAPI EnemyMove12(LPVOID lpParam);
DWORD WINAPI EnemyMove22(LPVOID lpParam);
DWORD WINAPI EnemyMove32(LPVOID lpParam);
DWORD WINAPI EnemyMove42(LPVOID lpParam);
DWORD WINAPI EnemyMove52(LPVOID lpParam);
DWORD WINAPI EnemyMove62(LPVOID lpParam);
DWORD WINAPI EnemyMove72(LPVOID lpParam);
DWORD WINAPI PlayerButtle2(LPVOID lpParam);
DWORD WINAPI PlayerMove2(LPVOID lpParam);



#pragma once


// Cmydia9 对话框

class Cmydia9 : public CDialogEx
{
	DECLARE_DYNAMIC(Cmydia9)

public:
	Cmydia9(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cmydia9();

// 对话框数据
	enum { IDD = IDD_DIALOG7 };

protected:
	HICON m_hIcon;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	
	DECLARE_MESSAGE_MAP()

	public:
	HDC hdc,mdc,bufdc;//第一个屏幕DC 第二个内存DC 第三个缓冲DC (句柄，可以看作纸）
	HBITMAP BackGround,hBitmap,HMytankHP,HEnemyTotal;//第一个是背景 第二个是屏幕 第三个是Tank的（用来转换为可以画在纸上的格式）
	CBitmap Back,MytankHP,BEnemyTotal;//第一个是背景 第二个是Tank（用来关联刚导入的位图）
	Tank Player;//自定义的坦克类
	BOOL Cmydia9::PreTranslateMessage(MSG*pMsg);//按键松键消息函数
	CPoint tank[9];
	CPoint wall[4];
	Tank Enemy[8];
	CPoint p;
	void InitCompareTank();
	int TotalEnemy;
	int itank;
	int mtank[8];
	Bullet BEnemy[8];
	Bullet BPlayer[3];
	int pi;
	Wall WGame[4];
	bool KeyLeft;
	bool KeyRight;
	bool KeyUp;
	bool KeyDown;
	bool KeySpace;
	bool control;
	
	bool ControlEnd[9];
	bool ControlEnd2[4];
	bool ControlTime[8];

	
};
