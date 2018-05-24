/*td2 exo12 clement caumes*/
#include"graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1;
	POINT p2;
	POINT p3;
	p1.y=100;
	p2.y=100;
	p1.x=lire_entier_clavier();
	p2.x=lire_entier_clavier();
	draw_line(p1,p2,blanc);
	draw_fill_circle(p1,5,bleu);
	draw_fill_circle(p2,5,rouge);
	p3.y=lire_entier_clavier();
	p3.x=((p2.x + p1.x)/2);
	draw_line(p1,p3,bleu);
	draw_line(p2,p3,rouge);
	draw_fill_circle(p3,5,blanc);
	
	
	
	
	wait_escape();
	exit(0);	
}
