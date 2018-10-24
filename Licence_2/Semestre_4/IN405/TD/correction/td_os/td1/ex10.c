#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>

char** separe_chaine(char* chaine)
{	
	int i,j,k;
	char** tab_char;
	int nbr_dir = 0;
	
	for(i=0;i<strlen(chaine);i++) if(chaine[i] == ':') nbr_dir++;
	nbr_dir += 2;
	
	//printf("%d\n",nbr_dir);
	
	tab_char = malloc(nbr_dir*sizeof(char*));
	if(tab_char == NULL)
	{
		printf("pb malloc\n");
		exit(1);
	}
	
	for(i=0;i<nbr_dir;i++)
	{
		tab_char[i] = malloc((strlen(chaine) + 1)*sizeof(char));
		if(tab_char[i] == NULL)
		{
			printf("pb malloc\n");
			exit(1);
		}
	}
	
	j = 0;k = 0;
	
	for(i=0;i<strlen(chaine);i++)
	{
		if(chaine[i] != ':')
		{
			tab_char[j][k] = chaine[i];
			k++;
		}
		else
		{
			tab_char[j][k] = '\0';
			k = 0;
			j++;
		}
		//printf("%s\n",tab_char[j]);
		//printf("j : %d , k : %d\n",j,k);
	}
	
	tab_char[nbr_dir - 1][0] = ':';
	
	return tab_char;
}

void affiche_dir()
{
	char* path;
	path = getenv("PATH");
	
	printf("%s\n",path);
	
	if(path == NULL)exit(1);
	
	char** tab_dir = separe_chaine(path);
	
	int i;
	
	while(tab_dir[i][0] != ':')
	{
		printf("%s\n",tab_dir[i]);
		i++;
	}
}

void which(char* fct_name)
{
	system("clear");
	
	char* path;
	path = getenv("PATH");
	
	if(path == NULL)exit(1);
	
	char** tab_dir = separe_chaine(path);
	
	int i,continuer,res;
	i = 0;continuer = 1;res = 0;
	
	DIR* repertoire;
	struct dirent* xd;
	
	while((continuer == 1)&&(tab_dir[i][0] != ':'))
	{
		repertoire = opendir(tab_dir[i]);
		if(strcmp(tab_dir[i],"/usr/local/games\"") != 0)xd = readdir(repertoire);
		else xd = NULL;
		
		while(xd != NULL)
		{
			if(strcmp(xd -> d_name,fct_name) == 0)
			{
				continuer = 0;res = 1;
				printf("%s se trouve dans %s\n",fct_name,tab_dir[i]);
			}
			xd = readdir(repertoire);
		}
		
		closedir(repertoire);
		
		i++;
	}
	if(res == 0)printf("%s ne se trouve dans aucun des repertoires cités par PATH\n",fct_name);
}

int main(int argc,char** argv)
{
	//affiche_dir();
	
	which(argv[1]);
	
	exit(0);
}
