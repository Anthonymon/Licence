#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*void lsl(char* nm){
	struct stat buf;
	int test;
	test=stat(nm,&buf);
	if(test==-1){
		printf("ERROR\n");
		exit(1);
	}
}*/


void lsll(char* nm){
	struct stat stbuf;
	int mask;
	char prot[9 + 1], *p;
	char * type;
	
	if(stat(nm,&stbuf)!=0){
		exit(1);
	}
	switch(stbuf.st_mode & S_IFMT){
		case S_IFDIR:
		type="repertoire";
		break;
		case S_IFREG:
		type="fichier normal";
		break;
		case S_IFCHR:
		type="fichier special";
		break;
		default:
		type="???";
		break;
	}
	
	strcpy(prot,"rwxrwxrwx");
	p=prot;
	mask=400;
	while(mask!=0){
		if((stbuf.st_mode & mask)==0){
			*p='-';
		}
		p++;
		mask>>=1;
	}
	
	printf("%s:\ntype : %s\nprotection : %s\n",nm,type,prot);
}

void myfunction(char* nom){
	struct stat buf;
	char* typee;
	if(stat(nom,&buf)==-1) exit(1);
	int type=(buf.st_mode & S_IFMT);
	if(type==S_IFREG) typee="REGULAR FILE";
	else if(type==S_IFDIR) typee="DIRECTORY";
	else if(type==S_IFCHR) typee="CHARACTER DEVICE";
	else typee="???";
	/*switch(buf.st_mode & S_IFMT){
		case S_IFDIR:
		typee="repertoire";
		break;
		case S_IFREG:
		typee="fichier normal";
		case S_IFCHR:
		typee="fichier special";
		break;
		default:
		typee="???";
		break;
	}*/
	printf("%s\n",typee);
	int mask=400; //100 000 000 en binaire
	int type2=(buf.st_mode & mask);
	int compteur=0;
	while(mask!=0){
		type2=(buf.st_mode & mask);
		if((type2!=0)&&(compteur%3==0))printf("r");
		else if((type2!=0)&&(compteur%3==1))printf("w");
		else if((type2!=0)&&(compteur%3==2))printf("x");
		else printf("-");
		compteur++;
		mask>>=1;
	}
	printf("\n");
	//if(type2==0) printf("A\n");
}


int main(int argc,char* argv[]){
	lsll(argv[1]);
	printf("\n");
	myfunction(argv[1]);
}
