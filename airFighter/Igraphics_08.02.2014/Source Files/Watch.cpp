#define _CRT_SECURE_NO_WARNINGS

#include "iGraphics.h"
#include<stdlib.h>
#include <string.h>
int random_pointy1=rand()%200+500,random_pointy2=rand()%200+500;
int random_point1=rand()%750+20,random_point2=rand()%750+20;
int i,j,m=0,collision_loop_point;
int bullet_state1=0,bullet_state2=0,bullet_state3=0;
int Enemy_1_bullet_state1=0,Enemy_1_bullet_state2=0,Enemy_1_bullet_state3=0;
int Enemy_2_bullet_state1=0,Enemy_2_bullet_state2=0,Enemy_2_bullet_state3=0;
int tomove1,tomove2;
double friend_plane_bar_length=100,enemy_plane1_bar_length=100,enemy_plane2_bar_length=100;
int enemy1_draw_state=0,enemy2_draw_state=0,friend_draw_state=2;
int restart_color_state=0;
int score=0,present_enemy1=0,present_enemy2=0;
char buffer[20];
int enemy1_bullet_state=0,enemy2_bullet_state=0;
//******************************"""""""STRUCTURE""""""*************************************************
struct polygon{
	double *p;
	double *q;
	//int n;
};
struct rectangle{
	double x;
	double y;
	//int dx;
	//int dy;
};
struct ellipse{
	double x;
	double y;
	//int a;
	//int b;
};
struct line{
	double x1;
	double y1;
	double x2;
	double y2;
};
struct planestruct{
	struct polygon poly[8];
	struct rectangle rec[4];
	struct ellipse elli[3];
	struct line li[3];
}friend_plane,enemy_plane1,enemy_plane2;

struct bulletstruct{
	struct ellipse elliL[4];
	struct ellipse elliR[4];
}friend_bullet,enemy_bullet1,enemy_bullet2;

void time_score()
{
	if(friend_draw_state!=1)
		score++;
}

//****************************************RANDOM POSITION FUNCTION FOR ENEMY PLANE 2******************************************

void random_position()
{
	tomove2=rand()%200;
	if(tomove2%3==0)
	{
		if(enemy_plane2.poly[1].p[1]<780)
		{
			for(i=0;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						enemy_plane2.poly[i].p[j]+=30;
						
					}
					enemy_plane2.poly[6].p[i]+=30;
				}
				for(i=0;i<8;i++)
				{
					enemy_plane2.poly[5].p[i]+=30;
				}
				for(i=0;i<3;i++)
				{
					enemy_plane2.poly[7].p[i]+=30;
				}
				enemy_plane2.rec[0].x+=30;
				enemy_plane2.rec[1].x+=30;
				enemy_plane2.rec[2].x+=30;
				enemy_plane2.rec[3].x+=30;

				enemy_plane2.elli[0].x+=30;
				enemy_plane2.elli[1].x+=30;
				enemy_plane2.elli[2].x+=30;

				enemy_plane2.li[0].x1+=30;
				enemy_plane2.li[0].x2+=30;
				enemy_plane2.li[1].x1+=30;
				enemy_plane2.li[1].x2+=30;
				enemy_plane2.li[2].x1+=30;
				enemy_plane2.li[2].x2+=30;
		}
	}
	else
	{
		if(enemy_plane2.poly[0].p[1]>0)
		{
			for(i=0;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						enemy_plane2.poly[i].p[j]-=20;
						
					}
					enemy_plane2.poly[6].p[i]-=20;
				}
				for(i=0;i<8;i++)
				{
					enemy_plane2.poly[5].p[i]-=20;
				}
				for(i=0;i<3;i++)
				{
					enemy_plane2.poly[7].p[i]-=20;
				}
				enemy_plane2.rec[0].x-=20;
				enemy_plane2.rec[1].x-=20;
				enemy_plane2.rec[2].x-=20;
				enemy_plane2.rec[3].x-=20;

				enemy_plane2.elli[0].x-=20;
				enemy_plane2.elli[1].x-=20;
				enemy_plane2.elli[2].x-=20;

				enemy_plane2.li[0].x1-=20;
				enemy_plane2.li[0].x2-=20;
				enemy_plane2.li[1].x1-=20;
				enemy_plane2.li[1].x2-=20;
				enemy_plane2.li[2].x1-=20;
				enemy_plane2.li[2].x2-=20;
		}
	}
	if(tomove2%5==0)
	{
		if(enemy_plane2.poly[4].q[2]<700)
		{
			for(i=0;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						enemy_plane2.poly[i].q[j]+=30;
						
					}
					enemy_plane2.poly[6].q[i]+=30;
				}
				for(i=0;i<8;i++)
				{
					enemy_plane2.poly[5].q[i]+=30;
				}
				for(i=0;i<3;i++)
				{
					enemy_plane2.poly[7].q[i]+=30;
				}
				enemy_plane2.rec[0].y+=30;
				enemy_plane2.rec[1].y+=30;
				enemy_plane2.rec[2].y+=30;
				enemy_plane2.rec[3].y+=30;

				enemy_plane2.elli[0].y+=30;
				enemy_plane2.elli[1].y+=30;
				enemy_plane2.elli[2].y+=30;

				enemy_plane2.li[0].y1+=30;
				enemy_plane2.li[0].y2+=30;
				enemy_plane2.li[1].y1+=30;
				enemy_plane2.li[1].y2+=30;
				enemy_plane2.li[2].y1+=30;
				enemy_plane2.li[2].y2+=30;

		}
	}
	else if(tomove2%6==0)
	{
		if(enemy_plane2.li[0].y2>500)
		{
			for(i=0;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						enemy_plane2.poly[i].q[j]-=30;
						
					}
					enemy_plane2.poly[6].q[i]-=30;
				}
				for(i=0;i<8;i++)
				{
					enemy_plane2.poly[5].q[i]-=30;
				}
				for(i=0;i<3;i++)
				{
					enemy_plane2.poly[7].q[i]-=30;
				}
				enemy_plane2.rec[0].y-=30;
				enemy_plane2.rec[1].y-=30;
				enemy_plane2.rec[2].y-=30;
				enemy_plane2.rec[3].y-=30;

				enemy_plane2.elli[0].y-=30;
				enemy_plane2.elli[1].y-=30;
				enemy_plane2.elli[2].y-=30;

				enemy_plane2.li[0].y1-=30;
				enemy_plane2.li[0].y2-=30;
				enemy_plane2.li[1].y1-=30;
				enemy_plane2.li[1].y2-=30;
				enemy_plane2.li[2].y1-=30;
				enemy_plane2.li[2].y2-=30;
		}
	}
		
	

	
}

//*******************************ENEMY PLANE MOVEMENT***************************************

void random_movement()
{
	//MOVING ENEMY PLANE
	tomove1=rand()%200;
	if(tomove1%3==0)
	{
		if(enemy_plane1.poly[1].p[1]<780)
		{
			for(i=0;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						enemy_plane1.poly[i].p[j]+=30;
						
					}
					enemy_plane1.poly[6].p[i]+=30;
				}
				for(i=0;i<8;i++)
				{
					enemy_plane1.poly[5].p[i]+=30;
				}
				for(i=0;i<3;i++)
				{
					enemy_plane1.poly[7].p[i]+=30;
				}
				enemy_plane1.rec[0].x+=30;
				enemy_plane1.rec[1].x+=30;
				enemy_plane1.rec[2].x+=30;
				enemy_plane1.rec[3].x+=30;

				enemy_plane1.elli[0].x+=30;
				enemy_plane1.elli[1].x+=30;
				enemy_plane1.elli[2].x+=30;

				enemy_plane1.li[0].x1+=30;
				enemy_plane1.li[0].x2+=30;
				enemy_plane1.li[1].x1+=30;
				enemy_plane1.li[1].x2+=30;
				enemy_plane1.li[2].x1+=30;
				enemy_plane1.li[2].x2+=30;
		
		}
	}
	else
		{
			if(enemy_plane1.poly[0].p[1]>0)
			{
				for(i=0;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						enemy_plane1.poly[i].p[j]-=20;
						
					}
					enemy_plane1.poly[6].p[i]-=20;
				}
				for(i=0;i<8;i++)
				{
					enemy_plane1.poly[5].p[i]-=20;
				}
				for(i=0;i<3;i++)
				{
					enemy_plane1.poly[7].p[i]-=20;
				}
				enemy_plane1.rec[0].x-=20;
				enemy_plane1.rec[1].x-=20;
				enemy_plane1.rec[2].x-=20;
				enemy_plane1.rec[3].x-=20;

				enemy_plane1.elli[0].x-=20;
				enemy_plane1.elli[1].x-=20;
				enemy_plane1.elli[2].x-=20;

				enemy_plane1.li[0].x1-=20;
				enemy_plane1.li[0].x2-=20;
				enemy_plane1.li[1].x1-=20;
				enemy_plane1.li[1].x2-=20;
				enemy_plane1.li[2].x1-=20;
				enemy_plane1.li[2].x2-=20;
				
			}
		}


		if(tomove1%5==0)
		{
		if(enemy_plane1.poly[4].q[2]<700)
		{
			for(i=0;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						enemy_plane1.poly[i].q[j]+=30;
						
					}
					enemy_plane1.poly[6].q[i]+=30;
				}
				for(i=0;i<8;i++)
				{
					enemy_plane1.poly[5].q[i]+=30;
				}
				for(i=0;i<3;i++)
				{
					enemy_plane1.poly[7].q[i]+=30;
				}
				enemy_plane1.rec[0].y+=30;
				enemy_plane1.rec[1].y+=30;
				enemy_plane1.rec[2].y+=30;
				enemy_plane1.rec[3].y+=30;

				enemy_plane1.elli[0].y+=30;
				enemy_plane1.elli[1].y+=30;
				enemy_plane1.elli[2].y+=30;

				enemy_plane1.li[0].y1+=30;
				enemy_plane1.li[0].y2+=30;
				enemy_plane1.li[1].y1+=30;
				enemy_plane1.li[1].y2+=30;
				enemy_plane1.li[2].y1+=30;
				enemy_plane1.li[2].y2+=30;

		
		}
	}
	else if(tomove1%6==0)
		{
			if(enemy_plane1.li[0].y2>500)
			{
				for(i=0;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						enemy_plane1.poly[i].q[j]-=30;
						
					}
					enemy_plane1.poly[6].q[i]-=30;
				}
				for(i=0;i<8;i++)
				{
					enemy_plane1.poly[5].q[i]-=30;
				}
				for(i=0;i<3;i++)
				{
					enemy_plane1.poly[7].q[i]-=30;
				}
				enemy_plane1.rec[0].y-=30;
				enemy_plane1.rec[1].y-=30;
				enemy_plane1.rec[2].y-=30;
				enemy_plane1.rec[3].y-=30;

				enemy_plane1.elli[0].y-=30;
				enemy_plane1.elli[1].y-=30;
				enemy_plane1.elli[2].y-=30;

				enemy_plane1.li[0].y1-=30;
				enemy_plane1.li[0].y2-=30;
				enemy_plane1.li[1].y1-=30;
				enemy_plane1.li[1].y2-=30;
				enemy_plane1.li[2].y1-=30;
				enemy_plane1.li[2].y2-=30;
			}
		}

}


