#include "graphics.h"

int main(){
	
	init_graphics(900,600);
	
	POINT tableau [10];
	POINT pause;
	
	int compteur;
	int compteur2;
	compteur2=0;
	POINT p1;
	
	for(compteur=0;compteur<10;compteur++){
		p1=wait_clic();
		draw_fill_circle(p1,10,rouge);
		tableau[compteur]=p1;
	}

	while(compteur2<10){
		pause=wait_clic();
		for(compteur=0;compteur<10;compteur++){
			if(distance(pause,(tableau[compteur]))<10){
				draw_fill_circle((tableau[compteur]),10,noir);
				tableau[compteur].x=1000;tableau[compteur].y=10000;
				compteur2++;
			}
		}
		
}
	wait_escape();
	exit(0);
}
