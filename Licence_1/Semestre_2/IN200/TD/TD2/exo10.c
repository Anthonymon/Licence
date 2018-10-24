#include "graphics.h"

COULEUR T1[256];

void remplir_gris(){
	int i;
	for(i=0;i<256;i++){
		T1[i]=couleur_RGB(i,i,i);
	}
}

int main(){
	init_graphics(900,600);
	remplir_gris();
	
	wait_escape();
	exit(0);
}
