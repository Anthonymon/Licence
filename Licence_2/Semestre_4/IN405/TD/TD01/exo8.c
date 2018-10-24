#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void arborescence(char* nom){
	DIR* directory;
	struct stat stbuf;
	directory=opendir(nom); //OUVERTURE
	if(directory==NULL){
		printf("Error1\n");
		exit(1);
	}
	struct dirent* structure;
	structure=readdir(directory);
	while(structure!=NULL){ //LECTURE EN COURS
		
		if(structure->d_name[0]!='.'){
			printf("->%s\n",structure->d_name);
			if(structure->d_type==DT_DIR){
				char* chemin=malloc(sizeof(nom)+strlen(structure->d_name)-sizeof(char));
				//int t=strlen(nom)+strlen("/")+strlen(structure->d_name);
				//char chemin[t];
				//printf("%d\n",strlen(nom)+strlen("/")+strlen(structure->d_name));
				chemin=strcat(nom,"/");
				chemin=strcat(chemin,structure->d_name);
				//printf("%s\n",chemin);
				arborescence(chemin); //PROBLEME ICI CAR AFFICHE ERROR1
				//arborescence(structure->d_name);
				//printf("OK\n");
				//free(chemin);
			}
		}
		structure=readdir(directory);
	}
	closedir(directory);
}

int main(int argc,char** argv){
	arborescence(argv[1]);
	//mkdir("test",666);
	return 0;
}
