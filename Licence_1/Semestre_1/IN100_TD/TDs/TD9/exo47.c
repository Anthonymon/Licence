#include "graphics.h"

int main(){
	
	init_graphics(900,600);
	
	POINT tableau [10];
	POINT pause;
	
	int compteur;
	POINT p1;
	
	for(compteur=0;compteur<10;compteur++){
		p1=wait_clic();
		draw_fill_circle(p1,10,rouge);
		tableau[compteur]=p1;
	}


	for(compteur=9;compteur>=0;compteur--){
		pause=wait_clic();
		draw_fill_circle((tableau[compteur]),10,noir);
	}
	
	wait_escape();
	exit(0);
}
