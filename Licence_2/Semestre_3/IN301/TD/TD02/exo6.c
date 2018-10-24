#include <stdio.h>

int main(){
	/*int x,y;char c;int partie1; int partie2;int partie3=0;int resultat;
	printf("Multiplication entre 2 nombres\n");
	printf("Tapez la multiplication : ");
	scanf(" %d %c %d",&x,&c,&y);
	while(x!=1){
		if(x%2==0){
			x=(x/2);
			y=(2*y);
			printf("= %d x %d \n",partie1,partie2);
			
			
		}
		else {
			partie1=(x-1);
			partie2=y;
			partie3=y+partie3;
			printf("= %d x %d + %d \n", partie1,partie2,partie3);
			x=partie1;
			y=partie2;
		}
	}*/
	int a,x,y;
	a=0;
	scanf("%d",&x);
	scanf("%d",&y);
	printf("%d x %d\n",x,y);
	while(x!=1){
		if(x%2==1){
			a=a+y;
			x=x-1;
			printf("%d * %d + %d\n",x,y,a);
		}
		else {
			x=x/2;
			y=y*2;
			printf("%d x %d + %d",x,y,a);
		}
		printf("%d\n",y+a);	
	}
	return 0;
}
