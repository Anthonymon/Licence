//clement caumes td1 exo2

#include "graphics.h"

void mon_draw_triangle(POINT p1,POINT p2,POINT p3,COULEUR c){
	draw_line(p1,p2,c);
	draw_line(p2,p3,c);
	draw_line(p1,p3,c);
}
void mon_draw_triangle_from_clic(COULEUR c){
	POINT p1,p2,p3;
	p1=wait_clic();
	p2=wait_clic();
	p3=wait_clic();
	mon_draw_triangle(p1,p2,p3,c);
}

int main(){
	init_graphics(900,600);
	int i;
	POINT p1,p2,p3;
	for(i=0;i<10;i++){
		p1=wait_clic();
		p2=wait_clic();
		p3=wait_clic();
		mon_draw_triangle(p1,p2,p3,rouge);
	}
	for(i=0;i<10;i++){
		mon_draw_triangle_from_clic(bleu);
	}
	wait_escape();
	exit(0);
}
