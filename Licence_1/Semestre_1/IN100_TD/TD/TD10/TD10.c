/* TD10 2.0 clement caumes*/
#include "graphics.h"
///////////exo51/////////////
int stockage_plateau[100];
///////////fin exo51//////////

POINT calcul_centre_pion(i){//calcul centre du pion en fonction de sa position i
	POINT pion;
	pion.x=(i%10)*60+30;
	pion.y=(i/10)*60+30;
	return pion;
}

void modifie_pion(POINT p,int i){
	if(stockage_plateau[i]==0){
		draw_fill_circle(p,25,blanc);
		stockage_plateau[i]=1;
	}
	else if(stockage_plateau[i]==1){
		draw_fill_circle(p,25,noir);
		stockage_plateau[i]=0;
	}
}

///////////exo52/////////////
void initialise_plateau(){  //place les pions au hasard
	int i;
	for(i=0;i<100;i++){// choisit au hasard les valeurs de chaque pion
		stockage_plateau[i]=alea_int(2);
	}
}
///////////fin exo52///////////

/////////////exo53////////////
void affiche_plateau(){
	POINT p1,p2; //dessine quadrillage
	p1.x=60;p1.y=0;p2.x=60;p2.y=600;
	while(p1.x<600){
		draw_line(p1,p2,blanc);
		p1.x=p1.x+60;
		p2.x=p1.x;
	}
	p1.x=0;p1.y=60;p2.x=600;p2.y=60;
	while(p1.y<600){
		draw_line(p1,p2,blanc);
		p1.y=p1.y+60;
		p2.y=p2.y+60;}
	
	int i;
	
	POINT p;
	for(i=0;i<100;i++){
		p=calcul_centre_pion(i);
		if(stockage_plateau[i]==0){
			draw_fill_circle(p,25,noir);
		}
		else if (stockage_plateau[i]==1){draw_fill_circle(p,25,blanc);}
	}
}
/////////////fin exo53//////////

////////////exo55//////////////
void modifie_plateau(POINT p){
	int i1;
	POINT pionMilieu;
	int i2;
	POINT pionDroit;
	int i3;
	POINT pionBas;
	int i4;
	POINT pionGauche;
	int i5;
	POINT pionHaut;
	
	i1=(p.y/60)*10+(p.x/60);
	pionMilieu=calcul_centre_pion(i1);
	i2=i1+1;
	pionDroit=calcul_centre_pion(i2);
	i3=i1-10;
	pionBas=calcul_centre_pion(i3);
	i4=i1-1;
	pionGauche=calcul_centre_pion(i4);
	i5=i1+10;
	pionHaut=calcul_centre_pion(i5);
	
	modifie_pion(pionMilieu,i1);//change le pion la ou on clique
	
	if((i1%10==9)&&(i1!=9)&&(i1!=99)){//cas des pions droit sauf haut et bas
		modifie_pion(pionHaut,i5);
		modifie_pion(pionGauche,i4);
		modifie_pion(pionBas,i3);
	}
	
	else if((i1%10==0)&&(i1!=0)&&(i1!=90)){//cas des pions gauche sauf haut et bas
		modifie_pion(pionHaut,i5);
		modifie_pion(pionDroit,i2);
		modifie_pion(pionBas,i3);
	}
	
	else if((i1/10==9)&&(i1!=90)&&(i1!=99)){
		modifie_pion(pionBas,i3);
		modifie_pion(pionDroit,i2);
		modifie_pion(pionGauche,i4);
	}
	
	else if((i1/10==0)&&(i1!=0)&&(i1!=9)){
		modifie_pion(pionHaut,i5);
		modifie_pion(pionDroit,i2);
		modifie_pion(pionGauche,i4);
	}
	
	else if(i1==0){
		modifie_pion(pionDroit,i2);
		modifie_pion(pionHaut,i5);
	}
	
	else if(i1==9){
		modifie_pion(pionHaut,i5);
		modifie_pion(pionGauche,i4);
	}
	
	else if(i1==90){
		modifie_pion(pionBas,i3);
		modifie_pion(pionDroit,i2);
	}
	
	else if(i1==99){
		modifie_pion(pionBas,i3);
		modifie_pion(pionGauche,i4);
	}
	
	else {
		modifie_pion(pionDroit,i2);
		modifie_pion(pionBas,i3);
		modifie_pion(pionGauche,i4);
		modifie_pion(pionHaut,i5);
	}
}
///////////fin exo55//////////


//////////exo57////////////
int encore(){
	int i;
	if(stockage_plateau[0]==0){
		for(i=1;i<100;i++){
			if(stockage_plateau[i]==1){
				return 1;
			}
		}
	}
	if(stockage_plateau[0]==1){
		for(i=1;i<100;i++){
			if(stockage_plateau[i]==0){
				return 1;
			}
		}
	}
	return 0;
}
/////////fin exo57//////////

/////////exo59/////////////
void jeu(){
	initialise_plateau();
	affiche_plateau();
	int compteur;
	compteur=0;
	int tour_suivant;
	tour_suivant=1;
	while((compteur<100)&&(tour_suivant==1)){
		POINT pUtilisateur;
		pUtilisateur=wait_clic();
		modifie_plateau(pUtilisateur);
		tour_suivant=encore();
		compteur++;
	}
}
/////////fin exo59//////////


int main(){
	init_graphics(600,600);
	fill_screen(gris);
	/*initialise_plateau();
	affiche_plateau();
	POINT pUtilisateur;
	pUtilisateur=wait_clic();
	modifie_plateau(pUtilisateur);
	int tour_suivant;
	tour_suivant=encore();*/
	
	jeu();
	
	wait_escape();
	exit(0);
}
