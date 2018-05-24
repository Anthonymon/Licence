/*td4 exo26 clement caumes*/
#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1,p2;
	p1.x=350;p1.y=200;
	p2.x=550;p2.y=400;
	draw_fill_rectangle(p1,p2,jaune);
	
	/*POINT p3;
	p3=wait_clic();
	int coups;
	coups=1;
	
	while((p3.x>350)&&(p3.x<550)&&(p3.y>200)&&(p3.y<400))
	{
		
		
				if((coups%2)==1)
					{ 
					p1.x=351;p1.y=201;
					p2.x=549;p2.y=399;
					draw_fill_rectangle(p1,p2,noir);
					}
				else if((coups%2)==0)
					{
					p1.x=351;p1.y=201;
					p2.x=549;p2.y=399;
					draw_fill_rectangle(p1,p2,jaune);
					}
		coups=coups+1;
		p3=wait_clic();
	
	}*/
	
	POINT p3;
	p3=wait_clic();
	int i;
	i=0;
	int compteur;
	compteur=0;
	for(i=0;((p3.x<550)&&(p3.x>350)&&(p3.y<400)&&(p3.y>200));i++)
	{
		if((compteur%2)==0)
		{
			p1.x=351;p1.y=201;
			p2.x=549;p2.y=399;
			draw_fill_rectangle(p1,p2,noir);
		}
		else if((compteur%2)==1)
		{
			p1.x=351;p1.y=201;
			p2.x=549;p2.y=399;
			draw_fill_rectangle(p1,p2,jaune);
		}
		compteur++;
		p3=wait_clic();
	}
	
	
	wait_escape();
	exit(0);
}
