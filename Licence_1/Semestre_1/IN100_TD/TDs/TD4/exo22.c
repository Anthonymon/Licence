/*td4 exo22 clement caumes*/
#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1;
	POINT p2;
	p1.x=100;p1.y=0;
	p2.x=100;p2.y=600;
	
	/*while(p1.x<900){
		draw_line(p1,p2,blanc);
		p1.x=p1.x+100;
		p2.x=p2.x+100;
	}*/
	
	for(p1.x=100;p1.x<900;p1.x=p1.x+100)
		{
			draw_line(p1,p2,blanc);
			p2.x=p2.x+100;
		}
	
	wait_escape();
	exit(0);
}
