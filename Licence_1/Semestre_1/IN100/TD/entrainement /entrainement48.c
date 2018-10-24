#include "graphics.h"

POINT T[10];
POINT pUtilisateur;
int i;


int compteur=0;

int main(){
	init_graphics(600,600);
	for(i=0;i<10;i++){
		pUtilisateur=wait_clic();
		T[i]=pUtilisateur;
		draw_fill_circle(T[i],10,rouge);
	}
	
	while(compteur<10){
		pUtilisateur=wait_clic();
		for(i=0;i<10;i++){
			if(distance(pUtilisateur,T[i])<10){
				draw_fill_circle(T[i],10,noir);
				T[i].x=10000;T[i].y=100000;
				for(i=0;i<10;i++){
					draw_fill_circle(T[i],10,rouge);
				}
				compteur++;
				
			}
		}
	}
	wait_escape();
	exit(0);
}
