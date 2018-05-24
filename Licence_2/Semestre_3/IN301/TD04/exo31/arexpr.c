#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct elemArith{
	int type; //0 pour le float 1 pour addition 
	float val;
	struct elemArith* filsG;
	struct elemArith* filsD;
};

typedef struct elemArith* arithExpr;


int parenthese_pos(char *s){//retourne la position de la parenthèse qui ferme la parenthèse en position 0
	int i=0;
	int compteur=1;
	do{
		i++;
		if(s[i]=='('){
			compteur++;
		}
		if(s[i]==')'){
			compteur--;
		}
	} while(compteur!=0);
	return i;
}


arithExpr lire_chaine(char *s){
	if(s[0]=='\0') return NULL;
	arithExpr nouveau = malloc(sizeof(struct elemArith));
	if(s[0]!='('){
		nouveau->type=0;
		sscanf(s,"%f",&nouveau->val);
		nouveau->filsD=NULL;
		nouveau->filsG=NULL;
	}
	else{
		int pos=parenthese_pos(s);
		if(s[pos+1]=='+') nouveau->type=1;
		else nouveau->type=2;
		nouveau->filsG=lire_chaine(s+1);
		nouveau->filsD=lire_chaine(s+pos+3);
	}
	return nouveau;
}


void affiche(arithExpr a){
	if(a!=NULL){
	
		if(a->type==1){ printf("+ ");}
		if(a->type==2){printf("x ");}
		if(a->type==0) printf("%f ",a->val);
		
		affiche(a->filsG);
		affiche(a->filsD);
	}
	//printf("AAA");
	
}

double eval_arith(arithExpr a){
	if(a->filsG!=NULL){
		if(a->type==1){
			return (eval_arith(a->filsG))+(eval_arith(a->filsD));
		}
		if(a->type==2){
			return (eval_arith(a->filsG))*(eval_arith(a->filsD));

		}
	}
	else{
		return a->val;
	}
	//return 0;
}

arithExpr rand_arith(int n, int m){
	return NULL;
	
}

void free_arith(arithExpr a){
	
}

arithExpr simplifie(arithExpr a){
	return NULL;
}


int main(int argc, char **argv){

	srand(time(NULL));

	if(argc != 2){
		printf("Il doit y a voir comme unique argument le chemin du fichier à ouvrir \n");	
		exit(1);
	}
	
	FILE *f = fopen(argv[1],"r");
	char buffer[300];
	fscanf(f,"%s",buffer);
	/*printf("Taille du fichier : %d\n",(int)strlen(buffer));
	printf("Contenu du fichier %s\n",buffer);
	printf("Position de la parenthèse fermante de la première parenthèse : %d\n",parenthese_pos(buffer));*/
	
	////////////////// Test des fonctions ///////////////////////
	//printf("!!%s\n,buffer);
	arithExpr a = lire_chaine(buffer);
	affiche(a);
	printf("= %f\n",eval_arith(a));
	//printf("\nValeur de l'expression : %f\n",eval_arith(a));
	//free_arith(a);
	//a = rand_arith(5,100);
	//affiche(a);
	free_arith(a);
	fclose(f);

	//printf("%d\n",parenthese_pos("((345*45)+2)*5"));
	exit(0);

}
