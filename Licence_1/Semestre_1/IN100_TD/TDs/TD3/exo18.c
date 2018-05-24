/*td3 exo18 clement caumes*/
#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1,p2;
	p1.x=450;p1.y=0;
	p2.x=450;p2.y=600;
	draw_line(p1,p2,blanc);
	p1.x=0;p1.y=300;
	p2.x=900;p2.y=300;
	draw_line(p1,p2,blanc);
	
	POINT p3;
	p3=wait_clic();
	if(((p3.y>300)&&(p3.x<450))||((p3.y<300)&&(p3.x>450))){
		draw_fill_circle(p3,50,bleu);
			}
	else{
		draw_fill_circle(p3,50,rouge);
		}
	
	
	wait_escape();
	exit(0);
}
