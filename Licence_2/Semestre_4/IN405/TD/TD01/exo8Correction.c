#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define T_BUF 4096

void copie_fichier(char* base,char* copie)
{
	int f1,f2;
	
	int reste;
	char buf[T_BUF];
	//char* p = buf;
	
	f1 = open(base,O_RDONLY);
	f2 = open(copie,O_WRONLY | O_CREAT,0666);
	
	while((reste = read(f1,buf,T_BUF * sizeof(char))) != 0) 
		write(f2,buf,reste * sizeof(char));
	
	close(f1);
	close(f2);
}

void copie_repertoire(char* base,char* copie)
{
	//printf("%s\n",base);
	//printf("%s\n",copie);
	
	DIR* repertoire = opendir(base);
	struct dirent* xd = readdir(repertoire);
	if((repertoire == NULL)||(xd == NULL))
	{
		printf("erreur de repertoire\n");
		exit(1);
	}
	
	char* c = malloc((strlen(copie)+256+1+1)*sizeof(char));
	char* d = malloc((strlen(base)+256+1+1)*sizeof(char));
	if((c == NULL)||(d == NULL))
	{
		printf("erreur de malloc\n");
		exit(1);
	}
	
	if((mkdir(copie,0700) != 0)&&(errno != 17))
	{
		printf("erreur de mkdir\n");
		printf("erreur : %d\n",errno);
		exit(1);
	}
	
	while(xd != NULL)
	{
		c[0] = '\0';
		strcat(c,copie);
		strcat(c,"/");
		strcat(c,xd -> d_name);
		d[0] = '\0';
		strcat(d,base);
		strcat(d,"/");
		strcat(d,xd -> d_name);
		
		if(xd -> d_name[0] != '.')
		{
			
			if(((xd -> d_type) & (DT_DIR)) != 0)
			{
				copie_repertoire(d,c);
			}
			else
			{
				copie_fichier(d,c);
			}
		}
		xd = readdir(repertoire);
	}
	
	closedir(repertoire);
	//printf("A");
}

int copie_arbre(char* source,char* copie){
	struct stat stbuf;
	int u=stat(source,&stbuf);
	if(u==-1) printf("A\n");
	
	int n;
	if(stbuf.st_mode & S_IFDIR!=0){
		/*n=*/copie_repertoire(source,copie);
		n=1;
		
	}
	else if(stbuf.st_mode & S_IFREG!=0){
		/*n=*/copie_fichier(source,copie);
		n=2;
	}
	else n=-1;
	return n;
}

int main(int argc,char** argv)
{
	copie_repertoire(argv[1],argv[2]);
	//int i=copie_arbre(argv[1],argv[2]);
	printf("%d\n",i);
	return 0;
}

