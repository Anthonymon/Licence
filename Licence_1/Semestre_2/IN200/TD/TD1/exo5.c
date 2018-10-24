//clement caumes td1 exo5

#include "graphics.h"

void efface_affiche(POINT ancien,POINT nouveau){
	draw_fill_circle(ancien,25,noir);
	affiche_all();
	draw_fill_circle(nouveau,25,rouge);
	affiche_all();
}

int main(){
	init_graphics(900,600);
	affiche_auto_off();
	POINT p;
	POINT p1;
	p.x=50;p.y=50;
	draw_fill_circle(p,25,rouge);
	int i;
	for(i=0;i<10000;i++){
		//wait_clic();
		attendre(10);
		p1.x=p.x+2;p1.y=p.y+3;
		efface_affiche(p,p1);
		p.x=p1.x;p.y=p1.y;
	}
	wait_escape();
	exit(0);
}
