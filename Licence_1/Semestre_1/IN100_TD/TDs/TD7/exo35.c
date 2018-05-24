//td7 exo35 clement caumes
#include "graphics.h"

int haut_ou_bas;
int gauche_ou_droite;
int OU_CA;
POINT p1;

void qui_dit_ou_c_est(POINT p){
	if(p.y<200){
		haut_ou_bas=0;}
	else {haut_ou_bas=1;}
	if(p.x<200){
		gauche_ou_droite=0;}
		else{gauche_ou_droite=1;}
	}

void calcul_OU_CA(){
	if((gauche_ou_droite==0)&&(haut_ou_bas==0)){
		OU_CA=0;}
	else if((gauche_ou_droite==1)&&(haut_ou_bas==0)){
		OU_CA=1;}
	else if((gauche_ou_droite==0)&&(haut_ou_bas==1)){
		OU_CA=2;}
	else if((gauche_ou_droite==1)&&(haut_ou_bas==1)){
		OU_CA=3;}
	}
		
void dessine_cercle_couleur(POINT centre){
	qui_dit_ou_c_est(centre);
	calcul_OU_CA();
	if(OU_CA==0){
		draw_fill_circle(centre,50,bleu);}
	else if(OU_CA==1){
		draw_fill_circle(centre,50,rouge);}
	else if(OU_CA==2){
		draw_fill_circle(centre,50,vert);}
	else if(OU_CA==3){
		draw_fill_circle(centre,50,jaune);}
	}
	
	
int main()
{
	int i;
	init_graphics(400,400);
	POINT p2,p3;
	p2.x=200;p2.y=0;
	p3.x=200;p3.y=400;
	draw_line(p2,p3,blanc);
	p2.x=0;p2.y=200;
	p3.x=400;p3.y=200;
	draw_line(p2,p3,blanc);
	
	for(i=0;i<20;i++)
	{
		p1=wait_clic();
		
		dessine_cercle_couleur(p1);
	}
	
	wait_escape();
	exit(0);
}
	
