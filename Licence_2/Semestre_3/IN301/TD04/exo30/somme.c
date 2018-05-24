#include <stdio.h>
#include <stdlib.h>

void faire_message_erreur(){
	printf("NUUUUUUL A REFAIRE\n");
	exit(1);
}

int test(char* s){
	
	if(!(isdigit(s[0])||s[0]=='-')){
		faire_message_erreur();
	}
	int i=1;
	int compteurPoints=0;
	while(s[i]!='\0'){
		if(isdigit(s[i])==0){
			if(s[i]=='.'){
				compteurPoints++;
			}
			else return 0;
		}
		if(compteurPoints>1){
			return 0;
		}
		i++;
	}
	return 1;
}

int test2(char* s){
	int i;
	int compteurParenthesesDroites=0;
	int compteurParenthesesGauches=0;
	while(s[i]!='\0'){
		if(s[i]=='('){
			compteurParenthesesGauches++;
		}
		if(s[i]==')'){
			compteurParenthesesDroites++;
		}
		i++;
	}
	if(compteurParenthesesDroites==compteurParenthesesGauches){
		return 1;
	}
	return 0;
}



int main(int argc,char** argv){
	double som=0;
	int i;
	
	for(i=1;i<argc;i++){
		if(test(argv[i])==0){
			faire_message_erreur();
		}
		som=som+atof(argv[i]);
	}
	printf("%f\n",som);
	

	
	return 0;
}
