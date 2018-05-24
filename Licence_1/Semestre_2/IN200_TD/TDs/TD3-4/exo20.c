#include "graphics.h"

struct raquette{
	POINT centre;
	int demiLongueur;
	int demiLargeur;
	COULEUR coul;
};
typedef struct raquette RAQUETTE;

RAQUETTE init_raquette(POINT centre1,COULEUR coul1,int demiLargeur1,int demiLongueur1){
	RAQUETTE raq;
	raq.centre=centre1;
	raq.coul=coul1;
	raq.demiLargeur=demiLargeur1;
	raq.demiLongueur=demiLongueur1;
	return raq;
}
	
	
void affiche_raquette(RAQUETTE raquet){
	POINT p1,p2;
	POINT centreRaquet=raquet.centre;
	p1.x=centreRaquet.x-raquet.demiLongueur;
	p1.y=centreRaquet.y-raquet.demiLargeur;
	p2.x=centreRaquet.x+raquet.demiLongueur;
	p2.y=centreRaquet.y+raquet.demiLargeur;
	draw_fill_rectangle(p1,p2,raquet.coul);
}

void efface_raquette(RAQUETTE raquet){
	POINT p1,p2;
	POINT centreRaquet=raquet.centre;
	p1.x=centreRaquet.x-raquet.demiLongueur;
	p1.y=centreRaquet.y-raquet.demiLargeur;
	p2.x=centreRaquet.x+raquet.demiLongueur;
	p2.y=centreRaquet.y+raquet.demiLargeur;
	draw_fill_rectangle(p1,p2,noir);
}

RAQUETTE deplace_raquette(RAQUETTE R,int dx){
	POINT p3;
	p3=R.centre;
	p3.x=p3.x+dx; //modification du centre;
	R.centre=p3;
	return R;
	
}


int main(){
	init_graphics(900,600);
	affiche_auto_off();
	RAQUETTE raquetteJeu;
	POINT p;
	p.x=WIDTH/2;
	p.y=40;
	COULEUR coulRaq=red;
	int hauteur=5;
	int longueurDemi=50;
	raquetteJeu=init_raquette(p,coulRaq,hauteur,longueurDemi);
	affiche_raquette(raquetteJeu);
	int i=1;
	POINT pointArrow;
	while(i==1){
		pointArrow=get_arrow();
		efface_raquette(raquetteJeu);
		raquetteJeu=deplace_raquette(raquetteJeu,pointArrow.x);
		affiche_raquette(raquetteJeu);
		affiche_all();
	}
	
	wait_escape();
	exit(0);
}
