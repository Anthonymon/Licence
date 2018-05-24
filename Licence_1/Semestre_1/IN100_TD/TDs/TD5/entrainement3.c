#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1;
	POINT p2;
	p1=wait_clic();
	p2.x=p1.x-50;p2.y=p1.y-50;
	draw_fill_rectangle(p1,p2,bleu);
	POINT p3;
	POINT p4;
	p3=wait_clic();
	p4.x=p3.x-50;p4.y=p3.y-50;
	draw_fill_rectangle(p3,p4,rouge);
	
	if((p3.x>p1.x)&&(p4.x<p1.x)&&(p3.y>p1.y)&&(p4.y<p1.y))
	{
		draw_fill_rectangle(p1,p4,magenta);
	}
	
	else if((p1.x>p3.x)&&(p2.x<p3.x)&&(p1.y>p3.y)&&(p2.y<p3.y))
	{
		draw_fill_rectangle(p2,p3,magenta);
	}
	
	wait_escape();
	exit(0);
}
