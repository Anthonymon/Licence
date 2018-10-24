/*td3 exo15 clement caumes*/
#include "graphics.h"
int main ()
{
	init_graphics(900,600);
	POINT p1;
	POINT p2;
	p1.x=450;p1.y=0;
	p2.x=450;p2.y=600;
	draw_line(p1,p2,blanc);
	
	POINT p3;
	POINT p4;
	int donneesX4;
	int donneesY4;
	p3=wait_clic();
	
	if(p3.x<450){
		draw_fill_circle(p3,50,bleu);
		donneesX4=900-p3.x;
		donneesY4=p3.y;
		p4.x=donneesX4;p4.y=donneesY4;
		draw_fill_circle(p4,50,rouge);
				}
				
	else{
		draw_fill_circle(p3,50,rouge);donneesX4=900-p3.x;
		donneesY4=p3.y;
		p4.x=donneesX4;p4.y=donneesY4;
		draw_fill_circle(p4,50,bleu);
	}
	wait_escape();
	exit(0);
}

