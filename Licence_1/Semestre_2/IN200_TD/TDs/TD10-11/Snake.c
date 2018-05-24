#include "graphics.h"

// Définition des différentes formes

#define VIDE 0
#define CERCLE 100
#define CARRE 101
#define CROIX 102
//#define TETE 103


// Définition des types

struct elem { //structure contenu du quadrillage
  int l,m; // position sur le quadrillage de l'élément
  int forme; // vaut VIDE, CERCLE, CARRE ou CROIX
  COULEUR coul; // vaut bleu, rouge, jaune ou vert
};
typedef struct elem ELEM;
ELEM J[40][60]; //tableau du quadrillage

struct serpent { //structure serpent
  int longueur; // nombre d'éléments dans le corps du serpent
  ELEM A[200]; // les éléments constitutifs du serpent
  int dx,dy; //les deplacements du serpent
};
typedef struct serpent SERPENT;

int forme_alea(){ //forme aleatoire de l'element
	int i=alea_int(200);
	if(i==1){return CERCLE;}
	else if(i==2){return CARRE;}
	else if(i==3){return CROIX;}
	else return VIDE;
}

COULEUR coul_alea(){ //couleur aleatoire de l'élément
	int i=alea_int(4);
	if(i==0){return bleu;}
	else if(i==1){return rouge;}
	else if(i==2){return jaune;}
	else if(i==3){return vert;}
	else return blanc;
}

ELEM element_aleatoire(){ //creer un element aléatoire sur le quadrillage 
	ELEM e;
	e.l=alea_int(40);
	e.m=alea_int(60);
	e.forme=forme_alea();
	e.coul=coul_alea();
	return e;
}

ELEM efface_element(ELEM e){
	//ELEM e;
	e.forme=VIDE;
	e.coul=noir;
	//e.l=e.l;
	//e.m=e.m;
	return e;
}

void init_jeu(ELEM J[40][60]){ //place aleatoirement les elements du jeu 
	int i,j;
	for(i=0;i<40;i++){
		for(j=0;j<60;j++){
			J[i][j]=element_aleatoire();
		}
	}
}

SERPENT init_serpent(){ //initialise le serpent et place sa tete aleatoirement
	SERPENT S;
	S.longueur=1;
	int i;
	for(i=2;i<S.longueur;i++){
		S.A[i].forme=VIDE;
	}
	S.A[0].forme=CERCLE;
	S.A[0].coul=blanc;
	
	S.A[0].l=alea_int(40);
	S.A[0].m=alea_int(60);
	S.dx=0;S.dy=1;
	
	return S;
}


void affiche_jeu(ELEM J[40][60]){ //dessine le quadrillage en fonction des elements de chaque case
	int i,j;
	POINT p;
	POINT p1,p2,p3,p4;
	for(i=0;i<40;i++){
		for(j=0;j<60;j++){
			p.x=((J[i][j]).l)*10+5;p.y=((J[i][j]).m)*10+5;
			p1.x=p.x-4;p1.y=p.y-4;
			p2.x=p.x+4;p2.y=p.y+4;
			p3.x=p.x-4;p3.y=p.y+4;
			p4.x=p.x+4;p4.y=p.y-4;
			if((J[i][j]).forme==CERCLE){
				draw_fill_circle(p,4,(J[i][j]).coul);
			}
			else if((J[i][j]).forme==CARRE){
				draw_fill_rectangle(p1,p2,(J[i][j]).coul);
			}
			else if((J[i][j]).forme==CROIX){
				draw_line(p1,p2,(J[i][j]).coul);
				draw_line(p3,p4,(J[i][j]).coul);
			}
				
		}
	}
	
}

void affiche_serpent(SERPENT S){ //dessine le serpent
	int i;
	POINT p,p1,p2,p3,p4;
	for(i=0;i<S.longueur;i++){
		p.x=(S.A[i].l)*10+5;p.y=(S.A[i].m)*10+5;
			p1.x=p.x-4;p1.y=p.y-4;
			p2.x=p.x+4;p2.y=p.y+4;
			p3.x=p.x-4;p3.y=p.y+4;
			p4.x=p.x+4;p4.y=p.y-4;
			if(S.A[i].forme==CERCLE){
				draw_fill_circle(p,4,S.A[i].coul);
			}
			else if(S.A[i].forme==CARRE){
				draw_fill_rectangle(p1,p2,S.A[i].coul);
			}
			else if(S.A[i].forme==CROIX){
				draw_line(p1,p2,S.A[i].coul);
				draw_line(p3,p4,S.A[i].coul);
			}
	}
}

SERPENT deplace_serpent(SERPENT S,POINT p){
	int i;int j;
	//write_int(p.x);
	if(!((p.x==0)&&(p.y==0))){ //si le joueur clique sur les boutons cela modifie dx et dy du serpent sinon non
		S.dx=p.x;S.dy=p.y;
	}
	//fill_screen(black);
	if(S.dx>=1){
		//for(i=0;i<S.longueur;i++){
			write_int(S.A[0].l);
			attendre(500);
			(S.A[0].l)++;//}
			affiche_serpent(S);
			write_int(S.A[0].l);
			//fill_screen(blue);
		//}
	}
	else if(S.dx==-1){
		//for(i=0;i<S.longueur;i++){
			//(S.A[i].l)--;
			fill_screen(jaune);
		//}
	}
	else if(S.dy==1){
		//for(i=0;i<S.longueur;i++){
			//(S.A[i].m)++;
			//fill_screen(gris);
		//}
	}
	else if(S.dy==-1){
		//for(i=0;i<S.longueur;i++){
			//(S.A[i].m)--;
			fill_screen(vert);
		//}
	}
	//fill_screen(beige);
	affiche_jeu(J);
	affiche_serpent(S);
	attendre(500);
}


int main()
{
	
	SERPENT S; //serpent du jeu
	POINT p;

	init_graphics(400,600);
	init_jeu(J);
	S = init_serpent();
	while(1){
		p=get_arrow();
		S=deplace_serpent(S,p);
		affiche_jeu(J);
		affiche_serpent(S);
	}

	wait_escape();
	exit(0);
}
