//clement caumes td1 exo1

#include "graphics.h"

void dessine_croix(POINT p,int longueur){
	POINT p1,p2,p3;
	p1.x=p.x;p1.y=p.y+longueur;
	p2.x=p.x+longueur;p2.y=p.y+longueur;
	p3.x=p.x+longueur;p3.y=p.y;
	draw_line(p,p1,blanc);
	draw_line(p,p2,blanc);
	draw_line(p,p3,blanc);
	draw_line(p1,p3,blanc);
	draw_line(p1,p2,blanc);
	draw_line(p2,p3,blanc);
}

void dessine_croix2(POINT p,int longueur,int ligne,int colonne){
	int i,j;
	POINT pIntermediaire;
	for(i=0;i<colonne;i++){
		pIntermediaire.x=p.x;pIntermediaire.y=p.y;
		pIntermediaire.y=pIntermediaire.y+longueur;
		for(j=0;j<ligne;j++){
			dessine_croix(p,longueur);
			p.x=p.x+longueur;
		}
		p.x=pIntermediaire.x;p.y=pIntermediaire.y;	
	}
}

int main(){
	init_graphics(900,600);
	POINT pUtilisateur;
	pUtilisateur=wait_clic();
	dessine_croix2(pUtilisateur,40,5,6);
	wait_escape();
	exit(0);
}
