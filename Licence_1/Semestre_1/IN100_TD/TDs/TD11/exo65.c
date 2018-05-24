//exo65 td11 clement caumes

#include "graphics.h"

POINT T1[20];
int Tdistance[20];
int compteur;
int pg;
int i;
int caseplusgrande;
POINT pUtilisateur1;
POINT pUtilisateur2;
POINT centre;


int calcul;

void distanceplusgrande(){//trouve le numero de la case du point le plus eloigne
	pg=Tdistance[0];
	for(i=0;i<20;i++){
		if(pg<Tdistance[i]){
			pg=Tdistance[i];
			caseplusgrande=i;
		}
	}
}

int main(){
	init_graphics(600,600);
	centre.x=300;centre.y=300;
	for(compteur=0;compteur<20;compteur++){//met le point dans le tableau 1 et la distance entre le centre et le point dans un autre tableau
		pUtilisateur1=wait_clic();
		draw_fill_circle(pUtilisateur1,10,rouge);
		T1[compteur]=pUtilisateur1;
		Tdistance[compteur]=distance(centre,pUtilisateur1);
	}
	
	for(compteur=0;compteur<20;compteur++){
		pUtilisateur2=wait_clic();
		distanceplusgrande();
		draw_fill_circle(T1[caseplusgrande],10,noir);
		T1[caseplusgrande]=pUtilisateur2;
		Tdistance[caseplusgrande]=distance(centre,pUtilisateur2);
		draw_fill_circle(pUtilisateur2,10,rouge);
		distanceplusgrande();
		
		
		
	}
	
	wait_escape();
	exit(0);
}
