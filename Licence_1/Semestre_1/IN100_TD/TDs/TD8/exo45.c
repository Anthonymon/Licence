#include "graphics.h"

int main()
{
	init_graphics(512,512);
	POINT p1;
	POINT p2;
	p1.x=0;p1.y=0;
	p2.x=2;p2.y=512;
	COULEUR degrade;
	int r;
	r=0;
	int b;
	b=512;
	
	while(p2.x<=512){
		degrade=couleur_RGB(r,0,b);
		draw_fill_rectangle(p1,p2,degrade);
		r++;
		b--;
		p1.x=p2.x;p2.x=p2.x+2;
		
	}
	wait_escape();
	exit(0);
}
