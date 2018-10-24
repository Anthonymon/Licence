#include "graphics.h"

int taille[20];
POINT points[20];
int i;
int i2;
int test1=0;
int compteur;
POINT pUtilisateur;
//int distance;

int test(){
	for(i=0;i<20;i++){
		if(taille[i]==0){compteur++;}
	}
	if(compteur==20){
		compteur=0;
		exit(0);
	}
	else {return 0;}
}

int main(){
	init_graphics(600,600);
	
	for(i=0;i<20;i++){//mettre 20 dans chaque case
		taille[i]=20;
	}
	
	for(i=0;i<20;i++){//mettre dans chaque case le point 
		pUtilisateur=wait_clic();
		points[i]=pUtilisateur;
		draw_fill_circle(points[i],taille[i],rouge);
	}
	
	test1=test();
	
	while(test1==0){
		pUtilisateur=wait_clic();
		for(i2=0;i2<20;i2++){
			if(distance(pUtilisateur,points[i2])<taille[i2]){
				//draw_fill_circle(points[i2],taille[i2],noir);
				//taille[i2]=taille[i2]+5;
				//draw_fill_circle(points[i2],taille[i2],rouge);
				for(i=0;i<20;i++){
					if(i==i2){
						draw_fill_circle(points[i2],taille[i2],noir);
						taille[i2]=taille[i2]+10;
						draw_fill_circle(points[i2],taille[i2],rouge);
					}
					draw_fill_circle(points[i],taille[i],noir);
					taille[i]=taille[i]-5;//diminuer tous les cercles
					draw_fill_circle(points[i],taille[i],rouge);
				}
				if(taille[0]==0||taille[1]==0){wait_escape();}
			}
		}
	}
	
	
	
	wait_escape();
	exit(0);
}
