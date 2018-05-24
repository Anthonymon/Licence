#include "graphics.h"

int main()
{
	init_graphics(900,600);
	POINT p1,p2;
	p1.x=450;p1.y=0;
	p2.x=450;p2.y=600;
	draw_line(p1,p2,blanc);
	
	int compteur;
	compteur=0;
	POINT pUtilisateur;


	int compteurRouge;
	compteurRouge=0;
	
	while(compteur<20){
		pUtilisateur=wait_clic();
		if(pUtilisateur.x<450){
			draw_fill_circle(pUtilisateur,50,rouge);
			compteurRouge++;
			compteur++;
		}
		if(pUtilisateur.x>450){
			if(compteurRouge>0){
				draw_fill_circle(pUtilisateur,50,bleu);
				compteur++;
			}
		compteurRouge=0;
		}
	}
	wait_escape();
	exit(0);
}
