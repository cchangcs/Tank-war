#include "stdafx.h"
#include "Resource.h"

#if !defined(_Thing_H_)
#define _Thing_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Tank
{
public:
	int HP;          //黄色坦克为我方坦克 HP 0-5 初始为3  绿色为敌方坦克 HP 0-3 初始为3  红色坦克为敌方坦克 HP 0-5 初始为5
	int Direct;      //坦克有四个方向行走 分别为 up-1 right-2 down-3 left-4
	int Speed;       //坦克有行走速度 我方坦克(黄)-初始速度为10 敌方坦克红色初始为10 绿色初始为20
	int Attribute;   //坦克有被击中没有的属性 初始为1 当HP为0时 attribute为0
	int IsPlayer;    //1是我方坦克 2是敌军坦克
	int Mark;        //标记坦克数量(加上我方坦克最大数量为9) 0-我方坦克 1-8地方坦克
	CPoint Site;     //坦克有自己的位置
	CBitmap Image;   //坦克有自己本身的图像
	HBITMAP HImage;  //坦克有自己的加载图像格式
	bool move;
	Tank(){};        //重写构造函数
	///~Tank(){};
	Tank(Tank &tank){};
	 //析构函数
public:
	bool InitTank(int H,int Dir,int Spe,int Attr,int IsP,int Ma,CPoint Si);  //初始化坦克非图像计算的值
	bool LoadImage();   //初始化坦克图像计算的值
	bool Collision(CPoint *tank,int n);   //碰撞检测
	void ChaseMode(CPoint player); //追逐模式
	void RandomMode();//随机模式
	
};

class Bullet
{
public:
	int Direct;          //子弹有方向 为坦克初始化时候的方向
	int Attribute;       //子弹有属性 1为子弹显示 0为子弹消失
	CPoint Site;         //子弹有位置 根据发射坦克位置来初始化
	int Speed;           //子弹有速度 速度为10
	int IsPlayer;        //通过确定是否玩家发射子弹来确认子弹属性
	CBitmap BImage;      //用于子弹加载位图
	HBITMAP HBImage;     //用于装换位图格式

	Bullet(){};
	Bullet(Bullet &bullet){};
	
public:
	bool InitBullet(int Dir,int Attr,int Spe,int IsP,CPoint Si);
	bool LoadImage();
	int Collision(CPoint *tank,int n);
	int Conflict(CPoint *wall,int n);
	bool InitAgain(CPoint p,int Dir);
	bool BulletMove();
};

class Props
{
public:
	int Attribute;            //道具属性1为出现 0为消失
	int Mark;                 //道具标识 0为停止时间 1为传送任意位置 2为坦克加血 3为无敌 4为坦克全减1血
	int IsPlayer;             //判断是否玩家吃到道具
	CBitmap PImage;           //用于道具加载位图
	HBITMAP HPImage;          //用于装换位图格式
	CPoint Site;

	Props(){};
	Props(Props &props){};
	
public:
	bool InitProps(int Attr,int Ma,int IsP,CPoint Si);
	bool LoadImage();
	void GetSite(CPoint *tank,int n);
};

class Wall
{
public:
	int HP;
	int Attribute;
	int Mark;
	CPoint Site;    
	CBitmap WImage;   
	HBITMAP HWImage;

	Wall(){};
	Wall(Wall &wall){};

public:
	bool InitWall(int H,int Attr,int Ma,CPoint Si);
	bool LoadImage();
	bool Collision(CPoint *tank,int n);   //碰撞检测
};

#endif !defined(_Thing_H_)