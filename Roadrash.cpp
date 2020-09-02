#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#include <iostream>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

int sm0 , sm1 , sm2 , sm3 ,sm4;

int pic_x, pic_y;
int rgb[5][3]=
{
    {200,0,0},
    {200,0,0},
    {200,0,0},
    {200,0,0},
    {200,0,0},

};

double dy;
double i=100;
double j;
double k=200;
double c= 0;
double m;
double n;
int d=7;
int lane1,lane2,lane3,lane4;
int z=2;
int l=500;////car
int o=700;////car
int q=300;////car
int r=100;////car

int npcbikespeed=18;

int b=1005;
int wind=500;
int tower=500+2000;
int bush=0;
int bu1=0;
int bu2=100;
int bu3=200;
int bu4=300;
int bu5=400;
int palm=1500;
int bill=400;
int ln1=4;
int ln2=6;
int ln3=4;
int ln4=6;
int carindx1=0;
int carindx2=1;
int carindx3=2;
int carindx4=3;

int mid=0;

int red=0;
int green=255;
int blue=0;
double maxspeed=55;

bool gameover=false;
int startcount=0;
bool gameon=false;


int nitro=0;

typedef struct
{

    double bx;
    double by;
    double speed;
    int pos;
} npcbike;

npcbike bike[9];


int ii,jj,ss;
int playerpos=10;
double xx=250;//gamestart


double mudy[4];
/*
	function iDraw() is called again and again by the system.
	*/
