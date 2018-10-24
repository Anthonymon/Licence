#include <stdio.h>
#include <stdlib.h>

int main(){
	/*int U0;
	int Unn;
	int Un;
	int tours=0;
	printf ("Ecris la valeur de départ : ");
	scanf("%d",&U0);
	Un=U0;
	while(Un!=1){
		tours++;
		if(Un%2==0){
			Unn=Un/2;
		}
		else if(Un%2==1){
			Unn=3*Un+1;
		}
		Un=Unn;
		printf("%d\n",Un);
	}
	
	printf("On compte %d iterations.\n",tours);*/
	
	int U0;
	int Unn;
	int Un;
	int tours=0;
	int i;
	int n;
	printf ("Ecris un nombre : ");
	scanf("%d",&n);
	/*for(i=n;i>0;i--){
		printf("%d\n",i);
	}*/
	//printf("12");
	for(i=0;i<n;i++){
		printf("12");
		U0=i;
		Un=U0;
		while(Un!=1){
			tours++;
			if(Un%2==0){
				Unn=Un/2;
			}
			else if(Un%2==1){
				Unn=3*Un+1;
			}
			Un=Unn;
		}
	printf("Pour %d il y a %d iterations.\n",i,tours);
	tours=0;
	}
	
	/*while(Un!=1){
		tours++;
		if(Un%2==0){
			Unn=Un/2;
		}
		else if(Un%2==1){
			Unn=3*Un+1;
		}
		Un=Unn;
	}
	printf("Pour %d il y a %d iterations.\n",i,tours);*/
	
	return 0;
}
