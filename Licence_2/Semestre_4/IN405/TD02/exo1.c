#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
	int pid=fork();
	if(pid==-1){
		exit(-1);
	}
	else if(pid==0){ //fils
		printf("fils: pid fils = %d\n",getpid());
		printf("fils: pid pere = %d\n",getppid());
		exit(getpid()%10);
	}
	else{ //pere
		int status;
		printf("pere: pid pere = %d\n",getpid());
		printf("pere: pid fils = %d\n",pid);
		wait(&status);
		printf("status: %d\n",status);
		if(WIFEXITED(status)){
			printf("exited, status=%d\n",WEXITSTATUS(status));
		}
		else if(WIFSIGNALED(status)){
			printf("killed by signal %d\n",WTERMSIG(status));
		}
		else if(WIFSTOPPED(status)){
			printf("stopped by signal %d\n",WSTOPSIG(status));
		}
		else if(WIFCONTINUED(status)){
			printf("continued\n");
		}
	}
	return 0;
}

