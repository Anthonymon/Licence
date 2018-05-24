#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void matproc(int n,int m){
	if(m>0){
		int pid,return_value,i;
		for(i=0;i<n;i++){
			pid=fork();
			if(pid==-1) exit(0);
			if(pid==0){
				matproc(n,m-1);
				exit(getpid()%10);
			} 
		}
		for(i=0;i<n;i++){
			pid=wait(&return_value);
			printf("pid fils: %d\n",pid);
			printf("return value: %d\n",WEXITSTATUS(return_value));

		}
	}
}

int main(int argc,char** argv){
	if(argc==1){
		printf("ERREUR\n");
		exit(1);
	 }
	int n=atoi(argv[1]);
	int m=atoi(argv[2]);
	matproc(n,m);
	exit(0);
}
