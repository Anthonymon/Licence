#include "graphics.h"

COULEUR T1[256];

void remplir_gris(){
	int i;
	for(i=0;i<256;i++){
		T1[i]=couleur_RGB(i,i,i);
	}
}

void affiche_horizontal(){
	int i;
	POINT p;
	POINT p1;
	for(i=0;i<256;i++){
		p.x=2*i;p.y=0;
		p1.x=p.x+2;p1.y=HEIGHT;
		draw_fill_rectangle(p,p1,T1[i]);
	}
}

int main(){
	init_graphics(500,256);
	remplir_gris();
	affiche_horizontal();
	
	wait_escape();
	exit(0);
}

