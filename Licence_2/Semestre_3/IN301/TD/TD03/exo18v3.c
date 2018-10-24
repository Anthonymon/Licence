#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alea(int n){
	return rand()%n;
}

struct Tableau{
	int taille;
	int tab[100];
};typedef struct Tableau TABLEAU;

TABLEAU initialiseTableau(){
	TABLEAU t1;
	int i;
	t1.taille=10;
	for(i=0;i<t1.taille;i++){
		t1.tab[i]=alea(20);
	}
	return t1;
}

void afficheTableau(TABLEAU t1){
	int i;
	for(i=0;i<t1.taille;i++){
		printf("%d ",t1.tab[i]);
	}
	printf("\n");
}

int produitTableau(TABLEAU t1){
	int prod=1;
	int i;
	if(t1.taille==0){return 0;}
	for(i=0;i<t1.taille;i++){
		prod=prod*t1.tab[i];
	}
	return prod;
}

int minTableau(TABLEAU t1){
	int i;
	int min=t1.tab[0];
	for(i=0;i<t1.taille;i++){
		if(min>t1.tab[i]){
			min=t1.tab[i];
		}
	}
	return min;
}

TABLEAU decalage(TABLEAU t1){
	t1.taille++;
	int i;
	for(i=t1.taille-1;i>0;i--){
		t1.tab[i]=t1.tab[i-1];
	}
	t1.tab[0]=0;
	return t1;
}

TABLEAU insertionTableauTri(TABLEAU t1,int e){
	t1.taille++;
	int p=0;
	int temp;
	int i;
	while(t1.tab[p]<e){
		p++;
	}
	for(i=t1.taille+1;i>p;i--){
		temp=t1.tab[i];
		t1.tab[i]=t1.tab[i-1];
		t1.tab[i-1]=temp;
	}
	t1.tab[p]=e;
	return t1;
}

TABLEAU inversionTableau(TABLEAU t1){
	int temp;
	int i=0;
	int j=t1.taille-1;
	
	if(t1.taille%2==0){
		while(i<j){
			temp=t1.tab[i];
			t1.tab[i]=t1.tab[j];
			t1.tab[j]=temp;
			i++;
			j--;
		}
		
	}
	else{
		while(i!=j){
			temp=t1.tab[i];
			t1.tab[i]=t1.tab[j];
			t1.tab[j]=temp;
			i++;
			j--;
		}
	}
	return t1;
}



int rechercheRangMin(TABLEAU t1,int inter){
	int i;
	int min=t1.tab[inter];
	int rangMin=inter;
	for(i=inter;i<t1.taille;i++){
		if(min>t1.tab[i]){
			min=t1.tab[i];
			rangMin=i;
		}
	}
	return rangMin;
}

TABLEAU triSelection(TABLEAU t1){ 
	int e;
	int temp;
	//int i;
	int TC;
	for(TC=0;TC<t1.taille;TC++){
		e=rechercheRangMin(t1,TC);
		temp=t1.tab[e];
		t1.tab[e]=t1.tab[TC];
		t1.tab[TC]=temp;
	}
	return t1;
}

TABLEAU supprElemHasardTableau(TABLEAU t1){
	int e=0;
	int i;
	while(e==0){
		e=alea(t1.taille);
	}
	t1.tab[e]=-1;
	for(i=e;i<t1.taille-1;i++){
		t1.tab[i]=t1.tab[i+1];
	}
	t1.taille--;
	
	return t1;
}

TABLEAU supprElemTableau(TABLEAU t1,int f){
	int e;
	int i;
	e=f;
	t1.tab[e]=-1;
	
	for(i=e;i<t1.taille-1;i++){
		t1.tab[i]=t1.tab[i+1];
	}
	t1.taille--;
	
	return t1;
}

TABLEAU elimineDoubleTableau(TABLEAU t1){
	int TC;
	int j;
	int e;
	for(TC=0;TC<t1.taille;TC++){
		e=t1.tab[TC];
		for(j=t1.taille-1;j>TC;j--){
			if(t1.tab[j]==e){
				t1=supprElemTableau(t1,j);
			}
		}
	}
	return t1;
}

TABLEAU triInsertion(TABLEAU t1){
	int TC;
	int p;
	int temp;
	int i;
	for(TC=0;TC<t1.taille-1;TC++){
		p=0;
		temp=t1.tab[TC+1];
		while(temp>t1.tab[p]){ //chercher la pos p
			p++;
		}
		for(i=TC;i>=p;i--){
			t1.tab[i+1]=t1.tab[i];
		}
		t1.tab[p]=temp;
		
	}
	return t1;
}

