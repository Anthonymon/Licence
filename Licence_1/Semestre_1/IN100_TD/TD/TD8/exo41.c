#include "graphics.h"

int main()
{
	init_graphics(900,600);
	POINT p1,p2;
	p1.x=300;p1.y=0;
	p2.x=300;p2.y=600;
	draw_line(p1,p2,blanc);
	p1.x=600;p1.y=0;
	p2.x=600;p2.y=600;
	draw_line(p1,p2,blanc);
	
	POINT pDrapeauBleu1;
	pDrapeauBleu1.x=0;pDrapeauBleu1.y=0;
	POINT pDrapeauBleu2;
	pDrapeauBleu2.x=299;pDrapeauBleu2.y=600;
	POINT pDrapeauBlanc1;
	pDrapeauBlanc1.x=300;pDrapeauBlanc1.y=0;
	POINT pDrapeauBlanc2;
	pDrapeauBlanc2.x=600;pDrapeauBlanc2.y=600;
	POINT pDrapeauRouge1;
	pDrapeauRouge1.x=601;pDrapeauRouge1.y=0;
	POINT pDrapeauRouge2;
	pDrapeauRouge2.x=900;pDrapeauRouge2.y=600;
	
	POINT pUtilisateur;
	
	int compteurGeneral;
	compteurGeneral=0;
	int compteurBleu;
	compteurBleu=0;
	int compteurBlanc;
	compteurBlanc=0;
	int compteurRouge;
	compteurRouge=0;
	
	while(compteurGeneral<20){
		pUtilisateur=wait_clic();
		
		if(pUtilisateur.x<300){
			
			if((compteurBleu%2)==0){
				draw_fill_rectangle(pDrapeauBleu1,pDrapeauBleu2,bleu);
			}
			else if((compteurBleu%2)==1){
				draw_fill_rectangle(pDrapeauBleu1,pDrapeauBleu2,noir);
			}
		compteurBleu++;
		}
		
		
		if((pUtilisateur.x>300)&&(pUtilisateur.x<600)){
			if((compteurBlanc%2)==0){
				draw_fill_rectangle(pDrapeauBlanc1,pDrapeauBlanc2,blanc);
			}
			else if((compteurBlanc%2)==1){
				draw_fill_rectangle(pDrapeauBlanc1,pDrapeauBlanc2,noir);
			}
		compteurBlanc++;
	}
		
		
		if(pUtilisateur.x>600){
			if((compteurRouge%2)==0){
				draw_fill_rectangle(pDrapeauRouge1,pDrapeauRouge2,rouge);
			}
			else if((compteurRouge%2)==1){
				draw_fill_rectangle(pDrapeauRouge1,pDrapeauRouge2,noir);
			}
		compteurRouge++;	
		}
		
		
		compteurGeneral++;
	}
	
	
	wait_escape();
	exit(0);
}
