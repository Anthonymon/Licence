/*td3 exo21 clement caumes*/

#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1;
	p1=wait_clic();
	
	if(((p1.x%2)==0)&&((p1.y%2)==0)){
		draw_fill_circle(p1,50,rouge);
		}
		
	else if(((p1.x%2)==1)&&((p1.y%2)==1)){
		draw_fill_circle(p1,50,vert);
		}
		
	else if(((p1.x%2)==1)&&((p1.y%2)==0)){
		draw_fill_circle(p1,50,bleu);
		}
		
	else{
		draw_fill_circle(p1,50,jaune);
			}
	
	wait_escape();
	exit(0);
}
