#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXBUF 1024

/*void which(char* in){
	DIR* directory;
	char* 
}

void decompose(char* in){
	int i;
	for(i=0;i<strlen(in)+1;i++){
		if(in[i]==':') in[i]='\n';
	}
	printf("%s\n",in);
}

int main(int argc,char** argv){
	char* p=getenv("PATH");
	decompose(p);
	return 0;
}*/

void separe(char* chaine,char** tab){
	char* q;
	int ntab;
	ntab=0;
	q=chaine;
	while(*q!='\0'){
		tab[ntab++]=q;
		while(*q!='\0' && *q!=':'){
			*q++;
		}
		if(*q==':'){
			*q++='\0';
		}
		tab[ntab]=NULL;
	}
}

int main(int argc,char**argv){
	int i;
	char* tab[20];
	char buf[MAXBUF];
	if(argc!=2) exit(1);
	separe(getenv("PATH"),tab);
	printf("PATH: ");
	i=0;
	while(tab[i]!=NULL){
		printf("%s\n",tab[i]);
		i++;
	}
	printf("LOOKING FOR %s cmd\n",argv[1]);
	i=0;
	while(tab[i]!=NULL){
		sprintf(buf,"%s%s",tab[i],argv[1]);
		if(access(buf,X_OK)!=-1){
			exit(0);
		}
		i++;
	
	}
}
