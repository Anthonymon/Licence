#include "graphics.h"

int main(){
	init_graphics(900,600);
	POINT pUtilisateur;
	POINT p1;
	POINT p2;
	p1.x=435;p1.y=285;
	p2.x=465;p2.y=315;
	draw_fill_rectangle(p1,p2,blanc);
	pUtilisateur.x=435;pUtilisateur.y=315;
	aff_pol(" 6",20,pUtilisateur,rouge);
	wait_escape();
	exit(0);
}
