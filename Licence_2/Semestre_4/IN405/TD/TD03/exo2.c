#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 2
#define TAILLE 20

/*struct partie{
	int deb;
	int fin;
	//int* tt;
};typedef struct partie PARTIE;

int max(int a,int b){
	return ((a<b)?b:a);
}

//void* maxPartieTab(void* 

int main(){
	srand(time(NULL));
	int i,j;
	int t[20];
	PARTIE partiee[20/N];
	for(i=0;i<20;i++){
		t[i]=rand()%1000;
	}
	for(j=0;j<20/N;j+2){
		partiee[j].deb=j;
		partiee[j].fin=j+N;
	}
	for(i=0;i<20/N;i++){
		printf("%d : %d,%d\n",i,partiee[i].deb,partiee[i].fin);
	}
	return 0;
	//printf("%d\n", max(34,34));
	
}*/

int tab[TAILLE];
struct info{
	pthread_t th;
	int debut;
	int fin;
	int retour;
	//int* t;
};

void* recherche(void* data){
	struct info* d=data;
	d->retour=tab[d->debut];
	int i;
	for(i=d->debut;i<(d->fin);i++){
		if(d->retour<tab[i]) d->retour=tab[i];
	}
	return NULL;
}

int main(int argc,char** argv){

	/*int n=atoi(argv[1]);
	int tab[TAILLE];
	struct info infos[n];
	pthread_t thr[n];
	srand(time(NULL));
	int i,j;
	
	//creer tableau d'entiers
	for(i=0;i<TAILLE;i++){
		tab[i]=rand()%1000;
	}
	//for(j=0;j<T
	for(i=0;i<n;i++){
		infos[i].t=tab;
		//infos[i].th=thr[i];
		infos[i].debut=(TAILLE/n)*i;
		infos[i].fin=((TAILLE/n)*i)+(TAILLE/n);
	}
	for(j=0;j<n;j++){
		printf("%d> %d , %d\n",j,infos[j].debut,infos[j].fin);
	}*/

	int n=atoi(argv[1]);
	struct info donnees[TAILLE];
	srand(time(NULL));
	int i;
	for(i=0;i<TAILLE;i++){
		tab[i]=rand()%1000;
	}
	for(i=1;i<n;i++){
		donnees[i].debut=i*TAILLE/n;
		donnees[i].fin=(i+1)*TAILLE/n;
		donnees[i].retour=0;
		pthread_create(&donnees[i].th,NULL,recherche,&donnees[i]);
	}
	donnees[0].debut=0;
	donnees[0].fin=TAILLE/n;
	donnees[0].retour=0;
	recherche(&donnees[0]);
	for(i=1;i<n;i++){
		pthread_join(donnees[i].th,NULL);
	}
	for(i=1;i<n;i++){
		if(donnees[i].retour>donnees[0].retour){
			donnees[0].retour=donnees[i].retour;
		}
	}
	printf("MAX:%d\n",donnees[0].retour);
	return 0;
}
