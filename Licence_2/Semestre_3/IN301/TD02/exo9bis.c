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
	/*int m;int n;
	printf("Quel est ton premier nombre : ");
	scanf("%d",&m);
	printf("Quel est ton deuxieme nombre : ");
	scanf("%d",&n);
	if((n<0)||(m<0)){
		printf("%d et %d ne sont pas amis\n",m,n);
	}
	else {
		if((calculDiv(m,n)==n)&&(calculDiv(n,m)==m)){
			printf("%d et %d sont amis\n",m,n);
		}
		else {printf("%d et %d ne sont pas amis\n",m,n);}
	}*/
	int m=100000;//int n=100000;
	int i;int j;int so;
	for(i=1;i<m;i++){
		for(j=1;j<i;j++){
			if(i%j==0){
				so=so+j;
			}
		}
		if((calculDiv(i,so)==so)&&(calculDiv(so,i)==i)){
			printf("%d %d\n",i,so);
		}
	}
	printf("fini\n");
	return 0;
}
