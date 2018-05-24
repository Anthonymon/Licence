#include <stdio.h>
#include <stdlib.h>

/*void permutation(int *i,int *j){
	int e=*i;
	*i=*j;
	*j=e;
	
}*/

void reinitPointeur(int *(*b)){
	*b=NULL;
}

int main(){
	/*printf("Taille char : %lu \n",sizeof(char));
	printf("Taille int : %lu \n", sizeof(int));
	printf("Taille long int : %lu \n",sizeof(long int));
	printf("Taille double : %lu \n",sizeof(double));
	printf("Taille char* : %lu \n", sizeof(char*));
	printf("Taille void* : %lu \n",sizeof(void*));
	printf("Taille int* : %lu \n",sizeof(int*));
	printf("Taille double* : %lu \n",sizeof(double*));
	printf("Taille int** : %lu \n",sizeof(int**));
	printf("Taille int [10] : %lu \n",sizeof(int[10]));
	printf("Taille char[7][3] : %lu \n",sizeof(char[7][3]));
	printf("\n");
	char tab[10];
	printf("Taille tab : %lu\n",sizeof(tab));
	printf("Taille tab[0] : %lu\n",sizeof(tab[0]));
	printf("Taille &tab[0] : %lu\n",sizeof(&tab[0]));
	printf("Taille *&tab : %lu\n",sizeof(*&tab));
	printf("Taille *&tab[0] : %lu\n",sizeof(*&tab[10]));
	printf("\n");
	char (*p)[10]=&tab;
	printf("Taille p : %lu\n",sizeof(p));
	printf("Taille *p : %lu\n",sizeof(*p));
	printf("Taille (*p)[2] : %lu\n",sizeof((*p)[2]));
	printf("Taille &(*p)[2] : %lu\n",sizeof(&(*p)[2]));*/
	
	/*int test1;int test2;
	printf("Ecris un nombre : ");
	scanf("%d",&test1);
	printf("Ecris un deuxieme nombre : ");
	scanf("%d",&test2);
	permutation(&test1,&test2);
	printf("%d et %d \n",test1,test2);*/
	
	int a=1;
	int *p=&a;
	printf("%p\n",p);
	reinitPointeur(&p);
	printf("%p\n",p);
	
	
	
	return 0;
}
