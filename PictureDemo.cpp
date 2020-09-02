#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"


int pic_x, pic_y;
int rgb[3]={0,0,255};
/*
	function iDraw() is called again and again by the system.
	*/
void iDraw() {
	//place your drawing codes here


	iClear();

	//iShowBMP(pic_x, pic_y, "3.bmp");


	//iShowBMP2(pic_x, pic_y+50, "horse2.bmp",0);

	//iShowBMP2(pic_x, pic_y, "pacman2.bmp",-1);

	//iShowBMP2(pic_x+60, pic_y+60, "pacman2.bmp",-1);

	double x1[3]={1,485,1};
	double y1[3]={150,400,400};
	double x2[3]={1200-200,1200-685,1200-200};
	double y2[3]={150,400,400};
	iSetColor(0,255,0);
	iFilledPolygon(x1,y1,3);
	iFilledPolygon(x2,y2,3);
	double hx[6]={0,0,485,1200-685,1000,1000};
	double hy[6]={0,150,400,400,150,0};
	iSetColor(105,105,105);
	iFilledPolygon(hx,hy,6);
	iSetColor(255,255,255);
	double lroadmarksx[4]={0,497,495,0};
	double lroadmarksy[4]={10,400,400,60};
	iFilledPolygon(lroadmarksx,lroadmarksy,4);
	double rroadmarksx[4]={1000,1200-697,1200-695,1000};
	double rroadmarksy[4]={10,400,400,60};
	iFilledPolygon(rroadmarksx,rroadmarksy,4);
	//iLine(1200,200,1200-450,600);
	//iFilledRectangle(200+pic_x,200+pic_y,100,100);
	iShowBMP(0, 400, "3.bmp");
	iShowBMP(pic_x+500, pic_y, "1.bmp");


	iText(10, 10, "Use cursors to move the picture.");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
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
	if (key == 'x') {
		//do something with 'x'
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

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	if (key == GLUT_KEY_LEFT) {
		pic_x-=5;
	}
	if (key == GLUT_KEY_RIGHT) {
		pic_x+=5;
	}
	if (key == GLUT_KEY_UP) {
		pic_y+=5;
	}
	if (key == GLUT_KEY_DOWN) {
		pic_y-=5;
	}
	//place your codes for other keys here
}

int main() {
	//place your own initialization codes here.
	pic_x = 30;
	pic_y = 20;
	iInitialize(1200-200, 700, "Road Rash");
	return 0;
}
