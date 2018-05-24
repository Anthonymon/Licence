#include <stdio.h>
#include <stdlib.h>

float valAbs(float i){
	if(i<0){
		return -i;
	}
	return i;
}

int main(){
	float entier;
	float inf;
	float sup;
	float racine;
	float milieu;
	float epsilon=0.001;
	racine=0;
	printf("Ecrire un nombre : ");
	scanf("%f",&entier);
	inf=0;sup=entier;milieu=(sup+inf)/2;
	while(valAbs(milieu*milieu-entier)>epsilon){

		if(milieu*milieu<entier){
			inf=milieu;
			//printf("%f %f %f\n",inf,milieu,sup);
			
		}
		else {sup=milieu;
		}
		milieu=(inf+sup)/2;
		//printf("%f %f %f\n",inf,milieu,sup);
		
	}
	racine=milieu;
	printf("La racine de %f est %f",entier,racine);
	return 0;
}
