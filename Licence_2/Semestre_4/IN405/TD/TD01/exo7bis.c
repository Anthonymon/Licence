#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void contenu_dossier(char* nom){
	DIR* directory;
	directory=opendir(nom);
	if(directory==NULL){
		printf("FAUX\n");
		exit(1);
	}
	struct dirent* structure;
	structure=readdir(directory);
	while(structure!=NULL){
		if(structure->d_name[0]!='.'){
			printf("%s\n",structure->d_name);

		}
		structure=readdir(directory);
	}
	
	
}

int main(int argc,char** argv){
	contenu_dossier(argv[1]);
	return 0;
}
