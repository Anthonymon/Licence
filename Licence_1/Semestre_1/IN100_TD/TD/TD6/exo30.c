//exo30 td6 clement caumes
#include "graphics.h"

void dessine_cercle_couleur(int rayon)
{
	POINT p1;
	p1=wait_clic();
	draw_fill_circle(p1,rayon,rouge);
	POINT p2;
	p2=wait_clic();
	int compteur;
	compteur=0;
	int distancePoint;
	distancePoint=distance(p1,p2);
	while(distancePoint<rayon){
		if ((compteur%3)==0){
			draw_fill_circle(p1,rayon,bleu);
		}
		else if ((compteur%3)==1){
			draw_fill_circle(p1,rayon,blanc);
		}
		else if ((compteur%3)==2){
			draw_fill_circle(p1,rayon,rouge);
		}
		compteur++;
		p2=wait_clic();
		distancePoint=distance(p1,p2);
	}
	wait_escape();
	exit(0);	
}


int main ()
{
	init_graphics(900,600);
	int rayonCercle;
	rayonCercle=lire_entier_clavier();
	dessine_cercle_couleur(rayonCercle);
	
	wait_escape();
	exit(0);
}
