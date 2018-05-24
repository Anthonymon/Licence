#include "graphics.h"

COULEUR T2[512][512];

void remplir_rouge_bleu(){
	int i,j;
	for(i=0;i<512;i++){
		for(j=0;j<512;j++){
			T2[i][j]=couleur_RGB(j,0,i);
		}
	}
}

void affiche_horizontal(){
	int i,j;
	POINT p;
	POINT p1;
	/*for(i=0;i<512;i++){
		for(j=0;j<512;j++){
		p.x=0;p.y=2*i;
		p1.x=WIDTH;p1.y=p.y+2;
		//p.x=0;p.y=2*i;
		//p1.x=p.x+2;p1.y=2*i;
		draw_fill_rectangle(p,p1,T2[i][j]);
		}
	}*/
	for(i=0;i<512;i++){
		for(j=0;j<512;j++){
			affiche_auto_off();
			p.x=2*i;p.y=2*j;
			p1.x=p.x+2;p1.y=p.y+2;
			draw_fill_rectangle(p,p1,T2[i][j]);
			affiche_auto_on();
		}
	}
}

int main(){
	//affiche_auto_off();
	init_graphics(512,512);
	remplir_rouge_bleu();
	affiche_horizontal();
	
	wait_escape();
	exit(0);
}

