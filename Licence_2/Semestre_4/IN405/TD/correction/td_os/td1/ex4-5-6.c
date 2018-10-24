#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXBUF 1024

int bgetchar();
void ex6(char* nom);

int main(int argc, char** argv)
{
	if(argc>1) ex6(argv[1]);
	
	int c;
	
	do
	{
		c = bgetchar();
		printf("%c\n",c);
	}while(c != EOF);
	
	return 0;
}

int bgetchar()
{
	static unsigned char buf[MAXBUF];
	static int ncar;
	static unsigned char* p;
	
	if(ncar == 0)
	{
		ncar = read(0,buf,MAXBUF*sizeof(char));
		p = buf;
	}
	
	/*if(ncar > 0)
	{
		ncar --;
		p ++;
		return *(p-1);
	}
	else return EOF;*/
	
	if(ncar -- > 0) return *p++;
	else return EOF; 
}

void ex6(char* nom)
{	
	char* s2 = malloc((strlen("pwd ")+strlen(nom))*sizeof(char));
	strcat(s2,"pwd ");
	strcat(s2,nom);
	system(s2);
	
	char* s1 = malloc((strlen("ls -l ")+strlen(nom))*sizeof(char));
	strcat(s1,"ls -l ");
	strcat(s1,nom);
	system(s1);
}

void ex6_2(char* nom)
{
	struct stat stbuf;
	char* type;
	char* perm = "";
	if(stat(nom,&stbuf) != 0)
	{
		perror("cannot stat");
		exit(1);
	}
	
	switch(stbuf.st_mode & S_IFMT)
	{
		case S_IFDIR:
			type = "repertoire";
			break;
		case S_IFREG:
			type = "fichier normal";
			break;
		case S_IFCHR:
			type = "fichier special";
			break;
		default :
			type = "???";
			break;
	}
	
	int mask = 0400;
	while(mask)
	{
		if(stbuf.st_mode & mask) strcat(perm,"1");
		else strcat(perm,"0");
		mask >>= 1;
	}
	
	printf("type : %s\n",type);
	printf("permission : %s\n",perm);
}





