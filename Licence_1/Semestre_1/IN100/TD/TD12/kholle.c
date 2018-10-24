#include "graphics.h"

int compteurDroit=0;
int compteurGauche=0;
POINT le_plus_haut1;
POINT le_plus_haut2;
COULEUR couleur;

POINT au_centre(POINT P){
	P.x=300;P.y=P.y;
	return P;
}

void aff(POINT p){
	if(p.x<300){
		p=au_centre(p);
		draw_fill_circle(p,50,bleu);
		compteurGauche++;
		if(le_plus_haut1.y<p.y){
			le_plus_haut1.y=p.y;
			couleur=bleu;
		}
	}
	else if(p.x>300){
		p=au_centre(p);
		draw_fill_circle(p,50,rouge);
		compteurDroit++;
		if(le_plus_haut2.y<p.y){
			le_plus_haut2.y=p.y;
			couleur=rouge;
		}
	}
	if(le_plus_haut1.y<le_plus_haut2.y){
		couleur=bleu;
	}
	else {couleur=rouge;}
	
}

int main(){
	init_graphics(600,400);
	POINT p1,p2;
	POINT pUtilisateur;
	le_plus_haut1.y=0;
	le_plus_haut2.y=0;
	
	p1.x=300;p1.y=0;
	p2.x=300;p2.y=400;
	draw_line(p1,p2,blanc);
	pUtilisateur=wait_clic();
	aff(pUtilisateur);
	
	while((compteurDroit!=compteurGauche)||(couleur==rouge)){
		pUtilisateur=wait_clic();
		aff(pUtilisateur);
	}
	
	wait_escape();
	exit(0);
}

