#include "graphics.h"

POINT T[10];
POINT pUtilisateur;
int i;

int main(){
	init_graphics(900,600);
	for(i=0;i<10;i++){
		pUtilisateur=wait_clic();
		T[i]=pUtilisateur;
		draw_fill_circle(pUtilisateur,10,rouge);
	}
	wait_clic();
	for(i=0;i<10;i++){
		draw_fill_circle(T[i],10,bleu);
	}
	wait_escape();
	exit(0);
}
