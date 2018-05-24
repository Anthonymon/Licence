#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAXBUF 1024

void mygetcharbuf(char* b){
	static int i; //DEJA INITIALISE A 0
	char c;
	int d;
	d=read(0,&c,1);
	if(d==-1){
		printf("PROBL4\n");
		exit(1);
	}
	b[i]=c;
	i++;
	mygetcharbuf(b);
	b[i]='\0';
}

int bgetchar(){
	static unsigned char buf[MAXBUF];
	static int ncar; //DEJA INIT A 0
	static char* p;
	
	if(ncar==0){
		ncar=read(0,buf,MAXBUF); ////////IMPORTANT
		p=buf;
	}
	//static int j;
	//int temp=j;
	if(ncar>0){
		int g=*p; //g prend la valeur de p 
	*p++;
	//j++;
	//printf("%c\n",p[temp-1]);
	ncar--;
	//if(g=='\0') return -1;
	return g;
	}
	else return -1;
	

}

int correction2(){
	static unsigned char buf[MAXBUF];
	static int ncar;
	static char* p;
	
	if(ncar==0){ //REMPLIT LE BUFFER
		ncar=read(0,buf,MAXBUF);
		p=buf; //POINTEUR AU DEBUT DU TABLEAU
	}
	if(ncar-- >0) return *p++; //VERIFIE SI IL Y A DES CARACTERES A ECRIRE
	//(ncar-- >0) = if(ncar>0){ncar=-1;}
	else return -1;
}

int main(){
	int res;
	while(1){
		res=bgetchar();
		if(res==-1){
			printf("EOF\n");
			break;
		}
		printf("got : %c\n",res);
	}
	return 0;
}
