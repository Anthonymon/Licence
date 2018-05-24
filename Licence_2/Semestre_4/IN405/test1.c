#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	//~ int a=fork();
	//~ if(a==0){
		//~ printf("A\n");
		//~ //exit(1);
	//~ }
	//~ else {
		//~ printf("B\n");
		//~ wait(NULL);
	//~ }
	
	int a,i,retour;
	for(i=0;i<10;i++){
		a=fork();
		if(a==0){
			printf("%d\n",i);
			exit(1);
		}
		else {
			wait(NULL);
		}
	}
	return 0;
}
