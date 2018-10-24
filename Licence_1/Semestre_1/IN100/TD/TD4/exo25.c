/*td4 exo25 clement caumes*/
#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1,p2;
	p1.x=350;p1.y=200;
	p2.x=550;p2.y=400;
	draw_fill_rectangle(p1,p2,jaune);
	
	
	/*wait_clic();
	
	int coups;
	coups=0;
	while (coups<10){
		coups=coups+1;
		if((coups%2)==1){
			p1.x=351;p1.y=201;
			p2.x=549;p2.y=399;
			draw_fill_rectangle(p1,p2,noir);
		}
		else if((coups%2)==0){
			p1.x=351;p1.y=201;
			p2.x=549;p2.y=399;
			draw_fill_rectangle(p1,p2,jaune);
		}
	wait_clic();
	}
	*/
	wait_clic();
	
	int coups;
	coups=1;
	for(coups=1;coups<10;coups=coups+1)
	{
		if((coups%2)==1){
			p1.x=351;p1.y=201;
			p2.x=549;p2.y=399;
			draw_fill_rectangle(p1,p2,noir);
		}
		
		else if((coups%2)==0){
			p1.x=351;p1.y=201;
			p2.x=549;p2.y=399;
			draw_fill_rectangle(p1,p2,jaune);
		}
		wait_clic();
	}
	
	wait_escape();
	exit(0);
}
