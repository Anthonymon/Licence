//td8 exo42 clement caumes
#include "graphics.h"

//partie 2

void dessine_case_blanche(POINT p){
	POINT p1,p2;
	p1.x=p.x;p1.y=p.y;
	p2.x=p.x+50;p2.y=p.y+50;
	draw_fill_rectangle(p1,p2,blanc);
}

void dessine_ligne_impaire(POINT p){
	while(p.x<400){
	if(((p.x)%100)==0){
		p.x=p.x+50;}
	else if(((p.x)%100)==50){
		dessine_case_blanche(p);
		p.x=p.x+50;}
	}
}

void dessine_ligne_paire(POINT p){
	while(p.x<400){
		if(((p.x)%100)==0){
			dessine_case_blanche(p);
			p.x=p.x+50;}
		else if(((p.x)%100)==50){
			p.x=p.x+50;}
		}
	}

int main()
{
	init_graphics(400,400);
	POINT pDebut;
	pDebut.x=0;pDebut.y=0;
	while(pDebut.y<400){
		if(((pDebut.y)%100)==0){
			dessine_ligne_impaire(pDebut);
		}
		else if(((pDebut.y)%100)==50){
			dessine_ligne_paire(pDebut);
		}
	pDebut.x=0;pDebut.y=pDebut.y+50;
	}
	
	wait_escape();
	exit(0);
}
