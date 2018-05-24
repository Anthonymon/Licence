#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){
	if(argc==1){
		printf("ERROR\n");
		exit(1);
	}
	int status;
	clock_t clock_start,clock_end;
	struct tms tms_start,tms_end;
	clock_start=times(&tms_start);
	
	int pid=fork();
	
	if(pid==-1) exit(1);
	/*//question1
	else if(pid==0){
		char chaine[259];
		chaine[0]='\0';
		strcat(chaine,"ls ");
		strcat(chaine,argv[1]);
		int i=system(chaine);
		if(i==-1) printf("ERREUR2");
	}
	//////*/
	
	/*//question2
	else if(pid==0){
		char chaine[270];
		chaine[0]='\0';
		strcat(chaine,"ls ");
		strcat(chaine,argv[1]);
		strcat(chaine," > /dev/null");
		//printf("%s\n",chaine);
		int i=system(chaine);
		if(i==-1) printf("ERREUR2");
	}
	//////*/
	//question 3
	else if(pid==0){
		char chaine[259];
		chaine[0]='\0';
		strcat(chaine,"ls ");
		strcat(chaine,argv[1]);
		int i=system(chaine);
		if(i==-1) printf("ERREUR2");
		clock_end=times(&tms_end);
		//printf("%d\n",clock_end-clock_start);
	}
	else {
		wait(&status);
	}
	
	
	return 0;
}
