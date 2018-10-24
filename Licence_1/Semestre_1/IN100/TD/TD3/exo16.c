/*td3 exo16 clement caumes*/
#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1;
	POINT p2;
	p1.x=450;p1.y=0;
	p2.x=450;p2.y=600;
	draw_line(p1,p2,blanc);
	
	POINT p3;
	POINT p4;
	p3=wait_clic();
	p4=wait_clic();
	
	if(((p3.x<450)||(p4.x<450))&&((p3.x>450)||(p4.x>450))){
		draw_line(p3,p4,rouge);
		}
	else{
		draw_line(p3,p4,bleu);
		}
	
	wait_escape();
	exit(0);
}