TABLEAU triPermutation(TABLEAU t1){
	int TC;
	int i;
	int temp;
	for(TC=1;TC<t1.taille-1;TC++){
		for(i=t1.taille-1;i>=TC;i--){
			if(t1.tab[i]<t1.tab[i-1]){
				temp=t1.tab[i];
				t1.tab[i]=t1.tab[i-1];
				t1.tab[i-1]=temp;
			}
		}
	}
	return t1;
}

int triPermutationIteration(TABLEAU t1){
	int TC;
	int iterations=0;
	int i;
	int temp;
	for(TC=1;TC<t1.taille-1;TC++){
		for(i=t1.taille-1;i>=TC;i--){
			if(t1.tab[i]<t1.tab[i-1]){
				temp=t1.tab[i];
				t1.tab[i]=t1.tab[i-1];
				t1.tab[i-1]=temp;
				iterations++;
			}
		}
	}
	return iterations;
}

/*TABLEAU fusionner(TABLEAU t1,int iMin,int iMilieu,int iMax){
	TABLEAU tInter; tInter.taille=t1.taille;
	int i=iMin;
	int j=iMilieu+1;
	int k=0;
	while((i<=iMilieu)&&(j<=iMax)){
		if(t1.tab[i]<t1.tab[j]){
			tInter.tab[k]=t1.tab[i];
			i++;
		}
		else{tInter.tab[k]=t1.tab[j];j++;}
		
		k++;
	}
	
	int h;
	for(h=0;h<t1.taille;h++){
		t1.tab[h]=tInter.tab[h];
	}
	
	return t1;
}*/


/*TABLEAU triFusion(TABLEAU t1,int iMin, int iMax){
	if(iMin<iMax){
		int iMilieu=(iMin+iMax)/2;
		triFusion(t1,iMin,iMilieu);
		triFusion(t1,iMilieu,iMax);
		t1=fusionner(t1,iMin,iMilieu,iMax);
	}
	return t1;
}*/

TABLEAU fusionner(TABLEAU t1,int iMin,int iMilieu,int iMax){
	TABLEAU t2;t2.taille=t1.taille;
	int i=iMin;
	int j=iMilieu+1;
	int k=0;
	while((i<=iMilieu)&&(j<=iMax)){
		if(t1.tab[i]<t1.tab[j]){
			t2.tab[k]=t1.tab[i];
			i++;
		}
		else {
			t2.tab[k]=t1.tab[j];
			j++;
		}
		k++;
	}
	while(i<=iMilieu){
		t2.tab[k]=t1.tab[i];
		i++;
		k++;
	}
	while(j<=iMax){
		t2.tab[k]=t1.tab[j];
		j++;
		k++;
	}
	return t2;
}

TABLEAU triFusion(TABLEAU t1,int iMin,int iMax){
	int iMilieu;
	if(t1.taille==0){return t1;}
	else if(t1.taille==1){return t1;}
	else if(iMin<iMax){
		iMilieu=(iMin+iMax)/2;
		t1=triFusion(t1,iMin,iMilieu);
		t1=triFusion(t1,iMilieu+1,iMax);
		t1=fusionner(t1,iMin,iMilieu,iMax);
		return t1;
	}
}

/*void fusionner1(int t1[],int N,int iMin,int iMilieu,int iMax){
	int tInter[N];
	int i=iMin;
	int j=iMilieu+1;
	int k=0;
	while((i<=iMilieu)&&(j<=iMax)){
		if(t1[i]<t1[j]){
			tInter[k]=t1[i];
			i++;
		}
		else{tInter[k]=t1[j];j++;}
		
		k++;
	}
	
	int h;
	for(h=0;h<N;h++){
		t1[h]=tInter[h];
	}
	
}

void triFusion1(int T[],int N,int iMin,int iMax){
	if(iMin<iMax){
		int iMilieu=(iMin+iMax)/2;
		triFusion1(T,N,iMin,iMilieu);
		triFusion1(T,N,iMilieu,iMax);
		fusionner1(T,N,iMin,iMilieu,iMax);
	}
}

void init_tabl(int T[],int N){
	int i;
	for(i=0;i<N;i++){
		T[i]=alea(20);
	}
}

void affiche_tab(int T[],int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d ",T[i]);
	}
	printf("\n");
}*/

int main(){
	srand(time(NULL));
	
	TABLEAU t;
	t=initialiseTableau();
	afficheTableau(t);
	t=triFusion(t,0,t.taille-1);
	afficheTableau(t);
	
	//t=triFusion(t,0,t.taille-1);
	//afficheTableau(t);
	
	
	
	
	
	return 0;
}
