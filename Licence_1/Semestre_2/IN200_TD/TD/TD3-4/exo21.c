#include "graphics.h"

int score;
struct raquette{
	POINT centre;
	int demiLongueur;
	int demiLargeur;
	COULEUR coul;
};
typedef struct raquette RAQUETTE;

struct balle{
	POINT centre;
	int rayon;
	COULEUR coul;
	int dx,dy;
};
typedef struct balle BALLE;

RAQUETTE init_raquette(POINT centre1,COULEUR coul1,int demiLargeur1,int demiLongueur1){
	RAQUETTE raq;
	raq.centre=centre1;
	raq.coul=coul1;
	raq.demiLargeur=demiLargeur1;
	raq.demiLongueur=demiLongueur1;
	return raq;
}

BALLE init_balle(POINT p,int taille,COULEUR couleur,int abscisse,int ordonnee){
	BALLE boule1;
	boule1.centre=p;
	boule1.rayon=taille;
	boule1.coul=couleur;
	boule1.dx=abscisse;
	boule1.dy=ordonnee;
	return boule1;
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

void affiche_balle(BALLE B){
	draw_fill_circle(B.centre,B.rayon,B.coul);
	POINT p;
	p.x=15;p.y=HEIGHT-10;
	aff_int(score,40,p,vert);
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

void efface_balle(BALLE B){
	draw_fill_circle(B.centre,B.rayon,noir);
	POINT p1,p2;
	p1.x=0;p1.y=HEIGHT-100;
	p2.x=100;p2.y=HEIGHT;
	draw_fill_rectangle(p1,p2,noir);
}

RAQUETTE deplace_raquette(RAQUETTE R,int dx){
	//RAQUETTE R;
	POINT pCentre,test;
	pCentre=R.centre;
	test.x=pCentre.x+5*dx; //modification du centre
	test.y=test.y;
	POINT bg,hd;
	bg.x=test.x-R.demiLongueur;bg.y=test.y-R.demiLargeur;
	hd.x=test.x+R.demiLongueur;hd.y=test.y+R.demiLargeur;
	if((bg.x<0)||(hd.x>WIDTH)){
		return R;
	}
	else {
		R.centre.x=pCentre.x+5*dx;
		return R;
	}
}

int choc(BALLE balle1,RAQUETTE raquette1){
	POINT p1,p2;
	POINT inter1,inter2;
	POINT inter3,inter4;
	POINT inter5;
	inter5=raquette1.centre;
	inter1=balle1.centre; //point du centre de la balle
	inter2=raquette1.centre; //point du centre de la balle
	p1.x=inter1.x;p1.y=inter1.y-balle1.rayon; //point qui correspond au bas de la balle
	p2.x=inter2.x;p2.y=inter2.y+raquette1.demiLargeur; //point qui correspond au haut du centre de la raquette
	inter3=raquette1.centre;
	inter3.x=inter5.x-raquette1.demiLongueur; //point en haut a gauche
	inter3.y=inter5.y+raquette1.demiLargeur;
	inter4.x=inter5.x+raquette1.demiLongueur; //point en haut a droite
	inter4.y=inter5.y+raquette1.demiLargeur;
	if((p1.y<=inter2.y+raquette1.demiLargeur)&&(p1.x>=inter3.x)&&(p1.x<=inter4.x)){
		p1.x=WIDTH+1;p1.y=HEIGHT+1;
		p2.x=WIDTH+2;p2.y=HEIGHT+2;
		draw_pixel(p1,black);
		draw_pixel(p2,black);
		return 1;
	}
	else {return 0;}
}

BALLE rebond_balle(BALLE B,RAQUETTE raq){
	POINT p;
	p=B.centre;
	int test;
	test=choc(B,raq);
	
	if(((p.y+B.rayon)>=HEIGHT)/*||((p.y-B.rayon)<=0)*/){
		B.dy=-B.dy;
	}
	else if(((p.x+B.rayon)>=WIDTH)||((p.x-B.rayon)<=0)){
		B.dx=-B.dx;
	}
	else if(test==1){
		B.dy=-B.dy;
	}
	else if(((p.y-B.rayon)==0)||(p.y-B.rayon==-1)||(p.y-B.rayon==-2)){
		score--;
	}
	
	return B;
}

BALLE deplace_balle(BALLE B){
	POINT p=B.centre;
	p.x=p.x+B.dx;
	p.y=p.y+B.dy;
	B.centre=p;
	return B;
}


int main(){
	init_graphics(900,600);
	affiche_auto_off();
	score=3;
	
	RAQUETTE raquetteJeu; //initialisation raquette et de ses parametres
	
	
	BALLE balleJeu; //initialisation balle et de ses parametres
	
	
	while(score>0){
		
		POINT p;
		p.x=WIDTH/2;
		p.y=40;
		COULEUR coulRaq=red;
		int hauteur=5;
		int longueurDemi=50;
		raquetteJeu=init_raquette(p,coulRaq,hauteur,longueurDemi); /////
		
		POINT p1;
		p1.x=WIDTH/2;p1.y=HEIGHT/2;
		int tailleBalleJeu=25;
		COULEUR coulBalleJeu=bleu;
		int deplacementX=2;
		int deplacementY=3;
		balleJeu=init_balle(p1,tailleBalleJeu,coulBalleJeu,deplacementX,deplacementY);
		
		affiche_raquette(raquetteJeu); //affichage de la raquette
		affiche_balle(balleJeu);
		wait_clic();
	
		POINT pointArrow;
		int i=1;
		while(i==1){ //boucle infinie 
			pointArrow=get_arrow();
			efface_raquette(raquetteJeu);
			efface_balle(balleJeu);
			raquetteJeu=deplace_raquette(raquetteJeu,pointArrow.x);
			balleJeu=deplace_balle(balleJeu);
			balleJeu=rebond_balle(balleJeu,raquetteJeu);
			affiche_raquette(raquetteJeu);
			attendre(3);
			affiche_balle(balleJeu);
			if(score==2){i=2;}
			affiche_all();
		}
	}
	
	
	wait_escape();
	exit(0);
}