//*************************"""""""IDRAW FUNCTION"""""""**********************************

void iDraw() 
{
	
	itoa(score,buffer,10);
	if(enemy1_draw_state==1)
	{
		present_enemy1++;
	}
	if(enemy2_draw_state==1)
	{
		present_enemy2++;
	}
	if(present_enemy1>=2000)
	{
		enemy1_draw_state=0;
		present_enemy1=0;
		enemy_plane1_bar_length=100;

	}
	if(present_enemy2>=2000)
	{
		enemy2_draw_state=0;
		present_enemy2=0;
		enemy_plane2_bar_length=100;
	}
	if(friend_draw_state==0)
	{

		iClear();

		//iShowBMP(0,0,"hf.bmp");

		enemy1_bullet_state=rand()%1;
		enemy2_bullet_state=rand()%1;

		iSetColor(255,255,0);
		iLine(0,60,800,60);

		//upper pakha
		iSetColor(46,139,87);
		iFilledPolygon(friend_plane.poly[0].p,friend_plane.poly[0].q,4);
		iFilledPolygon(friend_plane.poly[1].p,friend_plane.poly[1].q,4);
		iSetColor(0,0,0);
		iPolygon(friend_plane.poly[0].p,friend_plane.poly[0].q,4);
		iPolygon(friend_plane.poly[1].p,friend_plane.poly[1].q,4);
		//lower pakha
		iSetColor(46,139,87);
		iFilledPolygon(friend_plane.poly[2].p,friend_plane.poly[2].q,4);
		iFilledPolygon(friend_plane.poly[3].p,friend_plane.poly[3].q,4);
		iSetColor(0,0,0);
		iPolygon(friend_plane.poly[2].p,friend_plane.poly[2].q,4);
		iPolygon(friend_plane.poly[3].p,friend_plane.poly[3].q,4);

		iSetColor(30,144,255);
		iFilledPolygon(friend_plane.poly[4].p,friend_plane.poly[4].q,4);
		iSetColor(0,0,0);
		iPolygon(friend_plane.poly[4].p,friend_plane.poly[4].q,4);

		iSetColor(0,128,0);
		iFilledRectangle(friend_plane.rec[0].x,friend_plane.rec[0].y,30,10);
		iSetColor(0,0,0);
		iRectangle(friend_plane.rec[0].x,friend_plane.rec[0].y,30,10);
		iSetColor(255,255,255);

		iSetColor(144,238,144);
		iFilledPolygon(friend_plane.poly[5].p,friend_plane.poly[5].q,8);
		iSetColor(0,0,0);
		iPolygon(friend_plane.poly[5].p,friend_plane.poly[5].q,8);

		iSetColor(0,128,128);
		iFilledRectangle(friend_plane.rec[1].x,friend_plane.rec[1].y,26,25);
		iSetColor(0,0,0);
		iRectangle(friend_plane.rec[1].x,friend_plane.rec[1].y,26,25);

		iSetColor(65,105,225);
		iFilledPolygon(friend_plane.poly[6].p,friend_plane.poly[6].q,4);
		iSetColor(0,0,0);
		iPolygon(friend_plane.poly[6].p,friend_plane.poly[6].q,4);


		iSetColor(255,99,71);
		iFilledEllipse(friend_plane.elli[0].x,friend_plane.elli[0].y,8,25);
		iSetColor(0,0,0);
		iEllipse(friend_plane.elli[0].x,friend_plane.elli[0].y,8,25);

		iSetColor(255,255,0);
		iLine(friend_plane.li[0].x1,friend_plane.li[0].y1,friend_plane.li[0].x2,friend_plane.li[0].y2);

		iSetColor(173,255,47);
		iFilledPolygon(friend_plane.poly[7].p,friend_plane.poly[7].q,3);
		iSetColor(0,0,0);
		iPolygon(friend_plane.poly[7].p,friend_plane.poly[7].q,3);
		iLine(friend_plane.li[1].x1,friend_plane.li[1].y1,friend_plane.li[1].x2,friend_plane.li[1].y2);
		iLine(friend_plane.li[2].x1,friend_plane.li[2].y1,friend_plane.li[2].x2,friend_plane.li[2].y2);

		iSetColor(218,165,32);
		iFilledEllipse(friend_plane.elli[1].x,friend_plane.elli[1].y,5,10);
		iFilledEllipse(friend_plane.elli[2].x,friend_plane.elli[2].y,5,10);
		iSetColor(0,0,0);
		iEllipse(friend_plane.elli[1].x,friend_plane.elli[1].y,5,10);
		iEllipse(friend_plane.elli[2].x,friend_plane.elli[2].y,5,10);

		iSetColor(205,133,63);
		iFilledRectangle(friend_plane.rec[2].x,friend_plane.rec[2].y,10,12);
		iFilledRectangle(friend_plane.rec[3].x,friend_plane.rec[3].y,10,12);
		iSetColor(0,0,0);
		iRectangle(friend_plane.rec[2].x,friend_plane.rec[2].y,10,12);
		iRectangle(friend_plane.rec[3].x,friend_plane.rec[3].y,10,12);

		//ENEMY PLANE DRAWING 1
	
		if(enemy1_draw_state==0)
		{
			//upper pakha
			iSetColor(85,107,47);
			iFilledPolygon(enemy_plane1.poly[0].p,enemy_plane1.poly[0].q,4);
			iFilledPolygon(enemy_plane1.poly[1].p,enemy_plane1.poly[1].q,4);
			iSetColor(0,0,0);
			iPolygon(enemy_plane1.poly[0].p,enemy_plane1.poly[0].q,4);
			iPolygon(enemy_plane1.poly[1].p,enemy_plane1.poly[1].q,4);
			//lower pakha
			iSetColor(32,178,170);
			iFilledPolygon(enemy_plane1.poly[2].p,enemy_plane1.poly[2].q,4);
			iFilledPolygon(enemy_plane1.poly[3].p,enemy_plane1.poly[3].q,4);
			iSetColor(0,0,0);
			iPolygon(enemy_plane1.poly[2].p,enemy_plane1.poly[2].q,4);
			iPolygon(enemy_plane1.poly[3].p,enemy_plane1.poly[3].q,4);

			iSetColor(238,130,238);
			iFilledPolygon(enemy_plane1.poly[4].p,enemy_plane1.poly[4].q,4);
			iSetColor(0,0,0);
			iPolygon(enemy_plane1.poly[4].p,enemy_plane1.poly[4].q,4);

			iSetColor(102,205,170);
			iFilledRectangle(enemy_plane1.rec[0].x,enemy_plane1.rec[0].y,30,10);
			iSetColor(0,0,0);
			iRectangle(enemy_plane1.rec[0].x,enemy_plane1.rec[0].y,30,10);

			iSetColor(75,0,130);
			iFilledPolygon(enemy_plane1.poly[5].p,enemy_plane1.poly[5].q,8);
			iSetColor(0,0,0);
			iPolygon(enemy_plane1.poly[5].p,enemy_plane1.poly[5].q,8);

			iSetColor(0,128,0);
			iFilledRectangle(enemy_plane1.rec[1].x,enemy_plane1.rec[1].y,26,25);
			iSetColor(0,0,0);
			iRectangle(enemy_plane1.rec[1].x,enemy_plane1.rec[1].y,26,25);

			iSetColor(154,205,50);
			iFilledPolygon(enemy_plane1.poly[6].p,enemy_plane1.poly[6].q,4);
			iSetColor(0,0,0);
			iPolygon(enemy_plane1.poly[6].p,enemy_plane1.poly[6].q,4);


			iSetColor(106,90,205);
			iFilledEllipse(enemy_plane1.elli[0].x,enemy_plane1.elli[0].y,8,25);
			iSetColor(0,0,0);
			iEllipse(enemy_plane1.elli[0].x,enemy_plane1.elli[0].y,8,25);

			iSetColor(255,105,180);
			iLine(enemy_plane1.li[0].x1,enemy_plane1.li[0].y1,enemy_plane1.li[0].x2,enemy_plane1.li[0].y2);

			iSetColor(135,206,235);
			iFilledPolygon(enemy_plane1.poly[7].p,enemy_plane1.poly[7].q,3);
			iSetColor(0,0,0);
			iPolygon(enemy_plane1.poly[7].p,enemy_plane1.poly[7].q,3);
			iLine(enemy_plane1.li[1].x1,enemy_plane1.li[1].y1,enemy_plane1.li[1].x2,enemy_plane1.li[1].y2);
			iLine(enemy_plane1.li[2].x1,enemy_plane1.li[2].y1,enemy_plane1.li[2].x2,enemy_plane1.li[2].y2);

			iSetColor(165,42,42);
			iFilledEllipse(enemy_plane1.elli[1].x,enemy_plane1.elli[1].y,5,10);
			iFilledEllipse(enemy_plane1.elli[2].x,enemy_plane1.elli[2].y,5,10);
			iSetColor(0,0,0);
			iEllipse(enemy_plane1.elli[1].x,enemy_plane1.elli[1].y,5,10);
			iEllipse(enemy_plane1.elli[2].x,enemy_plane1.elli[2].y,5,10);

			iSetColor(65,105,225);
			iFilledRectangle(enemy_plane1.rec[2].x,enemy_plane1.rec[2].y,10,12);
			iFilledRectangle(enemy_plane1.rec[3].x,enemy_plane1.rec[3].y,10,12);
			iSetColor(0,0,0);
			iRectangle(enemy_plane1.rec[2].x,enemy_plane1.rec[2].y,10,12);
			iRectangle(enemy_plane1.rec[3].x,enemy_plane1.rec[3].y,10,12);
		}

		//ENEMY PLANE DRAWING 2
		if(enemy2_draw_state==0)
		{
			//upper pakha
			iSetColor(205,92,92);
			iFilledPolygon(enemy_plane2.poly[0].p,enemy_plane2.poly[0].q,4);
			iFilledPolygon(enemy_plane2.poly[1].p,enemy_plane2.poly[1].q,4);
			iSetColor(0,0,0);
			iPolygon(enemy_plane2.poly[0].p,enemy_plane2.poly[0].q,4);
			iPolygon(enemy_plane2.poly[1].p,enemy_plane2.poly[1].q,4);
			//lower pakha
			iSetColor(210,105,30);
			iFilledPolygon(enemy_plane2.poly[2].p,enemy_plane2.poly[2].q,4);
			iFilledPolygon(enemy_plane2.poly[3].p,enemy_plane2.poly[3].q,4);
			iSetColor(0,0,0);
			iPolygon(enemy_plane2.poly[2].p,enemy_plane2.poly[2].q,4);
			iPolygon(enemy_plane2.poly[3].p,enemy_plane2.poly[3].q,4);

			iSetColor(85,107,47);
			iFilledPolygon(enemy_plane2.poly[4].p,enemy_plane2.poly[4].q,4);
			iSetColor(0,0,0);
			iPolygon(enemy_plane2.poly[4].p,enemy_plane2.poly[4].q,4);

			iSetColor(75,0,130);
			iFilledRectangle(enemy_plane2.rec[0].x,enemy_plane2.rec[0].y,30,10);
			iSetColor(0,0,0);
			iRectangle(enemy_plane2.rec[0].x,enemy_plane2.rec[0].y,30,10);

			iSetColor(147,112,216);
			iFilledPolygon(enemy_plane2.poly[5].p,enemy_plane2.poly[5].q,8);
			iSetColor(0,0,0);
			iPolygon(enemy_plane2.poly[5].p,enemy_plane2.poly[5].q,8);

			iSetColor(160,82,45);
			iFilledRectangle(enemy_plane2.rec[1].x,enemy_plane2.rec[1].y,26,25);
			iSetColor(0,0,0);
			iRectangle(enemy_plane2.rec[1].x,enemy_plane2.rec[1].y,26,25);

			iSetColor(0,128,128);
			iFilledPolygon(enemy_plane2.poly[6].p,enemy_plane2.poly[6].q,4);
			iSetColor(0,0,0);
			iPolygon(enemy_plane2.poly[6].p,enemy_plane2.poly[6].q,4);


			iSetColor(143,188,143);
			iFilledEllipse(enemy_plane2.elli[0].x,enemy_plane2.elli[0].y,8,25);
			iSetColor(0,0,0);
			iEllipse(enemy_plane2.elli[0].x,enemy_plane2.elli[0].y,8,25);

			iSetColor(255,105,180);
			iLine(enemy_plane2.li[0].x1,enemy_plane2.li[0].y1,enemy_plane2.li[0].x2,enemy_plane2.li[0].y2);

			iSetColor(106,90,205);
			iFilledPolygon(enemy_plane2.poly[7].p,enemy_plane2.poly[7].q,3);
			iSetColor(0,0,0);
			iPolygon(enemy_plane2.poly[7].p,enemy_plane2.poly[7].q,3);
			iLine(enemy_plane2.li[1].x1,enemy_plane2.li[1].y1,enemy_plane2.li[1].x2,enemy_plane2.li[1].y2);
			iLine(enemy_plane2.li[2].x1,enemy_plane2.li[2].y1,enemy_plane2.li[2].x2,enemy_plane2.li[2].y2);

			iSetColor(154,205,50);
			iFilledEllipse(enemy_plane2.elli[1].x,enemy_plane2.elli[1].y,5,10);
			iFilledEllipse(enemy_plane2.elli[2].x,enemy_plane2.elli[2].y,5,10);
			iSetColor(0,0,0);
			iEllipse(enemy_plane2.elli[1].x,enemy_plane2.elli[1].y,5,10);
			iEllipse(enemy_plane2.elli[2].x,enemy_plane2.elli[2].y,5,10);

			iSetColor(244,164,96);
			iFilledRectangle(enemy_plane2.rec[2].x,enemy_plane2.rec[2].y,10,12);
			iFilledRectangle(enemy_plane2.rec[3].x,enemy_plane2.rec[3].y,10,12);
			iSetColor(0,0,0);
			iRectangle(enemy_plane2.rec[2].x,enemy_plane2.rec[2].y,10,12);
			iRectangle(enemy_plane2.rec[3].x,enemy_plane2.rec[3].y,10,12);
		}

		//FRIEND BULLET DRAWING
		iSetColor(189,183,107);
		iFilledEllipse(friend_bullet.elliL[0].x,friend_bullet.elliL[0].y,3,6);
		iFilledEllipse(friend_bullet.elliR[0].x,friend_bullet.elliR[0].y,3,6);
		friend_bullet.elliL[0].y++;
		friend_bullet.elliR[0].y++;
		if(friend_bullet.elliL[0].y>700)
		{
			friend_bullet.elliL[0].y=friend_plane.elli[2].y;
			friend_bullet.elliR[0].y=friend_plane.elli[2].y;
			friend_bullet.elliL[0].x=friend_plane.elli[1].x;
			friend_bullet.elliR[0].x=friend_plane.elli[2].x;
		}

		if(bullet_state1==1)
		{
			iFilledEllipse(friend_bullet.elliL[1].x,friend_bullet.elliL[1].y,3,6);
			iFilledEllipse(friend_bullet.elliR[1].x,friend_bullet.elliR[1].y,3,6);
			friend_bullet.elliL[1].y++;
			friend_bullet.elliR[1].y++;
			if(friend_bullet.elliL[1].y>700)
			{
				friend_bullet.elliL[1].y=friend_plane.elli[2].y;
				friend_bullet.elliR[1].y=friend_plane.elli[2].y;
				friend_bullet.elliL[1].x=friend_plane.elli[1].x;
				friend_bullet.elliR[1].x=friend_plane.elli[2].x;
			}
		}

		if(bullet_state2==1)
		{
			iFilledEllipse(friend_bullet.elliL[2].x,friend_bullet.elliL[2].y,3,6);
			iFilledEllipse(friend_bullet.elliR[2].x,friend_bullet.elliR[2].y,3,6);
			friend_bullet.elliL[2].y++;
			friend_bullet.elliR[2].y++;
			if(friend_bullet.elliL[2].y>700)
			{
				friend_bullet.elliL[2].y=friend_plane.elli[2].y;
				friend_bullet.elliR[2].y=friend_plane.elli[2].y;
				friend_bullet.elliL[2].x=friend_plane.elli[1].x;
				friend_bullet.elliR[2].x=friend_plane.elli[2].x;
			}
		}

		if(bullet_state3==1)
		{
			iFilledEllipse(friend_bullet.elliL[3].x,friend_bullet.elliL[3].y,3,6);
			iFilledEllipse(friend_bullet.elliR[3].x,friend_bullet.elliR[3].y,3,6);
			friend_bullet.elliL[3].y++;
			friend_bullet.elliR[3].y++;
			if(friend_bullet.elliL[3].y>700)
			{
				friend_bullet.elliL[3].y=friend_plane.elli[2].y;
				friend_bullet.elliR[3].y=friend_plane.elli[2].y;
				friend_bullet.elliL[3].x=friend_plane.elli[1].x;
				friend_bullet.elliR[3].x=friend_plane.elli[2].x;
			}
		}
	
		if(friend_bullet.elliL[0].y>295)
		{
			bullet_state1=1;
		}
		if(friend_bullet.elliL[0].y>430)
		{
			bullet_state2=1;
		}
		if(friend_bullet.elliL[0].y>565)
		{
			bullet_state3=1;
		}

		//ENEMY BULLET DRAWING 1
		if(enemy1_draw_state==0&&enemy1_bullet_state==0)
		{
			iSetColor(255,0,0);
			iFilledEllipse(enemy_bullet1.elliL[0].x,enemy_bullet1.elliL[0].y,3,6);
			iFilledEllipse(enemy_bullet1.elliR[0].x,enemy_bullet1.elliR[0].y,3,6);
			enemy_bullet1.elliL[0].y--;
			enemy_bullet1.elliR[0].y--;
			if(enemy_bullet1.elliL[0].y<65)
			{
				enemy_bullet1.elliL[0].y=enemy_plane1.elli[2].y;
				enemy_bullet1.elliR[0].y=enemy_plane1.elli[2].y;
				enemy_bullet1.elliL[0].x=enemy_plane1.elli[1].x;
				enemy_bullet1.elliR[0].x=enemy_plane1.elli[2].x;
			}

			if(Enemy_1_bullet_state1==1)
			{
				iFilledEllipse(enemy_bullet1.elliL[1].x,enemy_bullet1.elliL[1].y,3,6);
				iFilledEllipse(enemy_bullet1.elliR[1].x,enemy_bullet1.elliR[1].y,3,6);
				enemy_bullet1.elliL[1].y--;
				enemy_bullet1.elliR[1].y--;
				if(enemy_bullet1.elliL[1].y<65)
				{
					enemy_bullet1.elliL[1].y=enemy_plane1.elli[2].y;
					enemy_bullet1.elliR[1].y=enemy_plane1.elli[2].y;
					enemy_bullet1.elliL[1].x=enemy_plane1.elli[1].x;
					enemy_bullet1.elliR[1].x=enemy_plane1.elli[2].x;
				}
			}

			if(Enemy_1_bullet_state2==1)
			{
				iFilledEllipse(enemy_bullet1.elliL[2].x,enemy_bullet1.elliL[2].y,3,6);
				iFilledEllipse(enemy_bullet1.elliR[2].x,enemy_bullet1.elliR[2].y,3,6);
				enemy_bullet1.elliL[2].y--;
				enemy_bullet1.elliR[2].y--;
				if(enemy_bullet1.elliL[2].y<65)
				{
					enemy_bullet1.elliL[2].y=enemy_plane1.elli[2].y;
					enemy_bullet1.elliR[2].y=enemy_plane1.elli[2].y;
					enemy_bullet1.elliL[2].x=enemy_plane1.elli[1].x;
					enemy_bullet1.elliR[2].x=enemy_plane1.elli[2].x;
				}
			}

			if(Enemy_1_bullet_state3==1)
			{
				iFilledEllipse(enemy_bullet1.elliL[3].x,enemy_bullet1.elliL[3].y,3,6);
				iFilledEllipse(enemy_bullet1.elliR[3].x,enemy_bullet1.elliR[3].y,3,6);
				enemy_bullet1.elliL[3].y--;
				enemy_bullet1.elliR[3].y--;
				if(enemy_bullet1.elliL[3].y<65)
				{
					enemy_bullet1.elliL[3].y=enemy_plane1.elli[2].y;
					enemy_bullet1.elliR[3].y=enemy_plane1.elli[2].y;
					enemy_bullet1.elliL[3].x=enemy_plane1.elli[1].x;
					enemy_bullet1.elliR[3].x=enemy_plane1.elli[2].x;
				}
			}
	
			if(m==150)
			{
				Enemy_1_bullet_state1=1;
			}
			if(m==300)
			{
				Enemy_1_bullet_state2=1;
			}
			if(m==450)
			{
				Enemy_1_bullet_state3=1;
			}

		}
		else
		{
			Enemy_1_bullet_state1=0;
			Enemy_1_bullet_state2=0;
			Enemy_1_bullet_state3=0;
		}


		//ENEMY BULLET DRAWING 2
		if(enemy2_draw_state==0)
		{
			iSetColor(255,0,0);
			iFilledEllipse(enemy_bullet2.elliL[0].x,enemy_bullet2.elliL[0].y,3,6);
			iFilledEllipse(enemy_bullet2.elliR[0].x,enemy_bullet2.elliR[0].y,3,6);
			enemy_bullet2.elliL[0].y--;
			enemy_bullet2.elliR[0].y--;
			if(enemy_bullet2.elliL[0].y<65)
			{
				enemy_bullet2.elliL[0].y=enemy_plane2.elli[2].y;
				enemy_bullet2.elliR[0].y=enemy_plane2.elli[2].y;
				enemy_bullet2.elliL[0].x=enemy_plane2.elli[1].x;
				enemy_bullet2.elliR[0].x=enemy_plane2.elli[2].x;
			}

			if(Enemy_2_bullet_state1==1)
			{
				iFilledEllipse(enemy_bullet2.elliL[1].x,enemy_bullet2.elliL[1].y,3,6);
				iFilledEllipse(enemy_bullet2.elliR[1].x,enemy_bullet2.elliR[1].y,3,6);
				enemy_bullet2.elliL[1].y--;
				enemy_bullet2.elliR[1].y--;
				if(enemy_bullet2.elliL[1].y<65)
				{
					enemy_bullet2.elliL[1].y=enemy_plane2.elli[2].y;
					enemy_bullet2.elliR[1].y=enemy_plane2.elli[2].y;
					enemy_bullet2.elliL[1].x=enemy_plane2.elli[1].x;
					enemy_bullet2.elliR[1].x=enemy_plane2.elli[2].x;
				}
			}

			if(Enemy_2_bullet_state2==1)
			{
					iFilledEllipse(enemy_bullet2.elliL[2].x,enemy_bullet2.elliL[2].y,3,6);
					iFilledEllipse(enemy_bullet2.elliR[2].x,enemy_bullet2.elliR[2].y,3,6);
					enemy_bullet2.elliL[2].y--;
					enemy_bullet2.elliR[2].y--;
				if(enemy_bullet2.elliL[2].y<65)
				{
					enemy_bullet2.elliL[2].y=enemy_plane2.elli[2].y;
					enemy_bullet2.elliR[2].y=enemy_plane2.elli[2].y;
					enemy_bullet2.elliL[2].x=enemy_plane2.elli[1].x;
					enemy_bullet2.elliR[2].x=enemy_plane2.elli[2].x;
				}
			}

			if(Enemy_2_bullet_state3==1)
			{
				iFilledEllipse(enemy_bullet2.elliL[3].x,enemy_bullet2.elliL[3].y,3,6);
				iFilledEllipse(enemy_bullet2.elliR[3].x,enemy_bullet2.elliR[3].y,3,6);
				enemy_bullet2.elliL[3].y--;
				enemy_bullet2.elliR[3].y--;
				if(enemy_bullet2.elliL[3].y<65)
				{
					enemy_bullet2.elliL[3].y=enemy_plane2.elli[2].y;
					enemy_bullet2.elliR[3].y=enemy_plane2.elli[2].y;
					enemy_bullet2.elliL[3].x=enemy_plane2.elli[1].x;
					enemy_bullet2.elliR[3].x=enemy_plane2.elli[2].x;
				}
			}
	
			if(m==120)
			{
				Enemy_2_bullet_state1=1;
			}
			if(m==240)
			{
				Enemy_2_bullet_state2=1;
			}
			if(m==360)
			{
				Enemy_2_bullet_state3=1;
			}
		}

	m++;

//////LIFE BAR////
	iSetColor(255,255,255);
	iText(10,15,"FRIEND PLANE");
	if(friend_plane_bar_length>=67)
		iSetColor(0,128,0);
	if(friend_plane_bar_length>30&&friend_plane_bar_length<67)
		iSetColor(255,255,0);
	if(friend_plane_bar_length>0&&friend_plane_bar_length<=30)
		iSetColor(255,0,0);

	iFilledRectangle(10,35,friend_plane_bar_length,10);
	iSetColor(255,255,0);
	iRectangle(10,35,100,10);

	iSetColor(255,255,255);
	iText(150,15,"ENEMY PLANE 1");
	if(enemy_plane1_bar_length>=67)
		iSetColor(0,128,0);
	if(enemy_plane1_bar_length>30&&enemy_plane1_bar_length<67)
		iSetColor(255,255,0);
	if(enemy_plane1_bar_length>0&&enemy_plane1_bar_length<=30)
		iSetColor(255,0,0);
	iFilledRectangle(150,35,enemy_plane1_bar_length,10);
	iSetColor(255,255,0);
	iRectangle(150,35,100,10);

	iSetColor(255,255,255);
	iText(290,15,"ENEMY PLANE 2");
	if(enemy_plane2_bar_length>=67)
		iSetColor(0,128,0);
	if(enemy_plane2_bar_length>30&&enemy_plane2_bar_length<67)
		iSetColor(255,255,0);
	if(enemy_plane2_bar_length>0&&enemy_plane2_bar_length<=30)
		iSetColor(255,0,0);
	iFilledRectangle(290,35,enemy_plane2_bar_length,10);
	iSetColor(255,255,0);
	iRectangle(290,35,100,10);

	iSetColor(255,215,0);
	iFilledRectangle(700,20,70,30);
	iSetColor(0,0,0);
	iText(710,25,"MENU",GLUT_BITMAP_HELVETICA_18);
	iSetColor(255,215,0);
	iText(600,40,"SCORE",GLUT_BITMAP_HELVETICA_18);
	iText(600,20,buffer,GLUT_BITMAP_HELVETICA_18);

	for(collision_loop_point=0;collision_loop_point<=4;collision_loop_point++)
	{
		if(enemy_plane1_bar_length>0)
			if(((friend_bullet.elliL[collision_loop_point].y>enemy_plane1.poly[0].q[1] && friend_bullet.elliL[collision_loop_point].y<enemy_plane1.poly[0].q[2]) && ((friend_bullet.elliL[collision_loop_point].x>enemy_plane1.poly[0].p[1] && friend_bullet.elliL[collision_loop_point].x<enemy_plane1.poly[0].p[3]) || (friend_bullet.elliL[collision_loop_point].x>enemy_plane1.poly[1].p[1] && friend_bullet.elliL[collision_loop_point].x<enemy_plane1.poly[0].p[3]))) || (friend_bullet.elliL[collision_loop_point].x>enemy_plane1.rec[0].x && friend_bullet.elliL[collision_loop_point].x<enemy_plane1.rec[0].x+30 && friend_bullet.elliL[collision_loop_point].y>enemy_plane1.elli[0].y-25 && friend_bullet.elliL[collision_loop_point].y<enemy_plane1.rec[0].y))
			{
				enemy_plane1_bar_length-=0.02;
			}
		if(enemy_plane1_bar_length>0)
			if(( (friend_bullet.elliR[collision_loop_point].y>enemy_plane1.poly[0].q[1] && friend_bullet.elliR[collision_loop_point].y<enemy_plane1.poly[0].q[2]) && ((friend_bullet.elliR[collision_loop_point].x>enemy_plane1.poly[0].p[1] && friend_bullet.elliR[collision_loop_point].x<enemy_plane1.poly[0].p[3]) || (friend_bullet.elliR[collision_loop_point].x>enemy_plane1.poly[1].p[1] && friend_bullet.elliR[collision_loop_point].x<enemy_plane1.poly[0].p[3]))) || (friend_bullet.elliR[collision_loop_point].x>enemy_plane1.rec[0].x && friend_bullet.elliR[collision_loop_point].x<enemy_plane1.rec[0].x+30 && friend_bullet.elliR[collision_loop_point].y>enemy_plane1.elli[0].y-25 && friend_bullet.elliR[collision_loop_point].y<enemy_plane1.rec[0].y))
			{
				enemy_plane1_bar_length-=0.02;
			}
		if(enemy_plane2_bar_length>0)
			if(((friend_bullet.elliL[collision_loop_point].y>enemy_plane2.poly[0].q[1] && friend_bullet.elliL[collision_loop_point].y<enemy_plane2.poly[0].q[2]) && ((friend_bullet.elliL[collision_loop_point].x>enemy_plane2.poly[0].p[1] && friend_bullet.elliL[collision_loop_point].x<enemy_plane2.poly[0].p[3]) || (friend_bullet.elliL[collision_loop_point].x>enemy_plane2.poly[1].p[1] && friend_bullet.elliL[collision_loop_point].x<enemy_plane2.poly[0].p[3]))) || (friend_bullet.elliL[collision_loop_point].x>enemy_plane2.rec[0].x && friend_bullet.elliL[collision_loop_point].x<enemy_plane2.rec[0].x+30 && friend_bullet.elliL[collision_loop_point].y>enemy_plane2.elli[0].y-25 && friend_bullet.elliL[collision_loop_point].y<enemy_plane2.rec[0].y))
			{
				enemy_plane2_bar_length-=0.02;
			}
		if(enemy_plane1_bar_length>0)
			if(((friend_bullet.elliR[collision_loop_point].y>enemy_plane2.poly[0].q[1] && friend_bullet.elliR[collision_loop_point].y<enemy_plane2.poly[0].q[2]) && ((friend_bullet.elliR[collision_loop_point].x>enemy_plane2.poly[0].p[1] && friend_bullet.elliR[collision_loop_point].x<enemy_plane2.poly[0].p[3]) || (friend_bullet.elliR[collision_loop_point].x>enemy_plane2.poly[1].p[1] && friend_bullet.elliR[collision_loop_point].x<enemy_plane2.poly[0].p[3]))) || (friend_bullet.elliR[collision_loop_point].x>enemy_plane2.rec[0].x && friend_bullet.elliR[collision_loop_point].x<enemy_plane2.rec[0].x+30 && friend_bullet.elliR[collision_loop_point].y>enemy_plane2.elli[0].y-25 && friend_bullet.elliR[collision_loop_point].y<enemy_plane2.rec[0].y))
			{
				enemy_plane2_bar_length-=0.02;
			}
///////////////FRIEND PLANE
		if(friend_plane_bar_length>0)
			if(((enemy_bullet1.elliL[collision_loop_point].y>friend_plane.poly[0].q[2] && enemy_bullet1.elliL[collision_loop_point].y<friend_plane.poly[0].q[1]) && ((enemy_bullet1.elliL[collision_loop_point].x>friend_plane.poly[0].p[1] && enemy_bullet1.elliL[collision_loop_point].x<friend_plane.poly[0].p[3]) || (enemy_bullet1.elliL[collision_loop_point].x>friend_plane.poly[1].p[3] && enemy_bullet1.elliL[collision_loop_point].x<friend_plane.poly[1].p[2]))) || (enemy_bullet1.elliL[collision_loop_point].x>friend_plane.rec[1].x && enemy_bullet1.elliL[collision_loop_point].x<friend_plane.rec[1].x+26 && enemy_bullet1.elliL[collision_loop_point].y>friend_plane.rec[1].y && enemy_bullet1.elliL[collision_loop_point].y<friend_plane.elli[0].y+25))
			{
				friend_plane_bar_length-=0.02;
			}
		if(friend_plane_bar_length>0)
			if(((enemy_bullet1.elliR[collision_loop_point].y>friend_plane.poly[0].q[2] && enemy_bullet1.elliR[collision_loop_point].y<friend_plane.poly[0].q[1]) && ((enemy_bullet1.elliR[collision_loop_point].x>friend_plane.poly[0].p[1] && enemy_bullet1.elliR[collision_loop_point].x<friend_plane.poly[0].p[3]) || (enemy_bullet1.elliR[collision_loop_point].x>friend_plane.poly[1].p[3] && enemy_bullet1.elliR[collision_loop_point].x<friend_plane.poly[1].p[2]))) || (enemy_bullet1.elliR[collision_loop_point].x>friend_plane.rec[1].x && enemy_bullet1.elliR[collision_loop_point].x<friend_plane.rec[1].x+30 && enemy_bullet1.elliR[collision_loop_point].y>friend_plane.elli[1].y && enemy_bullet1.elliR[collision_loop_point].y<friend_plane.rec[0].y+25))
			{
				friend_plane_bar_length-=0.02;
			}
		if(friend_plane_bar_length>0)
			if(((enemy_bullet2.elliL[collision_loop_point].y>friend_plane.poly[0].q[2] && enemy_bullet2.elliL[collision_loop_point].y<friend_plane.poly[0].q[1]) && ((enemy_bullet2.elliL[collision_loop_point].x>friend_plane.poly[0].p[1] && enemy_bullet2.elliL[collision_loop_point].x<friend_plane.poly[0].p[3]) || (enemy_bullet2.elliL[collision_loop_point].x>friend_plane.poly[1].p[3] && enemy_bullet2.elliL[collision_loop_point].x<friend_plane.poly[1].p[2]))) || (enemy_bullet2.elliL[collision_loop_point].x>friend_plane.rec[1].x && enemy_bullet2.elliL[collision_loop_point].x<friend_plane.rec[1].x+30 && enemy_bullet2.elliL[collision_loop_point].y>friend_plane.elli[1].y && enemy_bullet2.elliL[collision_loop_point].y<friend_plane.rec[0].y+25))
			{
				friend_plane_bar_length-=0.02;
			}
		if(friend_plane_bar_length>0)
			if(((enemy_bullet2.elliR[collision_loop_point].y<friend_plane.poly[0].q[2] && enemy_bullet2.elliR[collision_loop_point].y>friend_plane.poly[0].q[1]) && ((enemy_bullet2.elliR[collision_loop_point].x>friend_plane.poly[0].p[1] && enemy_bullet2.elliR[collision_loop_point].x<friend_plane.poly[0].p[3]) || (enemy_bullet2.elliR[collision_loop_point].x>friend_plane.poly[1].p[3] && enemy_bullet2.elliR[collision_loop_point].x<friend_plane.poly[1].p[2]))) || (enemy_bullet2.elliR[collision_loop_point].x>friend_plane.rec[1].x && enemy_bullet2.elliR[collision_loop_point].x<friend_plane.rec[1].x+30 && enemy_bullet2.elliR[collision_loop_point].y<friend_plane.elli[1].y && enemy_bullet2.elliR[collision_loop_point].y>friend_plane.rec[0].y+25))
			{
				friend_plane_bar_length-=0.02;
			}

	}
	if(enemy_plane1_bar_length<0)
		enemy1_draw_state=1;
	if(enemy_plane2_bar_length<0)
		enemy2_draw_state=1;
	if(friend_plane_bar_length<0)
		friend_draw_state=1;
	}///////end of friend death cond

	else if(friend_draw_state==1)
	{
		iClear();
		//iShowBMP(0,0,"download");
		iSetColor(255,255,255);
		iText(350,600,"GAME OVER",GLUT_BITMAP_HELVETICA_18);
		iText(250,450,"you survived      seconds",GLUT_BITMAP_HELVETICA_18);
		iText(365,450,buffer,GLUT_BITMAP_HELVETICA_18);
		if(restart_color_state==0)
			iSetColor(255,215,0);
		else
			iSetColor(127,255,0);
		iFilledRectangle(250,100,300,100);
		iSetColor(0,0,0);
		iText(350,150,"RESTART",GLUT_BITMAP_HELVETICA_18);
		iSetColor(255,215,0);
		iFilledRectangle(250,300,300,100);
		iSetColor(0,0,0);
		iText(370,350,"MENU",GLUT_BITMAP_HELVETICA_18);
		
	}
	else if(friend_draw_state==2)
	{
		iClear();
		iSetColor(255,215,0);
		iFilledRectangle(250,550,300,100);
		iSetColor(0,0,0);
		iText(370,600,"PLAY",GLUT_BITMAP_HELVETICA_18);
		iSetColor(255,215,0);
		iFilledRectangle(250,400,300,100);
		iSetColor(0,0,0);
		iText(370,450,"SCORE",GLUT_BITMAP_HELVETICA_18);
		iSetColor(255,215,0);
		iFilledRectangle(250,250,300,100);
		iSetColor(0,0,0);
		iText(360,300,"ABOUT",GLUT_BITMAP_HELVETICA_18);
		iSetColor(255,215,0);
		iFilledRectangle(250,100,300,100);
		iSetColor(0,0,0);
		iText(370,150,"EXIT",GLUT_BITMAP_HELVETICA_18);

	}
	else if(friend_draw_state==3)
	{
		iClear();
		iSetColor(255,0,0);
		iText(20,650,"HIGHEST SCORE",GLUT_BITMAP_HELVETICA_18);
		iText(20,600,"1.",GLUT_BITMAP_HELVETICA_18);
		iText(20,500,"2.",GLUT_BITMAP_HELVETICA_18);
		iText(20,400,"3.",GLUT_BITMAP_HELVETICA_18);

		iSetColor(255,215,0);
		iFilledRectangle(650,50,100,50);
		iSetColor(0,0,0);
		iText(675,70,"BACK",GLUT_BITMAP_HELVETICA_18);
	}
	else if(friend_draw_state==4)
	{
		iClear();
		iSetColor(255,0,0);
		iText(20,650,"Submitted by - Salman Jahan",GLUT_BITMAP_HELVETICA_18);
		iText(20,620,"Id-151011",GLUT_BITMAP_HELVETICA_18);
		iText(20,590,"1st year 2nd Semister.",GLUT_BITMAP_HELVETICA_18);
		iText(20,560,"Project with iGraphics. Author - S. M. Shahriar Nirjon",GLUT_BITMAP_HELVETICA_18);

		iSetColor(255,215,0);
		iFilledRectangle(650,50,100,50);
		iSetColor(0,0,0);
		iText(675,70,"BACK",GLUT_BITMAP_HELVETICA_18);
	}

	
}
void iPassiveMouseMove(int mx,int my)
{
	if(mx<550&&mx>250&&my>100&&my<200)
	{
		restart_color_state=1;
	}
	else
		restart_color_state=0;
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
		//printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
		printf("x=%d  y=%d\n",mx,my);
		if(friend_draw_state==1&&mx<550&&mx>250&&my>100&&my<200)
		{
			friend_draw_state=0;
			friend_plane_bar_length=100;
			enemy_plane1_bar_length=100;
			enemy_plane2_bar_length=100;
			enemy1_draw_state=0;
			enemy2_draw_state=0;
			friend_draw_state=0;
			score=0;
		}
		if(friend_draw_state==1&&mx<550&&mx>250&&my>300&&my<300)
		{
			friend_draw_state=2;
		}
		if(friend_draw_state==2&&mx<550&&mx>250&&my>550&&my<650)
		{
			friend_draw_state=0;//play
			score=0;
		}
		if(friend_draw_state==2&&mx<550&&mx>250&&my>400&&my<500)
		{
			friend_draw_state=3;//score
		}
		if(friend_draw_state==2&&mx<550&&mx>250&&my>250&&my<350)
		{
			friend_draw_state=4;//instruction
		}
		if(friend_draw_state==2&&friend_draw_state==2&&mx<550&&mx>250&&my>100&&my<200)
		{
			exit(1);
		}
		if(friend_draw_state==0&&mx>700&&mx<770&&my>20&&my<50)
		{
			friend_draw_state=2;//first page
		}
		if(friend_draw_state==3&&mx>650&&mx<750&&my>50&&my<100)
			friend_draw_state=2;//first page
		if(friend_draw_state==4&&mx>650&&mx<750&&my>50&&my<100)
			friend_draw_state=2;//first page
		if(friend_draw_state==1&&mx>250&&mx<550&&my>300&&my<400)
			friend_draw_state=2;//first page

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here	
	}
}


