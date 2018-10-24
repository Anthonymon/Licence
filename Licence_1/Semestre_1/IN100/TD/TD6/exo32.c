//td 6 exo32 clement caumes
#include "graphics.h"

POINT p;
void dessine_couleurs()
{
	POINT p1;
	POINT p2;
	p1.x=700;p1.y=0;
	p2.x=750;p2.y=50;
	draw_fill_rectangle(p1,p2,rouge);
	p1.x=800;p1.y=0;
	draw_fill_rectangle(p1,p2,bleu);
	p2.x=850;p2.y=50;
	draw_fill_rectangle(p1,p2,vert);
	p1.x=900;p1.y=0;
	draw_fill_rectangle(p1,p2,jaune);
}

COULEUR choix_couleur(POINT p)
{
	if ((p.x<700)&&(p.y>50)){
		return noir;}
		
	else {
	if ((p.x>700)&&(p.x<750)){
		return rouge;}
	else if ((p.x>750)&&(p.x<800)){
		return bleu;}
	else if ((p.x>800)&&(p.x<850)){
		return vert;}
	else if ((p.x>850)&&(p.x<900)){
		return jaune;}
	}
	
}

void dessine_cercle()
{
	COULEUR couleurCercle;
	p=wait_clic();
	couleurCercle=choix_couleur(p);
	POINT p2;
	p2=wait_clic();
	draw_fill_circle(p2,50,couleurCercle);
}

int main()
{
	init_graphics(900,600);
	dessine_couleurs();
	int compteur;
	compteur=0;
	while(compteur<20){
		dessine_cercle();
		compteur++;
	}
	
	wait_escape();
	exit(0);
}
