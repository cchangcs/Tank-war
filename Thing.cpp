#include "stdafx.h"
#include "Resource.h"
#include "Thing.h"
#include<math.h>
#include<time.h>
#include<stdlib.h>

bool Tank::InitTank(int H,int Dir,int Sp,int Attr,int IsP,int Ma,CPoint Si)
{
	HP=H;
	Direct=Dir;
	Speed=Sp;
	Attribute=Attr;
	IsPlayer=IsP;
	Mark=Ma;
	Site=Si;
	move=false;
	return true;
}

bool Tank::LoadImage()
{
	1==IsPlayer?Image.LoadBitmap(IDB_BITMAP22):Image.LoadBitmap(IDB_BITMAP13 );
	HImage=HBITMAP(Image);
	return true;

}

bool Tank::Collision(CPoint *tank,int n)
{
	CPoint temp;
	int i;
	switch(Direct)
	{
	    case 1:temp.x=Site.x;temp.y=Site.y-Speed;break;
		case 2:temp.x=Site.x+Speed;temp.y=Site.y;break;
		case 3:temp.x=Site.x;temp.y=Site.y+Speed;break;
		case 4:temp.x=Site.x-Speed;temp.y=Site.y;break;
	}
	for(i=0;i<n;i++)
	{
		if(Mark!=i)
		{
			if(abs(tank[i].x-temp.x)<60&&abs(tank[i].y-temp.y)<60)
			{
				if(2==IsPlayer)
				{
					if(0!=i)
					{
						Direct++;
						if(5==Direct)
						{
							Direct=1;
						}
						move=true;
					}
				}
				
				return true;
			}
		}
	}
	if(temp.y<50||temp.y>650||temp.x<0||temp.x>1300||(temp.x>1190&&temp.y>610))
	{
		if(2==IsPlayer)
		{
			Direct++;
			if(5==Direct)
			{
				Direct=1;
			}
			move=true;
		}
		return true;
	}
	return false;
}

void Tank::ChaseMode(CPoint player)
{
	srand((unsigned)time(NULL));
	int i=rand()%2;

	if(player.x<Site.x&&player.y>Site.y)
	{
		Direct=(1==i)?3:4;
	}

	if(player.x>Site.x&&player.y>Site.y)
	{
		Direct=(1==i)?2:3;
	}

	if(player.x>Site.x&&player.y==Site.y)
	{
		Direct=2;
	}

	if(player.x>Site.x&&player.y<Site.y)
	{
		Direct=(1==i)?1:2;
	}

	if(player.x==Site.x&&player.y>Site.y)
	{
		Direct=3;
	}

	if(player.x==Site.x&&player.y<Site.y)
	{
		Direct=1;
	}

	if(player.x<Site.x&&player.y==Site.y)
	{
		Direct=4;
	}

	if(player.x<Site.x&&player.y<Site.y)
	{
		Direct=(1==i)?1:4;
	}
}

void Tank::RandomMode()
{
	srand((unsigned)time(NULL));
	int i=rand()%4+1;
	Direct=i;
}

bool Bullet::InitBullet(int Dir,int Attr,int Spe,int IsP,CPoint Si)
{
	Direct=Dir;
	Attribute=Attr;
	Speed=Spe;
	IsPlayer=IsP;
	Site=Si;
	return true;
}

bool Bullet::LoadImage()
{
	BImage.LoadBitmap(IDB_BITMAP15);
	HBImage=HBITMAP(BImage);
	return true;
}

int Bullet::Collision(CPoint *tank,int n)
{
	CPoint temp;
	switch(Direct)
	{
	    case 1:temp.x=Site.x;temp.y=Site.y-Speed;break;
		case 2:temp.x=Site.x+Speed;temp.y=Site.y;break;
		case 3:temp.x=Site.x;temp.y=Site.y+Speed;break;
		case 4:temp.x=Site.x-Speed;temp.y=Site.y;break;
	}
	if(1==IsPlayer)
	{
		for(int i=1;i<n;i++)
		{
			if(tank[i].x<temp.x&&tank[i].x+60>temp.x&&tank[i].y<temp.y&&tank[i].y+60>temp.y)
			{
				Attribute=0;
				return i;
			}
		}
	}
	else
	{
		if(tank[0].x<temp.x&&tank[0].x+60>temp.x&&tank[0].y<temp.y&&tank[0].y+60>temp.y)
		{
			Attribute=0;
			return 1;
		}
	}
	if(temp.y<50||temp.y>700||temp.x<0||temp.x>1350||(temp.x>1240&&temp.y>660))
	{
		Attribute=0;
		return 10;
	}
	return 0;
}

int Bullet::Conflict(CPoint *wall,int n)
{
	CPoint temp;
	switch(Direct)
	{
	    case 1:temp.x=Site.x;temp.y=Site.y-Speed;break;
		case 2:temp.x=Site.x+Speed;temp.y=Site.y;break;
		case 3:temp.x=Site.x;temp.y=Site.y+Speed;break;
		case 4:temp.x=Site.x-Speed;temp.y=Site.y;break;
	}
	
	for(int i=1;i<n;i++)
	{
		if(wall[i].x<temp.x&&wall[i].x+60>temp.x&&wall[i].y<temp.y&&wall[i].y+60>temp.y)
		{
			Attribute=0;
			return i;
		}
	}
	
	
	if(temp.y<50||temp.y>700||temp.x<0||temp.x>1350||(temp.x>1240&&temp.y>660))
	{
		Attribute=0;
		return 10;
	}
	return 0;
}

bool Bullet::InitAgain(CPoint p,int Dir)
{
	Direct=Dir;
	switch(Direct)
	{
	    case 1:Site.x=p.x+25;Site.y=p.y-10;break;
		case 2:Site.x=p.x+60;Site.y=p.y+25;break;
		case 3:Site.x=p.x+25;Site.y=p.y+60;break;
		case 4:Site.x=p.x-10;Site.y=p.y+25;break;
	}
	Attribute=1;
	return true;
}

bool Bullet::BulletMove()
{
	switch(Direct)
	{
	    case 1:Site.y-=Speed;break;
		case 2:Site.x+=Speed;break;
		case 3:Site.y+=Speed;break;
		case 4:Site.x-=Speed;break;
	}
	return true;
}

bool Props::InitProps(int Attr,int Ma,int IsP,CPoint Si)
{
	Attribute=Attr;
	Mark=Ma;
	IsPlayer=IsP;
	Site=Si;
	return true;
}

bool Wall::InitWall(int H,int Attr,int Ma,CPoint Si)
{
	HP=H;
	Attribute=Attr;
	Mark=Ma;
	Site=Si;
	return true;
}

bool Wall::LoadImage()
{
	WImage.LoadBitmap(IDB_BITMAP6);
	HWImage=HBITMAP(WImage);
	return true;
}

bool Wall::Collision(CPoint *tank,int n)
{return 0;}