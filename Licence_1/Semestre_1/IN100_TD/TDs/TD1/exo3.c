/*td 1 exercice 3 clement caumes 25/09*/

#include "graphics.h"
int main()
{
	/*debut parties 1 et 2
	init_graphics(600,400);
	POINT p1;
	POINT p2;
	p1.x=0;p1.y=0;
	p2.x=600;p2.y=0;
	draw_line(p1,p2,blanc);
	p1.x=0;p1.y=100;
	p2.x=600;p2.y=100;
	draw_line(p1,p2,blanc);
	p1.x=0;p1.y=200;
	p2.x=600;p2.y=200;
	draw_line(p1,p2,blanc);
	p1.x=0;p1.y=300;
	p2.x=600;p2.y=300;
	draw_line(p1,p2,blanc);
	p1.x=0;p1.y=400;
	p2.x=600;p2.y=400;
	draw_line(p1,p2,blanc);
	fin parties 1 et 2*/
	
	/*debut parties 3 et 4*/
	init_graphics(400,400);
	POINT p1;
	POINT p2;
	p1.x=50;p1.y=0;
	p2.x=100;p2.y=50;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=150;p1.y=100;
	draw_fill_rectangle(p1,p2,blanc);
	p2.x=200;p2.y=150;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=250;p1.y=200;
	draw_fill_rectangle(p1,p2,blanc);
	p2.x=300;p2.y=250;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=350;p1.y=300;
	draw_fill_rectangle(p1,p2,blanc);
	p2.x=400;p2.y=350;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=150;p1.y=0;
	p2.x=200;p2.y=50;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=250;p1.y=100;
	draw_fill_rectangle(p1,p2,blanc);
	p2.x=300;p2.y=150;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=350;p1.y=200;
	draw_fill_rectangle(p1,p2,blanc);
	p2.x=400;p2.y=250;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=250;p1.y=0;
	p2.x=300;p2.y=50;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=350;p1.y=100;
	draw_fill_rectangle(p1,p2,blanc);
	p2.x=400;p2.y=150;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=350;p1.y=0;
	p2.x=400;p2.y=50;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=0;p1.y=50;
	p2.x=50;p2.y=100;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=100;p1.y=150;
	draw_fill_rectangle(p1,p2,blanc);
	p2.x=150;p2.y=200;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=200;p1.y=250;
	draw_fill_rectangle(p1,p2,blanc);
	p2.x=250;p2.y=300;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=300;p1.y=350;
	draw_fill_rectangle(p1,p2,blanc);
	p2.x=350;p2.y=400;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=0;p1.y=150;
	p2.x=50;p2.y=200;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=100;p1.y=250;
	draw_fill_rectangle(p1,p2,blanc);
	p2.x=150;p2.y=300;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=200;p1.y=350;
	draw_fill_rectangle(p1,p2,blanc);
	p2.x=250;p2.y=400;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=0;p1.y=250;
	p2.x=50;p2.y=300;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=100;p1.y=350;
	draw_fill_rectangle(p1,p2,blanc);
	p2.x=150;p2.y=400;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=0;p1.y=350;
	p2.x=50;p2.y=400;
	draw_fill_rectangle(p1,p2,blanc);
	
	
	
	
	
	
	
	
	
	wait_escape();
	exit(0);
}
	
