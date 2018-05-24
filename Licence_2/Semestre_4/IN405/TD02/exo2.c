#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#define N 20

int main(){
	
	int pid,return_value,i;
	for(i=0;i<N;i++){
		pid=fork();
		if(pid==-1) exit(0);
		if(pid==0) exit(getpid()%10);
	}
	for(i=0;i<N;i++){
		pid=wait(&return_value);
		printf("pid fils: %d\n",pid);
		printf("return value: %d\n",WEXITSTATUS(return_value));
	}
	exit(0);
}
