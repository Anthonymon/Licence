#include "graphics.h"
#define nombreBalle 50
typedef struct balle BALLE;
struct balle{
	POINT centre;
	int rayon;
	COULEUR coul;
	int dx,dy;
};


BALLE init_balle(POINT p,int taille,COULEUR couleur,int abscisse,int ordonnee){
	BALLE boule1;
	boule1.centre=p;
	boule1.rayon=taille;
	boule1.coul=couleur;
	boule1.dx=abscisse;
	boule1.dy=ordonnee;
	return boule1;
}

BALLE deplace_balle(BALLE B){
	POINT p=B.centre;
	p.x=p.x+B.dx;
	p.y=p.y+B.dy;
	B.centre=p;
	return B;
}

void efface_balle(BALLE B){
	draw_fill_circle(B.centre,B.rayon,noir);
}

void affiche_balle(BALLE B){
	draw_fill_circle(B.centre,B.rayon,B.coul);
}

BALLE rebond_balle(BALLE B){
	POINT p;
	p=B.centre;
	
	if(((p.y+B.rayon)>=HEIGHT)||((p.y-B.rayon)<=0)){
		B.dy=-B.dy;
	}
	else if(((p.x+B.rayon)>=WIDTH)||((p.x-B.rayon)<=0)){
		B.dx=-B.dx;
	}
	/*if((p.x+B.rayon)<=199){
		B.dx=-B.dx;
		}*/
	/*if((p.x+B.rayon)<(200)){
		if((p.x+B.rayon)>=199){
		B.dx=-B.dx;
		}
		if((p.x-B.rayon)>200){
			if((p.x-B.rayon)<=199){
				B.dx=-B.dx;
			}
		}
	}*/
	/*if((((p.x+B.rayon)==199)||((p.x+B.rayon)==200)||((p.x+B.rayon)==201))&&(p.x<200)){
		B.dx=-B.dx;
	}
	if((((p.x-B.rayon)==199)||((p.x-B.rayon)==200)||((p.x-B.rayon)==201))&&(p.x>200)){
		B.dx=-B.dx;
	}*/
	if(p.x<=200){
		if(((p.x+B.rayon)==199)||((p.x+B.rayon)==200)||((p.x+B.rayon)==201)){
			B.dx=-B.dx;
		}
	}
	
	return B;
}

int main(){
	init_graphics(400,400);
	affiche_auto_off();
	BALLE T1[nombreBalle];
	
	
	
	///////////////initialisation tableau///////////////
	int i;
	for(i=0;i<nombreBalle;i++){
		POINT p;
		p.x=alea_int(200)+100;
		p.y=alea_int(200)+100;
		T1[i].centre=p; //determination du centre
		T1[i].coul=couleur_RGB(alea_int(256),alea_int(256),alea_int(256)); //determination couleur
		T1[i].rayon=alea_int(25)+5; //determination rayon
		int a=alea_int(2); //determination dx
		if(a==0){
			T1[i].dx=alea_int(5)+1;
		}
		else {T1[i].dx=-alea_int(5)-1;}
		int b=alea_int(2);
		if(b==0){
			T1[i].dy=alea_int(5)+1;
		}
		else {T1[i].dy=-alea_int(5)-1;}
	}
	//////////////////////////////////////////////
	///////////////////////////////////affiche tableau et deplace les balles
	int t;
	int v=1;
	for(t=0;t<nombreBalle;t++){
			affiche_balle(T1[t]);
		}
	int u;
//	for(u=0;u<nombreBalle;u++){
		while(v==1){
			for(u=0;u<nombreBalle;u++){
			attendre(1);
			efface_balle(T1[u]);
			T1[u]=deplace_balle(T1[u]);
			T1[u]=rebond_balle(T1[u]);
			affiche_balle(T1[u]);
			
			POINT p1,p2;
			p1.x=200;p1.y=0;
			p2.x=200;p2.y=400;
			draw_line(p1,p2,blanc);
			//affiche_all();
			}
			affiche_all();
		}
	//////////////////////////////////////////
	
	
	wait_escape();
	exit(0);
}