/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_RIGHT) {
		if(friend_plane.poly[1].p[0]<800)
			{
				for(i=0;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						friend_plane.poly[i].p[j]+=10;
						
					}
					friend_plane.poly[6].p[i]+=10;
				}
				for(i=0;i<8;i++)
				{
					friend_plane.poly[5].p[i]+=10;
				}
				for(i=0;i<3;i++)
				{
					friend_plane.poly[7].p[i]+=10;
				}
				friend_plane.rec[0].x+=10;
				friend_plane.rec[1].x+=10;
				friend_plane.rec[2].x+=10;
				friend_plane.rec[3].x+=10;

				friend_plane.elli[0].x+=10;
				friend_plane.elli[1].x+=10;
				friend_plane.elli[2].x+=10;

				friend_plane.li[0].x1+=10;
				friend_plane.li[0].x2+=10;
				friend_plane.li[1].x1+=10;
				friend_plane.li[1].x2+=10;
				friend_plane.li[2].x1+=10;
				friend_plane.li[2].x2+=10;
		}
	}
	if(key== GLUT_KEY_LEFT)
	{
		if(friend_plane.poly[0].p[0]>0)
			{
				for(i=0;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						friend_plane.poly[i].p[j]-=10;
						
					}
					friend_plane.poly[6].p[i]-=10;
				}
				for(i=0;i<8;i++)
				{
					friend_plane.poly[5].p[i]-=10;
				}
				for(i=0;i<3;i++)
				{
					friend_plane.poly[7].p[i]-=10;
				}
				friend_plane.rec[0].x-=10;
				friend_plane.rec[1].x-=10;
				friend_plane.rec[2].x-=10;
				friend_plane.rec[3].x-=10;

				friend_plane.elli[0].x-=10;
				friend_plane.elli[1].x-=10;
				friend_plane.elli[2].x-=10;

				friend_plane.li[0].x1-=10;
				friend_plane.li[0].x2-=10;
				friend_plane.li[1].x1-=10;
				friend_plane.li[1].x2-=10;
				friend_plane.li[2].x1-=10;
				friend_plane.li[2].x2-=10;

		}
	}
	if(key== GLUT_KEY_DOWN)
	{
		if(friend_plane.poly[4].q[2]>70)
			{
				for(i=0;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						friend_plane.poly[i].q[j]-=10;
						
					}
					friend_plane.poly[6].q[i]-=10;
				}
				for(i=0;i<8;i++)
				{
					friend_plane.poly[5].q[i]-=10;
				}
				for(i=0;i<3;i++)
				{
					friend_plane.poly[7].q[i]-=10;
				}
				friend_plane.rec[0].y-=10;
				friend_plane.rec[1].y-=10;
				friend_plane.rec[2].y-=10;
				friend_plane.rec[3].y-=10;

				friend_plane.elli[0].y-=10;
				friend_plane.elli[1].y-=10;
				friend_plane.elli[2].y-=10;

				friend_plane.li[0].y1-=10;
				friend_plane.li[0].y2-=10;
				friend_plane.li[1].y1-=10;
				friend_plane.li[1].y2-=10;
				friend_plane.li[2].y1-=10;
				friend_plane.li[2].y2-=10;

			}
	}
	if(key== GLUT_KEY_UP)
	{
			if(friend_plane.li[0].y2<700)
			{
				for(i=0;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						friend_plane.poly[i].q[j]+=10;
						
					}
					friend_plane.poly[6].q[i]+=10;
				}
				for(i=0;i<8;i++)
				{
					friend_plane.poly[5].q[i]+=10;
				}
				for(i=0;i<3;i++)
				{
					friend_plane.poly[7].q[i]+=10;
				}
				friend_plane.rec[0].y+=10;
				friend_plane.rec[1].y+=10;
				friend_plane.rec[2].y+=10;
				friend_plane.rec[3].y+=10;

				friend_plane.elli[0].y+=10;
				friend_plane.elli[1].y+=10;
				friend_plane.elli[2].y+=10;

				friend_plane.li[0].y1+=10;
				friend_plane.li[0].y2+=10;
				friend_plane.li[1].y1+=10;
				friend_plane.li[1].y2+=10;
				friend_plane.li[2].y1+=10;
				friend_plane.li[2].y2+=10;

			}

		
		}

}

