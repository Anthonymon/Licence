#include <stdio.h>
#include <stdlib.h>

int factorielle(int n){
	int f;
	if(n<=1){
		f=1;
	}
	else {
		f=n*factorielle(n-1);
	}
	return f;
}

int main(){
	int nombre;
	printf("Ecris un nombre : ");
	scanf("%d",&nombre);
	printf("La factorielle de %d est %d\n",nombre,factorielle(nombre));
	return 0;
}
