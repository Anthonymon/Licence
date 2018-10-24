#include "graphics.h"

struct balle{
	POINT centre;
	int rayon;
	COULEUR coul;
	int dx,dy;
};
typedef struct balle BALLE;

BALLE init_balle(POINT p,int taille,COULEUR couleur,int abscisse,int ordonnee){
	BALLE boule1;
	boule1.centre=p;
	boule1.rayon=taille;
	boule1.coul=couleur;
	boule1.dx=abscisse;
	boule1.dy=ordonnee;
	return boule1;
}

BALLE deplace_balle(BALLE B){
	POINT p=B.centre;
	p.x=p.x+B.dx;
	p.y=p.y+B.dy;
	B.centre=p;
	return B;
}

void efface_balle(BALLE B){
	draw_fill_circle(B.centre,B.rayon,noir);
}

void affiche_balle(BALLE B){
	draw_fill_circle(B.centre,B.rayon,B.coul);
}

BALLE rebond_balle(BALLE B){
	POINT p;
	p=B.centre;
	
	if(((p.y+B.rayon)>=HEIGHT)||((p.y-B.rayon)<=0)){
		B.dy=-B.dy;
	}
	else if(((p.x+B.rayon)>=WIDTH)||((p.x-B.rayon)<=0)){
		B.dx=-B.dx;
	}
	return B;
}

int main(){
	init_graphics(900,600);
	BALLE b1;
	POINT centre1; //centre ou commence ma balle
	centre1.x=450;centre1.y=300;
	int taille1=25; //taille de la balle
	COULEUR couleurBalle=rouge;
	int abscisse1=2;
	int ordonnee1=3;
	b1=init_balle(centre1,taille1,couleurBalle,abscisse1,ordonnee1);
	
	int i;
	i=1;
	while(i==1){
		attendre(1);
		efface_balle(b1);
		
		b1=deplace_balle(b1);
		b1=rebond_balle(b1);
		
		affiche_balle(b1);
	}
	
	wait_escape();
	exit(0);
}
