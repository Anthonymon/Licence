/*td2 exo13 clement caumes*/
#include"graphics.h"
int main()
{
	init_graphics(900,600);
	POINT c;
	POINT p1;
	POINT p2;
	c=wait_clic();
	draw_circle(c,100,blanc);
	int donneesX1;
	donneesX1=100*0.5+c.x;
	int donneesY1; 
	donneesY1=100*0.86+c.y;
	p1.x=donneesX1;
	p1.y=donneesY1;
	p2.x=(c.x+100);
	p2.y=(c.y);
	draw_line(p1,p2,blanc);
	int donneesX2;
	int donneesY2;
	donneesX2=c.x-100*0.5;
	donneesY2=c.y+100*0.86;
	p2.x=donneesX2;
	p2.y=donneesY2;
	draw_line(p1,p2,blanc);
	donneesX1=c.x-100;
	donneesY1=c.y;
	p1.x=donneesX1;
	p1.y=donneesY1;
	draw_line(p1,p2,blanc);
	donneesY2=c.y-100*0.86;
	p2.x=donneesX2;
	p2.y=donneesY2;
	draw_line(p1,p2,blanc);
	donneesX1=c.x+100*0.5;
	donneesY1=c.y-100*0.86;
	p1.x=donneesX1;
	p1.y=donneesY1;
	draw_line(p2,p1,blanc);
	donneesX2=c.x+100;
	donneesY2=c.y;
	p2.x=donneesX2;
	p2.y=donneesY2;
	draw_line(p1,p2,blanc);
	
	wait_escape();
	exit(0);
}
