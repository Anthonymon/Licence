//td7 exo37 clement caumes
#include "graphics.h"

POINT centre, centre_precedent;

void efface_affiche(){
	draw_fill_circle(centre_precedent,30,noir);
	draw_fill_circle(centre,30,bleu);
}

void plus_ou_moins(POINT p){
	centre_precedent.x=centre.x;
	centre_precedent.y=centre.y;
	
	if(p.y>centre.y){
		centre.y=centre.y+2;}
	else if(p.y<centre.y){
		centre.y=centre.y-2;}
}

int main (){
	int i;
	POINT utilisateur;
	init_graphics(400,400);
	centre_precedent.x=0;
	centre_precedent.y=0;
	centre.x=200;
	centre.y=200;
	
	for(i=0;i<20;i++)
	{
		utilisateur=wait_clic();
		plus_ou_moins(utilisateur);
		efface_affiche();
	}

	wait_clic();
	exit(0);}
