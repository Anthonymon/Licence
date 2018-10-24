#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1;
	POINT p2;
	p1=wait_clic();
	int compteur;
	compteur=1;
	
	while((compteur<10)){
		if((compteur%4)==1)
		{
			draw_fill_circle(p1,50,bleu);
		}
		
		else if(((compteur)%4)==2)
		{
			draw_fill_circle(p1,50,rouge);
		}
		
		else if((compteur%4)==3)
		{
			draw_fill_circle(p1,50,vert);
		}
		
		else if((compteur%4)==0)
		{
			draw_fill_circle(p1,50,jaune);
		}
		
		p2=wait_clic();
		draw_fill_circle(p1,50,noir);
		compteur++;
		p1.x=p2.x;p1.y=p2.y;
	}
	
	wait_escape();
	exit(0);
}
