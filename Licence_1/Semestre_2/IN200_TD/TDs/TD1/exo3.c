//clement caumes td1 exo3

#include "graphics.h"

void efface_affiche(POINT ancien,POINT nouveau){
	draw_fill_circle(ancien,25,noir);
	draw_fill_circle(nouveau,25,rouge);
}

int main(){
	init_graphics(900,600);
	POINT p1,p2;
	p1=wait_clic();
	p2=wait_clic();
	draw_fill_circle(p1,25,bleu);
	wait_clic();
	efface_affiche(p1,p2);
	wait_clic();
	exit(0);
}
