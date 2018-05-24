#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1;
	POINT p2;
	p1=wait_clic();
	p2=wait_clic();
	draw_fill_rectangle(p1,p2,jaune);
	
	POINT p3;
	p3=wait_clic();
	POINT p4;
	POINT p5;
	int compteur;
	compteur=1;
	
	if((p2.x<p1.x)&&(p2.y<p1.y))
	{
		POINT pointInter;
		pointInter.x=p2.x;pointInter.y=p2.y;
		p2.x=p1.x;p2.y=p1.y;
		p1.x=pointInter.x;p1.y=pointInter.y;
		
	}
	
	while(((p3.x<p2.x)&&(p3.x>p1.x)&&(p3.y<p2.y)&&(p3.y>p1.y)))
		{
			p4.x=p1.x+1;p4.y=p1.y+1;
			p5.x=p2.x-1;p5.y=p2.y-1;
			
			if((compteur%2)==1)
			{
				draw_fill_rectangle(p4,p5,noir);
			}
			else if((compteur%2)==0)
			{
				draw_fill_rectangle(p4,p5,jaune);
			}
			compteur=compteur+1;
			p3=wait_clic();
		}
	wait_escape();
	exit(0);
}
