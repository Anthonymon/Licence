/*td3 exo17 clement caumes*/
#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1,p2;
	p1.x=450;p1.y=0;
	p2.x=450;p2.y=600;
	draw_line(p1,p2,blanc);
	
	POINT p3,p4,p5;
	p3=wait_clic();
	p4=wait_clic();
	p5=wait_clic();
	
	if((p3.x<450)&&(p4.x<450)&&(p5.x<450)){
		draw_triangle(p3,p4,p5,blanc);
		}
		
	wait_escape();
	exit(0);
}
