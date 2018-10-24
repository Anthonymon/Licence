//exo31 td6 clement caumes
#include "graphics.h"

void dessine_line_H(COULEUR c)
{
	POINT p1;
	POINT p2;
	p1.x=0;p1.y=100;
	p2.x=900;p2.y=100;
	while(p1.y<600){
		draw_line(p1,p2,c);
		p1.y=p1.y+100;
		p2.y=p2.y+100;
		}
}

void dessine_line_V(COULEUR c)
{
	POINT p1;
	POINT p2;
	p1.x=100; p1.y=0;
	p2.x=100; p2.y=600;
	while(p1.x<900){
		draw_line(p1,p2,c);
		p1.x=p1.x+100;
		p2.x=p2.x+100;
		}
}

void dessine_quadrillage(COULEUR c)
{
	dessine_line_H(c);
	dessine_line_V(c);
}

int main ()
{
	init_graphics(900,600);
	dessine_quadrillage(blanc);
	
	
	wait_escape();
	exit(0);
}
	
