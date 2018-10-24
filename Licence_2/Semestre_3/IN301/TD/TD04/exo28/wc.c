#include <stdio.h>
#include <stdlib.h>

int calcul_nb_caracteres_fichier(FILE* f){
	int compteur=0;
	char c;
	c=fgetc(f);
	if(c==EOF){return compteur;}
	while(c!=EOF){
		c=fgetc(f);
		compteur++;
		if(c=='\n'){
			compteur--;
		}
	}
	return compteur;
}

int calcul_nb_mots_fichier(FILE *f){
	/*int compteur=0;
	char c;
	c=fgetc(f);
	if(c==EOF){return compteur;}
	while(c!=EOF){
		c=fgetc(f);
		if(c==' '){
			compteur++;
		}
	}
	return compteur;*/
	int compteur=0;
	char c1;
	//char c2;
	c1=getc(f);
	if(c1==EOF){
		return compteur;
		//printf("TEST");
	}
	while(c1!=EOF){
		if((c1==' ')||(c1=='\n')){
			compteur++;
		}
		while((c1==' ')||(c1=='\n')){
			c1=fgetc(f);
		}
		c1=fgetc(f);
	}
	return compteur;
	
	
}

int main(int argc,char **argv){
	FILE* F=fopen(argv[1],"r");
	if(F==NULL){exit(1);}
	//printf("%d\n",calcul_nb_caracteres_fichier(F));
	printf("%d\n",calcul_nb_mots_fichier(F));
	return 0;
}
