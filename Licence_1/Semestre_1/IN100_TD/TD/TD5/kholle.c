#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1,p2,p4;
	p4.x=450;p4.y=300;
	p1.x=100;p1.y=0;
	p2.x=150;p2.y=50;
	draw_fill_rectangle(p1,p2,vert);
	p1.x=425;p1.y=0;
	p2.x=475;p2.y=50;
	draw_fill_rectangle(p1,p2,jaune);
	p1.x=750;p1.y=0;
	p2.x=800;p2.y=50;
	draw_fill_rectangle(p1,p2,bleu);
	
	POINT p3;
	p3=wait_clic();
	
	while((((p3.x>100)&&(p3.x<150))||((p3.x>425)&&(p3.x<475))||((p3.x>750)&&(p3.x<800)))&&(p3.y<50))
	{
		
		if((p3.x>100)&&(p3.x<150))
		{
			draw_fill_circle(p4,50,vert);
		}
		
		else if ((p3.x>425)&&(p3.x<475))
		{
			draw_fill_circle(p4,50,jaune);
		}
		
		else if ((p3.x>750)&&(p3.x<800))
		{
			draw_fill_circle(p4,50,bleu);
		}
		
		p3=wait_clic();
	}
	
	wait_escape();
	exit(0);	
}
