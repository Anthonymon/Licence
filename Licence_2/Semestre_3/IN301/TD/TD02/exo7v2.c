#include <stdio.h>
int main(){
	float somme;
	float i=1.0;
	float precision=0.01;
	somme=0;
	while((1.0/(i*i))>precision){
		somme=somme+(1/i*i);
		i++;
	}
	printf("lim = %f",somme);
	
	return 0;
}
