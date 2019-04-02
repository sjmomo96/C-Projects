#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
int xs = 300, ys = 300, r = 20, d, e;
char high_score[30];
char str_score[30];
int file_ptr=0;
/************************************************all structure***********************************************/
typedef struct pacman
{
	//pacman
		//body
		double p;
		double q;
		//mouth
		double x[3];
		double y[3];
		//eye
		double eye_p1;
		double eye_q1;
		double eye_p2;
		double eye_q2;

}pacman;

pacman pc1;
typedef struct enemy
{
	//enemy-1
		//body
		double a;
		double b;
		//mouth
		double x_mouth1[3];
		double y_mouth1[3];
		double x_mouth2[3];
		double y_mouth2[3];
		//eye
		double eye_1;
		double eye_2;
		double eye_3;
		double eye_4;
		double eye_5;
		double eye_6;
		double eye_7;
		double eye_8;

}enemy;

enemy en[4];

struct dotVanish
{
		int D_V_RL[165];
		int D_V_UD[165];
};
typedef struct dotVanish dotVanish;
dotVanish dv;

void setValue()
{
	pc1.p = 125;
	pc1.q = 125;
	pc1.x[0] = 125;
	pc1.x[1] = 142;
	pc1.x[2] = 142;
	pc1.y[0] = 125;
	pc1.y[1] = 112;
	pc1.y[2] = 139;
	pc1.eye_p1 = 122;
	pc1.eye_q1 = 134;
	pc1.eye_p2 = 122;
	pc1.eye_q2 = 134;

	en[0].a = 125;
	en[0].b = 425;
	en[0].x_mouth1[0] = 117;
	en[0].x_mouth1[1] = 125;
	en[0].x_mouth1[2] = 108;
	en[0].y_mouth1[0] = 425;
	en[0].y_mouth1[1] = 408;
	en[0].y_mouth1[2] = 412;
	en[0].x_mouth2[0] = 133;
	en[0].x_mouth2[1] = 122;
	en[0].x_mouth2[2] = 139;
	en[0].y_mouth2[0] = 424;
	en[0].y_mouth2[1] = 408;
	en[0].y_mouth2[2] = 411;
	en[0].eye_1=118;
	en[0].eye_2=433;
	en[0].eye_3=118;
	en[0].eye_4=433;
	en[0].eye_5=131;
	en[0].eye_6=433;
	en[0].eye_7=131;
	en[0].eye_8=433;

	en[1].a=225;
	en[1].b=275;
	en[1].x_mouth1[0] = 217;
	en[1].x_mouth1[1] = 225;
	en[1].x_mouth1[2] = 210;
	en[1].y_mouth1[0] = 273;
	en[1].y_mouth1[1] = 258;
	en[1].y_mouth1[2] = 261;
	en[1].x_mouth2[0] = 230;
	en[1].x_mouth2[1] = 225;
	en[1].x_mouth2[2] = 239;
	en[1].y_mouth2[0] = 273;
	en[1].y_mouth2[1] = 258;
	en[1].y_mouth2[2] = 262;
	en[1].eye_1=217;
	en[1].eye_2=282;
	en[1].eye_3=217;
	en[1].eye_4=282;
	en[1].eye_5=233;
	en[1].eye_6=282;
	en[1].eye_7=233;
	en[1].eye_8=282;

	en[2].a=425;
	en[2].b=425;
	en[2].x_mouth1[0] = 418;
	en[2].x_mouth1[1] = 423;
	en[2].x_mouth1[2] = 410;
	en[2].y_mouth1[0] = 422;
	en[2].y_mouth1[1] = 408;
	en[2].y_mouth1[2] = 412;
	en[2].x_mouth2[0] = 431;
	en[2].x_mouth2[1] = 423;
	en[2].x_mouth2[2] = 436;
	en[2].y_mouth2[0] = 422;
	en[2].y_mouth2[1] = 408;
	en[2].y_mouth2[2] = 411;
	en[2].eye_1=417;
	en[2].eye_2=432;
	en[2].eye_3=417;
	en[2].eye_4=432;
	en[2].eye_5=432;
	en[2].eye_6=432;
	en[2].eye_7=432;
	en[2].eye_8=432;

	en[3].a=575;
	en[3].b=225;
	en[3].x_mouth1[0] = 566;
	en[3].x_mouth1[1] = 573;
	en[3].x_mouth1[2] = 558;
	en[3].y_mouth1[0] = 222;
	en[3].y_mouth1[1] = 209;
	en[3].y_mouth1[2] = 211;
	en[3].x_mouth2[0] = 582;
	en[3].x_mouth2[1] = 573;
	en[3].x_mouth2[2] = 586;
	en[3].y_mouth2[0] = 221;
	en[3].y_mouth2[1] = 209;
	en[3].y_mouth2[2] = 210;
	en[3].eye_1=566;
	en[3].eye_2=232;
	en[3].eye_3=566;
	en[3].eye_4=232;
	en[3].eye_5=581;
	en[3].eye_6=232;
	en[3].eye_7=581;
	en[3].eye_8=232;

}
//state_of_text = 0,color_state=0;

		//pacman move
		void func_right(void)
		{
			pc1.x[0]+=25;
			pc1.x[1]+=25;
			pc1.x[2]+=25;
			pc1.p+=25;
			pc1.eye_p1+=25;
			pc1.eye_p2+=25;
		}
		void func_left(void)
		{
			pc1.x[0]-=25;
			pc1.x[1]-=25;
			pc1.x[2]-=25;
			pc1.p-=25;
			pc1.eye_p1-=25;
			pc1.eye_p2-=25;
		}
		void func_up(void)
		{
			pc1.y[0]+=25;
			pc1.y[1]+=25;
			pc1.y[2]+=25;
			pc1.q+=25;
			pc1.eye_q1+=25;
			pc1.eye_q2+=25;
		}
		void func_down(void)
		{
			pc1.y[0]-=25;
			pc1.y[1]-=25;
			pc1.y[2]-=25;
			pc1.q-=25;
			pc1.eye_q1-=25;
			pc1.eye_q2-=25;
		}

		/*enemy move*/
		//enemy-1
		int state1=0;
		int state2=0;
		int i=0;
		int state3=0;
		int state4=0;
		void enemy_movement1()
		{
			if(state1==0)
			{
				en[0].a+=0.07;
				en[0].eye_1+=0.07;
				en[0].eye_3+=0.07;
				en[0].eye_5+=0.07;
				en[0].eye_7+=0.07;
				for(i=0;i<3;i++)
				{
					en[0].x_mouth1[i]+=0.07;
					en[0].x_mouth2[i]+=0.07;
				}
				if(en[0].a>174 && en[0].b>424)
				{
					state1=1;
				}
				if(en[0].a>174 && en[0].b<326)
				{
					state1=3;
				}
			}
			if(state1==1)
			{
				en[0].b-=0.07;
				en[0].eye_2-=0.07;
				en[0].eye_4-=0.07;
				en[0].eye_6-=0.07;
				en[0].eye_8-=0.07;
				for(i=0;i<3;i++)
				{
					en[0].y_mouth1[i]-=0.07;
					en[0].y_mouth2[i]-=0.07;
				}
				if(en[0].b<325)
				{
					state1=2;
				}
			}
			if(state1==2)
			{
				en[0].a-=0.07;
				en[0].eye_1-=0.07;
				en[0].eye_3-=0.07;
				en[0].eye_5-=0.07;
				en[0].eye_7-=0.07;
				for(i=0;i<3;i++)
				{
					en[0].x_mouth1[i]-=0.07;
					en[0].x_mouth2[i]-=0.07;
				}
				if(en[0].a<125)
				{
					state1=0;
				}
			}
			if(state1==3)
			{
				en[0].b+=0.07;
				en[0].eye_2+=0.07;
				en[0].eye_4+=0.07;
				en[0].eye_6+=0.07;
				en[0].eye_8+=0.07;
				for(i=0;i<3;i++)
				{
					en[0].y_mouth1[i]+=0.07;
					en[0].y_mouth2[i]+=0.07;
				}
				if(en[0].b>425)
				{
					state1=2;
				}
			}
		}

		//enemy-2
		void enemy_movement2()
		{
			if(state2==0)
			{
				en[1].b+=0.07;
				en[1].eye_2+=0.07;
				en[1].eye_4+=0.07;
				en[1].eye_6+=0.07;
				en[1].eye_8+=0.07;
				for(i=0;i<3;i++)
				{
					en[1].y_mouth1[i]+=0.07;
					en[1].y_mouth2[i]+=0.07;
				}
				if(en[1].b>375)
				{
					state2=1;
				}
			}
			if(state2==1)
			{
				en[1].b-=0.07;
				en[1].eye_2-=0.07;
				en[1].eye_4-=0.07;
				en[1].eye_6-=0.07;
				en[1].eye_8-=0.07;
				for(i=0;i<3;i++)
				{
					en[1].y_mouth1[i]-=0.07;
					en[1].y_mouth2[i]-=0.07;
				}
				if(en[1].a>224 && en[1].b<275)
				{
					state2=2;
				}
				if(en[1].b<275 && en[1].a>375)
				{
					state2=3;	
				}
			}
			if(state2==2)
			{
				en[1].a+=0.07;
				en[1].eye_1+=0.07;
				en[1].eye_3+=0.07;
				en[1].eye_5+=0.07;
				en[1].eye_7+=0.07;
				for(i=0;i<3;i++)
				{
					en[1].x_mouth1[i]+=0.07;
					en[1].x_mouth2[i]+=0.07;
				}
				if(en[1].a>375 && en[1].b<275)
				{
					state2=3;
					{
						state2=0;
					}
				}
			}
			if(state2==3)
			{
				en[1].a-=0.07;
				en[1].eye_1-=0.07;
				en[1].eye_3-=0.07;
				en[1].eye_5-=0.07;
				en[1].eye_7-=0.07;
				for(i=0;i<3;i++)
				{
					en[1].x_mouth1[i]-=0.07;
					en[1].x_mouth2[i]-=0.07;
				}
				if(en[1].a<225 && en[1].b<275)
				{
					state2=4;
					{
						state2=0;
					}
				}
			}
		}

		//enemy-3
		void enemy_movement3()
		{
			if(state3==0)
			{
				en[2].b+=0.07;
				en[2].eye_2+=0.07;
				en[2].eye_4+=0.07;
				en[2].eye_6+=0.07;
				en[2].eye_8+=0.07;
				for(i=0;i<3;i++)
				{
					en[2].y_mouth1[i]+=0.07;
					en[2].y_mouth2[i]+=0.07;
				}
				if(en[2].b>475)
				{
					state3=1;
				}
			}
			if(state3==1)
			{
				en[2].a-=0.07;
				en[2].eye_1-=0.07;
				en[2].eye_3-=0.07;
				en[2].eye_5-=0.07;
				en[2].eye_7-=0.07;
				for(i=0;i<3;i++)
				{
					en[2].x_mouth1[i]-=0.07;
					en[2].x_mouth2[i]-=0.07;
				}
				if(en[2].a<375)
				{
					state3=2;
				}
			}
			if(state3==2)
			{
				en[2].b-=0.07;
				en[2].eye_2-=0.07;
				en[2].eye_4-=0.07;
				en[2].eye_6-=0.07;
				en[2].eye_8-=0.07;
				for(i=0;i<3;i++)
				{
					en[2].y_mouth1[i]-=0.07;
					en[2].y_mouth2[i]-=0.07;
				}
				if(en[2].b<425)
				{
					state3=3;
				}
			}
			if(state3==3)
			{
				en[2].a-=0.07;
				en[2].eye_1-=0.07;
				en[2].eye_3-=0.07;
				en[2].eye_5-=0.07;
				en[2].eye_7-=0.07;
				for(i=0;i<3;i++)
				{
					en[2].x_mouth1[i]-=0.07;
					en[2].x_mouth2[i]-=0.07;
				}
				if(en[2].a<325)
				{
					state3=4;
				}
			}
			if(state3==4)
			{
				en[2].b+=0.07;
				en[2].eye_2+=0.07;
				en[2].eye_4+=0.07;
				en[2].eye_6+=0.07;
				en[2].eye_8+=0.07;
				for(i=0;i<3;i++)
				{
					en[2].y_mouth1[i]+=0.07;
					en[2].y_mouth2[i]+=0.07;
				}
				if(en[2].b>475)
				{
					state3=5;
				}
			}
			if(state3==5)
			{
				en[2].b-=0.07;
				en[2].eye_2-=0.07;
				en[2].eye_4-=0.07;
				en[2].eye_6-=0.07;
				en[2].eye_8-=0.07;
				for(i=0;i<3;i++)
				{
					en[2].y_mouth1[i]-=0.07;
					en[2].y_mouth2[i]-=0.07;
				}
				if(en[2].b<425)
				{
					state3=6;
				}
			}
			if(state3==6)
			{
				en[2].a+=0.07;
				en[2].eye_1+=0.07;
				en[2].eye_3+=0.07;
				en[2].eye_5+=0.07;
				en[2].eye_7+=0.07;
				for(i=0;i<3;i++)
				{
					en[2].x_mouth1[i]+=0.07;
					en[2].x_mouth2[i]+=0.07;
				}
				if(en[2].a>375)
				{
					state3=7;
				}
			}
			if(state3==7)
			{
				en[2].b+=0.07;
				en[2].eye_2+=0.07;
				en[2].eye_4+=0.07;
				en[2].eye_6+=0.07;
				en[2].eye_8+=0.07;
				for(i=0;i<3;i++)
				{
					en[2].y_mouth1[i]+=0.07;
					en[2].y_mouth2[i]+=0.07;
				}
				if(en[2].b>475)
				{
					state3=8;
				}
			}
			if(state3==8)
			{
				en[2].a+=0.07;
				en[2].eye_1+=0.07;
				en[2].eye_3+=0.07;
				en[2].eye_5+=0.07;
				en[2].eye_7+=0.07;
				for(i=0;i<3;i++)
				{
					en[2].x_mouth1[i]+=0.07;
					en[2].x_mouth2[i]+=0.07;
				}
				if(en[2].a>425)
				{
					state3=9;
				}
			}
			if(state3==9)
			{
				en[2].b-=0.07;
				en[2].eye_2-=0.07;
				en[2].eye_4-=0.07;
				en[2].eye_6-=0.07;
				en[2].eye_8-=0.07;
				for(i=0;i<3;i++)
				{
					en[2].y_mouth1[i]-=0.07;
					en[2].y_mouth2[i]-=0.07;
				}
				if(en[2].b<425)
				{
					state3=10;
					{
					state3=0;
					}
				}
			}
		}

		//enemy-4
		void enemy_movement4()
		{
			if(state4==0)
			{
				en[3].b-=0.07;
				en[3].eye_2-=0.07;
				en[3].eye_4-=0.07;
				en[3].eye_6-=0.07;
				en[3].eye_8-=0.07;
				for(i=0;i<3;i++)
				{
					en[3].y_mouth1[i]-=0.07;
					en[3].y_mouth2[i]-=0.07;
				}
				if(en[3].b<175)
				{
					state4=1;
				}
			}
			if(state4==1)
			{
				en[3].a-=0.07;
				en[3].eye_1-=0.07;
				en[3].eye_3-=0.07;
				en[3].eye_5-=0.07;
				en[3].eye_7-=0.07;
				for(i=0;i<3;i++)
				{
					en[3].x_mouth1[i]-=0.07;
					en[3].x_mouth2[i]-=0.07;
				}
				if(en[3].a<425)
				{
					state4=2;
				}
			}
			if(state4==2)
			{
				en[3].b+=0.07;
				en[3].eye_2+=0.07;
				en[3].eye_4+=0.07;
				en[3].eye_6+=0.07;
				en[3].eye_8+=0.07;
				for(i=0;i<3;i++)
				{
					en[3].y_mouth1[i]+=0.07;
					en[3].y_mouth2[i]+=0.07;
				}
				if(en[3].b>325)
				{
					state4=3;
				}
			}
			if(state4==3)
			{
				en[3].a+=0.07;
				en[3].eye_1+=0.07;
				en[3].eye_3+=0.07;
				en[3].eye_5+=0.07;
				en[3].eye_7+=0.07;
				for(i=0;i<3;i++)
				{
					en[3].x_mouth1[i]+=0.07;
					en[3].x_mouth2[i]+=0.07;
				}
				if(en[3].a>475 && en[3].b>325)
				{
					state4=4;
				}
			}
				if(state4==4)
			{
				en[3].a-=0.07;
				en[3].eye_1-=0.07;
				en[3].eye_3-=0.07;
				en[3].eye_5-=0.07;
				en[3].eye_7-=0.07;
				for(i=0;i<3;i++)
				{
					en[3].x_mouth1[i]-=0.07;
					en[3].x_mouth2[i]-=0.07;
				}
				if(en[3].a<425 && en[3].b>325)
				{
					state4=5;
				}	
			}
			if(state4==5)
			{
				en[3].b-=0.07;
				en[3].eye_2-=0.07;
				en[3].eye_4-=0.07;
				en[3].eye_6-=0.07;
				en[3].eye_8-=0.07;
				for(i=0;i<3;i++)
				{
					en[3].y_mouth1[i]-=0.07;
					en[3].y_mouth2[i]-=0.07;
				}
				if(en[3].a<425 && en[3].b<175)
				{
					state4=6;
				}
			}
				if(state4==6)
			{
				en[3].a+=0.07;
				en[3].eye_1+=0.07;
				en[3].eye_3+=0.07;
				en[3].eye_5+=0.07;
				en[3].eye_7+=0.07;
				for(i=0;i<3;i++)
				{
					en[3].x_mouth1[i]+=0.07;
					en[3].x_mouth2[i]+=0.07;
				}
				if(en[3].a>575 && en[3].b<175)
				{
					state4=7;
				}
			}
			if(state4==7)
			{
				en[3].b+=0.07;
				en[3].eye_2+=0.07;
				en[3].eye_4+=0.07;
				en[3].eye_6+=0.07;
				en[3].eye_8+=0.07;
				for(i=0;i<3;i++)
				{
					en[3].y_mouth1[i]+=0.07;
					en[3].y_mouth2[i]+=0.07;
				}
				if(en[3].a>575 && en[3].b>225)
				{
					state4=8;
					{
					state4=0;
					}
				}
			}
		}
		//dot vanish
		int D_V_RL[165]={0};
		int D_V_UD[165]={0};
		int R=0;
		int L=0;
		int U=0;
		int D=0;
	
		//Game over
		char str[100];
		int show1=0;
		//score
		int score_plus=0;
		char score[200]={"0"};
		//another
		int page1=0;
		int menu=1;
		int push=0;
		int resume=0;
		int color_change=0;

