#include "graphics.h"
#define L 40
#define C 60

#define DUREE_FEU 30
#define DUREE_CENDRE 10

#define TERRE saddlebrown
#define ARBRE vert
#define EAU bleu
#define FEU rouge
#define CENDRE_TIEDE gris
#define CENDRE_ETEINTE noir

//int T1[L][C];


struct parcelle{
	//int x;
	//int y;
	COULEUR type;
	//COULEUR coul;
};
typedef struct parcelle PARCELLE;

PARCELLE T1[L][C];

COULEUR couleur_terrain_aleatoire(){
	int i;
	i=alea_int(6);
	if(i==0){
		return TERRE;
	}
	else if(i==1){
		return ARBRE;
	}
	else if(i==2){
		return EAU;
	}
	else if(i==3){
		return FEU;
	}
	else if(i==4){
		return CENDRE_TIEDE;
	}
	else return CENDRE_ETEINTE;
}


void terrain_aleatoire(){
	int i,j;
	for(i=0;i<L;i++){
		for(j=0;j<C;j++){
			T1[i][j].type=couleur_terrain_aleatoire();
		}
	}
}

void affiche_parcelle(POINT bg,COULEUR c){
	POINT hd;
	hd.x=bg.x+10;hd.y=bg.y+10;
	draw_fill_rectangle(bg,hd,c);
}

void affiche_terrain(){
	POINT p;
	int i,j;
	for(i=0;i<L;i++){
		for(j=0;j<C;j++){
			p.x=i*10;
			p.y=j*10;
			affiche_parcelle(p,T1[i][j].type);
		}
	}
}

int main(){
	init_graphics(L*10,C*10);
	affiche_auto_off();
	
	terrain_aleatoire();
	affiche_terrain();
	affiche_all();
	//int i,j;
	/*while(1){
		for(i=0;i<L;i++){
			for(j=0;j<C;j++){
				fill_screen(T1[i][j].type);
			}
			//fill_screen(T1[1][0].type);
		}
	}*/
	
	wait_escape();
	exit(0);
}
