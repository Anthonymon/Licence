#include "graphics.h"

COULEUR T2[256][256];

void remplir_rouge_bleu(){
	int i,j;
	for(i=0;i<256;i++){
		for(j=0;j<256;j++){
			affiche_auto_off();
			T2[i][j]=couleur_RGB(i,0,j);
			
		}
		affiche_auto_on();
	}
	//affiche_auto_on();
}

void affiche_horizontal(){
	int i,j;
	POINT p;
	
	for(i=0;i<256;i++){
		for(j=0;j<256;j++){
			p.x=i;p.y=j;
			draw_pixel(p,T2[i][j]);
		}
	}
}

int main(){
	init_graphics(256,256);
	remplir_rouge_bleu();
	affiche_horizontal();
	
	wait_escape();
	exit(0);
}
