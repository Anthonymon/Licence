#include "graphics.h"

int main(){
	init_graphics(900,600);
	POINT p1,p2;
	POINT pUtilisateur;
	int compteur;
	compteur=0;
	p1.x=450;p1.y=0;
	p2.x=450;p2.y=600;
	draw_line(p1,p2,blanc);
	pUtilisateur=wait_clic();
	while((pUtilisateur.x<900)&&(pUtilisateur.y<600)){
		if(pUtilisateur.x<450){
			draw_fill_circle(pUtilisateur,20,rouge);
			compteur++;
		}
		else if ((pUtilisateur.x>450)&&(compteur>0)){
			draw_fill_circle(pUtilisateur,20,bleu);
		}
		pUtilisateur=wait_clic();
	}
	
	
	wait_escape();
	exit(0);
}
