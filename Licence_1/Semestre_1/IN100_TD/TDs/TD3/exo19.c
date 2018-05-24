/*td3 exo19 clement caumes*/
#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1,p2;
	p1.x=300;p1.y=0;
	p2.x=300;p2.y=600;
	draw_line(p1,p2,blanc);
	p1.x=600;p1.y=0;
	p2.x=600;p2.y=600;
	draw_line(p1,p2,blanc);
	
	POINT p3;
	p3=wait_clic();
	if((p3.x<300)||(p3.x>600)){
		draw_fill_circle(p3,50,bleu);
		}
	else{
		draw_fill_circle(p3,50,blanc);
		}
	
	wait_escape();
	exit(0);
}
