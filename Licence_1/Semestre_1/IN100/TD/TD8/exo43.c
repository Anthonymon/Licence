//td8 exo43 clement caumes
#include "graphics.h"

//partie 2

void dessine_case_blanche(POINT p){
	POINT p1,p2;
	p1.x=p.x;p1.y=p.y;
	p2.x=p.x+50;p2.y=p.y+50;
	draw_fill_rectangle(p1,p2,blanc);
}

void dessine_ligne_impaire(POINT p){
	while(p.x<400){
	if(((p.x)%100)==0){
		p.x=p.x+50;}
	else if(((p.x)%100)==50){
		dessine_case_blanche(p);
		p.x=p.x+50;}
	}
}

void dessine_ligne_paire(POINT p){
	while(p.x<400){
		if(((p.x)%100)==0){
			dessine_case_blanche(p);
			p.x=p.x+50;}
		else if(((p.x)%100)==50){
			p.x=p.x+50;}
		}
	}

void dessine_echiquier(){
	POINT pDebut;
	pDebut.x=0;pDebut.y=0;
	while(pDebut.y<400){
		if(((pDebut.y)%100)==0){
			dessine_ligne_impaire(pDebut);
		}
		else if(((pDebut.y)%100)==50){
			dessine_ligne_paire(pDebut);
		}
	pDebut.x=0;pDebut.y=pDebut.y+50;
		}
	}

void dessine_reine(POINT p){
	draw_fill_circle(p,20,rouge);
}

POINT trouve_le_centre(POINT p){
	if(p.x<50){p.x=25;}
	else if((p.x>50)&&(p.x<100)){p.x=75;}
	else if((p.x>100)&&(p.x<150)){p.x=125;}
	else if((p.x>150)&&(p.x<200)){p.x=175;}
	else if((p.x>200)&&(p.x<250)){p.x=225;}
	else if((p.x>250)&&(p.x<300)){p.x=275;}
	else if((p.x>300)&&(p.x<350)){p.x=325;}
	else if(p.x>350){p.x=375;}
	
	if(p.y<50){p.y=25;}
	else if((p.y>50)&&(p.y<100)){p.y=75;}
	else if((p.y>100)&&(p.y<150)){p.y=125;}
	else if((p.y>150)&&(p.y<200)){p.y=175;}
	else if((p.y>200)&&(p.y<250)){p.y=225;}
	else if((p.y>250)&&(p.y<300)){p.y=275;}
	else if((p.y>300)&&(p.y<350)){p.y=325;}
	else if(p.y>350){p.y=375;}	
	
	return p;
}

COULEUR trouve_couleur(POINT p){
	POINT pBase;
	pBase.x=p.x-25;pBase.y=p.y-25;
	if(((((pBase.x%100)==0)&&((pBase.y%100)==0)))||(((pBase.x%100)==50)&&((pBase.y%100)==50))){return noir;}
	else if(((((pBase.x%100)==0)&&((pBase.y%100)==50)))||(((pBase.x%100)==50)&&((pBase.y%100)==0))){return blanc;}
}



int main()
{
	init_graphics(400,400);
	dessine_echiquier();
	POINT positionDepart;
	positionDepart.x=25;positionDepart.y=25;
	dessine_reine(positionDepart);
	
	POINT pUtilisateur;
	pUtilisateur=wait_clic();
	POINT pExtremeGB;
	POINT pExtremeDH;
	pExtremeGB.x=positionDepart.x-25;pExtremeGB.y=positionDepart.y-25;
	pExtremeDH.x=positionDepart.x+25;pExtremeDH.y=positionDepart.y+25;
	
	while((((pUtilisateur.x)>(pExtremeGB.x))&&((pUtilisateur.x)<(pExtremeDH.x))) || (((pUtilisateur.y)>(pExtremeGB.y))&&((pUtilisateur.y)<(pExtremeDH.y)))){
		COULEUR coul;
		coul=trouve_couleur(positionDepart);
		draw_fill_circle(positionDepart,20,coul);
		
		pUtilisateur=trouve_le_centre(pUtilisateur); 
		dessine_reine(pUtilisateur);
		positionDepart.x=pUtilisateur.x;positionDepart.y=pUtilisateur.y;
		pUtilisateur=wait_clic();
		pExtremeGB.x=positionDepart.x-25;pExtremeGB.y=positionDepart.y-25;
		pExtremeDH.x=positionDepart.x+25;pExtremeDH.y=positionDepart.y+25;
		}
		
	wait_escape();
	exit(0);
}
