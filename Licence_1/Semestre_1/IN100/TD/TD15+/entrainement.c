#include "graphics.h"



int main(){
	init_graphics(900,600);
	POINT p1,p2;
	int T[20];
	int valeur[20];
	
	//int valeur_aleatoire[20];
	
	
	int i;
	for(i=0;i<20;i++){T[i]=alea_int(100);} //mets les valeurs aleatoires pour chaque bloc
	
	for(i=0;i<20;i++){
		p1.x=(100+20*i);p1.y=50;
		p2.x=(100+20*i+19);p2.y=(50+3*T[i]);
		valeur[i]=p2.y;
		//valeur_aleatoire[i]=T[i];
		draw_fill_rectangle(p1,p2,bleu);
	}
	int lemax;
	int lemin;
	int compteur;
	lemax=valeur[0];
	lemin=valeur[0];
	for(i=0;i<20;i++){
		if(valeur[i]>lemax){
			lemax=valeur[i];
			compteur=i;
		}
	}
	p1.x=(100+20*compteur);p1.y=50;
	p2.x=(100+20*compteur+19);p2.y=lemax;
	draw_fill_rectangle(p1,p2,vert);
	
	for(i=0;i<20;i++){
		if(valeur[i]<lemin){
			lemin=valeur[i];
			compteur=i;
		}
	}
	p1.x=(100+20*compteur);p1.y=50;
	p2.x=(100+20*compteur+19);p2.y=lemin;
	draw_fill_rectangle(p1,p2,rouge);
	

	wait_escape();
	exit(0);
}
