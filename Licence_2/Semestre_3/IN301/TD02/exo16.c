#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int alea(int n){
	return rand()%n;
}

void init_tableau(int T[],int e){
	int i;
	for(i=0;i<e;i++){
		T[i]=alea(15);
	}
}

void affiche_tableau(int T[],int e){
	int i;
	for(i=0;i<e;i++){
		printf("%d ",T[i]);
	}
	printf("\n");
}

int compte_valeurs(int T1[],int e){
	int T2[N];
	int h;
	for(h=0;h<N;h++){ //initialise un tableau de la meme taille
		T2[h]=0; //qui a 0 pour toutes ses valeurs
	}
	
	/*int i;int j;int k;int test=0;
	for(i=0;i<e;i++){
		for(j=0;j<N;j++){
			for(k=0;k<e;k++){
				if(T1[i]==T2[k]){
					
				}
			}
			
			if((T2[j]==0)&&(test==0)){
				T2[j]=T1[i];
				
			}
		}
	}*/
	
	int i;int j=0;int test=1;int m=0;
	for(i=0;i<e;i++){
		while((T2[j]!=T1[i])&&(test==1)){
			test=0;
			j++;
		}
		if(test==0){
			while(T2[m]!=0){
				m++;
			}
			T2[m]=T1[i];
		}
		test=1;m=0;j=0;
	}
	
	int r;int nb=0;
	for(r=0;r<N;r++){
		if(T2[r]==0){
			nb=nb+1;
		}
	}
	return e-nb;
	
}

int main(){
	srand(time(NULL));
	
	int T[N];
	init_tableau(T,N);
	affiche_tableau(T,N);
	printf("%d\n",compte_valeurs(T,N));
	
	return 0;
}
