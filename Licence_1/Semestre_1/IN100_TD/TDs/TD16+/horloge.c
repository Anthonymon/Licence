#include "graphics.h"

int main(){
	init_graphics(900,600);
	POINT p1,p2;
	p1.x=450;p1.y=250;
	p2.x=450;p2.y=350;
	draw_line(p1,p2,blanc);
	p1.x=450;p1.y=300;
	p2.x=500;p2.y=300;
	draw_line(p1,p2,blanc);
	
	wait_escape();
	exit(0);
}