//*********************"""""""""""""MAIN FUNCTION""""""""**********************************************

int main() {
	//place your own initialization codes here.

	//FRIEND PLANE POINT
	//rectangle point
	friend_plane.rec[0].x=385;
	friend_plane.rec[0].y=140;

	friend_plane.rec[1].x=387;
	friend_plane.rec[1].y=157;

	friend_plane.rec[2].x=360;
	friend_plane.rec[2].y=140;

	friend_plane.rec[3].x=430;
	friend_plane.rec[3].y=140;
	//ellipse point
	friend_plane.elli[0].x=400;
	friend_plane.elli[0].y=195;

	friend_plane.elli[1].x=365;
	friend_plane.elli[1].y=150;

	friend_plane.elli[2].x=435;
	friend_plane.elli[2].y=150;
	//line points
	friend_plane.li[0].x1=400;
	friend_plane.li[0].y1=220;
	friend_plane.li[0].x2=400;
	friend_plane.li[0].y2=230;

	friend_plane.li[1].x1=395;
	friend_plane.li[1].y1=136;
	friend_plane.li[1].x2=405;
	friend_plane.li[1].y2=136;

	friend_plane.li[2].x1=496;
	friend_plane.li[2].y1=125;
	friend_plane.li[2].x2=403;
	friend_plane.li[2].y2=125;

	//polygon points
	//upper pakha
	friend_plane.poly[0].p=(double*)calloc(4,sizeof(double));
	friend_plane.poly[0].q=(double*)calloc(4,sizeof(double));
	friend_plane.poly[0].p[0]=380;
	friend_plane.poly[0].p[1]=350;
	friend_plane.poly[0].p[2]=350;
	friend_plane.poly[0].p[3]=386;
	friend_plane.poly[0].q[0]=157;
	friend_plane.poly[0].q[1]=143;
	friend_plane.poly[0].q[2]=133;
	friend_plane.poly[0].q[3]=130;

	friend_plane.poly[1].p=(double*)calloc(4,sizeof(double));
	friend_plane.poly[1].q=(double*)calloc(4,sizeof(double));
	friend_plane.poly[1].p[0]=420;
	friend_plane.poly[1].p[1]=450;
	friend_plane.poly[1].p[2]=450;
	friend_plane.poly[1].p[3]=414;
	friend_plane.poly[1].q[0]=157;
	friend_plane.poly[1].q[1]=143;
	friend_plane.poly[1].q[2]=133;
	friend_plane.poly[1].q[3]=130;

	//lower pakha
	friend_plane.poly[2].p=(double*)calloc(4,sizeof(double));
	friend_plane.poly[2].q=(double*)calloc(4,sizeof(double));
	friend_plane.poly[2].p[0]=410;
	friend_plane.poly[2].p[1]=427;
	friend_plane.poly[2].p[2]=427;
	friend_plane.poly[2].p[3]=408;
	friend_plane.poly[2].q[0]=105;
	friend_plane.poly[2].q[1]=93;
	friend_plane.poly[2].q[2]=86;
	friend_plane.poly[2].q[3]=81;

	friend_plane.poly[3].p=(double*)calloc(4,sizeof(double));
	friend_plane.poly[3].q=(double*)calloc(4,sizeof(double));
	friend_plane.poly[3].p[0]=390;
	friend_plane.poly[3].p[1]=373;
	friend_plane.poly[3].p[2]=373;
	friend_plane.poly[3].p[3]=392;
	friend_plane.poly[3].q[0]=105;
	friend_plane.poly[3].q[1]=93;
	friend_plane.poly[3].q[2]=86;
	friend_plane.poly[3].q[3]=81;
	//other
	friend_plane.poly[4].p=(double*)calloc(4,sizeof(double));
	friend_plane.poly[4].q=(double*)calloc(4,sizeof(double));
	friend_plane.poly[4].p[0]=385;
	friend_plane.poly[4].p[1]=415;
	friend_plane.poly[4].p[2]=407;
	friend_plane.poly[4].p[3]=393;
	friend_plane.poly[4].q[0]=140;
	friend_plane.poly[4].q[1]=140;
	friend_plane.poly[4].q[2]=65;
	friend_plane.poly[4].q[3]=65;

	friend_plane.poly[5].p=(double*)calloc(8,sizeof(double));
	friend_plane.poly[5].q=(double*)calloc(8,sizeof(double));
	friend_plane.poly[5].p[0]=385;
	friend_plane.poly[5].p[1]=415;
	friend_plane.poly[5].p[2]=420;
	friend_plane.poly[5].p[3]=420;
	friend_plane.poly[5].p[4]=415;
	friend_plane.poly[5].p[5]=385;
	friend_plane.poly[5].p[6]=380;
	friend_plane.poly[5].p[7]=380;
	friend_plane.poly[5].q[0]=150;
	friend_plane.poly[5].q[1]=150;
	friend_plane.poly[5].q[2]=157;
	friend_plane.poly[5].q[3]=160;
	friend_plane.poly[5].q[4]=163;
	friend_plane.poly[5].q[5]=163;
	friend_plane.poly[5].q[6]=160;
	friend_plane.poly[5].q[7]=157;

	friend_plane.poly[6].p=(double*)calloc(4,sizeof(double));
	friend_plane.poly[6].q=(double*)calloc(4,sizeof(double));
	friend_plane.poly[6].p[0]=387;
	friend_plane.poly[6].p[1]=413;
	friend_plane.poly[6].p[2]=408;
	friend_plane.poly[6].p[3]=392;
	friend_plane.poly[6].q[0]=182;
	friend_plane.poly[6].q[1]=182;
	friend_plane.poly[6].q[2]=195;
	friend_plane.poly[6].q[3]=195;

	friend_plane.poly[7].p=(double*)calloc(3,sizeof(double));
	friend_plane.poly[7].q=(double*)calloc(3,sizeof(double));
	friend_plane.poly[7].p[0]=393;
	friend_plane.poly[7].p[1]=407;
	friend_plane.poly[7].p[2]=400;
	friend_plane.poly[7].q[0]=158;
	friend_plane.poly[7].q[1]=158;
	friend_plane.poly[7].q[2]=80;

	

	//FRIEND BULLET POINTS
	friend_bullet.elliL[0].x=friend_plane.elli[1].x;
	friend_bullet.elliL[0].y=friend_plane.elli[1].y;
	friend_bullet.elliL[1].x=friend_plane.elli[1].x;
	friend_bullet.elliL[1].y=friend_plane.elli[1].y;
	friend_bullet.elliL[2].x=friend_plane.elli[1].x;
	friend_bullet.elliL[2].y=friend_plane.elli[1].y;
	friend_bullet.elliL[3].x=friend_plane.elli[1].x;
	friend_bullet.elliL[3].y=friend_plane.elli[1].y;

	friend_bullet.elliR[0].x=friend_plane.elli[2].x;
	friend_bullet.elliR[0].y=friend_plane.elli[2].y;
	friend_bullet.elliR[1].x=friend_plane.elli[2].x;
	friend_bullet.elliR[1].y=friend_plane.elli[2].y;
	friend_bullet.elliR[2].x=friend_plane.elli[2].x;
	friend_bullet.elliR[2].y=friend_plane.elli[2].y;
	friend_bullet.elliR[3].x=friend_plane.elli[2].x;
	friend_bullet.elliR[3].y=friend_plane.elli[2].y;

//ENEMY PLANE POINTS 1
	enemy_plane1.rec[0].x=random_point1-15;
	enemy_plane1.rec[0].y=random_pointy1-110;

	enemy_plane1.rec[1].x=random_point1-13;
	enemy_plane1.rec[1].y=random_pointy1-142;

	enemy_plane1.rec[2].x=random_point1-40;
	enemy_plane1.rec[2].y=random_pointy1-112;

	enemy_plane1.rec[3].x=random_point1+30;
	enemy_plane1.rec[3].y=random_pointy1-112;
	//ellipse point
	enemy_plane1.elli[0].x=random_point1;
	enemy_plane1.elli[0].y=random_pointy1-155;

	enemy_plane1.elli[1].x=random_point1-35;
	enemy_plane1.elli[1].y=random_pointy1-110;

	enemy_plane1.elli[2].x=random_point1+35;
	enemy_plane1.elli[2].y=random_pointy1-110;
	//line points
	enemy_plane1.li[0].x1=random_point1;
	enemy_plane1.li[0].y1=random_pointy1-180;
	enemy_plane1.li[0].x2=random_point1;
	enemy_plane1.li[0].y2=random_pointy1-190;

	enemy_plane1.li[1].x1=random_point1-5;
	enemy_plane1.li[1].y1=random_pointy1-96;
	enemy_plane1.li[1].x2=random_point1+5;
	enemy_plane1.li[1].y2=random_pointy1-96;

	enemy_plane1.li[2].x1=random_point1-4;
	enemy_plane1.li[2].y1=random_pointy1-85;
	enemy_plane1.li[2].x2=random_point1+3;
	enemy_plane1.li[2].y2=random_pointy1-85;

	//polygon points
	//upper pakha
	enemy_plane1.poly[0].p=(double*)calloc(4,sizeof(double));
	enemy_plane1.poly[0].q=(double*)calloc(4,sizeof(double));
	enemy_plane1.poly[0].p[0]=random_point1-20;
	enemy_plane1.poly[0].p[1]=random_point1-50;
	enemy_plane1.poly[0].p[2]=random_point1-50;
	enemy_plane1.poly[0].p[3]=random_point1-14;
	enemy_plane1.poly[0].q[0]=random_pointy1-117;
	enemy_plane1.poly[0].q[1]=random_pointy1-103;
	enemy_plane1.poly[0].q[2]=random_pointy1-93;
	enemy_plane1.poly[0].q[3]=random_pointy1-90;

	enemy_plane1.poly[1].p=(double*)calloc(4,sizeof(double));
	enemy_plane1.poly[1].q=(double*)calloc(4,sizeof(double));
	enemy_plane1.poly[1].p[0]=random_point1+20;
	enemy_plane1.poly[1].p[1]=random_point1+50;
	enemy_plane1.poly[1].p[2]=random_point1+50;
	enemy_plane1.poly[1].p[3]=random_point1+14;
	enemy_plane1.poly[1].q[0]=random_pointy1-117;
	enemy_plane1.poly[1].q[1]=random_pointy1-103;
	enemy_plane1.poly[1].q[2]=random_pointy1-93;
	enemy_plane1.poly[1].q[3]=random_pointy1-90;

	//lower pakha
	enemy_plane1.poly[2].p=(double*)calloc(4,sizeof(double));
	enemy_plane1.poly[2].q=(double*)calloc(4,sizeof(double));
	enemy_plane1.poly[2].p[0]=random_point1+10;
	enemy_plane1.poly[2].p[1]=random_point1+27;
	enemy_plane1.poly[2].p[2]=random_point1+27;
	enemy_plane1.poly[2].p[3]=random_point1+8;
	enemy_plane1.poly[2].q[0]=random_pointy1-65;
	enemy_plane1.poly[2].q[1]=random_pointy1-53;
	enemy_plane1.poly[2].q[2]=random_pointy1-46;
	enemy_plane1.poly[2].q[3]=random_pointy1-41;

	enemy_plane1.poly[3].p=(double*)calloc(4,sizeof(double));
	enemy_plane1.poly[3].q=(double*)calloc(4,sizeof(double));
	enemy_plane1.poly[3].p[0]=random_point1-8;
	enemy_plane1.poly[3].p[1]=random_point1-27;
	enemy_plane1.poly[3].p[2]=random_point1-27;
	enemy_plane1.poly[3].p[3]=random_point1-8;
	enemy_plane1.poly[3].q[0]=random_pointy1-65;
	enemy_plane1.poly[3].q[1]=random_pointy1-53;
	enemy_plane1.poly[3].q[2]=random_pointy1-46;
	enemy_plane1.poly[3].q[3]=random_pointy1-41;
	//other
	enemy_plane1.poly[4].p=(double*)calloc(4,sizeof(double));
	enemy_plane1.poly[4].q=(double*)calloc(4,sizeof(double));
	enemy_plane1.poly[4].p[0]=random_point1-15;
	enemy_plane1.poly[4].p[1]=random_point1+15;
	enemy_plane1.poly[4].p[2]=random_point1+7;
	enemy_plane1.poly[4].p[3]=random_point1-7;
	enemy_plane1.poly[4].q[0]=random_pointy1-100;
	enemy_plane1.poly[4].q[1]=random_pointy1-100;
	enemy_plane1.poly[4].q[2]=random_pointy1-25;
	enemy_plane1.poly[4].q[3]=random_pointy1-25;

	enemy_plane1.poly[5].p=(double*)calloc(8,sizeof(double));
	enemy_plane1.poly[5].q=(double*)calloc(8,sizeof(double));
	enemy_plane1.poly[5].p[0]=random_point1-15;
	enemy_plane1.poly[5].p[1]=random_point1+15;
	enemy_plane1.poly[5].p[2]=random_point1+20;
	enemy_plane1.poly[5].p[3]=random_point1+20;
	enemy_plane1.poly[5].p[4]=random_point1+15;
	enemy_plane1.poly[5].p[5]=random_point1-15;
	enemy_plane1.poly[5].p[6]=random_point1-20;
	enemy_plane1.poly[5].p[7]=random_point1-20;
	enemy_plane1.poly[5].q[0]=random_pointy1-110;
	enemy_plane1.poly[5].q[1]=random_pointy1-110;
	enemy_plane1.poly[5].q[2]=random_pointy1-117;
	enemy_plane1.poly[5].q[3]=random_pointy1-120;
	enemy_plane1.poly[5].q[4]=random_pointy1-123;
	enemy_plane1.poly[5].q[5]=random_pointy1-123;
	enemy_plane1.poly[5].q[6]=random_pointy1-120;
	enemy_plane1.poly[5].q[7]=random_pointy1-117;

	enemy_plane1.poly[6].p=(double*)calloc(4,sizeof(double));
	enemy_plane1.poly[6].q=(double*)calloc(4,sizeof(double));
	enemy_plane1.poly[6].p[0]=random_point1-13;
	enemy_plane1.poly[6].p[1]=random_point1+13;
	enemy_plane1.poly[6].p[2]=random_point1+8;
	enemy_plane1.poly[6].p[3]=random_point1-8;
	enemy_plane1.poly[6].q[0]=random_pointy1-142;
	enemy_plane1.poly[6].q[1]=random_pointy1-142;
	enemy_plane1.poly[6].q[2]=random_pointy1-155;
	enemy_plane1.poly[6].q[3]=random_pointy1-155;

	enemy_plane1.poly[7].p=(double*)calloc(3,sizeof(double));
	enemy_plane1.poly[7].q=(double*)calloc(3,sizeof(double));
	enemy_plane1.poly[7].p[0]=random_point1-7;
	enemy_plane1.poly[7].p[1]=random_point1+7;
	enemy_plane1.poly[7].p[2]=random_point1;
	enemy_plane1.poly[7].q[0]=random_pointy1-118;
	enemy_plane1.poly[7].q[1]=random_pointy1-118;
	enemy_plane1.poly[7].q[2]=random_pointy1-40;

	//BULLET
	enemy_bullet1.elliL[0].x=random_point1-35;
	enemy_bullet1.elliL[1].x=random_point1-35;
	enemy_bullet1.elliL[2].x=random_point1-35;
	enemy_bullet1.elliL[3].x=random_point1-35;
	enemy_bullet1.elliL[0].y=random_pointy1-110;
	enemy_bullet1.elliL[1].y=random_pointy1-110;
	enemy_bullet1.elliL[2].y=random_pointy1-110;
	enemy_bullet1.elliL[3].y=random_pointy1-110;

	enemy_bullet1.elliR[0].x=random_point1+35;
	enemy_bullet1.elliR[1].x=random_point1+35;
	enemy_bullet1.elliR[2].x=random_point1+35;
	enemy_bullet1.elliR[3].x=random_point1+35;
	enemy_bullet1.elliR[0].y=random_pointy1-110;
	enemy_bullet1.elliR[1].y=random_pointy1-110;
	enemy_bullet1.elliR[2].y=random_pointy1-110;
	enemy_bullet1.elliR[3].y=random_pointy1-110;

	//ENEMY PLANE POINTS 2
	enemy_plane2.poly[0].p=(double*)calloc(4,sizeof(double));
	enemy_plane2.poly[0].q=(double*)calloc(4,sizeof(double));
	enemy_plane2.poly[1].p=(double*)calloc(4,sizeof(double));
	enemy_plane2.poly[1].q=(double*)calloc(4,sizeof(double));
	enemy_plane2.poly[2].p=(double*)calloc(4,sizeof(double));
	enemy_plane2.poly[2].q=(double*)calloc(4,sizeof(double));
	enemy_plane2.poly[3].p=(double*)calloc(4,sizeof(double));
	enemy_plane2.poly[3].q=(double*)calloc(4,sizeof(double));
	enemy_plane2.poly[4].p=(double*)calloc(4,sizeof(double));
	enemy_plane2.poly[4].q=(double*)calloc(4,sizeof(double));
	enemy_plane2.poly[5].p=(double*)calloc(8,sizeof(double));
	enemy_plane2.poly[5].q=(double*)calloc(8,sizeof(double));
	enemy_plane2.poly[6].p=(double*)calloc(4,sizeof(double));
	enemy_plane2.poly[6].q=(double*)calloc(4,sizeof(double));
	enemy_plane2.poly[7].p=(double*)calloc(3,sizeof(double));
	enemy_plane2.poly[7].q=(double*)calloc(3,sizeof(double));

	
	enemy_plane2.rec[0].x=random_point2-15;
	enemy_plane2.rec[0].y=random_pointy2-110;

	enemy_plane2.rec[1].x=random_point2-13;
	enemy_plane2.rec[1].y=random_pointy2-142;

	enemy_plane2.rec[2].x=random_point2-40;
	enemy_plane2.rec[2].y=random_pointy2-112;

	enemy_plane2.rec[3].x=random_point2+30;
	enemy_plane2.rec[3].y=random_pointy2-112;
	//ellipse point
	enemy_plane2.elli[0].x=random_point2;
	enemy_plane2.elli[0].y=random_pointy2-155;

	enemy_plane2.elli[1].x=random_point2-35;
	enemy_plane2.elli[1].y=random_pointy2-110;

	enemy_plane2.elli[2].x=random_point2+35;
	enemy_plane2.elli[2].y=random_pointy2-110;
	//line points
	enemy_plane2.li[0].x1=random_point2;
	enemy_plane2.li[0].y1=random_pointy2-180;
	enemy_plane2.li[0].x2=random_point2;
	enemy_plane2.li[0].y2=random_pointy2-190;

	enemy_plane2.li[1].x1=random_point2-5;
	enemy_plane2.li[1].y1=random_pointy2-96;
	enemy_plane2.li[1].x2=random_point2+5;
	enemy_plane2.li[1].y2=random_pointy2-96;

	enemy_plane2.li[2].x1=random_point2-4;
	enemy_plane2.li[2].y1=random_pointy2-85;
	enemy_plane2.li[2].x2=random_point2+3;
	enemy_plane2.li[2].y2=random_pointy2-85;

	//polygon points
	//upper pakha
	
	enemy_plane2.poly[0].p[0]=random_point2-20;
	enemy_plane2.poly[0].p[1]=random_point2-50;
	enemy_plane2.poly[0].p[2]=random_point2-50;
	enemy_plane2.poly[0].p[3]=random_point2-14;
	enemy_plane2.poly[0].q[0]=random_pointy2-117;
	enemy_plane2.poly[0].q[1]=random_pointy2-103;
	enemy_plane2.poly[0].q[2]=random_pointy2-93;
	enemy_plane2.poly[0].q[3]=random_pointy2-90;

	
	enemy_plane2.poly[1].p[0]=random_point2+20;
	enemy_plane2.poly[1].p[1]=random_point2+50;
	enemy_plane2.poly[1].p[2]=random_point2+50;
	enemy_plane2.poly[1].p[3]=random_point2+14;
	enemy_plane2.poly[1].q[0]=random_pointy2-117;
	enemy_plane2.poly[1].q[1]=random_pointy2-103;
	enemy_plane2.poly[1].q[2]=random_pointy2-93;
	enemy_plane2.poly[1].q[3]=random_pointy2-90;

	//lower pakha
	
	enemy_plane2.poly[2].p[0]=random_point2+10;
	enemy_plane2.poly[2].p[1]=random_point2+27;
	enemy_plane2.poly[2].p[2]=random_point2+27;
	enemy_plane2.poly[2].p[3]=random_point2+8;
	enemy_plane2.poly[2].q[0]=random_pointy2-65;
	enemy_plane2.poly[2].q[1]=random_pointy2-53;
	enemy_plane2.poly[2].q[2]=random_pointy2-46;
	enemy_plane2.poly[2].q[3]=random_pointy2-41;

	
	enemy_plane2.poly[3].p[0]=random_point2-8;
	enemy_plane2.poly[3].p[1]=random_point2-27;
	enemy_plane2.poly[3].p[2]=random_point2-27;
	enemy_plane2.poly[3].p[3]=random_point2-8;
	enemy_plane2.poly[3].q[0]=random_pointy2-65;
	enemy_plane2.poly[3].q[1]=random_pointy2-53;
	enemy_plane2.poly[3].q[2]=random_pointy2-46;
	enemy_plane2.poly[3].q[3]=random_pointy2-41;
	//other
	
	enemy_plane2.poly[4].p[0]=random_point2-15;
	enemy_plane2.poly[4].p[1]=random_point2+15;
	enemy_plane2.poly[4].p[2]=random_point2+7;
	enemy_plane2.poly[4].p[3]=random_point2-7;
	enemy_plane2.poly[4].q[0]=random_pointy2-100;
	enemy_plane2.poly[4].q[1]=random_pointy2-100;
	enemy_plane2.poly[4].q[2]=random_pointy2-25;
	enemy_plane2.poly[4].q[3]=random_pointy2-25;

	
	enemy_plane2.poly[5].p[0]=random_point2-15;
	enemy_plane2.poly[5].p[1]=random_point2+15;
	enemy_plane2.poly[5].p[2]=random_point2+20;
	enemy_plane2.poly[5].p[3]=random_point2+20;
	enemy_plane2.poly[5].p[4]=random_point2+15;
	enemy_plane2.poly[5].p[5]=random_point2-15;
	enemy_plane2.poly[5].p[6]=random_point2-20;
	enemy_plane2.poly[5].p[7]=random_point2-20;
	enemy_plane2.poly[5].q[0]=random_pointy2-110;
	enemy_plane2.poly[5].q[1]=random_pointy2-110;
	enemy_plane2.poly[5].q[2]=random_pointy2-117;
	enemy_plane2.poly[5].q[3]=random_pointy2-120;
	enemy_plane2.poly[5].q[4]=random_pointy2-123;
	enemy_plane2.poly[5].q[5]=random_pointy2-123;
	enemy_plane2.poly[5].q[6]=random_pointy2-120;
	enemy_plane2.poly[5].q[7]=random_pointy2-117;

	
	enemy_plane2.poly[6].p[0]=random_point2-13;
	enemy_plane2.poly[6].p[1]=random_point2+13;
	enemy_plane2.poly[6].p[2]=random_point2+8;
	enemy_plane2.poly[6].p[3]=random_point2-8;
	enemy_plane2.poly[6].q[0]=random_pointy2-142;
	enemy_plane2.poly[6].q[1]=random_pointy2-142;
	enemy_plane2.poly[6].q[2]=random_pointy2-155;
	enemy_plane2.poly[6].q[3]=random_pointy2-155;

	enemy_plane2.poly[7].p[0]=random_point2-7;
	enemy_plane2.poly[7].p[1]=random_point2+7;
	enemy_plane2.poly[7].p[2]=random_point2;
	enemy_plane2.poly[7].q[0]=random_pointy2-118;
	enemy_plane2.poly[7].q[1]=random_pointy2-118;
	enemy_plane2.poly[7].q[2]=random_pointy2-40;

	//BULLET
	enemy_bullet2.elliL[0].x=random_point2-35;
	enemy_bullet2.elliL[1].x=random_point2-35;
	enemy_bullet2.elliL[2].x=random_point2-35;
	enemy_bullet2.elliL[3].x=random_point2-35;
	enemy_bullet2.elliL[0].y=random_pointy2-110;
	enemy_bullet2.elliL[1].y=random_pointy2-110;
	enemy_bullet2.elliL[2].y=random_pointy2-110;
	enemy_bullet2.elliL[3].y=random_pointy2-110;

	enemy_bullet2.elliR[0].x=random_point2+35;
	enemy_bullet2.elliR[1].x=random_point2+35;
	enemy_bullet2.elliR[2].x=random_point2+35;
	enemy_bullet2.elliR[3].x=random_point2+35;
	enemy_bullet2.elliR[0].y=random_pointy2-110;
	enemy_bullet2.elliR[1].y=random_pointy2-110;
	enemy_bullet2.elliR[2].y=random_pointy2-110;
	enemy_bullet2.elliR[3].y=random_pointy2-110;

	void (*ptrOfPosition)(void);
	ptrOfPosition=random_position;
	iSetTimer(250,*ptrOfPosition);

	void (*ptrOfMovment)(void);
	ptrOfMovment=random_movement;
	iSetTimer(250,*ptrOfMovment);

	void (*scpre_ptr)(void);
	scpre_ptr=time_score;
	iSetTimer(1000,*scpre_ptr);

	iInitialize(800, 700, "Air Fighter Game");
	return 0;
}