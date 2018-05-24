#include "graphics.h"
#define LARGEUR 8 //nombre de cases en largeur
#define HAUTEUR 12 //nombre de cases en longueur

COULEUR B [LARGEUR][HAUTEUR]; //initialisation du tableau de couleurs
int score; //initialisation du score

COULEUR couleur_aleatoire(){ //tire au hasard une couleur 
	int hasard;
	hasard=alea_int(4);
	if(hasard==0){
		return jaune;
	}
	else if(hasard==1){
		return rouge;
	}
	else if(hasard==2){
		return bleu;
	}
	else if(hasard==3){
		return vert;
	}
	return blanc;
}

void init_boules(){ //initialise le tableau avec des couleurs aleatoires
	int i,j;
	
	for(i=0;i<LARGEUR;i++){
		for(j=0;j<HAUTEUR;j++){
			B[i][j]=couleur_aleatoire();
		}
	}
	/*for(i=0;i<LARGEUR;i++){
		for(j=0;j<HAUTEUR;j++){
			B[i][j]=black;
		}
	}
	B[0][0]=B[0][1]=rouge;*/
}

void affiche_score(){ //affiche score
	POINT p;
	POINT p1,p2;
	p1.x=160; p1.y=(HAUTEUR*50)+40;
	p2.x=260; p2.y=(HAUTEUR*50)+1;
	draw_fill_rectangle(p1,p2,black);
	p.x=10;p.y=(HAUTEUR*50)+40;
	aff_pol("SCORE:",30,p,blanc);
	p.x=160;
	aff_int(score,30,p,blanc);
}

void affiche_boules(){ //affiche les boules
	POINT p;
	draw_circle(p,25,B[0][0]);
	int i,j;
	for(i=0;i<LARGEUR;i++){
		p.x=i*50+25;
		for(j=0;j<HAUTEUR;j++){
			p.y=j*50+25;
			draw_fill_circle(p,25,B[i][j]);
		}
	}
}

void dessine_quadrillage(){ //dessine quadrillage
	POINT p1,p2;
	p1.x=0;p1.y=50;
	p2.x=LARGEUR*50;p2.y=50;
	//int i=LARGEUR/50;
	//int j=HAUTEUR/50;
	while(p1.y<=(HAUTEUR*50)){
		draw_line(p1,p2,blanc);
		p1.y=p1.y+50;
		p2.y=p1.y;
	}
	p1.x=50;p1.y=0;
	p2.x=50;p2.y=HAUTEUR*50;
	while(p1.x<(LARGEUR*50)){
		draw_line(p1,p2,blanc);
		p1.x=p1.x+50;
		p2.x=p1.x;
	}
}

void affichage(){ //affiche le quadrillage le score et les boules
	affiche_score();
	affiche_boules();
	dessine_quadrillage();
}

void descendre_colonne(){ //modifie les colonnes si il y a des espaces entre les boules
	int i;int j;
	for(i=0;i<LARGEUR;i++){
		for(j=0;j<HAUTEUR-1;j++){
			if(B[i][j]==noir){
				B[i][j]=B[i][j+1];
				B[i][j+1]=noir;
			}
		}
	}
}

int test_colonne(int i){ //test si les boules de cette colonne sont noirs
	int j;
	int nombre=0;
	for(j=0;j<HAUTEUR;j++){
		if(B[i][j]==noir){
			nombre++;
		}
	}
	if(nombre==HAUTEUR){
		return 1;
	}
	else return 0;
}

void deplacement_droite(){ //deplacement de colonnes vides vers la droite
	int i,j;
	for(i=LARGEUR-1;i>0;i--){
		if(test_colonne(i)==1){
			for(j=0;j<HAUTEUR;j++){
				B[i][j]=B[i-1][j];
				B[i-1][j]=noir;
			}
		}
	}
}

int mettre_a_noir(COULEUR coul,int i, int j,int n){ //n correspond au nombre de cases effacees
	B[i][j]=noir; n++;
	if((i<7)&&(B[i+1][j]==coul)){
		n=mettre_a_noir(coul,i+1,j,n);
	}
	if((i>0)&&(B[i-1][j]==coul)){
		n=mettre_a_noir(coul,i-1,j,n);
	}
	if((j<11)&&(B[i][j+1]==coul)){
		n=mettre_a_noir(coul,i,j+1,n);
	}
	if((j>0)&&(B[i][j-1]==coul)){
		n=mettre_a_noir(coul,i,j-1,n); 
	}
	if(n==1){B[i][j]=coul;} //si n==1 B reprend sa couleur 
	deplacement_droite();
	descendre_colonne();

	return n;
}

int test_aucune_boule(){ //test si il y a que des boules noires
	int i,j;
	int nombre=0;
	for(i=0;i<LARGEUR;i++){
		for(j=0;j<HAUTEUR;j++){
			if(B[i][j]==noir){
				nombre++;
			}
			else {
				nombre=0;
			}
		}
	}
	if(nombre==HAUTEUR*LARGEUR){
		return 1;
	}
	else {return 0;}
}

void gestion_clic(){ 
	POINT p;
	p=wait_clic();
	while((p.y>600)||(B[p.x/50][p.y/50]==noir)){
		p=wait_clic();
	}
	int i,j,n;
	n=0;
	i=p.x/50;
	j=p.y/50;
	n=mettre_a_noir(B[i][j],i,j,n);
	score=n*(n-1)+score;
	if(test_aucune_boule()==1){
		score=score+200;
	}
	
}

int main(){
	init_graphics(LARGEUR*50,HAUTEUR*50+50);
	fill_screen(noir);
	init_boules();
	affichage();
	while((test_aucune_boule()==0)){
		gestion_clic();
		affichage();
	}
	
	
	wait_escape();
	exit(0);
}
