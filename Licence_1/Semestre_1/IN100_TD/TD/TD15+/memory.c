#include "graphics.h"

int typeCartes[16]; //tableau qui indique le type de cartes (dessin) -->numero cartes 1 a 8
int retournes[16]; //tableau qui indique si la carte est retourne 0-->caché 1-->retourné
int decouvertes[16]; //tableau qui indique si la carte est decouverte par le joueur 0-->inconnu 1--> decouverte
int hasard[16]; //tableau qui indique si on a donne une identite a la carte 0-->inconnu 1-->decouverte

POINT calcul_point(int i){ //calcule le centre de la case en fonction du numero du tableau
	POINT centre;
	if((i>=0)&&(i<=3)){
		centre.y=100;
		if(i==0){centre.x=100;}
		else if(i==1){centre.x=250;}
		else if(i==2){centre.x=400;}
		else if(i==3){centre.x=550;}
		return centre;
	}
	else if((i>=4)&&(i<=7)){
		centre.y=250;
		if(i==4){centre.x=100;}
		else if(i==5){centre.x=250;}
		else if(i==6){centre.x=400;}
		else if(i==7){centre.x=550;}
		return centre;
	}
	else if((i>=8)&&(i<=11)){
		centre.y=400;
		if(i==8){centre.x=100;}
		else if(i==9){centre.x=250;}
		else if(i==10){centre.x=400;}
		else if(i==11){centre.x=550;}
		return centre;
	}
	else{
		centre.y=550;
		if(i==12){centre.x=100;}
		else if(i==13){centre.x=250;}
		else if(i==14){centre.x=400;}
		else if(i==15){centre.x=550;}
		return centre;
	}
}

void dessine_carte_retournee(int i){
	POINT centre_carte;
	POINT p1,p2,p3;
	centre_carte=calcul_point(i);
	if(typeCartes[i]==0){
		draw_fill_circle(centre_carte,30,rouge);
		draw_fill_circle(centre_carte,15,blanc);
	}
	else if(typeCartes[i]==1){
		p1.x=centre_carte.x-30;p1.y=centre_carte.y-30;
		p2.x=centre_carte.x+30;p2.y=centre_carte.y+30;
		draw_fill_rectangle(p1,p2,bleu);
	}
	else if(typeCartes[i]==2){
		p1.x=centre_carte.x-30;p1.y=centre_carte.y-30;
		p2.x=centre_carte.x+30;p2.y=centre_carte.y+30;
		p3.x=centre_carte.x;p3.y=centre_carte.y-30;
		draw_fill_rectangle(p1,p2,vert);
		p2.x=centre_carte.x+30;
		draw_fill_triangle(p1,p2,p3,blanc);
	}
	else if(typeCartes[i]==3){
		draw_fill_circle(centre_carte,30,bleu);
		draw_fill_circle(centre_carte,10,blanc);
	}
	else if(typeCartes[i]==4){
		p1.x=centre_carte.x-30;p1.y=centre_carte.y-30;
		p2.x=centre_carte.x+30;p2.y=centre_carte.y+30;
		draw_fill_rectangle(p1,p2,pink);
	}
	else if(typeCartes[i]==5){
		p1.x=centre_carte.x-30;p1.y=centre_carte.y-30;
		p2.x=centre_carte.x+30;p2.y=centre_carte.y+30;
		p3.x=centre_carte.x;p3.y=centre_carte.y+30;
		draw_fill_rectangle(p1,p2,orange);
		p2.x=centre_carte.x+30;
		draw_fill_triangle(p1,p2,p3,blanc);
	}
	else if(typeCartes[i]==6){
		p1.x=centre_carte.x-30;p1.y=centre_carte.y-30;
		p2.x=centre_carte.x+30;p2.y=centre_carte.y+30;
		draw_fill_rectangle(p1,p2,rouge);
	}
	else if(typeCartes[i]==7){
		draw_fill_circle(centre_carte,30,vert);
	}
}

void init_jeu(){
	int m;
	for(m=0;m<16;m++){ //au debut toutes les cartes sont caches et inconnues
		retournes[m]=0;
		decouvertes[m]=0;
	}
	
	int i,j,k;
	for(i=0;i<8;i++){ //au debut on place les differentes valeurs sur les cartes
		j=alea_int(16);
		while(hasard[j]==1){
			j=alea_int(16);
		}
		typeCartes[j]=i;
		hasard[j]=1;
		
		k=alea_int(16);
		while(hasard[k]==1){
			k=alea_int(16);
		}
		typeCartes[k]=i;
		hasard[k]=1;
	}
}

void affiche_jeu(){
	fill_screen(argent);
	{ //dessin du placement des cartes
		POINT p1,p2;
		p1.x=50;p1.y=50;
		p2.x=150;p2.y=150;
		while(p2.x<=600){
			draw_fill_rectangle(p1,p2,blanc);
			draw_rectangle(p1,p2,noir);
			p1.x=p1.x+150;p2.x=p2.x+150;
		}
		p1.x=50;p1.y=200;
		p2.x=150;p2.y=300;
		while(p2.x<=600){
			draw_fill_rectangle(p1,p2,blanc);
			draw_rectangle(p1,p2,noir);
			p1.x=p1.x+150;p2.x=p2.x+150;
		}
		p1.x=50;p1.y=350;
		p2.x=150;p2.y=450;
		while(p2.x<=600){
			draw_fill_rectangle(p1,p2,blanc);
			draw_rectangle(p1,p2,noir);
			p1.x=p1.x+150;p2.x=p2.x+150;
		}
		p1.x=50;p1.y=500;
		p2.x=150;p2.y=600;
		while(p2.x<=600){
			draw_fill_rectangle(p1,p2,blanc);
			draw_rectangle(p1,p2,noir);
			p1.x=p1.x+150;p2.x=p2.x+150;
		}
	}
	
	{
		int i;
		POINT milieu;
		POINT p1,p2;
		for(i=0;i<16;i++){
			if(retournes[i]==0){ //si la carte est cache
				milieu=calcul_point(i);
				p1.x=milieu.x-40;p1.y=milieu.y-40;
				p2.x=milieu.x+40;p2.y=milieu.y+40;
				draw_fill_rectangle(p1,p2,darkred);
				milieu=calcul_point(i);
				milieu.x=milieu.x-18;
				milieu.y=milieu.y+30;
				aff_pol("C",50,milieu,blanc);
			}
			if(retournes[i]==1){
				dessine_carte_retournee(i);
			}
		}
	}
	
}

int main(){
	init_graphics(650,650);
	init_jeu();
	affiche_jeu();
	
	wait_escape();
	exit(0);
}
