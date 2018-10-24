#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

#define MAXBUF 1024

int main(){
	pid_t pid;
	char buffer[20];
	int status;
	int tab_tube[2];
	pipe(tab_tube);
	pid=fork();
	if(pid==0){
		close(tab_tube[0]);
		write(tab_tube[1],"ZBEUB",sizeof(buffer));
		close(tab_tube[1]);
	}
	else{
		close(tab_tube[1]);
		read(tab_tube[0],buffer,sizeof(buffer));
		close(tab_tube[0]);
		printf("BUFFER : %s\n",buffer);
	}
}
