/*tp 1 exercice 2 clement caumes 25/09/15*/

#include "graphics.h"
int main()
{
	init_graphics(900,600);
	
	/*debut partie 1
	POINT p1;
	POINT p2;
	POINT p3;
	p1.x=101;p1.y=350;
	p2.x=899;p2.y=350;
	p3.x=500;p3.y=350;
	draw_line(p1,p2,blanc);
	draw_circle(p1,100,bleu);
	draw_circle(p2,100,rouge);
	draw_circle(p3,100,blanc);
	fin partie 1*/
	
	/*debut partie 2
	POINT p1;
	POINT p2;
	p1.x=0;p1.y=0;
	p2.x=600;p2.y=0;
	draw_line(p1,p2,bleu);
	p1.x=0;p1.y=120;
	p2.x=600;p2.y=120;
	draw_line(p1,p2,blanc);
	p1.x=0;p1.y=240;
	p2.x=600;p2.y=240;
	draw_line(p1,p2,rouge);
	p1.x=0;p1.y=360;
	p2.x=600;p2.y=360;
	draw_line(p1,p2,jaune);
	p1.x=0;p1.y=480;
	p2.x=600;p2.y=480;
	draw_line(p1,p2,orange);
	fin partie 2*/
	
	/*debut partie 3
	POINT p1;
	POINT p2;
	p1.x=20;p1.y=20;
	p2.x=40;p2.y=40;
	draw_rectangle(p1,p2,blanc);
	fin partie 3*/
	
	/*debut partie 4
	POINT p1;
	POINT p2;
	p1.x=200;p1.y=200;
	p2.x=300;p2.y=200;
	draw_line(p1,p2,magenta);
	p2.x=200;p2.y=300;
	draw_line(p1,p2,jaune);
	p1.x=300;p1.y=300;
	draw_line(p1,p2,orange);
	p2.x=300;p2.y=200;
	draw_line(p1,p2,rouge);
	fin partie 4*/
	
	/*debut partie 5
	POINT p1;
	POINT p2;
	p1.x=95;p1.y=195;
	p2.x=145;p2.y=145;
	draw_line(p1,p2,blanc);
	p2.x=145;p2.y=195;
	draw_line(p1,p2,blanc);
	p2.x=95;p2.y=145;
	draw_line(p1,p2,blanc);
	p1.x=145;p1.y=145;
	draw_line(p1,p2,blanc);
	p2.x=145;p2.y=195;
	draw_line(p1,p2,blanc);
	p1.x=95;p1.y=145;
	draw_line(p1,p2,blanc);
	fin partie 5*/
	
	/*debut partie 6*/
	POINT p1;
	POINT p2;
	p1.x=450;p1.y=300;
	draw_circle(p1,100,blanc);
	p1.x=550;p1.y=300;
	p2.x=500;p2.y=386;
	draw_line(p1,p2,blanc);
	p2.x=500;p2.y=214;
	draw_line(p1,p2,blanc);
	p1.x=400;p1.y=214;
	draw_line(p1,p2,blanc);
	p2.x=350;p2.y=300;
	draw_line(p1,p2,blanc);
	p1.x=400;p1.y=386;
	draw_line(p1,p2,blanc);
	p2.x=500;p2.y=386;
	draw_line(p1,p2,blanc);
	/*fin partie 6*/
	
	
	wait_escape();
	exit(0);
}