void iDraw()
{



    iClear();

////////////////grass///////////////

    iSetColor(0,150,0);
    double xl[4]= {0,250,250,0};
    double yl[4]= {0,0,500,500};
    iFilledPolygon(xl,yl,4);


    double xr[4]= {750,1000,1000,750};
    double yr[4]= {0,0,500,500};
    iFilledPolygon(xr,yr,4);

    if(dy+bu1<0) bu1+=500;
    if(dy+bu2<0) bu2+=500;
    if(dy+bu3<0) bu3+=500;
    if(dy+bu4<0) bu4+=500;
    if(dy+bu5<0) bu5+=500;

    if(dy+bill<0) bill+=500;


///////////////bush and bill///////////////////////

    iShowBMP(175,dy+bu1,"bush1.bmp");
    iShowBMP(750,dy+bu1,"bush2.bmp");

    iShowBMP(175,dy+bu2,"bush2.bmp");
    iShowBMP(750,dy+bu2,"bush1.bmp");

    iShowBMP(175,dy+bu3,"bush1.bmp");
    iShowBMP(750,dy+bu3,"bush2.bmp");

    iShowBMP(175,dy+bu4,"bush2.bmp");
    iShowBMP(750,dy+bu4,"bush1.bmp");

    iShowBMP(175,dy+bu5,"bush1.bmp");
    iShowBMP(750,dy+bu5,"bush2.bmp");

    iShowBMP(50,bill+dy,"bil1.bmp");
    iShowBMP(825,bill+dy,"bil3.bmp");
    iShowBMP(925,bill+dy,"bil2.bmp");

//////////////river////////////////////

    for(m=1000,n=1500; n<=100000; m+=2000,n+=2000)
    {
        iSetColor(153,76,0);
        double mudx[4]= {0,1000,1000,0};
        double mudy[4]= {m+dy,m+dy,n+dy,n+dy};
        iFilledPolygon(mudx,mudy,4);


        iSetColor(0,128,255);
        double riverx[4]= {0,1000,1000,0};
        double rivery[4]= {m+25+dy,m+25+dy,n-25+dy,n-25+dy};
        iFilledPolygon(riverx,rivery,4);
    }

/////////////////road and raodmarks////////////////

    iSetColor(107,107,107);

    double roadx[4]= {250,750,750,250};
    double roady[4]= {0,0,500,500};
    iFilledPolygon(roadx,roady,4);




    iSetColor(255,255,255);
    double lroadmrx[4]= {275,290,290,275};
    double lroadmry[4]= {0,0,500,500};
    iFilledPolygon(lroadmrx,lroadmry,4);







    iSetColor(255,255,255);
    double rroadmrx[4]= {725,710,710,725};
    double rroadmry[4]= {0,0,500,500};
    iFilledPolygon(rroadmrx,rroadmry,4);





    for(i=50,j=0; i<=1000000; i=i+100,j=j+100)
    {

        iSetColor(204,204,0);
        double midx[4]= {500-7.5,500+7.5,500+7.5,500-7.5};
        double midy[4]= {i+dy,i+dy,j+dy,j+dy};
        iFilledPolygon(midx,midy,4);

        iSetColor(255,255,255);
        double rroadmrx1[4]= {387.5-7.5,387.5+7.5,387.5+7.5,387.5-7.5};
        double rroadmry1[4]= {i+dy,i+dy,j+dy,j+dy};
        iFilledPolygon(rroadmrx1,rroadmry1,4);

        iSetColor(255,255,255);
        double lroadmrx1[4]= {1000-387.5-7.5,1000-387.5+7.5,1000-387.5+7.5,1000-387.5-7.5};
        double lroadmry1[4]= {i+dy,i+dy,j+dy,j+dy};
        iFilledPolygon(lroadmrx1,lroadmry1,4);
    }

    /////////game finish///////
    iSetColor(255,0,0);
    iFilledRectangle(250,399500+dy,500,100);
    iSetColor(255,255,255);
    iFilledRectangle(250,399500+dy,500,10);
    iFilledRectangle(250,399520+dy,500,10);
    iFilledRectangle(250,399540+dy,500,10);
    iFilledRectangle(250,399560+dy,500,10);
    iFilledRectangle(250,399580+dy,500,10);
    if(399600+dy<130) gameover=true;


    ///////////////cars and npc bikes//////////////////////////


    char carindexout[7][7]= {"c1.bmp","c2.bmp","c3.bmp","c4.bmp","c5.bmp","c6.bmp","c7.bmp"};
    char carindexin[7][8]= {"c8.bmp","c9.bmp","c10.bmp","c11.bmp","c12.bmp","c13.bmp","c14.bmp"};


    iShowBMP(310,q+dy+lane1,carindexout[carindx1]);
    iShowBMP(410,r+dy+lane2,carindexout[carindx2]);
    iShowBMP(525,l+dy-lane3,carindexin[carindx3]);
    iShowBMP(625,o+dy-lane4,carindexin[carindx4]);
    if(l+dy-lane3<=0)
    {
        l+=2000+rand()%400;
        carindx3=rand()%7;
    }
    if(o+dy-lane4<=0)
    {
        o+=2000+rand()%400;
        carindx4=rand()%7;
    }

    if(q+dy+lane1<=-900)
    {
        q+=1800;
        carindx1=rand()%7;
    }
    else if(q+dy+lane1>=900)
    {
        q-=1800;
        carindx1=rand()%7;
    }

    if(r+dy+lane2<=-900)
    {
        r+=1800;
        carindx2=rand()%7;
    }
    else if(r+dy+lane2>=900)
    {
        r-=1800;
        carindx2=rand()%7;
    }



    char bikes[9][10]= {"bike1.bmp","bike2.bmp","bike3.bmp","bike4.bmp","bike5.bmp","bike6.bmp","bike7.bmp","bike8.bmp","bike9.bmp"};


    for(ii=0,jj=0,ss=0; ii<9; ii++,jj+=1500,ss+=2)
    {
        if(ii == 0 || ii ==3 || ii==6) bike[ii].bx=260;
        else if(ii == 1 || ii ==4 || ii==7) bike[ii].bx=480;
        else if(ii == 2 || ii ==5 || ii==8) bike[ii].bx=700;
        bike[ii].by=400+jj;
        bike[ii].pos=1;
    }
    for(ii=0; ii<9; ii++)
    {
        iShowBMP(bike[ii].bx, bike[ii].by +dy +bike[ii].speed   ,bikes[ii]);
    }

    for(ii=0; ii<9; ii++)
    {
        if(bike[ii].by +dy +bike[ii].speed < 130) bike[ii].pos=-1;
        else bike[ii].pos=1;


    }

    playerpos=(bike[0].pos+bike[1].pos+bike[2].pos+bike[3].pos+bike[4].pos+bike[5].pos+bike[6].pos+bike[7].pos+bike[8].pos+11)/2;







    ////////sprite/////////////////

    iShowBMP(0,wind+dy,"windmill.bmp");
    iShowBMP(820,wind+dy,"tree2.bmp");
    iShowBMP(930,wind+dy,"tower.bmp");

    if(wind+dy<=0) wind+=4000;


    iShowBMP(0,tower+dy,"column.bmp");
    iShowBMP(100,tower+dy,"1.bmp");
    iShowBMP(960,tower+dy,"rock.bmp");
    iShowBMP(900,tower+dy,"rock.bmp");
    iShowBMP(840,tower+dy,"rock.bmp");
    if(tower+dy<=0) tower+=4000;

    iShowBMP(50,b+dy,"boat_house.bmp");
    iShowBMP(800,b+dy,"boat_housem.bmp");
    if(b+dy<=0) b+=2000;


    iShowBMP(100,palm+dy,"palm.bmp");
    iShowBMP(50,palm+dy,"palm.bmp");
    iShowBMP(0,palm+dy,"palm.bmp");

    iShowBMP(900+25,palm+dy,"palm.bmp");
    iShowBMP(850+25,palm+dy,"palm.bmp");
    iShowBMP(800+25,palm+dy,"palm.bmp");
    if(palm+dy<=0) palm+=2000;



    if((k+dy)<=0)
    {
        k+=500;

        z=z+1;
    }
    if(z%4==0) k+=0;


    else
    {

        iShowBMP(0,k+dy+50,"tree1.bmp");


        iShowBMP(850,k+dy+50,"tree2.bmp");



    };


    /////////player and info////////////



    iShowBMP(450+pic_x,130,"bike.bmp");


    iSetColor(0,0,0);


    iSetColor(0,0,0);
    iFilledRectangle(5,0,235,90);
    iFilledRectangle(755,0,240,90);
    iSetColor(255,255,255);
    iFilledRectangle(15,0,215,80);
    iFilledRectangle(765,0,220,80);
    iSetColor(255,0,0);

    iText(820,60,"CREATED BY:");
    iText(770,35,"MD.MINHAZUR RAHMAN(1605093)");
    iText(780,10,"& PRONOB DAS(1605098)");

    iText(75, 60, " R O A D   ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(75, 35, " R A S H   ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(85, 5, "  2 D ",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0,0,0);
    iFilledCircle(500,-190,315);
    iSetColor(255,255,255);
    iFilledCircle(500,-190,300);
    iSetColor(red,green,blue);
    iFilledRectangle(425,10,150,25);
    iSetColor(0,0,0);
    iFilledRectangle(320,10,85,25);
    iFilledRectangle(595,10,80,25);


    iSetColor(rgb[4][0],rgb[4][1],rgb[4][2]);
    iFilledCircle(605,22.5,5);
    iSetColor(rgb[3][0],rgb[3][1],rgb[3][2]);
    iFilledCircle(620,22.5,5);
    iSetColor(rgb[2][0],rgb[2][1],rgb[2][2]);
    iFilledCircle(635,22.5,5);
    iSetColor(rgb[1][0],rgb[1][1],rgb[1][2]);
    iFilledCircle(650,22.5,5);
    iSetColor(rgb[0][0],rgb[0][1],rgb[0][2]);
    iFilledCircle(665,22.5,5);

    iSetColor(255,255,255);

    switch(sm0)
    {
    case 0:
    {

        iLine(340-15,15,340-15,30);
        iLine(340-15,30,350-15,30);
        iLine(350-15,15,350-15,30);
        iLine(340-15,15,350-15,15);
        break ;
    }
    case 1:
    {
        iLine(345-15,15,345-15,30);
        break ;
    }
    case 2:
    {
        iLine(340-15,30,350-15,30);
        iLine(350-15,30,350-15,22.5);
        iLine(350-15,22.5,340-15,22.5);
        iLine(340-15,22.5,340-15,15);
        iLine(340-15,15,350-15,15);
        break ;
    }
    case 3:
    {
        iLine(350-15,15,350-15,30);
        iLine(340-15,30,350-15,30);
        iLine(350-15,22.5,340-15,22.5);
        iLine(340-15,15,350-15,15);
        break ;
    }

    case 4:
    {
        iLine(340-15,30,340-15,22.5);
        iLine(350-15,22.5,340-15,22.5);
        iLine(350-15,15,350-15,30);
        break ;
    }

    case 5:
    {
        iLine(350-15,22.5,350-15,15);
        iLine(340-15,30,350-15,30);
        iLine(340-15,30,340-15,22.5);
        iLine(350-15,22.5,340-15,22.5);
        iLine(340-15,15,350-15,15);
        break ;
    }

    case 6:
    {
        iLine(340-15,15,340-15,30);
        iLine(340-15,30,350-15,30);
        iLine(340-15,15,350-15,15);
        iLine(350-15,22.5,350-15,15);
        iLine(350-15,22.5,340-15,22.5);
        break ;
    }

    case 7:
    {
        iLine(340-15,30,350-15,30);
        iLine(350-15,15,350-15,30);
        break ;
    }
    case 8:
    {
        iLine(340-15,15,340-15,30);
        iLine(340-15,30,350-15,30);
        iLine(350-15,15,350-15,30);
        iLine(340-15,15,350-15,15);
        iLine(350-15,22.5,340-15,22.5);
        break ;
    }

    case 9:
    {
        iLine(340-15,30,350-15,30);
        iLine(350-15,15,350-15,30);
        iLine(340-15,15,350-15,15);
        iLine(340-15,30,340-15,22.5);
        iLine(350-15,22.5,340-15,22.5);
        break ;
    }
    }

    switch(sm1)
    {
    case 0:
    {

        iLine(340,15,340,30);
        iLine(340,30,350,30);
        iLine(350,15,350,30);
        iLine(340,15,350,15);
        break ;
    }
    case 1:
    {
        iLine(345,15,345,30);
        break ;
    }
    case 2:
    {
        iLine(340,30,350,30);
        iLine(350,30,350,22.5);
        iLine(350,22.5,340,22.5);
        iLine(340,22.5,340,15);
        iLine(340,15,350,15);
        break ;
    }
    case 3:
    {
        iLine(350,15,350,30);
        iLine(340,30,350,30);
        iLine(350,22.5,340,22.5);
        iLine(340,15,350,15);
        break ;
    }

    case 4:
    {
        iLine(340,30,340,22.5);
        iLine(350,22.5,340,22.5);
        iLine(350,15,350,30);
        break ;
    }

    case 5:
    {
        iLine(350,22.5,350,15);
        iLine(340,30,350,30);
        iLine(340,30,340,22.5);
        iLine(350,22.5,340,22.5);
        iLine(340,15,350,15);
        break ;
    }

    case 6:
    {
        iLine(340,15,340,30);
        iLine(340,30,350,30);
        iLine(340,15,350,15);
        iLine(350,22.5,350,15);
        iLine(350,22.5,340,22.5);
        break ;
    }

    case 7:
    {
        iLine(340,30,350,30);
        iLine(350,15,350,30);
        break ;
    }
    case 8:
    {
        iLine(340,15,340,30);
        iLine(340,30,350,30);
        iLine(350,15,350,30);
        iLine(340,15,350,15);
        iLine(350,22.5,340,22.5);
        break ;
    }

    case 9:
    {
        iLine(340,30,350,30);
        iLine(350,15,350,30);
        iLine(340,15,350,15);
        iLine(340,30,340,22.5);
        iLine(350,22.5,340,22.5);
        break ;
    }
    }

    switch(sm2)
    {
    case 0:
    {
        iLine(340+15,15,340+15,30);
        iLine(340+15,30,350+15,30);
        iLine(350+15,15,350+15,30);
        iLine(340+15,15,350+15,15);
        break ;
    }
    case 1:
    {
        iLine(345+15,15,345+15,30);
        break ;
    }
    case 2:
    {
        iLine(340+15,30,350+15,30);
        iLine(350+15,30,350+15,22.5);
        iLine(350+15,22.5,340+15,22.5);
        iLine(340+15,22.5,340+15,15);
        iLine(340+15,15,350+15,15);
        break ;
    }
    case 3:
    {
        iLine(350+15,15,350+15,30);
        iLine(340+15,30,350+15,30);
        iLine(350+15,22.5,340+15,22.5);
        iLine(340+15,15,350+15,15);
        break ;
    }

    case 4:
    {
        iLine(340+15,30,340+15,22.5);
        iLine(350+15,22.5,340+15,22.5);
        iLine(350+15,15,350+15,30);
        break ;
    }
    case 5:
    {
        iLine(350+15,22.5,350+15,15);
        iLine(340+15,30,350+15,30);
        iLine(340+15,30,340+15,22.5);
        iLine(350+15,22.5,340+15,22.5);
        iLine(340+15,15,350+15,15);
        break;
    }
    case 6:
    {
        iLine(340+15,15,340+15,30);
        iLine(340+15,30,350+15,30);
        iLine(340+15,15,350+15,15);
        iLine(350+15,22.5,350+15,15);
        iLine(350+15,22.5,340+15,22.5);
        break ;
    }
    case 7:
    {
        iLine(340+15,30,350+15,30);
        iLine(350+15,15,350+15,30);
        break ;
    }
    case 8:
    {
        iLine(340+15,15,340+15,30);
        iLine(340+15,30,350+15,30);
        iLine(350+15,15,350+15,30);
        iLine(340+15,15,350+15,15);
        iLine(350+15,22.5,340+15,22.5);
        break ;
    }
    case 9:
    {
        iLine(340+15,30,350+15,30);
        iLine(350+15,15,350+15,30);
        iLine(340+15,15,350+15,15);
        iLine(340+15,30,340+15,22.5);
        iLine(350+15,22.5,340+15,22.5);
        break ;
    }
    }


    switch(sm3)
    {
    case 0:
    {
        iLine(340+35,15,340+35,30);
        iLine(340+35,30,350+35,30);
        iLine(350+35,15,350+35,30);
        iLine(340+35,15,350+35,15);
        break ;
    }
    case 1:
    {

        iLine(345+35,15,345+35,30);
        break;
    }
    case 2:
    {
        iLine(340+35,30,350+35,30);
        iLine(350+35,30,350+35,22.5);
        iLine(350+35,22.5,340+35,22.5);
        iLine(340+35,22.5,340+35,15);
        iLine(340+35,15,350+35,15);
        break ;
    }
    case 3:
    {
        iLine(350+35,15,350+35,30);
        iLine(340+35,30,350+35,30);
        iLine(350+35,22.5,340+35,22.5);
        iLine(340+35,15,350+35,15);
        break ;
    }

    case 4:

    {
        iLine(340+35,30,340+35,22.5);
        iLine(350+35,22.5,340+35,22.5);
        iLine(350+35,15,350+35,30);
        break ;
    }

    case 5:

    {
        iLine(350+35,22.5,350+35,15);
        iLine(340+35,30,350+35,30);
        iLine(340+35,30,340+35,22.5);
        iLine(350+35,22.5,340+35,22.5);
        iLine(340+35,15,350+35,15);
        break ;
    }

    case 6:
    {
        iLine(340+35,15,340+35,30);
        iLine(340+35,30,350+35,30);
        iLine(340+35,15,350+35,15);
        iLine(350+35,22.5,350+35,15);
        iLine(350+35,22.5,340+35,22.5);
        break ;
    }

    case 7:
    {
        iLine(340+35,30,350+35,30);
        iLine(350+35,15,350+35,30);
        break ;
    }
    case 8:
    {
        iLine(340+35,15,340+35,30);
        iLine(340+35,30,350+35,30);
        iLine(350+35,15,350+35,30);
        iLine(340+35,15,350+35,15);
        iLine(350+35,22.5,340+35,22.5);
        break;
    }

    case 9:
    {
        iLine(340+35,30,350+35,30);
        iLine(350+35,15,350+35,30);
        iLine(340+35,15,350+35,15);
        iLine(340+35,30,340+35,22.5);
        iLine(350+35,22.5,340+35,22.5);
        break ;
    }

    }

    switch(sm4)
    {
    case 0:
    {
        iLine(340+50,15,340+50,30);
        iLine(340+50,30,350+50,30);
        iLine(350+50,15,350+50,30);
        iLine(340+50,15,350+50,15);
        break ;
    }
    case 1:
    {
        iLine(345+50,15,345+50,30);
        break ;
    }
    case 2:
    {
        iLine(340+50,30,350+50,30);
        iLine(350+50,30,350+50,22.5);
        iLine(350+50,22.5,340+50,22.5);
        iLine(340+50,22.5,340+50,15);
        iLine(340+50,15,350+50,15);
        break ;
    }
    case 3:
    {
        iLine(350+50,15,350+50,30);
        iLine(340+50,30,350+50,30);
        iLine(350+50,22.5,340+50,22.5);
        iLine(340+50,15,350+50,15);
        break ;
    }

    case 4:
    {
        iLine(340+50,30,340+50,22.5);
        iLine(350+50,22.5,340+50,22.5);
        iLine(350+50,15,350+50,30);
        break ;
    }

    case 5:
    {
        iLine(350+50,22.5,350+50,15);
        iLine(340+50,30,350+50,30);
        iLine(340+50,30,340+50,22.5);
        iLine(350+50,22.5,340+50,22.5);
        iLine(340+50,15,350+50,15);
        break ;
    }

    case 6:
    {
        iLine(340+50,15,340+50,30);
        iLine(340+50,30,350+50,30);
        iLine(340+50,15,350+50,15);
        iLine(350+50,22.5,350+50,15);
        iLine(350+50,22.5,340+50,22.5);
        break ;
    }

    case 7:
    {
        iLine(340+50,30,350+50,30);
        iLine(350+50,15,350+50,30);
        break ;
    }
    case 8:
    {
        iLine(340+50,15,340+50,30);
        iLine(340+50,30,350+50,30);
        iLine(350+50,15,350+50,30);
        iLine(340+50,15,350+50,15);
        iLine(350+50,22.5,340+50,22.5);
        break ;
    }

    case 9:
    {
        iLine(340+50,30,350+50,30);
        iLine(350+50,15,350+50,30);
        iLine(340+50,15,350+50,15);
        iLine(340+50,30,340+50,22.5);
        iLine(350+50,22.5,340+50,22.5);
        break ;
    }

    }
    iPoint(370,20,1.5);
    iSetColor(0,0,0);
    iText(470,90,"POSITION");


    iSetColor(0,0,0);
    iFilledRectangle(470,60,60,25);

    iSetColor(255,255,255);

    switch(playerpos)
    {
    case 1:
    {
        iLine(340+145,15+50,340+145,30+50);
        iLine(340+145,30+50,350+145,30+50);
        iLine(350+145,15+50,350+145,30+50);
        iLine(340+145,15+50,350+145,15+50);
        iLine(345+160,15+50,345+160,30+50);
        break ;
    }
    case 2:
    {
        iLine(340+145,15+50,340+145,30+50);
        iLine(340+145,30+50,350+145,30+50);
        iLine(350+145,15+50,350+145,30+50);
        iLine(340+145,15+50,350+145,15+50);
        iLine(340+160,30+50,350+160,30+50);
        iLine(350+160,30+50,350+160,22.5+50);
        iLine(350+160,22.5+50,340+160,22.5+50);
        iLine(340+160,22.5+50,340+160,15+50);
        iLine(340+160,15+50,350+160,15+50);
        break ;
    }
    case 3:
    {
        iLine(340+145,15+50,340+145,30+50);
        iLine(340+145,30+50,350+145,30+50);
        iLine(350+145,15+50,350+145,30+50);
        iLine(340+145,15+50,350+145,15+50);
        iLine(350+160,15+50,350+160,30+50);
        iLine(340+160,30+50,350+160,30+50);
        iLine(350+160,22.5+50,340+160,22.5+50);
        iLine(340+160,15+50,350+160,15+50);
        break ;
    }

    case 4:
    {
        iLine(340+145,15+50,340+145,30+50);
        iLine(340+145,30+50,350+145,30+50);
        iLine(350+145,15+50,350+145,30+50);
        iLine(340+145,15+50,350+145,15+50);
        iLine(340+160,30+50,340+160,22.5+50);
        iLine(350+160,22.5+50,340+160,22.5+50);
        iLine(350+160,15+50,350+160,30+50);
        break ;
    }

    case 5:
    {
        iLine(340+145,15+50,340+145,30+50);
        iLine(340+145,30+50,350+145,30+50);
        iLine(350+145,15+50,350+145,30+50);
        iLine(340+145,15+50,350+145,15+50);
        iLine(350+160,22.5+50,350+160,15+50);
        iLine(340+160,30+50,350+160,30+50);
        iLine(340+160,30+50,340+160,22.5+50);
        iLine(350+160,22.5+50,340+160,22.5+50);
        iLine(340+160,15+50,350+160,15+50);
        break ;
    }

    case 6:
    {
        iLine(340+145,15+50,340+145,30+50);
        iLine(340+145,30+50,350+145,30+50);
        iLine(350+145,15+50,350+145,30+50);
        iLine(340+145,15+50,350+145,15+50);
        iLine(340+160,15+50,340+160,30+50);
        iLine(340+160,30+50,350+160,30+50);
        iLine(340+160,15+50,350+160,15+50);
        iLine(350+160,22.5+50,350+160,15+50);
        iLine(350+160,22.5+50,340+160,22.5+50);
        break ;
    }

    case 7:
    {
        iLine(340+145,15+50,340+145,30+50);
        iLine(340+145,30+50,350+145,30+50);
        iLine(350+145,15+50,350+145,30+50);
        iLine(340+145,15+50,350+145,15+50);
        iLine(340+160,30+50,350+160,30+50);
        iLine(350+160,15+50,350+160,30+50);
        break ;
    }
    case 8:
    {
        iLine(340+145,15+50,340+145,30+50);
        iLine(340+145,30+50,350+145,30+50);
        iLine(350+145,15+50,350+145,30+50);
        iLine(340+145,15+50,350+145,15+50);
        iLine(340+160,15+50,340+160,30+50);
        iLine(340+160,30+50,350+160,30+50);
        iLine(350+160,15+50,350+160,30+50);
        iLine(340+160,15+50,350+160,15+50);
        iLine(350+160,22.5+50,340+160,22.5+50);
        break ;
    }

    case 9:
    {
        iLine(340+145,15+50,340+145,30+50);
        iLine(340+145,30+50,350+145,30+50);
        iLine(350+145,15+50,350+145,30+50);
        iLine(340+145,15+50,350+145,15+50);
        iLine(340+160,30+50,350+160,30+50);
        iLine(350+160,15+50,350+160,30+50);
        iLine(340+160,15+50,350+160,15+50);
        iLine(340+160,30+50,340+160,22.5+50);
        iLine(350+160,22.5+50,340+160,22.5+50);
        break ;
    }
    case 10:
        {
        iLine(345+160-15,15+50,345+160-15,30+50);

        iLine(340+160,15+50,340+160,30+50);
        iLine(340+160,30+50,350+160,30+50);
        iLine(350+160,15+50,350+160,30+50);
        iLine(340+160,15+50,350+160,15+50);
        }
    }


    iSetColor(0,0,0);
    iText(460,40,"BIKE STATUS");
    iText(325,40,"SPEED(km/h)");
    iText(615,40,"NITRO");




    /////natural  deaccelaration/////
    if(c<=0) c=0;
    else c-=.07;

    ///////////game start////////////

    char start[5][7]={"01.bmp","02.bmp","03.bmp","GO.bmp","1.bmp"};

    iShowBMP(400,xx,start[startcount]);



    ////game over//////////

    if(gameover==true)
    {
        c=0;

        iSetColor(255,255,255);
        iFilledRectangle(240,150,520,200);
        iSetColor(255,0,0);
        iText(370,300,"G  A  M  E         O  V  E  R  !  !",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(255,225,"Y O U R      F I N A L      P O S I T I O N     I S  ",GLUT_BITMAP_TIMES_ROMAN_24);


    iSetColor(255,0,0);


    switch(playerpos)
    {
    case 1:
    {
        iLine(340+145,15+150,340+145,30+150);
        iLine(340+145,30+150,350+145,30+150);
        iLine(350+145,15+150,350+145,30+150);
        iLine(340+145,15+150,350+145,15+150);
        iLine(345+160,15+150,345+160,30+150);
        break ;
    }
    case 2:
    {
        iLine(340+145,15+150,340+145,30+150);
        iLine(340+145,30+150,350+145,30+150);
        iLine(350+145,15+150,350+145,30+150);
        iLine(340+145,15+150,350+145,15+150);
        iLine(340+160,30+150,350+160,30+150);
        iLine(350+160,30+150,350+160,22.5+150);
        iLine(350+160,22.5+150,340+160,22.5+150);
        iLine(340+160,22.5+150,340+160,15+150);
        iLine(340+160,15+150,350+160,15+150);
        break ;
    }
    case 3:
    {
        iLine(340+145,15+150,340+145,30+150);
        iLine(340+145,30+150,350+145,30+150);
        iLine(350+145,15+150,350+145,30+150);
        iLine(340+145,15+150,350+145,15+150);
        iLine(350+160,15+150,350+160,30+150);
        iLine(340+160,30+150,350+160,30+150);
        iLine(350+160,22.5+150,340+160,22.5+150);
        iLine(340+160,15+150,350+160,15+150);
        break ;
    }

    case 4:
    {
        iLine(340+145,15+150,340+145,30+150);
        iLine(340+145,30+150,350+145,30+150);
        iLine(350+145,15+150,350+145,30+150);
        iLine(340+145,15+150,350+145,15+150);
        iLine(340+160,30+150,340+160,22.5+150);
        iLine(350+160,22.5+150,340+160,22.5+150);
        iLine(350+160,15+150,350+160,30+150);
        break ;
    }

    case 5:
    {
        iLine(340+145,15+150,340+145,30+150);
        iLine(340+145,30+150,350+145,30+150);
        iLine(350+145,15+150,350+145,30+150);
        iLine(340+145,15+150,350+145,15+150);
        iLine(350+160,22.5+150,350+160,15+150);
        iLine(340+160,30+150,350+160,30+150);
        iLine(340+160,30+150,340+160,22.5+150);
        iLine(350+160,22.5+150,340+160,22.5+150);
        iLine(340+160,15+150,350+160,15+150);
        break ;
    }

    case 6:
    {
        iLine(340+145,15+150,340+145,30+150);
        iLine(340+145,30+150,350+145,30+150);
        iLine(350+145,15+150,350+145,30+150);
        iLine(340+145,15+150,350+145,15+150);
        iLine(340+160,15+150,340+160,30+150);
        iLine(340+160,30+150,350+160,30+150);
        iLine(340+160,15+150,350+160,15+150);
        iLine(350+160,22.5+150,350+160,15+150);
        iLine(350+160,22.5+150,340+160,22.5+150);
        break ;
    }

    case 7:
    {
        iLine(340+145,15+150,340+145,30+150);
        iLine(340+145,30+150,350+145,30+150);
        iLine(350+145,15+150,350+145,30+150);
        iLine(340+145,15+150,350+145,15+150);
        iLine(340+160,30+150,350+160,30+150);
        iLine(350+160,15+150,350+160,30+150);
        break ;
    }
    case 8:
    {
        iLine(340+145,15+150,340+145,30+150);
        iLine(340+145,30+150,350+145,30+150);
        iLine(350+145,15+150,350+145,30+150);
        iLine(340+145,15+150,350+145,15+150);
        iLine(340+160,15+150,340+160,30+150);
        iLine(340+160,30+150,350+160,30+150);
        iLine(350+160,15+150,350+160,30+150);
        iLine(340+160,15+150,350+160,15+150);
        iLine(350+160,22.5+150,340+160,22.5+150);
        break ;
    }

    case 9:
    {
        iLine(340+145,15+150,340+145,30+150);
        iLine(340+145,30+150,350+145,30+150);
        iLine(350+145,15+150,350+145,30+150);
        iLine(340+145,15+150,350+145,15+150);
        iLine(340+160,30+150,350+160,30+150);
        iLine(350+160,15+150,350+160,30+150);
        iLine(340+160,15+150,350+160,15+150);
        iLine(340+160,30+150,340+160,22.5+150);
        iLine(350+160,22.5+150,340+160,22.5+150);
        break ;
    }
    case 10:
        {
        iLine(345+160-15,15+150,345+160-15,30+150);

        iLine(340+160,15+150,340+160,30+150);
        iLine(340+160,30+150,350+160,30+150);
        iLine(350+160,15+150,350+160,30+150);
        iLine(340+160,15+150,350+160,15+150);
        }
    }
    }

    }

    /*
    	function iMouseMove() is called when the user presses and drags the mouse.
    	(mx, my) is the position where the mouse pointer is.
    	*/
    void iMouseMove(int mx, int my)
    {
        //place your codes here
    }

    /*
    	function iMouse() is called when the user presses/releases the mouse.
    	(mx, my) is the position where the mouse pointer is.
    	*/
    void iMouse(int button, int state, int mx, int my)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            //place your codes here
        }
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {
            //place your codes here
        }
    }

    /*
    	function iKeyboard() is called whenever the user hits a key in keyboard.
    	key- holds the ASCII value of the key pressed.
    	*/
    int nitro_count=-1;
    void iKeyboard(unsigned char key)
    {
        if (key == 'x')
        {
            //do something with 'x'
            exit(0);
        }


        if (key=='n')
        {
            nitro_count++;
            rgb[nitro_count][0]=rgb[nitro_count][1]=rgb[nitro_count][2]=255;
            if(nitro_count>4) maxspeed=55;
            else maxspeed=85;



        }

        if (key=='N')
        {
            nitro_count++;
            rgb[nitro_count][0]=rgb[nitro_count][1]=rgb[nitro_count][2]=255;
            if(nitro_count>4) maxspeed=55;
            else maxspeed=85;



        }


        //place your codes for other keys here
    }
    /*
    	function iSpecialKeyboard() is called whenver user hits special keys like-
    	function keys, home, end, pg up, pg down, arraows etc. you have to use
    	appropriate constants to detect them. A list is:
    	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
    	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEwY_F12,
    	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
    	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
    	*/

    void iSpecialKeyboard(unsigned char key)
    {

        if (key == GLUT_KEY_END)
        {
            exit(0);
        }

        if (key == GLUT_KEY_LEFT )
        {
            if(pic_x+475<=285 || c<=0) pic_x-=0;
            else
            {
                pic_x-=10;
                mid=2;
            }
        }
        if (key == GLUT_KEY_RIGHT)
        {
            if(pic_x+475>=720 || c<=0) pic_x-=0;
            else
            {
                pic_x+=10;
                mid=1;
            }

        }

if(gameon==true && gameover==false) {

        if (key == GLUT_KEY_UP)

        {


            if(c>=maxspeed)
            {
                c=maxspeed;
                mid=0;
            }
            else if(maxspeed > 55 && c>=84)
            {
                c-=.01;
                nitro=1;
            }
            else if(nitro==1 && c>=55) c-=.01;
            else if(c<55 && nitro==1)
            {
                maxspeed=55;
                c+=.4;
                nitro=0;
            }


            //else if(c==30.5) {nitro=0;maxspeed=30;}

            else
            {
                c+=.4;
            }


    }
}
        if (key == GLUT_KEY_DOWN)

        {
            if(c<=0) c=0;
            else c-=1;

        }
        //place your codes for other keys here
    }
    int counter=0;
    void collision()

    {

        if   (((450+pic_x + 40 > 310 && 450+pic_x < 310 + 60) && (130 + 80 > q+dy+lane1 && 130 < q+dy+lane1 + 120))
                ||((450+pic_x + 40 > 410 && 450+pic_x < 410 + 60) && (130 + 80 > r+dy+lane2 && 130 < r+dy+lane2 + 120))
                ||((450+pic_x + 40 > 525 && 450+pic_x < 525 + 60) && (130 + 80 > l+dy-lane3 && 130 < l+dy-lane3 + 120))
                ||((450+pic_x + 40 > 625 && 450+pic_x < 625 + 60) && (130 + 80 > o+dy-lane4 && 130 < o+dy-lane4 + 120)))
        {
            {
                counter++;
                c=0;
                pic_x=30;
            }
            if(counter==1) red=128;
            if(counter==2)
            {
                red=150;
                green=200;
            }
            if(counter==3)
            {
                red=255;
                green=255;
            }
            if(counter==4)
            {
                red=200;
                green=150;
            }
            if(counter==5)
            {
                red=255;
                green=128;
            }
            if(counter==6)  green=0;
            if(counter==7)  gameover=true;

        }
        else
        {

            for(ii=0; ii<9; ii++)
            {

                if((450+pic_x + 40 > bike[ii].bx && 450+pic_x < bike[ii].bx + 40) && (130 + 80 > bike[ii].by +dy +bike[ii].speed  && 130 < bike[ii].by +dy +bike[ii].speed  + 80))


                {
                    counter++;
                    c=0;
                    pic_x=30;
                }
                if(counter==1) red=128;
                if(counter==2)
                {
                    red=150;
                    green=200;
                }
                if(counter==3)
                {
                    red=255;
                    green=255;
                }
                if(counter==4)
                {
                    red=200;
                    green=150;
                }
                if(counter==5)
                {
                    red=255;
                    green=128;
                }
                if(counter==6)  green=0;
                if(counter==7)  gameover=true;
            }
        }

    }

