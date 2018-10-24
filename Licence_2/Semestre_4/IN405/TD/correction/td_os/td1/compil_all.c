#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	DIR* repertoire = opendir("./");
	
	char nom[256];
	char commande[256*2+50];
	
	struct dirent* xd = readdir(repertoire);
	
	while(xd != NULL)
	{
		//printf("%s\n",&(xd -> d_name[strlen((xd -> d_name)-2)]));
		//printf("%s\n",&(xd -> d_name[strlen(xd -> d_name) - 2]));
		
		if((xd -> d_name[0] != '.')&&(((xd -> d_type) & DT_DIR) == 0)&&(strcmp(xd -> d_name,"compil_all.c") != 0)&&(strncmp(&(xd -> d_name[strlen(xd -> d_name) - 2]),".c",2*sizeof(char)) == 0))
		{
			strcpy(nom,xd -> d_name);
			//nom[strlen(nom)- 2] = '\0';
			nom[strlen(nom)- 1] = '\0';
			strcat(nom,"out");
			
			commande[0] = '\0';
			strcat(commande,"gcc -o ");
			strcat(commande,nom);
			strcat(commande," ");
			strcat(commande,xd -> d_name);
			strcat(commande," -Wall");
			
			//printf("%s\n",commande);
			
			system(commande);
		}
		xd = readdir(repertoire);
	}
	
	closedir(repertoire);

	return 0;
}
