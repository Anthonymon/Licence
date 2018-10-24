#include "graphics.h"

int main(){
	init_graphics(600,600);
	POINT p;
	p.x=60;
	p.y=550;
	aff_pol("TIC TAC TOE",75,p,vert);
	POINT p1,p2;
	p1.x=100;p1.y=300;
	p2.x=250;p2.y=335;
	POINT ecriture;
	ecriture.x=135;
	ecriture.y=333;
	draw_fill_rectangle(p1,p2,bleu);
	aff_pol("1 joueur",20,ecriture,rouge);
	
	wait_clic();
	
	wait_escape();
	exit(0);
}
