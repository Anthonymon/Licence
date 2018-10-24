#include <stdio.h>
#include <stdlib.h>

void permutation(int* a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void reinitPointeur(int*(*p)){
	(*p)=0;
}

int main(){
	/*int x=2;
	int y=3;
	printf("x = %d y = %d\n",x,y);
	permutation(&x,&y);
	printf("x = %d y = %d\n",x,y);*/
	
	int a=1;
	printf("a = %d\n",a);
	int* p=&a;
	reinitPointeur(&(*p));
	printf("a = %d\n",a);
	
	
	return 0;
}