void car_bike_speed ()
  {


    if(gameon==true && gameover==false){
        dy-=c;
        lane1+=ln1;
        lane2+=ln2;
        lane3+=ln3;
        lane4+=ln4;


        for(ii=0,jj=0; ii<9; ii++,jj+=5)
        {
            bike[ii].speed +=npcbikespeed+jj;
        }

        if(l+dy-lane4<=0) ln4=4+rand()%20;
        if(l+dy-lane3<=0) ln3=6+rand()%15;

        if((q+dy+lane1<=-700) || (q+dy+lane1>=700)) ln1=4+rand()%20;
        if((r+dy+lane2<=-700) || (r+dy+lane2>=700)) ln2=6+rand()%15;



}
    }


    void speedmeter()
    {
        double tsm=c*200;
        sm0=(int)tsm/10000;
        tsm=(int)tsm%10000;
        sm1=(int)tsm/1000;
        tsm=(int)tsm%1000;
        sm2=(int)tsm/100;
        tsm=(int)tsm%100;
        sm3=(int)tsm/10;
        sm4=(int)tsm%10;


    }


 void gamestart()
    {
        if(gameon==false){
        startcount++;
        if(startcount>3) {gameon=true;xx=600;}
        }
    }






    int main()
    {
        //place your own initialization codes here.
        pic_x = 30;
        pic_y = 20;

        iSetTimer(10,car_bike_speed);
        iSetTimer(10,collision);
        iSetTimer(10,speedmeter);
        iSetTimer(1000,gamestart);
        iInitialize(1000, 500, "Road Rush");


        return 0;
    }