/*********************************************iDRAW code*********************************************/
void iDraw() 
{
	/****************************************MENU SCREEN*********************************************/
	iSetColor(0,0,0);
	iFilledRectangle(0, 0, 700, 600);
	if(page1==0)
	{
		iSetColor(205,92,92);
		iFilledRectangle(200, 560, 300, 35);
		iSetColor(255,255,0);
		iText(250, 571, "CLASSIC PACMAN", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(124,0,0);
		iFilledRectangle(200, 450, 300, 100);
		iSetColor(139,169,19);
		iText(290, 501, "NEW GAME", GLUT_BITMAP_TIMES_ROMAN_24);
		/*if(color_change==1)
		{
			iSetColor(205,92,92);
			printf("500 = %d, 420= %d\n",mx,my);
		}
		else
		{
			iSetColor(139,169,19);
		}*/

		iSetColor(124,0,0);
		iFilledRectangle(200, 320, 300, 100);
		iSetColor(139,169,19);
		iText(303, 365, "ABOUT", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(124,0,0);
		iFilledRectangle(200, 190, 300, 100);
		iSetColor(139,169,19);
		iText(282, 240, "HIGH SCORE", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(124,0,0);
		iFilledRectangle(200, 50, 300, 100);
		iSetColor(139,169,19);
		iText(313, 95, "QUIT", GLUT_BITMAP_TIMES_ROMAN_24);

	}
	/***********************************************ABOUT SCREEN****************************************************/
	if(page1 == 2)
	{
		iSetColor(124,0,0);
		iFilledRectangle(230, 500, 245, 55);
		iSetColor(139,169,19);
		iText(310, 521, "ABOUT", GLUT_BITMAP_TIMES_ROMAN_24);
		
		iSetColor(124,0,0);
		iFilledRectangle(70,110,600,370);
		iSetColor(173,255,47);
		iText(105, 420, "Submitted By  :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(177, 390, "Name  :  Salman Jahan Momo", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(215, 360, "Id  :  15101105", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 330, "Sec  :  C  ,,  1st year second semister", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(160, 270, "PROJECT WITH   [ iGraphics ]", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(155, 220, "\n Author  :  S. M. Shahriar Nirjon", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(95, 190, "\nSuggested By  :  Md. T. Morshed (Lecturer of UAP)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(120, 160, "\n Supervisor  :  Md. Habibur Rahman (Lecturer of UAP)", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(124,0,0);
		iFilledRectangle(32,550,90,33);
		iSetColor(139,169,19);
		iText(39, 557, "MENU", GLUT_BITMAP_TIMES_ROMAN_24);
		if(menu==1)
		{
			page1;
		}
	}
	/************************************************************High Score screen*******************************************************/
	if(page1 == 3)
	{
		iSetColor(124,0,0);
		iFilledRectangle(235, 460, 185, 55);
		iSetColor(139,169,19);
		iText(252, 480, "HIGH SCORE", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(124,0,0);
		iFilledRectangle(137, 350, 360, 68);
		iSetColor(139,169,19);
		iText(370, 380, high_score,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(230, 379, "SCORE  : ", GLUT_BITMAP_TIMES_ROMAN_24);
		
		iSetColor(124,0,0);	
		iFilledRectangle(32, 550, 90, 33);
		iSetColor(139,169,19);
		iText(39, 557, "MENU", GLUT_BITMAP_TIMES_ROMAN_24);
		if(menu==1)
		{
			page1;
		}

	}
	if(page1 == 4)
	{
		exit(0);
	}
	/**********************************************GAME SCREEN*****************************************/
	if(page1==1)
	{
		iSetColor(0,0,0);
		iFilledRectangle(0,0,700,600);
		iSetColor(124,0,0);	
		iFilledRectangle(32, 550, 90, 33);
		iSetColor(139,169,19);
		iText(39, 557, "MENU", GLUT_BITMAP_TIMES_ROMAN_24);
		if(menu==1)
		{
			page1;
		}

		/*bord of game where pacman move */
		iSetColor(124,0,0);
		iFilledRectangle(100,100,500,400);
		iSetColor(0,0,0);
		iRectangle(100,100,500,400);

		iSetColor(124,0,0);
		iFilledRectangle(545,550,120,33);
		iSetColor(139,169,19);
		iText(558, 557, "RESUME", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(124,0,0);
		iFilledRectangle(545,510,120,33);
		iSetColor(139,169,19);
		iText(568, 517, "PAUSE", GLUT_BITMAP_TIMES_ROMAN_24);
		//x-axis
		iSetColor(0,0,0);
		iFilledRectangle(150,450,54,4);
		iFilledRectangle(250,450,54,4);
		iFilledRectangle(500,450,54,4);
		iFilledRectangle(100,400,54,4);
		iFilledRectangle(200,400,54,4);
		iFilledRectangle(300,400,250,4);
		iFilledRectangle(400,350,54,4);
		iFilledRectangle(550,350,50,4);
		iFilledRectangle(150,300,54,4);
		iFilledRectangle(250,300,101,4);
		iFilledRectangle(450,300,54,4);
		iFilledRectangle(200,250,54,4);
		iFilledRectangle(300,250,101,4);
		iFilledRectangle(500,250,100,4);
		iFilledRectangle(200,200,54,4);
		iFilledRectangle(450,200,100,4);
		iFilledRectangle(150,150,54,4);
		iFilledRectangle(250,150,54,4);
		iFilledRectangle(400,150,54,4);
		iFilledRectangle(550,150,50,4);
		//y-axis
		iFilledRectangle(350,450,4,50);
		iFilledRectangle(450,450,4,50);
		iFilledRectangle(200,400,4,50);
		iFilledRectangle(400,400,4,50);
		iFilledRectangle(550,400,4,50);
		iFilledRectangle(550,400,4,50);
		iFilledRectangle(150,350,4,50);
		iFilledRectangle(300,350,4,100);
		iFilledRectangle(250,300,4,100);
		iFilledRectangle(350,300,4,50);
		iFilledRectangle(500,300,4,100);
		iFilledRectangle(550,300,4,50);
		iFilledRectangle(200,250,4,100);
		iFilledRectangle(150,200,4,100);
		iFilledRectangle(450,200,4,100);
		iFilledRectangle(200,150,4,50);
		iFilledRectangle(300,150,4,100);
		iFilledRectangle(400,150,4,200);
		iFilledRectangle(350,100,4,100);
		iFilledRectangle(500,100,4,50);
		
		/* point,, inside line,, which, pacman will eat*/
		iSetColor(139,169,19);
		if(D_V_RL[1]==0)
		iPoint(125,125,2);
		if(D_V_RL[2]==0)
		iPoint(150,125,2);
		if(D_V_RL[3]==0)
		iPoint(175,125,2);
		if(D_V_RL[4]==0)
		iPoint(200,125,2);
		if(D_V_RL[5]==0)
		iPoint(225,125,2);
		if(D_V_RL[6]==0)
		iPoint(250,125,2);
		if(D_V_RL[7]==0)
		iPoint(275,125,2);
		if(D_V_RL[8]==0)
		iPoint(300,125,2);
		if(D_V_RL[9]==0)
		iPoint(325,125,2);
		if(D_V_RL[10]==0)
		iPoint(375,125,2);
		if(D_V_RL[11]==0)
		iPoint(400,125,2);
		if(D_V_RL[12]==0)
		iPoint(425,125,2);
		if(D_V_RL[13]==0)
		iPoint(450,125,2);
		if(D_V_RL[14]==0)
		iPoint(475,125,2);
		if(D_V_RL[15]==0)
		iPoint(528,125,2);
		if(D_V_RL[16]==0)
		iPoint(550,125,2);
		if(D_V_RL[17]==0)
		iPoint(575,125,2);

		//up
		if(D_V_UD[123]==0)
		iPoint(125,150,2);
		if(D_V_UD[124]==0)
		iPoint(225,150,2);
		if(D_V_UD[125]==0)
		iPoint(325,150,2);
		if(D_V_UD[126]==0)
		iPoint(375,150,2);
		if(D_V_UD[127]==0)
		iPoint(475,150,2);
		if(D_V_UD[128]==0)
		iPoint(528,150,2);

		//right
		if(D_V_RL[18]==0)
		iPoint(125,175,2);
		if(D_V_UD[18]==0)
		iPoint(125,175,2);
		if(D_V_RL[19]==0)
		iPoint(150,175,2);
		if(D_V_UD[20]==0)
		iPoint(175,175,2);
		if(D_V_RL[21]==0)
		iPoint(225,175,2);
		if(D_V_RL[22]==0)
		iPoint(250,175,2);
		if(D_V_RL[23]==0)
		iPoint(275,175,2);
		if(D_V_RL[24]==0)
		iPoint(325,175,2);
		if(D_V_RL[25]==0)
		iPoint(375,175,2);
		if(D_V_RL[26]==0)
		iPoint(425,175,2);
		if(D_V_RL[27]==0)
		iPoint(450,175,2);
		if(D_V_RL[28]==0)
		iPoint(475,175,2);
		if(D_V_RL[29]==0)
		iPoint(500,175,2);
		if(D_V_RL[30]==0)
		iPoint(528,175,2);
		if(D_V_RL[31]==0)
		iPoint(550,175,2);
		if(D_V_RL[32]==0)
		iPoint(575,175,2);
	
		//up
		if(D_V_UD[129]==0)
		iPoint(125,200,2);
		if(D_V_UD[130]==0)
		iPoint(175,200,2);
		if(D_V_UD[131]==0)
		iPoint(275,200,2);
		if(D_V_UD[132]==0)
		iPoint(325,200,2);
		if(D_V_UD[133]==0)
		iPoint(375,200,2);
		if(D_V_UD[134]==0)
		iPoint(425,200,2);
		if(D_V_UD[135]==0)
		iPoint(575,200,2);
		if(D_V_UD[33]==0)
		iPoint(125,225,2);

		//right
		if(D_V_RL[34]==0)
		iPoint(175,225,2);
		if(D_V_RL[35]==0)
		iPoint(200,225,2);
		if(D_V_RL[36]==0)
		iPoint(225,225,2);
		if(D_V_RL[37]==0)
		iPoint(250,225,2);
		if(D_V_RL[38]==0)
		iPoint(275,225,2);
		if(D_V_RL[39]==0)
		iPoint(325,225,2);
		if(D_V_RL[40]==0)
		iPoint(350,225,2);
		if(D_V_RL[41]==0)
		iPoint(375,225,2);
		if(D_V_RL[42]==0)
		iPoint(425,225,2);
		if(D_V_RL[43]==0)
		iPoint(475,225,2);
		if(D_V_RL[44]==0)
		iPoint(500,225,2);
		if(D_V_RL[45]==0)
		iPoint(528,225,2);
		if(D_V_RL[46]==0)
		iPoint(550,225,2);
		if(D_V_RL[47]==0)
		iPoint(575,225,2);

		//up
		if(D_V_UD[136]==0)
		iPoint(125,250,2);
		if(D_V_UD[137]==0)
		iPoint(175,250,2);
		if(D_V_UD[138]==0)
		iPoint(275,250,2);
		if(D_V_UD[139]==0)
		iPoint(425,250,2);
		if(D_V_UD[140]==0)
		iPoint(475,250,2);
		if(D_V_UD[48]==0)
		iPoint(125,275,2);

		//right
		if(D_V_UD[49]==0)
		iPoint(175,275,2);
		if(D_V_RL[50]==0)
		iPoint(225,275,2);
		if(D_V_RL[51]==0)
		iPoint(250,275,2);
		if(D_V_RL[52]==0)
		iPoint(275,275,2);
		if(D_V_RL[53]==0)
		iPoint(300,275,2);
		if(D_V_RL[54]==0)
		iPoint(325,275,2);
		if(D_V_RL[55]==0)
		iPoint(350,275,2);
		if(D_V_RL[56]==0)
		iPoint(375,275,2);
		if(D_V_RL[57]==0)
		iPoint(425,275,2);
		if(D_V_RL[58]==0)
		iPoint(475,275,2);
		if(D_V_RL[59]==0)
		iPoint(500,275,2);
		if(D_V_RL[60]==0)
		iPoint(528,275,2);
		if(D_V_RL[61]==0)
		iPoint(550,275,2);
		if(D_V_RL[62]==0)
		iPoint(575,275,2);

		//up
		if(D_V_UD[141]==0)
		iPoint(125,300,2);
		if(D_V_UD[142]==0)
		iPoint(225,300,2);
		if(D_V_UD[143]==0)
		iPoint(375,300,2);
		if(D_V_UD[144]==0)
		iPoint(425,300,2);
		if(D_V_UD[145]==0)
		iPoint(528,300,2);
		if(D_V_UD[146]==0)
		iPoint(575,300,2);
		if(D_V_UD[66]==0)
		iPoint(225,325,2);

		//right
		if(D_V_UD[63]==0)
		iPoint(125,325,2);
		if(D_V_RL[64]==0)
		iPoint(150,325,2);
		if(D_V_UD[65]==0)
		iPoint(175,325,2);
		if(D_V_RL[67]==0)
		iPoint(275,325,2);
		if(D_V_RL[68]==0)
		iPoint(300,325,2);
		if(D_V_RL[69]==0)
		iPoint(325,325,2);
		if(D_V_RL[70]==0)
		iPoint(375,325,2);
		if(D_V_RL[71]==0)
		iPoint(425,325,2);
		if(D_V_RL[72]==0)
		iPoint(450,325,2);
		if(D_V_RL[73]==0)
		iPoint(475,325,2);
		if(D_V_RL[74]==0)
		iPoint(528,325,2);
		if(D_V_RL[75]==0)
		iPoint(575,325,2);

		//up
		if(D_V_UD[147]==0)
		iPoint(125,350,2);
		if(D_V_UD[148]==0)
		iPoint(175,350,2);
		if(D_V_UD[149]==0)
		iPoint(225,350,2);
		if(D_V_UD[150]==0)
		iPoint(275,350,2);
		if(D_V_UD[151]==0)
		iPoint(325,350,2);
		if(D_V_UD[152]==0)
		iPoint(375,350,2);
		if(D_V_UD[153]==0)
		iPoint(475,350,2);
		if(D_V_UD[154]==0)
		iPoint(528,350,2);
		if(D_V_UD[76]==0)
		iPoint(125,375,2);

		//right
		if(D_V_UD[77]==0)
		iPoint(175,375,2);
		if(D_V_RL[78]==0)
		iPoint(200,375,2);
		if(D_V_RL[79]==0)
		iPoint(225,375,2);
		if(D_V_RL[80]==0)
		iPoint(275,375,2);
		if(D_V_RL[81]==0)
		iPoint(325,375,2);
		if(D_V_RL[82]==0)
		iPoint(350,375,2);
		if(D_V_RL[83]==0)
		iPoint(375,375,2);
		if(D_V_RL[84]==0)
		iPoint(400,375,2);
		if(D_V_RL[85]==0)
		iPoint(425,375,2);
		if(D_V_RL[86]==0)
		iPoint(450,375,2);
		if(D_V_RL[87]==0)
		iPoint(475,375,2);
		if(D_V_RL[88]==0)
		iPoint(528,375,2);
		if(D_V_RL[89]==0)
		iPoint(550,375,2);
		if(D_V_RL[90]==0)
		iPoint(575,375,2);

		//up
		if(D_V_UD[155]==0)
		iPoint(175,400,2);
		if(D_V_UD[156]==0)
		iPoint(275,400,2);
		if(D_V_UD[157]==0)
		iPoint(575,400,2);

		//right
		if(D_V_UD[91]==0)
		iPoint(125,425,2);
		if(D_V_RL[92]==0)
		iPoint(150,425,2);
		if(D_V_RL[93]==0)
		iPoint(175,425,2);
		if(D_V_RL[94]==0)
		iPoint(225,425,2);
		if(D_V_RL[95]==0)
		iPoint(250,425,2);
		if(D_V_RL[96]==0)
		iPoint(275,425,2);
		if(D_V_RL[97]==0)
		iPoint(325,425,2);
		if(D_V_RL[98]==0)
		iPoint(350,425,2);
		if(D_V_RL[99]==0)
		iPoint(375,425,2);
		if(D_V_RL[100]==0)
		iPoint(425,425,2);
		if(D_V_RL[101]==0)
		iPoint(450,425,2);
		if(D_V_RL[102]==0)
		iPoint(475,425,2);
		if(D_V_RL[103]==0)
		iPoint(500,425,2);
		if(D_V_RL[104]==0)
		iPoint(528,425,2);
		if(D_V_RL[105]==0)
		iPoint(575,425,2);

		//up
		if(D_V_UD[158]==0)
		iPoint(125,450,2);
		if(D_V_UD[159]==0)
		iPoint(225,450,2);
		if(D_V_UD[160]==0)
		iPoint(325,450,2);
		if(D_V_UD[161]==0)
		iPoint(375,450,2);
		if(D_V_UD[162]==0)
		iPoint(425,450,2);
		if(D_V_UD[163]==0)
		iPoint(475,450,2);
		if(D_V_UD[164]==0)
		iPoint(575,450,2);

		//right
		if(D_V_RL[106]==0)
		iPoint(125,475,2);
		if(D_V_RL[107]==0)
		iPoint(150,475,2);
		if(D_V_RL[108]==0)
		iPoint(175,475,2);
		if(D_V_RL[109]==0)
		iPoint(200,475,2);
		if(D_V_RL[110]==0)
		iPoint(225,475,2);
		if(D_V_RL[111]==0)
		iPoint(250,475,2);
		if(D_V_RL[112]==0)
		iPoint(275,475,2);
		if(D_V_RL[113]==0)
		iPoint(300,475,2);
		if(D_V_RL[114]==0)
		iPoint(325,475,2);
		if(D_V_RL[115]==0)
		iPoint(375,475,2);
		if(D_V_RL[116]==0)
		iPoint(400,475,2);
		if(D_V_RL[117]==0)
		iPoint(425,475,2);
		if(D_V_RL[118]==0)
		iPoint(475,475,2);
		if(D_V_RL[119]==0)
		iPoint(500,475,2);
		if(D_V_RL[120]==0)
		iPoint(528,475,2);
		if(D_V_RL[121]==0)
		iPoint(550,475,2);
		if(D_V_RL[122]==0)
		iPoint(575,475,2);
		
		/*enemy of pacman*/

		//enemy-1
		//body
		iSetColor(0,100,0);
		iFilledCircle(en[0].a,en[0].b,16);
		//mouth
		iSetColor(124,0,0);
		iFilledPolygon(en[0].x_mouth1,en[0].y_mouth1,3);
		iSetColor(124,0,0);
		iFilledPolygon(en[0].x_mouth2,en[0].y_mouth2,3);
		//eye
		iSetColor(0 ,0 ,0);
		iFilledCircle(en[0].eye_1,en[0].eye_2,4);
		iSetColor(222,222,222);
		iFilledCircle(en[0].eye_3,en[0].eye_4,1);
		iSetColor(0 ,0 ,0);
		iFilledCircle(en[0].eye_5,en[0].eye_6,4);
		iSetColor(222,222,222);
		iFilledCircle(en[0].eye_7,en[0].eye_8,1);

		//enemy-2
		//body
		iSetColor(0,255,0);
		iFilledCircle(en[1].a,en[1].b,16);
		//mouth
		iSetColor(124,0,0);
		iFilledPolygon(en[1].x_mouth1,en[1].y_mouth1,3);
		iSetColor(124,0,0);
		iFilledPolygon(en[1].x_mouth2,en[1].y_mouth2,3);
		//eye
		iSetColor(0 ,0 ,0);
		iFilledCircle(en[1].eye_1,en[1].eye_2,4);
		iSetColor(222,222,222);
		iFilledCircle(en[1].eye_3,en[1].eye_4,1);
		iSetColor(0 ,0 ,0);
		iFilledCircle(en[1].eye_5,en[1].eye_6,4);
		iSetColor(222,222,222);
		iFilledCircle(en[1].eye_7,en[1].eye_8,1);
		
		//enemy-3
		//body
		iSetColor(0,255,255);
		iFilledCircle(en[2].a,en[2].b,16);
		//mouth
		iSetColor(124,0,0);
		iFilledPolygon(en[2].x_mouth1,en[2].y_mouth1,3);
		iSetColor(124,0,0);
		iFilledPolygon(en[2].x_mouth2,en[2].y_mouth2,3);
		//eye
		iSetColor(0 ,0 ,0);
		iFilledCircle(en[2].eye_1,en[2].eye_2,4);
		iSetColor(222,222,222);
		iFilledCircle(en[2].eye_3,en[2].eye_4,1);
		iSetColor(0 ,0 ,0);
		iFilledCircle(en[2].eye_5,en[2].eye_6,4);
		iSetColor(222,222,222);
		iFilledCircle(en[2].eye_7,en[2].eye_8,1);

		//enemy-4
		//body
		iSetColor(85,107,47);
		iFilledCircle(en[3].a,en[3].b,16);
		//mouth
		iSetColor(124,0,0);
		iFilledPolygon(en[3].x_mouth1,en[3].y_mouth1,3);
		iSetColor(124,0,0);
		iFilledPolygon(en[3].x_mouth2,en[3].y_mouth2,3);
		//eye
		iSetColor(0 ,0 ,0);
		iFilledCircle(en[3].eye_1,en[3].eye_2,4);
		iSetColor(222,222,222);
		iFilledCircle(en[3].eye_3,en[3].eye_4,1);
		iSetColor(0 ,0 ,0);
		iFilledCircle(en[3].eye_5,en[3].eye_6,4);
		iSetColor(222,222,222);
		iFilledCircle(en[3].eye_7,en[3].eye_8,1);

		//enemy move
		if(show1==0)
		{
			enemy_movement1();
			enemy_movement2();
			enemy_movement3();
			enemy_movement4();
		}

		/*pacman*/
		//body
		iSetColor(255,255,0);
		iFilledCircle(pc1.p,pc1.q,17);
		//mouth
		iSetColor(124,0,0);
		iFilledPolygon(pc1.x,pc1.y,3);
		//eye
		iSetColor(0 ,0 ,0);
		iFilledCircle(pc1.eye_p1,pc1.eye_q1,5);
		iSetColor(222,222,222);
		iFilledCircle(pc1.eye_p2,pc1.eye_q2,2);

		//game over
		///enemy-1
		int enemy1_a = en[0].a;                     //a = x_axis
		int enemy1_b = en[0].b;                     //b = y_axis
		int pacman_p = pc1.p;                       //p = x_axis
		int pacman_q = pc1.q;                       //q = y_axis

		if((enemy1_a-1-15 < pacman_p+17+1)&&(pacman_p-17-1 < enemy1_a+1+15) && (enemy1_b-1-15 < pacman_q+17+1)&&(pacman_q-17-1 < enemy1_b+1+15)|| (enemy1_a-1-15 < pacman_p+17+1)&&(pacman_p-17-1 < enemy1_a+1+15)&&(enemy1_b-1-15 < pacman_q+17+1)&&(pacman_q-17-1 < enemy1_b+1+15))
		{
			show1=2;
			if(file_ptr==0)
			{
			//puts(high_score);
			
				FILE *fp;

				if((fp=fopen("help.txt","a+"))!=NULL)
				{
					strcpy(high_score, str_score);
					puts(high_score);
					fputs(high_score, fp);
				}
				else
				{
					printf("Error! opening file");
					exit(1);
				}
				fclose(fp);
				file_ptr=1;
			}
		}
		//enemy-2
		enemy1_a = en[1].a;
		enemy1_b = en[1].b;
		pacman_p = pc1.p;
		pacman_q = pc1.q;
		if((enemy1_a-1-15 < pacman_p+17+1)&&(pacman_p-17-1 < enemy1_a+1+15) && (enemy1_b-1-15 < pacman_q+17+1)&&(pacman_q-17-1 < enemy1_b+1+15)|| (enemy1_a-1-15 < pacman_p+17+1)&&(pacman_p-17-1 < enemy1_a+1+15)&&(enemy1_b-1-15 < pacman_q+17+1)&&(pacman_q-17-1 < enemy1_b+1+15))
		{
			show1=2;
			if(file_ptr==0)
			{
				FILE *fp;
				if((fp=fopen("help.txt","a+"))!=NULL)
				{
					strcpy(high_score, str_score);
					fputs(high_score, fp);
				}
				else
				{
					printf("Error! opening file");
					exit(1);
				}
				fclose(fp);
				file_ptr=1;
			}
		}
		//enemy-3
		enemy1_a = en[2].a;
		enemy1_b = en[2].b;
		pacman_p = pc1.p;
		pacman_q = pc1.q;
		if((enemy1_a-1-15 < pacman_p+17+1)&&(pacman_p-17-1 < enemy1_a+1+15) && (enemy1_b-1-15 < pacman_q+17+1)&&(pacman_q-17-1 < enemy1_b+1+15)|| (enemy1_a-1-15 < pacman_p+17+1)&&(pacman_p-17-1 < enemy1_a+1+15)&&(enemy1_b-1-15 < pacman_q+17+1)&&(pacman_q-17-1 < enemy1_b+1+15))
		{
			show1=2;
			if(file_ptr==0)
			{
				FILE *fp;
				if((fp=fopen("help.txt","a+"))!=NULL)
				{
					strcpy(high_score, str_score);
					fputs(high_score, fp);
				}
				else
				{
					printf("Error! opening file");
					exit(1);
				}
				fclose(fp);
				file_ptr=1;
			}
		}
		//enemy-4
		enemy1_a = en[3].a;
		enemy1_b = en[3].b;
		pacman_p = pc1.p;
		pacman_q = pc1.q;
		if((enemy1_a-1-15 < pacman_p+17+1)&&(pacman_p-17-1 < enemy1_a+1+15) && (enemy1_b-1-15 < pacman_q+17+1)&&(pacman_q-17-1 < enemy1_b+1+15)|| (enemy1_a-1-15 < pacman_p+17+1)&&(pacman_p-17-1 < enemy1_a+1+15)&&(enemy1_b-1-15 < pacman_q+17+1)&&(pacman_q-17-1 < enemy1_b+1+15))
		{
			show1=2;
			if(file_ptr==0)
			{
				FILE *fp;
				if((fp=fopen("help.txt","a+"))!=NULL)
				{
					strcpy(high_score, str_score);
					fputs(high_score, fp);
				}
				else
				{
					printf("Error! opening file");
					exit(1);
				}
				fclose(fp);
				file_ptr=1;
			}
		}
		if(show1==2)
		{
			iSetColor(237,28,36);
			iText(275, 285, "GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(255,255,0);
			iText(275, 287, "GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
			
			//PlaySound("death.wav",NULL,SND_ASYNC);

			iSetColor(25,25,112);
			iFilledRectangle(225, 550, 150, 37);
			iSetColor(255,233,0);
			iText(255, 560, "Score ",GLUT_BITMAP_TIMES_ROMAN_24);
			strcpy(high_score, str_score);
			sprintf(str_score, "%d", score_plus); 
			iText(320, 560, str_score,GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(25,25,112);
			iFilledRectangle(540, 25, 130, 33);
			iSetColor(255,233,0);
			iText(570, 36, "Restart ",GLUT_BITMAP_TIMES_ROMAN_24);
		}	
	}
	/*******************************************************MEDIUM**************************************************/
	/********************************************************HIGH***************************************************/
	/****************************************************Finish Idraw****************************************************/
}
/*function iMouseMove() is called when the user presses and drags the mouse.
		(mx, my) is the position where the mouse pointer is.*/
void iMouseMove(int mx, int my) 
{
	//place your code here
}


void iPassiveMouseMove(int mx,int my)
{
	printf("%d %d", mx,my);
	/*if(200<mx  && mx<500 && 320<my && my<420)
	{
		//printf("500 = %d, 420= %d\n",mx,my);
		color_change=1;
	}
	else
	{
		color_change=0;
	}*/
}
\
/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
		if(page1 == 0)
		{
			if(200<mx  && mx<500 && 450<my && my<550 )
			{
				PlaySound("click.wav",NULL,SND_ASYNC);
				page1=1;
			}
			if(200<mx  && mx<500 && 320<my && my<420 )
			{
				PlaySound("click.wav",NULL,SND_ASYNC);
				page1=2;			
			}
			if(200<mx  && mx<500 && 190<my && my<300 )
			{
				PlaySound("click.wav",NULL,SND_ASYNC);
				page1=3;		
			}
			if(200<mx && mx<500 && 50<my && my<150 )
			{
				PlaySound("click.wav",NULL,SND_ASYNC);
				page1=4;
			}
		}
		if(page1 == 1)
		{
			PlaySound("start.wav",NULL,SND_ASYNC);
			if(32<mx && mx<120 && 550<my && my<585 )
			{
				PlaySound("click.wav",NULL,SND_ASYNC);
				menu=1;
				{
					page1=0;
				}
			}
			if(show1==2)                                   //restart
			{
				//iFilledRectangle(540, 25, 130, 33);
				if(540<mx && mx<670 && 58<my && my<585 )
				{
					show1=0;
					{
						page1=1;
					}
				}
			}
		}
		if(page1 == 2)
		{
			if(32<mx && mx<120 && 550<my && my<585 )
			{
				PlaySound("click.wav",NULL,SND_ASYNC);
				menu=1;
				{
					page1=0;
				}
			}
		}
		if(page1 == 3)
		{
			if(32<mx && mx<120 && 550<my && my<585 )
			{
					FILE *fp;
					if((fp=fopen("help.txt","w+"))!=NULL)
					{
						strcpy(high_score, str_score);
						fputs(high_score, fp);
					}
					else
					{
						printf("Error! opening file");
						exit(1);
					}
					fclose(fp);
				PlaySound("click.wav",NULL,SND_ASYNC);
				menu=1;
				{
					page1=0;
				}
			}
		}
		if(push==0)
		{
			if(545<mx && mx<665 && 510<my && my<543 )      //pause
			{
				show1=1;
			}
		}
		if(push==0)
		{
			if(545<mx && mx<665 && 550<my && my<583 )         //resume
			{
				show1=0;
			}
		}
	}

	//place your codes here	
		printf("x = %d, y= %d\n",mx,my);
	//if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
	//place your codes here	
}

/*function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.*/
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	//place your codes for other keys here
}

/*function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT*/

void iSpecialKeyboard(unsigned char key)
{
	if(key==GLUT_KEY_F2)
	{
		show1=0;
	}
	if(key==GLUT_KEY_RIGHT)
	{
		if(pc1.p!=575)
		{
			if(pc1.p==125 && pc1.q==125)
			{
				D_V_RL[1]=1;
				D_V_UD[1]=1;
				func_right();
				if(score[1]==0)
				{
					score_plus+=5;
				}
				score[1]=1;
			}
			else if(pc1.p==150 && pc1.q==125)
			{
				D_V_RL[2]=1;
				D_V_UD[2]=1;
				func_right();
				if(score[2]==0)
				{
					score_plus+=5;
				}
				score[2]=1;
			}
			else if(pc1.p==175 && pc1.q==125)
			{
				D_V_RL[3]=1;
				D_V_UD[3]=1;
				func_right();
				if(score[3]==0)
				{
					score_plus+=5;
				}
				score[3]=1;
			}	
			else if(pc1.p==200 && pc1.q==125)
			{
				D_V_RL[4]=1;
				D_V_UD[4]=1;
				func_right();
				if(score[4]==0)
				{
					score_plus+=5;
				}
				score[4]=1;
			}
			else if(pc1.p==225 && pc1.q==125)
			{
				D_V_RL[5]=1;
				D_V_UD[5]=1;
				func_right();
				if(score[5]==0)
				{
					score_plus+=5;
				}
				score[5]=1;
			}
			else if(pc1.p==250 && pc1.q==125)
			{
				D_V_RL[6]=1;
				D_V_UD[6]=1;
				func_right();
				if(score[6]==0)
				{
					score_plus+=5;
				}
				score[6]=1;
			}
			else if(pc1.p==275 && pc1.q==125)
			{
				D_V_RL[7]=1;
				D_V_UD[7]=1;
				func_right();
				if(score[7]==0)
				{
					score_plus+=5;
				}
				score[7]=1;
			}
			else if(pc1.p==300 && pc1.q==125)
				{
				D_V_RL[8]=1;
				D_V_UD[8]=1;
				func_right();
				if(score[8]==0)
				{
					score_plus+=5;
				}
				score[8]=1;
			}
			else if(pc1.p==375 && pc1.q==125)
				{
				D_V_RL[10]=1;
				D_V_UD[10]=1;
				func_right();
				if(score[10]==0)
				{
					score_plus+=5;
				}
				score[10]=1;
			}
			else if(pc1.p==400 && pc1.q==125)
				{
				D_V_RL[11]=1;
				D_V_UD[11]=1;
				func_right();
				if(score[11]==0)
				{
					score_plus+=5;
				}
				score[11]=1;
			}
			else if(pc1.p==425 && pc1.q==125)
			{
				D_V_RL[12]=1;
				D_V_UD[12]=1;
				func_right();
				if(score[12]==0)
				{
					score_plus+=5;
				}
				score[12]=1;
			}
			else if(pc1.p==450 && pc1.q==125)
			{
				D_V_RL[13]=1;
				D_V_UD[13]=1;
				func_right();
				if(score[13]==0)
				{
					score_plus+=5;
				}
				score[13]=1;
			}
			else if(pc1.p==525 && pc1.q==125)
			{
				D_V_RL[15]=1;
				D_V_UD[15]=1;
				func_right();
				if(score[15]==0)
				{
					score_plus+=5;
				}
				score[15]=1;
			}
			else if(pc1.p==550 && pc1.q==125)
			{
				D_V_RL[16]=1;
				D_V_UD[16]=1;
				func_right();
				if(score[16]==0)
				{
					score_plus+=5;
				}
				score[16]=1;
			}
			else if(pc1.p==575 && pc1.q==125)				
			{
				D_V_RL[17]=1;
				D_V_UD[17]=1;
				func_right();
				if(score[17]==0)
				{
					score_plus+=5;
				}
				score[17]=1;
			}

			else if(pc1.p==125 && pc1.q==175)
			{
				D_V_RL[18]=1;
				D_V_UD[18]=1;
				func_right();
				if(score[18]==0)
				{
					score_plus+=5;
				}
				score[18]=1;
			}
			else if(pc1.p==150 && pc1.q==175)
			{
				D_V_RL[19]=1;
				D_V_UD[19]=1;
				func_right();
				if(score[19]==0)
				{
					score_plus+=5;
				}
				score[19]=1;
			}
			else if(pc1.p==225 && pc1.q==175)
			{
				D_V_RL[21]=1;
				D_V_UD[21]=1;
				func_right();
				if(score[21]==0)
				{
					score_plus+=5;
				}
				score[21]=1;
			}
			else if(pc1.p==250 && pc1.q==175)
			{
				D_V_RL[22]=1;
				D_V_UD[22]=1;
				func_right();
				if(score[22]==0)
				{
					score_plus+=5;
				}
				score[22]=1;
			}
			else if(pc1.p==425 && pc1.q==175)
			{
				D_V_RL[26]=1;
				D_V_UD[26]=1;
				func_right();
				if(score[26]==0)
				{
					score_plus+=5;
				}
				score[26]=1;
			}
			else if(pc1.p==450 && pc1.q==175)
			{
				D_V_RL[27]=1;
				D_V_UD[27]=1;
				func_right();
				if(score[27]==0)
				{
					score_plus+=5;
				}
				score[27]=1;
			}
			else if(pc1.p==475 && pc1.q==175)
			{
				D_V_RL[28]=1;
				D_V_UD[28]=1;
				func_right();
				if(score[28]==0)
				{
					score_plus+=5;
				}
				score[28]=1;
			}
			else if(pc1.p==500 && pc1.q==175)
			{
				D_V_RL[29]=1;
				D_V_UD[29]=1;
				func_right();
				if(score[29]==0)
				{
					score_plus+=5;
				}
				score[29]=1;
			}
			else if(pc1.p==525 &&pc1.q==175)
			{
				D_V_RL[30]=1;
				D_V_UD[30]=1;
				func_right();
				if(score[30]==0)
				{
					score_plus+=5;
				}
				score[30]=1;
			}
			else if(pc1.p==550 &&pc1.q==175)
			{
				D_V_RL[31]=1;
				D_V_UD[31]=1;
				func_right();
				if(score[31]==0)
				{
					score_plus+=5;
				}
				score[31]=1;
			}
			else if(pc1.p==575 && pc1.q==175)
			{
				D_V_RL[32]=1;
				D_V_UD[32]=1;
				func_right();
				if(score[32]==0)
				{
					score_plus+=5;
				}
				score[32]=1;
			}
			
			else if(pc1.p==175 && pc1.q==225)
			{
				D_V_RL[34]=1;
				D_V_UD[34]=1;
				func_right();
				if(score[34]==0)
				{
					score_plus+=5;
				}
				score[34]=1;
			}
			else if(pc1.p==200 && pc1.q==225)
			{
				D_V_RL[35]=1;
				D_V_UD[35]=1;
				func_right();
				if(score[35]==0)
				{
					score_plus+=5;
				}
				score[35]=1;
			}
			else if(pc1.p==225 && pc1.q==225)
			{
				D_V_RL[36]=1;
				D_V_UD[36]=1;
				func_right();
				if(score[36]==0)
				{
					score_plus+=5;
				}
				score[36]=1;
			}
			else if(pc1.p==250 && pc1.q==225)
			{
				D_V_RL[37]=1;
				D_V_UD[37]=1;
				func_right();
				if(score[37]==0)
				{
					score_plus+=5;
				}
				score[37]=1;
			}
			else if(pc1.p==325 && pc1.q==225)
			{
				D_V_RL[39]=1;
				D_V_UD[39]=1;
				func_right();
				if(score[39]==0)
				{
					score_plus+=5;
				}
				score[39]=1;
			}
			else if(pc1.p==350 && pc1.q==225)
			{
				D_V_RL[40]=1;
				D_V_UD[40]=1;
				func_right();
				if(score[40]==0)
				{
					score_plus+=5;
				}
				score[40]=1;
			}
			else if(pc1.p==475 && pc1.q==225)
			{
				D_V_RL[43]=1;
				D_V_UD[43]=1;
				func_right();
				if(score[43]==0)
				{
					score_plus+=5;
				}
				score[43]=1;
			}
			else if(pc1.p==500 && pc1.q==225)
			{
				D_V_RL[44]=1;
				D_V_UD[44]=1;
				func_right();
				if(score[44]==0)
				{
					score_plus+=5;
				}
				score[44]=1;
			}
			else if(pc1.p==525 && pc1.q==225)
			{
				D_V_RL[45]=1;
				D_V_UD[45]=1;
				func_right();
				if(score[45]==0)
				{
					score_plus+=5;
				}
				score[45]=1;
			}
			else if(pc1.p==550 && pc1.q==225)
			{
				D_V_RL[46]=1;
				D_V_UD[46]=1;
				func_right();
				if(score[46]==0)
				{
					score_plus+=5;
				}
				score[46]=1;
			}
			else if(pc1.p==575 && pc1.q==225)
			{
				D_V_RL[47]=1;
				D_V_UD[47]=1;
				func_right();
				if(score[47]==0)
				{
					score_plus+=5;
				}
				score[47]=1;
			}

			else if(pc1.p==225 && pc1.q==275)
			{
				D_V_RL[50]=1;
				D_V_UD[50]=1;
				func_right();
				if(score[50]==0)
				{
					score_plus+=5;
				}
				score[50]=1;
			}
			else if(pc1.p==250 && pc1.q==275)
			{
				D_V_RL[51]=1;
				D_V_UD[51]=1;
				func_right();
				if(score[51]==0)
				{
					score_plus+=5;
				}
				score[51]=1;
			}
			else if(pc1.p==275 && pc1.q==275)
			{
				D_V_RL[52]=1;
				D_V_UD[52]=1;
				func_right();
				if(score[52]==0)
				{
					score_plus+=5;
				}
				score[52]=1;
			}
			else if(pc1.p==300 && pc1.q==275)
			{ 
				D_V_RL[53]=1;
				D_V_UD[53]=1;
				func_right();
				if(score[53]==0)
				{
					score_plus+=5;
				}
				score[53]=1;
			}
			else if(pc1.p==325 && pc1.q==275)
			{
				D_V_RL[54]=1;
				D_V_UD[54]=1;
				func_right();
				if(score[54]==0)
				{
					score_plus+=5;
				}
				score[54]=1;
			}
			else if(pc1.p==350 && pc1.q==275)
			{
				D_V_RL[55]=1;
				D_V_UD[55]=1;
				func_right();
				if(score[55]==0)
				{
					score_plus+=5;
				}
				score[55]=1;
			}
			else if(pc1.p==475 && pc1.q==275)
			{
				D_V_RL[58]=1;
				D_V_UD[58]=1;
				func_right();
				if(score[58]==0)
				{
					score_plus+=5;
				}
				score[58]=1;
			}
			else if(pc1.p==500 && pc1.q==275)
			{
				D_V_RL[59]=1;
				D_V_UD[59]=1;
				func_right();
				if(score[59]==0)
				{
					score_plus+=5;
				}
				score[59]=1;
			}
			else if(pc1.p==525 && pc1.q==275)
			{
				D_V_RL[60]=1;
				D_V_UD[60]=1;
				func_right();
				if(score[60]==0)
				{
					score_plus+=5;
				}
				score[60]=1;
			}
			else if(pc1.p==550 && pc1.q==275)
			{
				D_V_RL[61]=1;
				D_V_UD[61]=1;
				func_right();
				if(score[61]==0)
				{
					score_plus+=5;
				}
				score[61]=1;
			}
			else if(pc1.p==575 && pc1.q==275)
			{
				D_V_RL[62]=1;
				D_V_UD[62]=1;
				func_right();
				if(score[62]==0)
				{
					score_plus+=5;
				}
				score[62]=1;
			}

			else if(pc1.p==125 && pc1.q==325)
			{
				D_V_RL[63]=1;
				D_V_UD[63]=1;
				func_right();
				if(score[63]==0)
				{
					score_plus+=5;
				}
				score[63]=1;
			}
			else if(pc1.p==150 && pc1.q==325)
			{
				D_V_RL[64]=1;
				D_V_UD[64]=1;
				func_right();
				if(score[64]==0)
				{
					score_plus+=5;
				}
				score[64]=1;
			}
			else if(pc1.p==275 && pc1.q==325)
			{
				D_V_RL[67]=1;
				D_V_UD[67]=1;
				func_right();
				if(score[67]==0)
				{
					score_plus+=5;
				}
				score[67]=1;
			}
			else if(pc1.p==300 && pc1.q==325)
			{
				D_V_RL[68]=1;
				D_V_UD[68]=1;
				func_right();
				if(score[68]==0)
				{
					score_plus+=5;
				}
				score[68]=1;
			}
			else if(pc1.p==425 && pc1.q==325)
			{
				D_V_RL[71]=1;
				D_V_UD[71]=1;
				func_right();
				if(score[71]==0)
				{
					score_plus+=5;
				}
				score[71]=1;
			}
			else if(pc1.p==450 &&pc1.q==325)
			{
				D_V_RL[72]=1;
				D_V_UD[72]=1;
				func_right();
				if(score[72]==0)
				{
					score_plus+=5;
				}
				score[72]=1;
			}

			else if(pc1.p==175 && pc1.q==375)
			{
				D_V_RL[77]=1;
				D_V_UD[77]=1;
				func_right();
				if(score[77]==0)
				{
					score_plus+=5;
				}
				score[77]=1;
			}
			else if(pc1.p==200 && pc1.q==375)
			{
				D_V_RL[78]=1;
				D_V_UD[78]=1;
				func_right();
				if(score[78]==0)
				{
					score_plus+=5;
				}
				score[78]=1;
			}
			else if(pc1.p==325 && pc1.q==375)
			{
				D_V_RL[81]=1;
				D_V_UD[81]=1;
				func_right();
				if(score[81]==0)
				{
					score_plus+=5;
				}
				score[81]=1;
			}
			else if(pc1.p==350 && pc1.q==375)
			{
				D_V_RL[82]=1;
				D_V_UD[82]=1;
				func_right();
				if(score[82]==0)
				{
					score_plus+=5;
				}
				score[82]=1;
			}
			else if(pc1.p==375 && pc1.q==375)
			{
				D_V_RL[83]=1;
				D_V_UD[83]=1;
				func_right();
				if(score[83]==0)
				{
					score_plus+=5;
				}
				score[83]=1;
			}
			else if(pc1.p==400 &&pc1.q==375)
			{
				D_V_RL[84]=1;
				D_V_UD[84]=1;
				func_right();
				if(score[84]==0)
				{
					score_plus+=5;
				}
				score[84]=1;
			}
			else if(pc1.p==425 && pc1.q==375)
			{
				D_V_RL[85]=1;
				D_V_UD[85]=1;
				func_right();
				if(score[85]==0)
				{
					score_plus+=5;
				}
				score[85]=1;
			}
			else if(pc1.p==450 && pc1.q==375)
			{
				D_V_RL[86]=1;
				D_V_UD[86]=1;
				func_right();
				if(score[86]==0)
				{
					score_plus+=5;
				}
				score[86]=1;
			}
			else if(pc1.p==525 && pc1.q==375)
			{
				D_V_RL[88]=1;
				D_V_UD[88]=1;
				func_right();
				if(score[88]==0)
				{
					score_plus+=5;
				}
				score[88]=1;
			}
			else if(pc1.p==550 && pc1.q==375)
			{
				D_V_RL[89]=1;
				D_V_UD[89]=1;
				func_right();
				if(score[89]==0)
				{
					score_plus+=5;
				}
				score[89]=1;
			}
			else if(pc1.p==575 && pc1.q==375)
			{
				D_V_RL[90]=1;
				D_V_UD[90]=1;
				func_right();
				if(score[90]==0)
				{
					score_plus+=5;
				}
				score[90]=1;
			}

			else if(pc1.p==125 && pc1.q==425)
			{
				D_V_RL[91]=1;
				D_V_UD[91]=1;
				func_right();
				if(score[91]==0)
				{
					score_plus+=5;
				}
				score[91]=1;
			}
			else if(pc1.p==150 && pc1.q==425)
			{
				D_V_RL[92]=1;
				D_V_UD[92]=1;
				func_right();
				if(score[92]==0)
				{
					score_plus+=5;
				}
				score[92]=1;
			}
			else if(pc1.p==225 && pc1.q==425)
			{
				D_V_RL[94]=1;
				D_V_UD[94]=1;
				func_right();
				if(score[94]==0)
				{
					score_plus+=5;
				}
				score[94]=1;
			}
			else if(pc1.p==250 && pc1.q==425)
			{
				D_V_RL[95]=1;
				D_V_UD[95]=1;
				func_right();
				if(score[95]==0)
				{
					score_plus+=5;
				}
				score[95]=1;
			}
			else if(pc1.p==325 && pc1.q==425)
			{
				D_V_RL[97]=1;
				D_V_UD[97]=1;
				func_right();
				if(score[97]==0)
				{
					score_plus+=5;
				}
				score[97]=1;
			}
			else if(pc1.p==350 &&pc1.q==425)
			{
				D_V_RL[98]=1;
				D_V_UD[98]=1;
				func_right();
				if(score[98]==0)
				{
					score_plus+=5;
				}
				score[98]=1;
			}
			else if(pc1.p==425 && pc1.q==425)
			{
				D_V_RL[100]=1;
				D_V_UD[100]=1;
				func_right();
				if(score[100]==0)
				{
					score_plus+=5;
				}
				score[100]=1;
			}
			else if(pc1.p==450 && pc1.q==425)
			{
				D_V_RL[101]=1;
				D_V_UD[101]=1;
				func_right();
				if(score[101]==0)
				{
					score_plus+=5;
				}
				score[101]=1;
			}
			else if(pc1.p==475 && pc1.q==425)
			{
				D_V_RL[102]=1;
				D_V_UD[102]=1;
				func_right();
				if(score[102]==0)
				{
					score_plus+=5;
				}
				score[102]=1;
			}
			else if(pc1.p==500 && pc1.q==425)
			{
				D_V_RL[103]=1;
				D_V_UD[103]=1;
				func_right();
				if(score[103]==0)
				{
					score_plus+=5;
				}
				score[103]=1;
			}

			else if(pc1.p==125 && pc1.q==475)
			{
				D_V_RL[106]=1;
				D_V_UD[106]=1;
				func_right();
				if(score[106]==0)
				{
					score_plus+=5;
				}
				score[106]=1;
			}
			else if(pc1.p==150 && pc1.q==475)
			{
				D_V_RL[107]=1;
				D_V_UD[107]=1;
				func_right();
				if(score[107]==0)
				{
					score_plus+=5;
				}
				score[107]=1;
			}
			else if(pc1.p==175 && pc1.q==475)
			{
				D_V_RL[108]=1;
				D_V_UD[108]=1;
				func_right();
				if(score[108]==0)
				{
					score_plus+=5;
				}
				score[108]=1;
			}
			else if(pc1.p==200 && pc1.q==475)
			{
				D_V_RL[109]=1;
				D_V_UD[109]=1;
				func_right();
				if(score[109]==0)
				{
					score_plus+=5;
				}
				score[109]=1;
			}
			else if(pc1.p==225 && pc1.q==475)
			{
				D_V_RL[110]=1;
				D_V_UD[110]=1;
				func_right();
				if(score[110]==0)
				{
					score_plus+=5;
				}
				score[110]=1;
			}
			else if(pc1.p==250 && pc1.q==475)
			{
				D_V_RL[111]=1;
				D_V_UD[111]=1;
				func_right();
				if(score[111]==0)
				{
					score_plus+=5;
				}
				score[111]=1;
			}
			else if(pc1.p==275 && pc1.q==475)
			{
				D_V_RL[112]=1;
				D_V_UD[112]=1;
				func_right();
				if(score[112]==0)
				{
					score_plus+=5;
				}
				score[112]=1;
			}
			else if(pc1.p==300 && pc1.q==475)
			{
				D_V_RL[113]=1;
				D_V_UD[113]=1;
				func_right();
				if(score[113]==0)
				{
					score_plus+=5;
				}
				score[113]=1;
			}
			else if(pc1.p==375 && pc1.q==475)
			{
				D_V_RL[115]=1;
				D_V_UD[115]=1;
				func_right();
				if(score[115]==0)
				{
					score_plus+=5;
				}
				score[115]=1;
			}
			else if(pc1.p==400 && pc1.q==475)
			{
				D_V_RL[116]=1;
				D_V_UD[116]=1;
				func_right();
				if(score[116]==0)
				{
					score_plus+=5;
				}
				score[116]=1;
			}
			else if(pc1.p==475 && pc1.q==475)
			{
				D_V_RL[118]=1;
				D_V_UD[118]=1;
				func_right();
				if(score[118]==0)
				{
					score_plus+=5;
				}
				score[118]=1;
			}
			else if(pc1.p==500 && pc1.q==475)
			{
				D_V_RL[119]=1;
				D_V_UD[119]=1;
				func_right();
				if(score[119]==0)
				{
					score_plus+=5;
				}
				score[119]=1;
			}
			else if(pc1.p==525 && pc1.q==475)
			{
				D_V_RL[120]=1;
				D_V_UD[120]=1;
				func_right();
				if(score[120]==0)
				{
					score_plus+=5;
				}
				score[120]=1;
			}
			else if(pc1.p==550 && pc1.q==475)
			{
				D_V_RL[121]=1;
				D_V_UD[121]=1;
				func_right();
				if(score[121]==0)
				{
					score_plus+=5;
				}
				score[121]=1;
			}
			else if(pc1.p==575 && pc1.q==475)
			{
				D_V_RL[122]=1;
				D_V_UD[122]=1;
				func_right();
				if(score[122]==0)
				{
					score_plus+=5;
				}
				score[122]=1;
			}

		}
	}
		
	if(key==GLUT_KEY_LEFT)
	{
		if(pc1.p!=125)
		{
			if(pc1.p==125 && pc1.q==125)
			{
				D_V_RL[1]=1;
				D_V_UD[1]=1;
				func_left();
				if(score[1]==0)
				{
					score_plus+=5;
				}
				score[1]=1;
			}
			else if(pc1.p==150 && pc1.q==125)
			{
				D_V_RL[2]=1;
				D_V_UD[2]=1;
				func_left();
				if(score[2]==0)
				{
					score_plus+=5;
				}
				score[2]=1;
			}
			else if(pc1.p==175 && pc1.q==125)
			{
				D_V_RL[3]=1;
				D_V_UD[3]=1;
				func_left();
				if(score[3]==0)
				{
					score_plus+=5;
				}
				score[3]=1;
			}
			else if(pc1.p==200 && pc1.q==125)
			{
				D_V_RL[4]=1;
				D_V_UD[4]=1;
				func_left();
				if(score[4]==0)
				{
					score_plus+=5;
				}
				score[4]=1;
			}
			else if(pc1.p==225 && pc1.q==125)
			{
				D_V_RL[5]=1;
				D_V_UD[5]=1;
				func_left();
				if(score[5]==0)
				{
					score_plus+=5;
				}
				score[5]=1;
			}
			else if(pc1.p==250 && pc1.q==125)
			{
				D_V_RL[6]=1;
				D_V_UD[6]=1;
				func_left();
				if(score[6]==0)
				{
					score_plus+=5;
				}
				score[6]=1;
			}
			else if(pc1.p==275 && pc1.q==125)
			{
				D_V_RL[7]=1;
				D_V_UD[7]=1;
				func_left();
				if(score[7]==0)
				{
					score_plus+=5;
				}
				score[7]=1;
			}
			else if(pc1.p==300 && pc1.q==125)
			{
				D_V_RL[8]=1;
				D_V_UD[8]=1;
				func_left();
				if(score[8]==0)
				{
					score_plus+=5;
				}
				score[8]=1;
			}
			else if(pc1.p==325 && pc1.q==125)
			{
				D_V_RL[9]=1;
				D_V_UD[9]=1;
				func_left();
				if(score[9]==0)
				{
					score_plus+=5;
				}
				score[9]=1;
			}
			else if(pc1.p==400 && pc1.q==125)
			{
				D_V_RL[11]=1;
				D_V_UD[11]=1;
				func_left();
				if(score[11]==0)
				{
					score_plus+=5;
				}
				score[11]=1;
			}
			else if(pc1.p==425 && pc1.q==125)
			{
				D_V_RL[12]=1;
				D_V_UD[12]=1;
				func_left();
				if(score[12]==0)
				{
					score_plus+=5;
				}
				score[12]=1;
			}
			else if(pc1.p==450 && pc1.q==125)
			{
				D_V_RL[13]=1;
				D_V_UD[13]=1;
				func_left();
				if(score[13]==0)
				{
					score_plus+=5;
				}
				score[13]=1;
			}
			else if(pc1.p==475 && pc1.q==125)
			{
				D_V_RL[14]=1;
				D_V_UD[14]=1;
				func_left();
				if(score[14]==0)
				{
					score_plus+=5;
				}
				score[14]=1;
			}
			else if(pc1.p==550 && pc1.q==125)
			{
				D_V_RL[16]=1;
				D_V_UD[16]=1;
				func_left();
				if(score[16]==0)
				{
					score_plus+=5;
				}
				score[16]=1;
			}
			else if(pc1.p==575 && pc1.q==125)
			{
				D_V_RL[17]=1;
				D_V_UD[17]=1;
				func_left();
				if(score[17]==0)
				{
					score_plus+=5;
				}
				score[17]=1;
			}


			else if(pc1.p==125 && pc1.q==175)
			{
				D_V_RL[18]=1;
				D_V_UD[18]=1;
				func_left();
				if(score[18]==0)
				{
					score_plus+=5;
				}
				score[18]=1;
			}
			else if(pc1.p==150 && pc1.q==175)
			{
				D_V_RL[19]=1;
				D_V_UD[19]=1;
				func_left();
				if(score[19]==0)
				{
					score_plus+=5;
				}
				score[19]=1;
			}
			else if(pc1.p==175 && pc1.q==175)
			{
				D_V_RL[20]=1;
				D_V_UD[20]=1;
				func_left();
				if(score[20]==0)
				{
					score_plus+=5;
				}
				score[20]=1;
			}
			else if(pc1.p==250 && pc1.q==175)
			{
				D_V_RL[22]=1;
				D_V_UD[22]=1;
				func_left();
				if(score[22]==0)
				{
					score_plus+=5;
				}
				score[22]=1;
			}
			else if(pc1.p==275 && pc1.q==175)
			{
				D_V_RL[23]=1;
				D_V_UD[23]=1;
				func_left();
				if(score[23]==0)
				{
					score_plus+=5;
				}
				score[23]=1;
			}
			else if(pc1.p==450 && pc1.q==175)
			{
				D_V_RL[27]=1;
				D_V_UD[27]=1;
				func_left();
				if(score[27]==0)
				{
					score_plus+=5;
				}
				score[27]=1;
			}
			else if(pc1.p==475 && pc1.q==175)
			{
				D_V_RL[28]=1;
				D_V_UD[28]=1;
				func_left();
				if(score[28]==0)
				{
					score_plus+=5;
				}
				score[28]=1;
			}
			else if(pc1.p==500 && pc1.q==175)
			{
				D_V_RL[29]=1;
				D_V_UD[29]=1;
				func_left();
				if(score[29]==0)
				{
					score_plus+=5;
				}
				score[29]=1;
			}
			else if(pc1.p==525 &&pc1. q==175)
			{
				D_V_RL[30]=1;
				D_V_UD[30]=1;
				func_left();
				if(score[30]==0)
				{
					score_plus+=5;
				}
				score[30]=1;
			}
			else if(pc1.p==550 && pc1.q==175)
			{
				D_V_RL[31]=1;
				D_V_UD[31]=1;
				func_left();
				if(score[31]==0)
				{
					score_plus+=5;
				}
				score[31]=1;
			}
			else if(pc1.p==575 && pc1.q==175)
			{
				D_V_RL[32]=1;
				D_V_UD[32]=1;
				func_left();
				if(score[32]==0)
				{
					score_plus+=5;
				}
				score[32]=1;
			}

			else if(pc1.p==125 && pc1.q==225)
			{
				D_V_RL[33]=1;
				D_V_UD[33]=1;
				func_left();
				if(score[33]==0)
				{
					score_plus+=5;
				}
				score[33]=1;
			}
			else if(pc1.p==200 && pc1.q==225)
			{
				D_V_RL[35]=1;
				D_V_UD[35]=1;
				func_left();
				if(score[35]==0)
				{
					score_plus+=5;
				}
				score[35]=1;
			}
			else if(pc1.p==225 && pc1.q==225)
			{
				D_V_RL[36]=1;
				D_V_UD[36]=1;
				func_left();
				if(score[36]==0)
				{
					score_plus+=5;
				}
				score[36]=1;
			}
			else if(pc1.p==250 && pc1.q==225)
			{
				D_V_RL[37]=1;
				D_V_UD[37]=1;
				func_left();
				if(score[37]==0)
				{
					score_plus+=5;
				}
				score[37]=1;
			}
			else if(pc1.p==275 && pc1.q==225)
			{
				D_V_RL[38]=1;
				D_V_UD[38]=1;
				func_left();
				if(score[38]==0)
				{
					score_plus+=5;
				}
				score[38]=1;
			}
			else if(pc1.p==350 && pc1.q==225)
			{
				D_V_RL[40]=1;
				D_V_UD[40]=1;
				func_left();
				if(score[40]==0)
				{
					score_plus+=5;
				}
				score[40]=1;
			}
			else if(pc1.p==375 && pc1.q==225)
			{
				D_V_RL[41]=1;
				D_V_UD[41]=1;
				func_left();
				if(score[41]==0)
				{
					score_plus+=5;
				}
				score[41]=1;
			}
			else if(pc1.p==500 && pc1.q==225)
			{
				D_V_RL[44]=1;
				D_V_UD[44]=1;
				func_left();
				if(score[44]==0)
				{
					score_plus+=5;
				}
				score[44]=1;
			}
			else if(pc1.p==525 && pc1.q==225)
			{
				D_V_RL[45]=1;
				D_V_UD[45]=1;
				func_left();
				if(score[45]==0)
				{
					score_plus+=5;
				}
				score[45]=1;
			}
			else if(pc1.p==550 && pc1.q==225)
			{
				D_V_RL[46]=1;
				D_V_UD[46]=1;
				func_left();
				if(score[46]==0)
				{
					score_plus+=5;
				}
				score[46]=1;
			}
			else if(pc1.p==575 && pc1.q==225)
			{
				D_V_RL[47]=1;
				D_V_UD[47]=1;
				func_left();
				if(score[47]==0)
				{
					score_plus+=5;
				}
				score[47]=1;
			}

			else if(pc1.p==125 && pc1.q==275)
			{
				D_V_RL[48]=1;
				D_V_UD[48]=1;
				func_left();
				if(score[48]==0)
				{
					score_plus+=5;
				}
				score[48]=1;
			}
			else if(pc1.p==250 && pc1.q==275)
			{
				D_V_RL[51]=1;
				D_V_UD[51]=1;
				func_left();
				if(score[51]==0)
				{
					score_plus+=5;
				}
				score[51]=1;
			}
			else if(pc1.p==275 && pc1.q==275)
			{
				D_V_RL[52]=1;
				D_V_UD[52]=1;
				func_left();
				if(score[52]==0)
				{
					score_plus+=5;
				}
				score[52]=1;
			}
			else if(pc1.p==300 && pc1.q==275)
			{
				D_V_RL[53]=1;
				D_V_UD[53]=1;
				func_left();
				if(score[53]==0)
				{
					score_plus+=5;
				}
				score[53]=1;
			}
			else if(pc1.p==325 && pc1.q==275)
			{
				D_V_RL[54]=1;
				D_V_UD[54]=1;
				func_left();
				if(score[54]==0)
				{
					score_plus+=5;
				}
				score[54]=1;
			}
			else if(pc1.p==350 && pc1.q==275)
			{
				D_V_RL[55]=1;
				D_V_UD[55]=1;
				func_left();
				if(score[55]==0)
				{
					score_plus+=5;
				}
				score[55]=1;
			}
			else if(pc1.p==375 && pc1.q==275)
			{
				D_V_RL[56]=1;
				D_V_UD[56]=1;
				func_left();
				if(score[56]==0)
				{
					score_plus+=5;
				}
				score[56]=1;
			}
			else if(pc1.p==500 && pc1.q==275)
			{
				D_V_RL[59]=1;
				D_V_UD[59]=1;
				func_left();
				if(score[59]==0)
				{
					score_plus+=5;
				}
				score[59]=1;
			}
			else if(pc1.p==525 && pc1.q==275)
			{
				D_V_RL[60]=1;
				D_V_UD[60]=1;
				func_left();
				if(score[60]==0)
				{
					score_plus+=5;
				}
				score[60]=1;
			}
			else if(pc1.p==550 && pc1.q==275)
			{
				D_V_RL[61]=1;
				D_V_UD[61]=1;
				func_left();
				if(score[61]==0)
				{
					score_plus+=5;
				}
				score[61]=1;
			}
			else if(pc1.p==575 && pc1.q==275)
			{
				D_V_RL[62]=1;
				D_V_UD[62]=1;
				func_left();
				if(score[62]==0)
				{
					score_plus+=5;
				}
				score[62]=1;
			}

			else if(pc1.p==125 && pc1.q==325)
			{
				D_V_RL[63]=1;
				D_V_UD[63]=1;
				func_left();
				if(score[63]==0)
				{
					score_plus+=5;
				}
				score[63]=1;
			}
			else if(pc1.p==150 && pc1.q==325)
			{
				D_V_RL[64]=1;
				D_V_UD[64]=1;
				func_left();
				if(score[64]==0)
				{
					score_plus+=5;
				}
				score[64]=1;
			}
			else if(pc1.p==175 && pc1.q==325)
			{
				D_V_RL[65]=1;
				D_V_UD[65]=1;
				func_left();
				if(score[65]==0)
				{
					score_plus+=5;
				}
				score[65]=1;
			}
			else if(pc1.p==300 && pc1.q==325)
			{
				D_V_RL[68]=1;
				D_V_UD[68]=1;
				func_left();
				if(score[68]==0)
				{
					score_plus+=5;
				}
				score[68]=1;
			}
			else if(pc1.p==325 && pc1.q==325)
			{
				D_V_RL[69]=1;
				D_V_UD[69]=1;
				func_left();
				if(score[69]==0)
				{
					score_plus+=5;
				}
				score[69]=1;
			}
			else if(pc1.p==450 && pc1.q==325)
			{
				D_V_RL[72]=1;
				D_V_UD[72]=1;
				func_left();
				if(score[72]==0)
				{
					score_plus+=5;
				}
				score[72]=1;
			}
			else if(pc1.p==475 && pc1.q==325)
			{
				D_V_RL[73]=1;
				D_V_UD[73]=1;
				func_left();
				if(score[73]==0)
				{
					score_plus+=5;
				}
				score[73]=1;
			}

			else if(pc1.p==125 && pc1.q==375)
			{
				D_V_RL[76]=1;
				D_V_UD[76]=1;
				func_left();
				if(score[76]==0)
				{
					score_plus+=5;
				}
				score[76]=1;
			}
			else if(pc1.p==200 && pc1.q==375)
			{
				D_V_RL[78]=1;
				D_V_UD[78]=1;
				func_left();
				if(score[78]==0)
				{
					score_plus+=5;
				}
				score[78]=1;
			}
			else if(pc1.p==225 && pc1.q==375)
			{
				D_V_RL[79]=1;
				D_V_UD[79]=1;
				func_left();
				if(score[79]==0)
				{
					score_plus+=5;
				}
				score[79]=1;
			}
			else if(pc1.p==350 && pc1.q==375)
			{
				D_V_RL[82]=1;
				D_V_UD[82]=1;
				func_left();
				if(score[82]==0)
				{
					score_plus+=5;
				}
				score[82]=1;
			}
			else if(pc1.p==375 && pc1.q==375)
			{
				D_V_RL[83]=1;
				D_V_UD[83]=1;
				func_left();
				if(score[83]==0)
				{
					score_plus+=5;
				}
				score[83]=1;
			}
			else if(pc1.p==400 && pc1.q==375)
			{
				D_V_RL[84]=1;
				D_V_UD[84]=1;
				func_left();
				if(score[84]==0)
				{
					score_plus+=5;
				}
				score[84]=1;
			}
			else if(pc1.p==425 && pc1.q==375)
			{
				D_V_RL[85]=1;
				D_V_UD[85]=1;
				func_left();
				if(score[85]==0)
				{
					score_plus+=5;
				}
				score[85]=1;
			}
			else if(pc1.p==450 && pc1.q==375)
			{
				D_V_RL[86]=1;
				D_V_UD[86]=1;
				func_left();
				if(score[86]==0)
				{
					score_plus+=5;
				}
				score[86]=1;
			}
			else if(pc1.p==475 && pc1.q==375)
			{
				D_V_RL[87]=1;
				D_V_UD[87]=1;
				func_left();
				if(score[87]==0)
				{
					score_plus+=5;
				}
				score[87]=1;
			}
			else if(pc1.p==550 && pc1.q==375)
			{
				D_V_RL[89]=1;
				D_V_UD[89]=1;
				func_left();
				if(score[89]==0)
				{
					score_plus+=5;
				}
				score[89]=1;
			}
			else if(pc1.p==575 && pc1.q==375)
			{
				D_V_RL[90]=1;
				D_V_UD[90]=1;
				func_left();
				if(score[90]==0)
				{
					score_plus+=5;
				}
				score[90]=1;
			}

			else if(pc1.p==125 && pc1.q==425)
			{
				D_V_RL[91]=1;
				D_V_UD[91]=1;
				func_left();
				if(score[91]==0)
				{
					score_plus+=5;
				}
				score[91]=1;
			}
			else if(pc1.p==150 && pc1.q==425)
			{
				D_V_RL[92]=1;
				D_V_UD[92]=1;
				func_left();
				if(score[92]==0)
				{
					score_plus+=5;
				}
				score[92]=1;
			}
			else if(pc1.p==175 && pc1.q==425)
			{
				D_V_RL[93]=1;
				D_V_UD[93]=1;
				func_left();
				if(score[93]==0)
				{
					score_plus+=5;
				}
				score[93]=1;
			}
			else if(pc1.p==250 && pc1.q==425)
			{
				D_V_RL[95]=1;
				D_V_UD[95]=1;
				func_left();
				if(score[95]==0)
				{
					score_plus+=5;
				}
				score[95]=1;
			}
			else if(pc1.p==275 && pc1.q==425)
			{
				D_V_RL[96]=1;
				D_V_UD[96]=1;
				func_left();
				if(score[96]==0)
				{
					score_plus+=5;
				}
				score[96]=1;
			}
			else if(pc1.p==350 && pc1.q==425)
			{
				D_V_RL[98]=1;
				D_V_UD[98]=1;
				func_left();
				if(score[98]==0)
				{
					score_plus+=5;
				}
				score[98]=1;
			}
			else if(pc1.p==375 && pc1.q==425)
			{
				D_V_RL[99]=1;
				D_V_UD[99]=1;
				func_left();
				if(score[99]==0)
				{
					score_plus+=5;
				}
				score[99]=1;
			}
			else if(pc1.p==450 && pc1.q==425)
			{
				D_V_RL[101]=1;
				D_V_UD[101]=1;
				func_left();
				if(score[101]==0)
				{
					score_plus+=5;
				}
				score[101]=1;
			}
			else if(pc1.p==475 && pc1.q==425)
			{
				D_V_RL[102]=1;
				D_V_UD[102]=1;
				func_left();
				if(score[102]==0)
				{
					score_plus+=5;
				}
				score[102]=1;
			}
			else if(pc1.p==500 && pc1.q==425)
			{
				D_V_RL[103]=1;
				D_V_UD[103]=1;
				func_left();
				if(score[103]==0)
				{
					score_plus+=5;
				}
				score[103]=1;
			}
			else if(pc1.p==525 && pc1.q==425)
			{
				D_V_RL[104]=1;
				D_V_UD[104]=1;
				func_left();
				if(score[104]==0)
				{
					score_plus+=5;
				}
				score[104]=1;
			}

			else if(pc1.p==125 && pc1.q==475)
			{
				D_V_RL[106]=1;
				D_V_UD[106]=1;
				func_left();
				if(score[106]==0)
				{
					score_plus+=5;
				}
				score[106]=1;
			}
			else if(pc1.p==150 && pc1.q==475)
			{
				D_V_RL[107]=1;
				D_V_UD[107]=1;
				func_left();
				if(score[107]==0)
				{
					score_plus+=5;
				}
				score[107]=1;
			}
			else if(pc1.p==175 && pc1.q==475)
			{
				D_V_RL[108]=1;
				D_V_UD[108]=1;
				func_left();
				if(score[108]==0)
				{
					score_plus+=5;
				}
				score[108]=1;
			}
			else if(pc1.p==200 && pc1.q==475)
			{
				D_V_RL[109]=1;
				D_V_UD[109]=1;
				func_left();
				if(score[109]==0)
				{
					score_plus+=5;
				}
				score[109]=1;
			}
			else if(pc1.p==225 && pc1.q==475)
			{
				D_V_RL[110]=1;
				D_V_UD[110]=1;
				func_left();
				if(score[110]==0)
				{
					score_plus+=5;
				}
				score[110]=1;
			}
			else if(pc1.p==250 && pc1.q==475)
			{
				D_V_RL[111]=1;
				D_V_UD[111]=1;
				func_left();
				if(score[111]==0)
				{
					score_plus+=5;
				}
				score[111]=1;
			}
			else if(pc1.p==275 && pc1.q==475)
			{
				D_V_RL[112]=1;
				D_V_UD[112]=1;
				func_left();
				if(score[112]==0)
				{
					score_plus+=5;
				}
				score[112]=1;
			}
			else if(pc1.p==300 && pc1.q==475)
			{
				D_V_RL[113]=1;
				D_V_UD[113]=1;
				func_left();
				if(score[113]==0)
				{
					score_plus+=5;
				}
				score[113]=1;
			}
			else if(pc1.p==325 && pc1.q==475)
			{
				D_V_RL[114]=1;
				D_V_UD[114]=1;
				func_left();
				if(score[114]==0)
				{
					score_plus+=5;
				}
				score[114]=1;
			}
			else if(pc1.p==400 && pc1.q==475)
			{
				D_V_RL[116]=1;
				D_V_UD[116]=1;
				func_left();
				if(score[116]==0)
				{
					score_plus+=5;
				}
				score[116]=1;
			}
			else if(pc1.p==425 && pc1.q==475)
			{
				D_V_RL[117]=1;
				D_V_UD[117]=1;
				func_left();
				if(score[117]==0)
				{
					score_plus+=5;
				}
				score[117]=1;
			}
			else if(pc1.p==500 && pc1.q==475)
			{
				D_V_RL[119]=1;
				D_V_UD[119]=1;
				func_left();
				if(score[119]==0)
				{
					score_plus+=5;
				}
				score[119]=1;
			}
			else if(pc1.p==525 && pc1.q==475)
			{
				D_V_RL[120]=1;
				D_V_UD[120]=1;
				func_left();
				if(score[120]==0)
				{
					score_plus+=5;
				}
				score[120]=1;
			}
			else if(pc1.p==550 && pc1.q==475)
			{
				D_V_RL[121]=1;
				D_V_UD[121]=1;
				func_left();
				if(score[121]==0)
				{
					score_plus+=5;
				}
				score[121]=1;
			}
			else if(pc1.p==575 && pc1.q==475)
			{
				D_V_RL[122]=1;
				D_V_UD[122]=1;
				func_left();
				if(score[122]==0)
				{
					score_plus+=5;
				}
				score[122]=1;
			}
		}
	}

	 if(key==GLUT_KEY_UP)
	{
		if(pc1.q!=475)
		{
			if(pc1.p==125 && pc1.q==125)
			{
				D_V_RL[1]=1;
				D_V_UD[1]=1;
				func_up();
				if(score[1]==0)
				{
					score_plus+=5;
				}
				score[1]=1;
			}
			else if(pc1.p==125 && pc1.q==150)
			{
				D_V_RL[123]=1;
				D_V_UD[123]=1;
				func_up();
				if(score[123]==0)
				{
					score_plus+=5;
				}
				score[123]=1;
			}
			else if(pc1.p==125 && pc1.q==175)
			{
				D_V_RL[18]=1;
				D_V_UD[18]=1;
				func_up();
				if(score[18]==0)
				{
					score_plus+=5;
				}
				score[18]=1;
			}
			else if(pc1.p==125 && pc1.q==200)
			{
				D_V_RL[129]=1;
				D_V_UD[129]=1;
				func_up();
				if(score[129]==0)
				{
					score_plus+=5;
				}
				score[129]=1;
			}
			else if(pc1.p==125 && pc1.q==225)
			{
				D_V_RL[33]=1;
				D_V_UD[33]=1;
				func_up();
				if(score[33]==0)
				{
					score_plus+=5;
				}
				score[33]=1;
			}
			else if(pc1.p==125 && pc1.q==250)
			{
				D_V_RL[136]=1;
				D_V_UD[136]=1;
				func_up();
				if(score[136]==0)
				{
					score_plus+=5;
				}
				score[136]=1;
			}
			else if(pc1.p==125 && pc1.q==275)
			{
				D_V_RL[48]=1;
				D_V_UD[48]=1;
				func_up();
				if(score[48]==0)
				{
					score_plus+=5;
				}
				score[48]=1;
			}
			else if(pc1.p==125 && pc1.q==300)
			{
				D_V_RL[141]=1;
				D_V_UD[141]=1;
				func_up();
				if(score[141]==0)
				{
					score_plus+=5;
				}
				score[141]=1;
			}
			else if(pc1.p==125 && pc1.q==325)
			{
				D_V_RL[63]=1;
				D_V_UD[63]=1;
				func_up();
				if(score[63]==0)
				{
					score_plus+=5;
				}
				score[63]=1;
			}
			else if(pc1.p==125 && pc1.q==350)
			{
				D_V_RL[147]=1;
				D_V_UD[147]=1;
				func_up();
				if(score[147]==0)
				{
					score_plus+=5;
				}
				score[147]=1;
			}
			else if(pc1.p==125 && pc1.q==425)
			{
				D_V_RL[91]=1;
				D_V_UD[91]=1;
				func_up();
				if(score[91]==0)
				{
					score_plus+=5;
				}
				score[91]=1;
			}
			else if(pc1.p==125 && pc1.q==450)
			{
				D_V_RL[158]=1;
				D_V_UD[158]=1;
				func_up();
				if(score[158]==0)
				{
					score_plus+=5;
				}
				score[158]=1;
			}

			else if(pc1.p==175 && pc1.q==175)
			{
				D_V_RL[20]=1;
				D_V_UD[20]=1;
				func_up();
				if(score[20]==0)
				{
					score_plus+=5;
				}
				score[20]=1;
			}
			else if(pc1.p==175 && pc1.q==200)
			{
				D_V_RL[130]=1;
				D_V_UD[130]=1;
				func_up();
				if(score[130]==0)
				{
					score_plus+=5;
				}
				score[130]=1;
			}
			else if(pc1.p==175 && pc1.q==225)
			{
				D_V_RL[34]=1;
				D_V_UD[34]=1;
				func_up();
				if(score[34]==0)
				{
					score_plus+=5;
				}
				score[34]=1;
			}
			else if(pc1.p==175 && pc1.q==250)
			{
				D_V_RL[137]=1;
				D_V_UD[137]=1;
				func_up();
				if(score[137]==0)
				{
					score_plus+=5;
				}
				score[137]=1;
			}
			else if(pc1.p==175 && pc1.q==325)
			{
				D_V_RL[65]=1;
				D_V_UD[65]=1;
				func_up();
				if(score[65]==0)
				{
					score_plus+=5;
				}
				score[65]=1;
			}
			else if(pc1.p==175 && pc1.q==350)
			{
				D_V_RL[148]=1;
				D_V_UD[148]=1;
				func_up();
				if(score[148]==0)
				{
					score_plus+=5;
				}
				score[148]=1;
			}
			else if(pc1.p==175 && pc1.q==375)
			{
				D_V_RL[77]=1;
				D_V_UD[77]=1;
				func_up();
				if(score[77]==0)
				{
					score_plus+=5;
				}
				score[77]=1;
			}
			else if(pc1.p==175 && pc1.q==400)
			{
				D_V_RL[155]=1;
				D_V_UD[155]=1;
				func_up();
				if(score[155]==0)
				{
					score_plus+=5;
				}
				score[155]=1;
			}

			else if(pc1.p==225 && pc1.q==125)
			{
				D_V_RL[5]=1;
				D_V_UD[5]=1;
				func_up();
				if(score[5]==0)
				{
					score_plus+=5;
				}
				score[5]=1;
			}
			else if(pc1.p==225 && pc1.q==150)
			{
				D_V_RL[124]=1;
				D_V_UD[124]=1;
				func_up();
				if(score[124]==0)
				{
					score_plus+=5;
				}
				score[124]=1;
			}
			else if(pc1.p==225 && pc1.q==275)
			{
				D_V_RL[50]=1;
				D_V_UD[50]=1;
				func_up();
				if(score[50]==0)
				{
					score_plus+=5;
				}
				score[50]=1;
			}
			else if(pc1.p==225 && pc1.q==300)
			{
				D_V_RL[142]=1;
				D_V_UD[142]=1;
				func_up();
				if(score[142]==0)
				{
					score_plus+=5;
				}
				score[142]=1;
			}
			else if(pc1.p==225 && pc1.q==325)
			{
				D_V_RL[66]=1;
				D_V_UD[66]=1;
				func_up();
				if(score[66]==0)
				{
					score_plus+=5;
				}
				score[66]=1;
			}
			else if(pc1.p==225 && pc1.q==350)
			{
				D_V_RL[149]=1;
				D_V_UD[149]=1;
				func_up();
				if(score[149]==0)
				{
					score_plus+=5;
				}
				score[149]=1;
			}
			else if(pc1.p==225 && pc1.q==425)
			{
				D_V_RL[94]=1;
				D_V_UD[94]=1;
				func_up();
				if(score[94]==0)
				{
					score_plus+=5;
				}
				score[94]=1;
			}
			else if(pc1.p==225 && pc1.q==450)
			{
				D_V_RL[159]=1;
				D_V_UD[159]=1;
				func_up();
				if(score[159]==0)
				{
					score_plus+=5;
				}
				score[159]=1;
			}


			else if(pc1.p==275 && pc1.q==175)
			{
				D_V_RL[23]=1;
				D_V_UD[23]=1;
				func_up();
				if(score[23]==0)
				{
					score_plus+=5;
				}
				score[23]=1;
			}
			else if(pc1.p==275 && pc1.q==200)
			{
				D_V_RL[131]=1;
				D_V_UD[131]=1;
				func_up();
				if(score[131]==0)
				{
					score_plus+=5;
				}
				score[131]=1;
			}
			else if(pc1.p==275 && pc1.q==225)
			{
				D_V_RL[38]=1;
				D_V_UD[38]=1;
				func_up();
				if(score[38]==0)
				{
					score_plus+=5;
				}
				score[38]=1;
			}
			else if(pc1.p==275 && pc1.q==250)
			{
				D_V_RL[138]=1;
				D_V_UD[138]=1;
				func_up();
				if(score[138]==0)
				{
					score_plus+=5;
				}
				score[138]=1;
			}
			else if(pc1.p==275 && pc1.q==325)
			{
				D_V_RL[67]=1;
				D_V_UD[67]=1;
				func_up();
				if(score[67]==0)
				{
					score_plus+=5;
				}
				score[67]=1;
			}
			else if(pc1.p==275 && pc1.q==350)
			{
				D_V_RL[150]=1;
				D_V_UD[150]=1;
				func_up();
				if(score[150]==0)
				{
					score_plus+=5;
				}
				score[150]=1;
			}
			else if(pc1.p==275 && pc1.q==375)
			{
				D_V_RL[80]=1;
				D_V_UD[80]=1;
				func_up();
				if(score[80]==0)
				{
					score_plus+=5;
				}
				score[80]=1;
			}
			else if(pc1.p==275 && pc1.q==400)
			{
				D_V_RL[156]=1;
				D_V_UD[156]=1;
				func_up();
				if(score[156]==0)
				{
					score_plus+=5;
				}
				score[156]=1;
			}

			else if(pc1.p==325 && pc1.q==125)
			{
				D_V_RL[9]=1;
				D_V_UD[9]=1;
				func_up();
				if(score[9]==0)
				{
					score_plus+=5;
				}
				score[9]=1;
			}
			else if(pc1.p==325 && pc1.q==150)
			{
				D_V_RL[125]=1;
				D_V_UD[125]=1;
				func_up();
				if(score[125]==0)
				{
					score_plus+=5;
				}
				score[125]=1;
			}
			else if(pc1.p==325 && pc1.q==175)
			{
				D_V_RL[24]=1;
				D_V_UD[24]=1;
				func_up();
				if(score[24]==0)
				{
					score_plus+=5;
				}
				score[24]=1;
			}
			else if(pc1.p==325 && pc1.q==200)
			{
				D_V_RL[132]=1;
				D_V_UD[132]=1;
				func_up();
				if(score[132]==0)
				{
					score_plus+=5;
				}
				score[132]=1;
			}
			else if(pc1.p==325 && pc1.q==325)
			{
				D_V_RL[69]=1;
				D_V_UD[69]=1;
				func_up();
				if(score[69]==0)
				{
					score_plus+=5;
				}
				score[69]=1;
			}
			else if(pc1.p==325 && pc1.q==350)
			{
				D_V_RL[151]=1;
				D_V_UD[151]=1;
				func_up();
				if(score[151]==0)
				{
					score_plus+=5;
				}
				score[151]=1;
			}
			else if(pc1.p==325 && pc1.q==425)
			{
				D_V_RL[97]=1;
				D_V_UD[97]=1;
				func_up();
				if(score[97]==0)
				{
					score_plus+=5;
				}
				score[97]=1;
			}
			else if(pc1.p==325 && pc1.q==450)
			{
				D_V_RL[160]=1;
				D_V_UD[160]=1;
				func_up();
				if(score[160]==0)
				{
					score_plus+=5;
				}
				score[160]=1;
			}

			else if(pc1.p==375 && pc1.q==125)
			{
				D_V_RL[10]=1;
				D_V_UD[10]=1;
				func_up();
				if(score[10]==0)
				{
					score_plus+=5;
				}
				score[10]=1;
			}
			else if(pc1.p==375 && pc1.q==150)
			{
				D_V_RL[126]=1;
				D_V_UD[126]=1;
				func_up();
				if(score[126]==0)
				{
					score_plus+=5;
				}
				score[126]=1;
			}
			else if(pc1.p==375 && pc1.q==175)
			{
				D_V_RL[25]=1;
				D_V_UD[25]=1;
				func_up();
				if(score[25]==0)
				{
					score_plus+=5;
				}
				score[25]=1;
			}
			else if(pc1.p==375 && pc1.q==200)
			{
				D_V_RL[133]=1;
				D_V_UD[133]=1;
				func_up();
				if(score[133]==0)
				{
					score_plus+=5;
				}
				score[133]=1;
			}
			else if(pc1.p==375 && pc1.q==275)
			{
				D_V_RL[56]=1;
				D_V_UD[56]=1;
				func_up();
				if(score[56]==0)
				{
					score_plus+=5;
				}
				score[56]=1;
			}
			else if(pc1.p==375 && pc1.q==300)
			{
				D_V_RL[143]=1;
				D_V_UD[143]=1;
				func_up();
				if(score[143]==0)
				{
					score_plus+=5;
				}
				score[143]=1;
			}
			else if(pc1.p==375 && pc1.q==325)
			{
				D_V_RL[70]=1;
				D_V_UD[70]=1;
				func_up();
				if(score[70]==0)
				{
					score_plus+=5;
				}
				score[70]=1;
			}
			else if(pc1.p==375 && pc1.q==350)
			{
				D_V_RL[152]=1;
				D_V_UD[152]=1;
				func_up();
				if(score[152]==0)
				{
					score_plus+=5;
				}
				score[152]=1;
			}
			else if(pc1.p==375 && pc1.q==425)
			{
				D_V_RL[99]=1;
				D_V_UD[99]=1;
				func_up();
				if(score[99]==0)
				{
					score_plus+=5;
				}
				score[99]=1;
			}
			else if(pc1.p==375 && pc1.q==450)
			{
				D_V_RL[161]=1;
				D_V_UD[161]=1;
				func_up();
				if(score[161]==0)
				{
					score_plus+=5;
				}
				score[161]=1;
			}

			else if(pc1.p==425 && pc1.q==175)
			{
				D_V_RL[26]=1;
				D_V_UD[26]=1;
				func_up();
				if(score[26]==0)
				{
					score_plus+=5;
				}
				score[26]=1;
			}
			else if(pc1.p==425 && pc1.q==200)
			{
				D_V_RL[134]=1;
				D_V_UD[134]=1;
				func_up();
				if(score[134]==0)
				{
					score_plus+=5;
				}
				score[134]=1;
			}
			else if(pc1.p==425 && pc1.q==225)
			{
				D_V_RL[42]=1;
				D_V_UD[42]=1;
				func_up();
				if(score[42]==0)
				{
					score_plus+=5;
				}
				score[42]=1;
			}
			else if(pc1.p==425 && pc1.q==250)
			{
				D_V_RL[139]=1;
				D_V_UD[139]=1;
				func_up();
				if(score[139]==0)
				{
					score_plus+=5;
				}
				score[139]=1;
			}
			else if(pc1.p==425 && pc1.q==275)
			{
				D_V_RL[57]=1;
				D_V_UD[57]=1;
				func_up();
				if(score[57]==0)
				{
					score_plus+=5;
				}
				score[57]=1;
			}
			else if(pc1.p==425 && pc1.q==300)
			{
				D_V_RL[144]=1;
				D_V_UD[144]=1;
				func_up();
				if(score[144]==0)
				{
					score_plus+=5;
				}
				score[144]=1;
			}
			else if(pc1.p==425 && pc1.q==425)
			{
				D_V_RL[100]=1;
				D_V_UD[100]=1;
				func_up();
				if(score[100]==0)
				{
					score_plus+=5;
				}
				score[100]=1;
			}
			else if(pc1.p==425 && pc1.q==450)
			{
				D_V_RL[162]=1;
				D_V_UD[162]=1;
				func_up();
				if(score[162]==0)
				{
					score_plus+=5;
				}
				score[162]=1;
			}

			else if(pc1.p==475 && pc1.q==125)
			{
				D_V_RL[14]=1;
				D_V_UD[14]=1;
				func_up();
				if(score[14]==0)
				{
					score_plus+=5;
				}
				score[14]=1;
			}
			else if(pc1.p==475 && pc1.q==150)
			{
				D_V_RL[127]=1;
				D_V_UD[127]=1;
				func_up();
				if(score[127]==0)
				{
					score_plus+=5;
				}
				score[127]=1;
			}
			else if(pc1.p==475 && pc1.q==225)
			{
				D_V_RL[43]=1;
				D_V_UD[43]=1;
				func_up();
				if(score[43]==0)
				{
					score_plus+=5;
				}
				score[43]=1;
			}
			else if(pc1.p==475 && pc1.q==250)
			{
				D_V_RL[140]=1;
				D_V_UD[140]=1;
				func_up();
				if(score[140]==0)
				{
					score_plus+=5;
				}
				score[140]=1;
			}
			else if(pc1.p==475 && pc1.q==325)
			{
				D_V_RL[73]=1;
				D_V_UD[73]=1;
				func_up();
				if(score[73]==0)
				{
					score_plus+=5;
				}
				score[73]=1;
			}
			else if(pc1.p==475 && pc1.q==350)
			{
				D_V_RL[153]=1;
				D_V_UD[153]=1;
				func_up();
				if(score[153]==0)
				{
					score_plus+=5;
				}
				score[153]=1;
			}
			else if(pc1.p==475 && pc1.q==425)
			{
				D_V_RL[102]=1;
				D_V_UD[102]=1;
				func_up();
				if(score[102]==0)
				{
					score_plus+=5;
				}
				score[102]=1;
			}
			else if(pc1.p==475 && pc1.q==450)
			{
				D_V_RL[163]=1;
				D_V_UD[163]=1;
				func_up();
				if(score[163]==0)
				{
					score_plus+=5;
				}
				score[163]=1;
			}

			else if(pc1.p==525 && pc1.q==125)
			{
				D_V_RL[15]=1;
				D_V_UD[15]=1;
				func_up();
				if(score[15]==0)
				{
					score_plus+=5;
				}
				score[15]=1;
			}
			else if(pc1.p==525 && pc1.q==150)
			{
				D_V_RL[128]=1;
				D_V_UD[128]=1;
				func_up();
				if(score[128]==0)
				{
					score_plus+=5;
				}
				score[128]=1;
			}
			else if(pc1.p==525 && pc1.q==275)
			{
				D_V_RL[60]=1;
				D_V_UD[60]=1;
				func_up();
				if(score[60]==0)
				{
					score_plus+=5;
				}
				score[60]=1;
			}
			else if(pc1.p==525 &&pc1. q==300)
			{
				D_V_RL[145]=1;
				D_V_UD[145]=1;
				func_up();
				if(score[145]==0)
				{
					score_plus+=5;
				}
				score[145]=1;
			}
			else if(pc1.p==525 && pc1.q==325)
			{
				D_V_RL[74]=1;
				D_V_UD[74]=1;
				func_up();
				if(score[74]==0)
				{
					score_plus+=5;
				}
				score[74]=1;
			}
			else if(pc1.p==525 && pc1.q==350)
			{
				D_V_RL[154]=1;
				D_V_UD[154]=1;
				func_up();
				if(score[154]==0)
				{
					score_plus+=5;
				}
				score[154]=1;
			}

			else if(pc1.p==575 && pc1.q==175)
			{
				D_V_RL[32]=1;
				D_V_UD[32]=1;
				func_up();
				if(score[32]==0)
				{
					score_plus+=5;
				}
				score[32]=1;
			}
			else if(pc1.p==575 && pc1.q==200)
			{
				D_V_RL[135]=1;
				D_V_UD[135]=1;
				func_up();
				if(score[135]==0)
				{
					score_plus+=5;
				}
				score[135]=1;
			}
			else if(pc1.p==575 && pc1.q==275)
			{
				D_V_RL[62]=1;
				D_V_UD[62]=1;
				func_up();
				if(score[62]==0)
				{
					score_plus+=5;
				}
				score[62]=1;
			}
			else if(pc1.p==575 && pc1.q==300)
			{
				D_V_RL[146]=1;
				D_V_UD[146]=1;
				func_up();
				if(score[146]==0)
				{
					score_plus+=5;
				}
				score[146]=1;
			}
			else if(pc1.p==575 && pc1.q==375)
			{
				D_V_RL[90]=1;
				D_V_UD[90]=1;
				func_up();
				if(score[90]==0)
				{
					score_plus+=5;
				}
				score[90]=1;
			}
			else if(pc1.p==575 && pc1.q==400)
			{
				D_V_RL[157]=1;
				D_V_UD[157]=1;
				func_up();
				if(score[157]==0)
				{
					score_plus+=5;
				}
				score[157]=1;
			}
			else if(pc1.p==575 && pc1.q==425)
			{
				D_V_RL[105]=1;
				D_V_UD[105]=1;
				func_up();
				if(score[105]==0)
				{
					score_plus+=5;
				}
				score[105]=1;
			}
			else if(pc1.p==575 && pc1.q==450)
			{
				D_V_RL[164]=1;
				D_V_UD[164]=1;
				func_up();
				if(score[164]==0)
				{
					score_plus+=5;
				}
				score[164]=1;
			}
		}
	}

	if(key==GLUT_KEY_DOWN)
	{
		if(pc1.q!=125)
		{
			 if(pc1.p==125 && pc1.q==150)
			 {
				D_V_RL[123]=1;
				D_V_UD[123]=1;
				func_down();
				if(score[123]==0)
				{
					score_plus+=5;
				}
				score[123]=1;
			 }
			else if(pc1.p==125 && pc1.q==175)
			{
				D_V_RL[18]=1;
				D_V_UD[18]=1;
				func_down();
				if(score[18]==0)
				{
					score_plus+=5;
				}
				score[18]=1;
			 }
			else if(pc1.p==125 && pc1.q==200)
			{
				D_V_RL[129]=1;
				D_V_UD[129]=1;
				func_down();
				if(score[129]==0)
				{
					score_plus+=5;
				}
				score[129]=1;
			 }
			else if(pc1.p==125 && pc1.q==225)
			{
				D_V_RL[33]=1;
				D_V_UD[33]=1;
				func_down();
				if(score[33]==0)
				{
					score_plus+=5;
				}
				score[33]=1;
			 }
			else if(pc1.p==125 && pc1.q==250)
			{
				D_V_RL[136]=1;
				D_V_UD[136]=1;
				func_down();
				if(score[136]==0)
				{
					score_plus+=5;
				}
				score[136]=1;
			 }
			else if(pc1.p==125 && pc1.q==275)
			{
				D_V_RL[48]=1;
				D_V_UD[48]=1;
				func_down();
				if(score[48]==0)
				{
					score_plus+=5;
				}
				score[48]=1;
			 }
			else if(pc1.p==125 && pc1.q==300)
			{
				D_V_RL[141]=1;
				D_V_UD[141]=1;
				func_down();
				if(score[141]==0)
				{
					score_plus+=5;
				}
				score[141]=1;
			 }
			else if(pc1.p==125 && pc1.q==325)
			{
				D_V_RL[63]=1;
				D_V_UD[63]=1;
				func_down();
				if(score[63]==0)
				{
					score_plus+=5;
				}
				score[63]=1;
			 }
			else if(pc1.p==125 && pc1.q==350)
			{
				D_V_RL[147]=1;
				D_V_UD[147]=1;
				func_down();
				if(score[147]==0)
				{
					score_plus+=5;
				}
				score[147]=1;
			 }
			else if(pc1.p==125 && pc1.q==375)
			{
				D_V_RL[76]=1;
				D_V_UD[76]=1;
				func_down();
				if(score[76]==0)
				{
					score_plus+=5;
				}
				score[76]=1;
			 }
			else if(pc1.p==125 && pc1.q==450)
			{
				D_V_RL[158]=1;
				D_V_UD[158]=1;
				func_down();
				if(score[158]==0)
				{
					score_plus+=5;
				}
				score[158]=1;
			 }
			else if(pc1.p==125 && pc1.q==475)
			{
				D_V_RL[106]=1;
				D_V_UD[106]=1;
				func_down();
				if(score[106]==0)
				{
					score_plus+=5;
				}
				score[106]=1;
			 }

			else if(pc1.p==175 && pc1.q==200)
			{
				D_V_RL[130]=1;
				D_V_UD[130]=1;
				func_down();
				if(score[130]==0)
				{
					score_plus+=5;
				}
				score[130]=1;
			 }
			else if(pc1.p==175 && pc1.q==225)
			{
				D_V_RL[34]=1;
				D_V_UD[34]=1;
				func_down();
				if(score[34]==0)
				{
					score_plus+=5;
				}
				score[34]=1;
			 }
			else if(pc1.p==175 && pc1.q==250)
			{
				D_V_RL[137]=1;
				D_V_UD[137]=1;
				func_down();
				if(score[137]==0)
				{
					score_plus+=5;
				}
				score[137]=1;
			 }
			else if(pc1.p==175 && pc1.q==275)
			{
				D_V_RL[49]=1;
				D_V_UD[49]=1;
				func_down();
				if(score[49]==0)
				{
					score_plus+=5;
				}
				score[49]=1;
			 }
			else if(pc1.p==175 && pc1.q==350)
			{
				D_V_RL[148]=1;
				D_V_UD[148]=1;
				func_down();
				if(score[148]==0)
				{
					score_plus+=5;
				}
				score[148]=1;
			 }
			else if(pc1.p==175 && pc1.q==375)
			{
				D_V_RL[77]=1;
				D_V_UD[77]=1;
				func_down();
				if(score[77]==0)
				{
					score_plus+=5;
				}
				score[77]=1;
			 }
			else if(pc1.p==175 && pc1.q==400)
			{
				D_V_RL[155]=1;
				D_V_UD[155]=1;
				func_down();
				if(score[155]==0)
				{
					score_plus+=5;
				}
				score[155]=1;
			 }
			else if(pc1.p==175 && pc1.q==425)
			{
				D_V_RL[93]=1;
				D_V_UD[93]=1;
				func_down();
				if(score[93]==0)
				{
					score_plus+=5;
				}
				score[93]=1;
			 }

			else if(pc1.p==225 && pc1.q==150)
			{
				D_V_RL[124]=1;
				D_V_UD[124]=1;
				func_down();
				if(score[124]==0)
				{
					score_plus+=5;
				}
				score[124]=1;
			 }
			else if(pc1.p==225 && pc1.q==175)
			{
				D_V_RL[21]=1;
				D_V_UD[21]=1;
				func_down();
				if(score[21]==0)
				{
					score_plus+=5;
				}
				score[21]=1;
			 }
			else if(pc1.p==225 && pc1.q==300)
			{
				D_V_RL[142]=1;
				D_V_UD[142]=1;
				func_down();
				if(score[142]==0)
				{
					score_plus+=5;
				}
				score[142]=1;
			 }
			else if(pc1.p==225 && pc1.q==325)
			{
				D_V_RL[66]=1;
				D_V_UD[66]=1;
				func_down();
				if(score[66]==0)
				{
					score_plus+=5;
				}
				score[66]=1;
			 }
			else if(pc1.p==225 && pc1.q==350)
			{
				D_V_RL[149]=1;
				D_V_UD[149]=1;
				func_down();
				if(score[149]==0)
				{
					score_plus+=5;
				}
				score[149]=1;
			 }
			else if(pc1.p==225 && pc1.q==375)
			{
				D_V_RL[79]=1;
				D_V_UD[79]=1;
				func_down();
				if(score[79]==0)
				{
					score_plus+=5;
				}
				score[79]=1;
			 }
			else if(pc1.p==225 && pc1.q==450)
			{
				D_V_RL[159]=1;
				D_V_UD[159]=1;
				func_down();
				if(score[159]==0)
				{
					score_plus+=5;
				}
				score[159]=1;
			 }
			else if(pc1.p==225 && pc1.q==475)
			{
				D_V_RL[110]=1;
				D_V_UD[110]=1;
				func_down();
				if(score[110]==0)
				{
					score_plus+=5;
				}
				score[110]=1;
			 }

			else if(pc1.p==275 && pc1.q==200)
			{
				D_V_RL[131]=1;
				D_V_UD[131]=1;
				func_down();
				if(score[131]==0)
				{
					score_plus+=5;
				}
				score[131]=1;
			 }
			else if(pc1.p==275 && pc1.q==225)
			{
				D_V_RL[38]=1;
				D_V_UD[38]=1;
				func_down();
				if(score[38]==0)
				{
					score_plus+=5;
				}
				score[38]=1;
			 }
			else if(pc1.p==275 && pc1.q==250)
			{
				D_V_RL[138]=1;
				D_V_UD[138]=1;
				func_down();
				if(score[138]==0)
				{
					score_plus+=5;
				}
				score[138]=1;
			 }
			else if(pc1.p==275 && pc1.q==275)
			{
				D_V_RL[52]=1;
				D_V_UD[52]=1;
				func_down();
				if(score[52]==0)
				{
					score_plus+=5;
				}
				score[52]=1;
			 }
			else if(pc1.p==275 && pc1.q==350)
			{
				D_V_RL[150]=1;
				D_V_UD[150]=1;
				func_down();
				if(score[150]==0)
				{
					score_plus+=5;
				}
				score[150]=1;
			 }
			else if(pc1.p==275 && pc1.q==375)
			{
				D_V_RL[80]=1;
				D_V_UD[80]=1;
				func_down();
				if(score[80]==0)
				{
					score_plus+=5;
				}
				score[80]=1;
			 }
			else if(pc1.p==275 && pc1.q==400)
			{
				D_V_RL[156]=1;
				D_V_UD[156]=1;
				func_down();
				if(score[156]==0)
				{
					score_plus+=5;
				}
				score[156]=1;
			 }
			else if(pc1.p==275 && pc1.q==425)
			{
				D_V_RL[96]=1;
				D_V_UD[96]=1;
				func_down();
				if(score[96]==0)
				{
					score_plus+=5;
				}
				score[96]=1;
			 }

			else if(pc1.p==325 && pc1.q==150)
			{
				D_V_RL[125]=1;
				D_V_UD[125]=1;
				func_down();
				if(score[125]==0)
				{
					score_plus+=5;
				}
				score[125]=1;
			 }
			else if(pc1.p==325 && pc1.q==175)
			{
				D_V_RL[24]=1;
				D_V_UD[24]=1;
				func_down();
				if(score[24]==0)
				{
					score_plus+=5;
				}
				score[24]=1;
			 }
			else if(pc1.p==325 && pc1.q==200)
			{
				D_V_RL[132]=1;
				D_V_UD[132]=1;
				func_down();
				if(score[132]==0)
				{
					score_plus+=5;
				}
				score[132]=1;
			 }
			else if(pc1.p==325 && pc1.q==225)
			{
				D_V_RL[39]=1;
				D_V_UD[39]=1;
				func_down();
				if(score[39]==0)
				{
					score_plus+=5;
				}
				score[39]=1;
			 }
			else if(pc1.p==325 && pc1.q==350)
			{
				D_V_RL[151]=1;
				D_V_UD[151]=1;
				func_down();
				if(score[151]==0)
				{
					score_plus+=5;
				}
				score[151]=1;
			 }
			else if(pc1.p==325 && pc1.q==375)
			{
				D_V_RL[81]=1;
				D_V_UD[81]=1;
				func_down();
				if(score[81]==0)
				{
					score_plus+=5;
				}
				score[81]=1;
			 }
			else if(pc1.p==325 && pc1.q==450)
			{
				D_V_RL[160]=1;
				D_V_UD[160]=1;
				func_down();
				if(score[160]==0)
				{
					score_plus+=5;
				}
				score[160]=1;
			 }
			else if(pc1.p==325 && pc1.q==475)
			{
				D_V_RL[114]=1;
				D_V_UD[114]=1;
				func_down();
				if(score[114]==0)
				{
					score_plus+=5;
				}
				score[114]=1;
			 }

			else if(pc1.p==375 && pc1.q==150)
			{
				D_V_RL[126]=1;
				D_V_UD[126]=1;
				func_down();
				if(score[126]==0)
				{
					score_plus+=5;
				}
				score[126]=1;
			 }
			else if(pc1.p==375 && pc1.q==175)
			{
				D_V_RL[25]=1;
				D_V_UD[25]=1;
				func_down();
				if(score[25]==0)
				{
					score_plus+=5;
				}
				score[25]=1;
			 }
			else if(pc1.p==375 && pc1.q==200)
			{
				D_V_RL[133]=1;
				D_V_UD[133]=1;
				func_down();
				if(score[133]==0)
				{
					score_plus+=5;
				}
				score[133]=1;
			 }
			else if(pc1.p==375 && pc1.q==225)
			{
				D_V_RL[41]=1;
				D_V_UD[41]=1;
				func_down();
				if(score[41]==0)
				{
					score_plus+=5;
				}
				score[41]=1;
			 }
			else if(pc1.p==375 && pc1.q==300)
			{
				D_V_RL[143]=1;
				D_V_UD[143]=1;
				func_down();
				if(score[143]==0)
				{
					score_plus+=5;
				}
				score[143]=1;
			 }
			else if(pc1.p==375 && pc1.q==325)
			{
				D_V_RL[70]=1;
				D_V_UD[70]=1;
				func_down();
				if(score[70]==0)
				{
					score_plus+=5;
				}
				score[70]=1;
			 }
			else if(pc1.p==375 && pc1.q==350)
			{
				D_V_RL[152]=1;
				D_V_UD[152]=1;
				func_down();
				if(score[152]==0)
				{
					score_plus+=5;
				}
				score[152]=1;
			 }
			else if(pc1.p==375 && pc1.q==375)
			{
				D_V_RL[83]=1;
				D_V_UD[83]=1;
				func_down();
				if(score[83]==0)
				{
					score_plus+=5;
				}
				score[83]=1;
			 }
			else if(pc1.p==375 && pc1.q==450)
			{
				D_V_RL[161]=1;
				D_V_UD[161]=1;
				func_down();
				if(score[161]==0)
				{
					score_plus+=5;
				}
				score[161]=1;
			 }
			else if(pc1.p==375 && pc1.q==475)
			{
				D_V_RL[115]=1;
				D_V_UD[115]=1;
				func_down();
				if(score[115]==0)
				{
					score_plus+=5;
				}
				score[115]=1;
			 }

			else if(pc1.p==425 && pc1.q==200)
			{
				D_V_RL[134]=1;
				D_V_UD[134]=1;
				func_down();
				if(score[134]==0)
				{
					score_plus+=5;
				}
				score[134]=1;
			 }
			else if(pc1.p==425 && pc1.q==225)
			{
				D_V_RL[42]=1;
				D_V_UD[42]=1;
				func_down();
				if(score[42]==0)
				{
					score_plus+=5;
				}
				score[42]=1;
			 }
			else if(pc1.p==425 && pc1.q==250)
			{
				D_V_RL[139]=1;
				D_V_UD[139]=1;
				func_down();
				if(score[139]==0)
				{
					score_plus+=5;
				}
				score[139]=1;
			 }
			else if(pc1.p==425 && pc1.q==275)
			{
				D_V_RL[57]=1;
				D_V_UD[57]=1;
				func_down();
				if(score[57]==0)
				{
					score_plus+=5;
				}
				score[57]=1;
			 }
			else if(pc1.p==425 && pc1.q==300)
			{
				D_V_RL[141]=1;
				D_V_UD[144]=1;
				func_down();
				if(score[144]==0)
				{
					score_plus+=5;
				}
				score[144]=1;
			 }
			else if(pc1.p==425 && pc1.q==325)
			{
				D_V_RL[71]=1;
				D_V_UD[71]=1;
				func_down();
				if(score[71]==0)
				{
					score_plus+=5;
				}
				score[71]=1;
			 }
			else if(pc1.p==425 && pc1.q==450)
			{
				D_V_RL[162]=1;
				D_V_UD[162]=1;
				func_down();
				if(score[162]==0)
				{
					score_plus+=5;
				}
				score[162]=1;
			 }
			else if(pc1.p==425 && pc1.q==475)
			{
				D_V_RL[117]=1;
				D_V_UD[117]=1;
				func_down();
				if(score[117]==0)
				{
					score_plus+=5;
				}
				score[117]=1;
			 }

			else if(pc1.p==475 && pc1.q==150)
			{
				D_V_RL[127]=1;
				D_V_UD[127]=1;
				func_down();
				if(score[127]==0)
				{
					score_plus+=5;
				}
				score[127]=1;
			 }
			else if(pc1.p==475 && pc1.q==175)
			{
				D_V_RL[28]=1;
				D_V_UD[28]=1;
				func_down();
				if(score[28]==0)
				{
					score_plus+=5;
				}
				score[28]=1;
			 }
			else if(pc1.p==475 && pc1.q==250)
			{
				D_V_RL[140]=1;
				D_V_UD[140]=1;
				func_down();
				if(score[140]==0)
				{
					score_plus+=5;
				}
				score[140]=1;
			 }
			else if(pc1.p==475 && pc1.q==275)
			{
				D_V_RL[58]=1;
				D_V_UD[58]=1;
				func_down();
				if(score[58]==0)
				{
					score_plus+=5;
				}
				score[58]=1;
			 }
			else if(pc1.p==475 && pc1.q==350)
			{
				D_V_RL[153]=1;
				D_V_UD[153]=1;
				func_down();
				if(score[153]==0)
				{
					score_plus+=5;
				}
				score[153]=1;
			 }
			else if(pc1.p==475 && pc1.q==375)
			{
				D_V_RL[87]=1;
				D_V_UD[87]=1;
				func_down();
				if(score[87]==0)
				{
					score_plus+=5;
				}
				score[87]=1;
			 }
			else if(pc1.p==475 && pc1.q==450)
			{
				D_V_RL[163]=1;
				D_V_UD[163]=1;
				func_down();
				if(score[163]==0)
				{
					score_plus+=5;
				}
				score[163]=1;
			 }
			else if(pc1.p==475 && pc1.q==475)
			{
				D_V_RL[118]=1;
				D_V_UD[118]=1;
				func_down();
				if(score[118]==0)
				{
					score_plus+=5;
				}
				score[118]=1;
			 }

			else if(pc1.p==525 && pc1.q==125)
			{
				D_V_RL[15]=1;
				D_V_UD[15]=1;
				func_down();
				if(score[15]==0)
				{
					score_plus+=5;
				}
				score[15]=1;
			 }
			else if(pc1.p==525 && pc1.q==150)
			{
				D_V_RL[128]=1;
				D_V_UD[128]=1;
				func_down();
				if(score[128]==0)
				{
					score_plus+=5;
				}
				score[128]=1;
			 }
			else if(pc1.p==525 && pc1.q==175)
			{
				D_V_RL[30]=1;
				D_V_UD[30]=1;
				func_down();
				if(score[30]==0)
				{
					score_plus+=5;
				}
				score[30]=1;
			 }
			else if(pc1.p==525 && pc1.q==300)
			{
				D_V_RL[145]=1;
				D_V_UD[145]=1;
				func_down();
				if(score[145]==0)
				{
					score_plus+=5;
				}
				score[145]=1;
			 }
			else if(pc1.p==525 && pc1.q==325)
			{
				D_V_RL[74]=1;
				D_V_UD[74]=1;
				func_down();
				if(score[74]==0)
				{
					score_plus+=5;
				}
				score[74]=1;
			 }
			else if(pc1.p==525 && pc1.q==350)
			{
				D_V_RL[154]=1;
				D_V_UD[154]=1;
				func_down();
				if(score[154]==0)
				{
					score_plus+=5;
				}
				score[154]=1;
			 }
			else if(pc1.p==525 && pc1.q==375)
			{
				D_V_RL[88]=1;
				D_V_UD[88]=1;
				func_down();
				if(score[88]==0)
				{
					score_plus+=5;
				}
				score[88]=1;
			 }

			else if(pc1.p==575 && pc1.q==200)
			{
				D_V_RL[135]=1;
				D_V_UD[135]=1;
				func_down();
				if(score[135]==0)
				{
					score_plus+=5;
				}
				score[135]=1;
			 }
			else if(pc1.p==575 && pc1.q==225)
			{
				D_V_RL[47]=1;
				D_V_UD[47]=1;
				func_down();
				if(score[47]==0)
				{
					score_plus+=5;
				}
				score[47]=1;
			 }
			else if(pc1.p==575 && pc1.q==300)
			{
				D_V_RL[146]=1;
				D_V_UD[146]=1;
				func_down();
				if(score[146]==0)
				{
					score_plus+=5;
				}
				score[146]=1;
			 }
			else if(pc1.p==575 && pc1.q==325)
			{
				D_V_RL[75]=1;
				D_V_UD[75]=1;
				func_down();
				if(score[75]==0)
				{
					score_plus+=5;
				}
				score[75]=1;
			 }
			else if(pc1.p==575 && pc1.q==400)
			{
				D_V_RL[157]=1;
				D_V_UD[157]=1;
				func_down();
				if(score[157]==0)
				{
					score_plus+=5;
				}
				score[157]=1;
			 }
			else if(pc1.p==575 && pc1.q==425)
			{
				D_V_RL[105]=1;
				D_V_UD[105]=1;
				func_down();
				if(score[105]==0)
				{
					score_plus+=5;
				}
				score[105]=1;
			 }
			else if(pc1.p==575 && pc1.q==450)
			{
				D_V_RL[164]=1;
				D_V_UD[164]=1;
				func_down();
				if(score[164]==0)
				{
					score_plus+=5;
				}
				score[164]=1;
			 }
			else if(pc1.p==575 && pc1.q==475)
			{
				D_V_RL[122]=1;
				D_V_UD[122]=1;
				func_down();
				if(score[122]==0)
				{
					score_plus+=5;
				}
				score[122]=1;
			 }
		}
	}
}
int main() 
{
	FILE *fp;
	if((fp=fopen("help.txt","a+"))!=NULL)
	{
		fgets(high_score,30, fp);
		puts(high_score);
	}
	else
	{
		printf("Error! opening file");
		exit(1);
	}
	setValue();
	iInitialize(700,600, "game Project");
	return 0;
}