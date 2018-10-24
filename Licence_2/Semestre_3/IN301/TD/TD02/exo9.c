#include <stdio.h>

int calculDiv(int u,int v){
	int somme=0;
	int i;
	for(i=1;i<u;i++){
		if(u%i==0){
			somme=somme+i;
		}
	}
	return somme;
}

int main(){
	int m;int n;
	printf("Quel est ton premier nombre : ");
	scanf("%d",&m);
	printf("Quel est ton deuxieme nombre : ");
	scanf("%d",&n);
	if((n<0)||(m<0)){
		printf("%d et %d ne sont pas amis\n",m,n);
	}
	else {
		if((calculDiv(m,n)==n)&&(calculDiv(n,m)==m)){
			printf("%d et %d sont amis",m,n);
		}
		else {printf("%d et %d ne sont pas amis",m,n);}
	}
	
	return 0;
}
