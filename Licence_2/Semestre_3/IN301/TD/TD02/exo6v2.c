#include <stdio.h>

int main(){
	int x;int y;int z;
	scanf("%d",&x);
	scanf("%d",&y);
	printf("%d x %d \n",x,y);
	int c;
	int resul;
	while(x>1){
		if(x%2==1){
			x=x-1;
			c=c+y;
		}
		else {
			x=x/2;
			y=y*2;
			}
	printf("= %d x %d + %d \n",x,y,c);
	}
	resul=c*x+y;
	printf("= %d",resul);
	return 0;
}
