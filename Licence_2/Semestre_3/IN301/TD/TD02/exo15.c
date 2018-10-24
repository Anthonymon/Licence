#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 12

int alea(int n){
	return rand()%n;
}

void initialise_tableau(int T[],int e){
	int i;
	for(i=0;i<e;i++){
		T[i]=alea(N+5);
	}
}

void affiche_tableau(int T[],int e){
	int i;
	for(i=0;i<e;i++){
		printf("%d ",T[i]);
	}
	printf("\n");
}

void produit_tableau(int T[],int e){
	int i;
	int prod=1;
	for(i=0;i<e;i++){
		prod*=T[i];
	}
	printf("%d",prod);
}

int min_tableau(int T[],int e){
	int min=T[0];
	int i;
	for(i=0;i<e;i++){
		if(min>T[i]){
			min=T[i];
		}
	}
	return min;
}

void decalage_tableau(int T[],int e){
	int i;
	T[e-1]=T[e-2];
	for(i=e-1;i>0;i--){
		T[i]=T[i-1];
	}
	T[0]=0;
}

void insere_tableau_trie(int T[],int e,int ajout){
	int i=0;
	while(ajout>=T[i]){
		i++;
	}
	int temp=T[i];
	T[i]=ajout;
	int j;
	for(j=e-1;j>i-1;j--){
		T[j]=T[j-1];
	}
	T[i+1]=temp;
}

void inverse_tableau(int T[],int e){
	int i=0;int j=e-1;
	int temp;
	if(e%2==1){ //si cest impair
		while(i!=j){
			temp=T[i];
			T[i]=T[j];
			T[j]=temp;
			i++;j--;
		}
	}
	else{
		while(i+1!=j){
			temp=T[i];
			T[i]=T[j];
			T[j]=temp;
			i++;j--;
		}
		int k,l;
		k=e/2;
		l=k-1;
		temp=T[k];
		T[k]=T[l];
		T[l]=temp;
		
	}
	
}

void tableau_double(int T[],int e){
	int i;int j;int posTest=0;
	for(i=0;i<e;i++){
		for(j=e-1;j>0;j--){
			posTest=j;
			if((T[i]>=0)||(posTest!=i)){ //si cest negatif on sort de la boucle
				if(T[i]==T[j]){
					T[j]=-T[j];
				}
			}
		}
	}
}


int main(){
	srand(time(NULL));
	int T[N];
	initialise_tableau(T,N);
	affiche_tableau(T,N);
	tableau_double(T,N);
	affiche_tableau(T,N);
	
	return 0;
}
