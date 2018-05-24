#include <stdio.h>

int main(){
	int i,j;
	i=0; j=0;
	for(i=0;i<10;i++){
		for(j=0;j<9-i;j++){
			printf(" ");
		}
		printf("x\n");
	}
	return 0;
}
