//td7 exo36 clement caumes
#include "graphics.h"

int a_qui_de_jouer;
POINT centre;

void quadrillage(){
	POINT p1;
	POINT p2;
	p1.x=100;p1.y=0;
	p2.x=100;p1.y=300;
	draw_line(p1,p2,blanc);
	p1.x=200;p1.y=0;
	p2.x=200;p2.y=300;
	draw_line(p1,p2,blanc);
	p1.x=0;p1.y=100;
	p2.x=300;p2.y=100;
	draw_line(p1,p2,blanc);
	p1.x=0;p1.y=200;
	p2.x=300;p2.y=200;
	draw_line(p1,p2,blanc);
}

void calcul_du_centre(POINT p){
	if(p.x<100){
		if(p.y<100){
			centre.x=50;centre.y=50;}
		else if ((p.y>100)&&(p.y<200)){
			centre.x=50;centre.y=150;}
		else if (p.y>200){
			centre.x=50;centre.y=250;}
	}

	if((p.x>100)&&(p.x<200)){
		if(p.y<100){
			centre.x=150;centre.y=50;}
		else if ((p.y>100)&&(p.y<200)){
			centre.x=150;centre.y=150;}
		else if (p.y>200){
			centre.x=150;centre.y=250;}
	}
	
	if(p.x>200){
		if(p.y<100){
			centre.x=250;centre.y=50;}
		else if((p.y>100)&&(p.y<200)){
			centre.x=250;centre.y=150;}
		else if(p.y>200){
			centre.x=250;centre.y=250;}
	}
}

	void dessine_croix(POINT utilisateur){
		POINT p1,p2;
		p1.x=utilisateur.x-40;p1.y=utilisateur.y-40;
		p2.x=utilisateur.x+40;p2.y=utilisateur.y+40;
		draw_line(p1,p2,bleu);
		p1.y=utilisateur.y+40;
		p2.y=utilisateur.y-40;
		draw_line(p1,p2,bleu);
		}
	
	void dessine_cercle(POINT p){
		draw_circle(centre,40,rouge);
		}

void dessine_action(POINT p){
	calcul_du_centre(p);
	
	if(a_qui_de_jouer==0){dessine_croix(centre);}
	else if (a_qui_de_jouer==1){dessine_cercle(centre);}
	
}
			

int main()
{
	int i;
	init_graphics(300,300);
	quadrillage();
	
	a_qui_de_jouer=0;
	
	for(i=0;i<9;i++)
	{
		POINT pUtilisateur;
		pUtilisateur=wait_clic();
		dessine_action(pUtilisateur);
		a_qui_de_jouer=1-a_qui_de_jouer;
	}
	wait_escape();
	exit(0);
}
	
