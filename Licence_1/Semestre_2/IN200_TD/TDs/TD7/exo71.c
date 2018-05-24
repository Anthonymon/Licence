#include "graphics.h"
#define allumettesTotal 23
int nb_allumettes;
int tour;


void affiche_une_allumette(POINT P){ //affiche une allumette en fonction de sa position
	POINT p1;
	p1.x=P.x;p1.y=P.y+200;
	draw_line(P,p1,blanc);
}

void efface_une_allumette(POINT P){ //efface une allumette en fonction de sa position
	POINT p1;
	p1.x=P.x;p1.y=P.y+200;
	draw_line(P,p1,noir);
}

void efface_allumette(int N){ //efface les allumettes jusqua la numero N
	POINT p;
	p.x=20;p.y=200;
	int i;
	for(i=0;i<N;i++){
		efface_une_allumette(p);
		p.x=p.x+20;
	}
}

void affiche_allumette(int N){ //affiche les allumettes jusqua la numero N
	POINT p;
	p.x=20;p.y=200;
	int i;
	for(i=0;i<N;i++){
		affiche_une_allumette(p);
		p.x=p.x+20;
	}
}

void affiche_123(){ //affiche les trois boutons
	POINT p1,p2,p3;
	p1.x=150;p1.y=50;
	p2.x=250;p2.y=150;
	draw_fill_rectangle(p1,p2,blanc);
	p3.x=200;p3.y=100;
	draw_fill_circle(p3,13,noir);
	
	p1.x=400;p1.y=50;
	p2.x=500;p2.y=150;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=430;p1.y=120;
	draw_fill_circle(p1,13,noir);
	p2.x=470;p2.y=80;
	draw_fill_circle(p2,13,noir);
	
	p1.x=650;p1.y=50;
	p2.x=750;p2.y=150;
	draw_fill_rectangle(p1,p2,blanc);
	p1.x=700;p1.y=100;
	draw_fill_circle(p1,13,noir);
	p1.x=670;p1.y=130;
	draw_fill_circle(p1,13,noir);
	p2.x=730;p2.y=70;
	draw_fill_circle(p2,13,noir);
}

void affiche_score(int score){ //affiche le score
	POINT p1,p2,p3;
	p1.x=750;p1.y=500;
	p2.x=900;p2.y=600;
	draw_fill_rectangle(p1,p2,noir);
	p3.x=750;p3.y=580;
	aff_int(score,60,p3,blanc);
	
}

int get_valeur(){ //retourne 1, 2 ou 3 en fonction des boutons
	POINT p;
	p=wait_clic();
	while(((p.y>150)||(p.y<50))||((p.x<150)||((p.x>250)&&(p.x<400))||((p.x>500)&&(p.x<650))||(p.x>750))){
		p=wait_clic();
	}
	if((p.x>150)&&(p.x<250)){
		return 1;
	}
	else if((p.x>400)&&(p.x<500)){
		return 2;
	}
	else if((p.x>650)&&(p.x<750)){
		return 3;
	}
	return 0;
}

void affiche_tour(int tours){
	POINT p1,p2;
	p1.x=10;p1.y=570;
	p2.x=30;p2.y=590;
	if((tours%2)==0){
		draw_fill_rectangle(p1,p2,rouge);
	}
	else if((tours%2)==1){
		draw_fill_rectangle(p1,p2,bleu);
	}
	
}

void affichage(int nb2){ //affichage global
	//fill_screen(black);
	affiche_score(nb2);
	affiche_allumette(nb2);
	affiche_123();
	affiche_tour(tour);
}

void jouer_humain(int nb){ //jouer humain

	int i;
	i=get_valeur();
	efface_allumette(allumettesTotal);
	if(i==1){
		nb--;
	}
	else if(i==2){
		nb=nb-2;
	}
	else if(i==3){
		nb=nb-3;
	}
	nb_allumettes=nb;
	tour++;
	//write_int(nb);
	affichage(nb_allumettes);
}

void jouer(){
	tour=0;
	POINT p;
	p.x=250;p.y=350;
	nb_allumettes=allumettesTotal;
	//affiche_allumette(nb_allumettes);
	//affiche_123();
	affichage(nb_allumettes);
	affiche_score(nb_allumettes);
	while(nb_allumettes>0){
		jouer_humain(nb_allumettes);
		//write_int(nb_allumettes);		
	}
	if((tour%2)==0){
		fill_screen(rouge);
	}
	else if((tour%2)==1){
		fill_screen(bleu);
	}
	aff_pol("BRAVO!",100,p,blanc);
}

int main(){
	init_graphics(900,600);
	jouer();

	wait_escape();
	exit(0);
}
