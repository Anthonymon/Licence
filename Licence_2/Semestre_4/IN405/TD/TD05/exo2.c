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

void creation(int* compteur, int nb_process,int* tab_tube){
	char buffer[20];
	close(tab_tube[1]);
	read(tab_tube[0],buffer,sizeof(buffer));
	close(tab_tube[0]);
	int pid=fork();
	if(pid==0){ //fils
		if((*compteur)<(nb_process)){
			(*compteur)++;
			printf("%d\n",(*compteur));
			creation(compteur,nb_process,tab_tube);
		}
	}
	else{
		wait(NULL);	
	}
}

int main(int argc, char** argv){
	int nb_process=atoi(argv[1]);
	int compteur=0;
	char buffer[20];
	int tab_tube[2];
	pipe(tab_tube);
	int pid=fork();
	if(pid==0){
		
		creation(&compteur,nb_process,tab_tube);
	}
	else{
		close(tab_tube[0]);
		write(tab_tube[1],"ZBEUB",sizeof(buffer));
		close(tab_tube[1]);
		wait(NULL);
	}
	return 0;	
}
