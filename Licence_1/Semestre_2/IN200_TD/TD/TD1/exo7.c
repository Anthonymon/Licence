//clement caumes td1 exo6
#include "graphics.h"

POINT init_balle(int x,int y){
	POINT p;
	p.x=x;p.y=y;
	return p;
}

POINT deplace_balle(POINT ancien,int x,int y){
	draw_fill_circle(ancien,25,noir);
	affiche_all();
	ancien=init_balle(ancien.x+x,ancien.y+y);
	
	draw_fill_circle(ancien,25,bleu);
	return ancien;
}

int main(){
	affiche_auto_off();
	init_graphics(900,600);
	POINT p;
	p=init_balle(50,50);
	draw_fill_circle(p,25,bleu);
	int i;
	POINT p2;
	for(i=0;i<1000;i++){
		attendre(10);
		p2=deplace_balle(p,2,4);
		p=init_balle(p2.x,p2.y);
	}
	wait_escape();
	exit(0);
}
