

#include <stdio.h>
#include "constantes.h"
#include "sudoku.h"
#include <string.h>

void lire(SUDOKU S){
	FILE *F=fopen("sudoku.sudo","r");
	int x,y;
	for(x=0;x<N;x++){
		for(y=0;y<N;y++){
			fscanf(F,"%d",&(S.la_case[y][x].val));	
		}
	}
	fclose(F);

}

SUDOKU lire2(char *nomFichier){ //
	SUDOKU s;
	FILE *f=fopen(nomFichier,"r");
	if(f!=NULL){
		printf("FICHIER INVALIDE");
		//exit(1);
	}
	int x,y;
	char c;
	for(x=0;x<9;x++){
		for(y=0;y<9;y++){
			c=getc(f);
			while((c=='\n') || (c==' '))c=fgetc(f);
			s.la_case[x][y].val=c-48;
			//s.la_case[y][x].modifiable=0;
			if(s.la_case[x][y].val){
				s.la_case[x][y].modifiable=0;
			}
			else{
				s.la_case[x][y].modifiable=1;
			}
			
		}
	}
	fclose(f);
	return s;
}

void ecrire(SUDOKU S){
	FILE *F=fopen("sudoku.sudo","w");
	int x,y;
	for(x=0;x<N;x++){
		for(y=0;y<N;y++){
			fprintf(F,"%d ",S.la_case[y][x].val);
		}
		fprintf(F,"\n");
	}
	fclose(F);
	//fill_screen(red);
}

int testeMotsIdentiques(char* s1,char* s2){
	if(strcmp(s1,s2)==0){
		return 1;
	}
	return 0;
} 


int testeExtensionSudo(char* s1){
	char* extansion=s1;
	int num=strlen(s1);
	extansion=s1+num-strlen(".sudo");
	return testeMotsIdentiques(extansion,".sudo");
} 

char* retourneNomFichier(int num,char** mot){
	if(num==3){
		if(testeMotsIdentiques(mot[1],"play")==1){
			if(testeExtensionSudo(mot[2])){
				return mot[2];
			}
		}
	}
	return "COMMANDE INVALIDE";
}



