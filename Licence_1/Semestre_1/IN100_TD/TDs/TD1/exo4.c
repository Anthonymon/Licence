/*td1 exercice 4 clement caumes 25/09*/

#include"graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1;
	POINT p2;
	p1=wait_clic();
	draw_fill_circle(p1,100,blanc);
	p2=wait_clic();
	draw_fill_circle(p1,100,noir);
	draw_fill_circle(p2,100,blanc);
	p1=wait_clic();
	draw_fill_circle(p2,100,noir);
	draw_fill_circle(p1,100,blanc);
	p2=wait_clic();
	draw_fill_circle(p1,100,noir);
	draw_fill_circle(p2,100,blanc);
	
	p1=wait_clic();
	draw_fill_circle(p2,100,noir);
	draw_fill_circle(p1,100,blanc);
	p2=wait_clic();
	draw_fill_circle(p1,100,noir);
	draw_fill_circle(p2,100,blanc);
	
	p1=wait_clic();
	draw_fill_circle(p2,100,noir);
	draw_fill_circle(p1,100,blanc);
	p2=wait_clic();
	draw_fill_circle(p1,100,noir);
	draw_fill_circle(p2,100,blanc);
	
	p1=wait_clic();
	draw_fill_circle(p2,100,noir);
	draw_fill_circle(p1,100,blanc);
	p2=wait_clic();
	draw_fill_circle(p1,100,noir);
	draw_fill_circle(p2,100,blanc);
	
	wait_escape();
	exit(0);
}
