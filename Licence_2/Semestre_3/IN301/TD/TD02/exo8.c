#include <stdio.h>

int main(){
	int nombre;
	printf("Quel est ton nombre : ");
	scanf("%d",&nombre);
	int i;
	int test=0;
	if(nombre<1){
		printf("non premier\n");
	}
	if(nombre==2){
		printf("premier\n");
	}
	else{
		if(nombre%2==0){
			printf("non premier\n");
		}
		else {
			for(i=1;i<=nombre;i++){
				if(nombre%i==0){
					test++;
				}
			}
			if(test==2){
				test=0;
				printf("premier\n");
			}
			
		}
	}
	return 0;
}
