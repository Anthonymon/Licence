/*td4 exo24 clement caumes*/
#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1,p2;
	p1.x=450;p1.y=0;
	p2.x=450;p2.y=600;
	draw_line(p1,p2,blanc);
	
	/*POINT p3;
	p3=wait_clic();
	while(p3.x<450){
		draw_fill_circle(p3,50,bleu);
		p3=wait_clic();
				} */
	/*POINT p3;
	p3=wait_clic();
	int coups;
	coups=1;
	int condition;
	condition=1;
	for(coups=1;condition==1;coups=coups+1)
	{
		if(p3.x<450)
		{
			draw_fill_circle(p3,50,bleu);
		}
		else if(p3.x>=450)
		{
			condition=0;
		}
			p3=wait_clic();
	}*/
	
	POINT p3;
	p3=wait_clic();
	int i;
	i=0;
	for(i=0;p3.x<450;i++)
	{
		draw_fill_circle(p3,50,bleu);
		p3=wait_clic();
	}
	
	wait_escape();
	exit(0);
}
