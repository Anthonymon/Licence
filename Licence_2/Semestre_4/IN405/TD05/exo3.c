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

/*int compteur_max(int* tab){
	int compteur=0;
	char c='a';
	int d=write(tab[1],&c,1);
	while(d!=0){
		d=write(tab[1],&c,1);
		compteur++;
	}
	return compteur;
}

int main(){
	pid_t pid;
	char buffer[20];
	int status;
	int tab_tube[2];
	pipe(tab_tube);
	pid=fork();
	if(pid==0){
		close(tab_tube[0]);
		//write(tab_tube[1],"ZBEUB",sizeof(buffer));
		printf(">>%d\n",compteur_max(tab_tube));
		close(tab_tube[1]);
	}
	else{
		close(tab_tube[1]);
		//read(tab_tube[0],buffer,sizeof(buffer));
		close(tab_tube[0]);
		//printf("BUFFER1 : %s\n",buffer);
	}
}*/

#define INCREMENT 1024
int taille;

void afficher(int signo){
	printf("%d octets\n",taille);
	exit(0);
}

int main(){
	char buf[INCREMENT];
	int pipefd[2];
	struct sigaction sa;
	pipe(pipefd);
	taille=0;
	sa.sa_handler=afficher;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	if(sigaction(SIGALRM,&sa,NULL)==1){
		exit(1);
	}
	alarm(4);
	while(1){
		write(pipefd[1],buf,INCREMENT);
		taille+=INCREMENT;
	}
}
