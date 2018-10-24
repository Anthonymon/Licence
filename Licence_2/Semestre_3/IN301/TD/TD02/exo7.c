#include <stdio.h>

int main(){
	float precision =0.1;
	float s=0;
	int i=0;
	while(1.0/(i*i)>precision){
		s=s+(1.0/(i*i));
		i++;
	}
	printf("La limite est : %f",s);
	return 0;
}
