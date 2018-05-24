#include "graphics.h"

POINT T[10];
POINT pUtilisateur;
int i;

int main(){
	init_graphics(600,600);
	for(i=0;i<10;i++){
		pUtilisateur=wait_clic();
		T[i]=pUtilisateur;
		draw_fill_circle(T[i],10,rouge);
	}
	
	for(i=9;i>=0;i--){
		wait_clic();
		draw_fill_circle(T[i],10,bleu);
	}
	
	wait_escape();
	exit(0);
}
