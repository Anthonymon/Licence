//clement caumes td1 exo6
#include "graphics.h"

POINT deplace_balle(POINT ancien,int x,int y){
	draw_fill_circle(ancien,25,noir);
	affiche_all();
	ancien.x=ancien.x+x;
	ancien.y=ancien.y+y;
	draw_fill_circle(ancien,25,bleu);
	return ancien;
}

int main(){
	affiche_auto_off();
	init_graphics(900,600);
	POINT p;
	p.x=50;p.y=50;
	draw_fill_circle(p,25,bleu);
	int i;
	POINT p2;
	for(i=0;i<1000;i++){
		attendre(10);
		p2=deplace_balle(p,2,4);
		p.x=p2.x;p.y=p2.y;
	}
	wait_escape();
	exit(0);
}
