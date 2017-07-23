#include"Thing.h"
// TankGame2Dlg.h : 头文件
DWORD WINAPI MyPaint3(LPVOID lpParam);
DWORD WINAPI InitTank3(LPVOID lpParam);
DWORD WINAPI EnemyMove03(LPVOID lpParam);
DWORD WINAPI EnemyMove13(LPVOID lpParam);
DWORD WINAPI EnemyMove23(LPVOID lpParam);
DWORD WINAPI EnemyMove33(LPVOID lpParam);
DWORD WINAPI EnemyMove43(LPVOID lpParam);
DWORD WINAPI EnemyMove53(LPVOID lpParam);
DWORD WINAPI EnemyMove63(LPVOID lpParam);
DWORD WINAPI EnemyMove73(LPVOID lpParam);
DWORD WINAPI PlayerButtle3(LPVOID lpParam);
DWORD WINAPI PlayerMove3(LPVOID lpParam);


#pragma once


// Cmydia10 对话框

class Cmydia10 : public CDialogEx
{
	DECLARE_DYNAMIC(Cmydia10)

public:
	Cmydia10(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cmydia10();

// 对话框数据
	enum { IDD = IDD_DIALOG8 };

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
	BOOL Cmydia10::PreTranslateMessage(MSG*pMsg);//按键松键消息函数
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
