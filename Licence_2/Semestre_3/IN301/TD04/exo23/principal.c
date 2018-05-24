#include <stdlib.h>
#include <stdio.h>
#include "circonference.h"
#include "surface.h"

int main(){
	float r;
	printf("Ecrire un rayon : ");
	scanf("%f",&r);
	//printf("\n");
	printf("Sa circonference est : %f",circonference(r));
	printf("\n");
	printf("Sa surface est : %f",surface(r));
	exit(0);
}
