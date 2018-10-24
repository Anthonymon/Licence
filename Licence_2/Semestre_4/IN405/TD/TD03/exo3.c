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

int tab[TAILLE];
pthread_mutex_t mutex;
int max=0;


struct info{
	pthread_t th;
	int debut;
	int fin;
	int retour;
};

void* recherche(void* data){
	int max_local;
	struct info* d=data;
	max_local=tab[d->debut];
	int i;
	for(i=d->debut;i<(d->fin);i++){
		pthread_mutex_lock(&mutex);
		if(max_local<tab[i]) max_local=tab[i];
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(int argc,char** argv){
	pthread_mutex_init(&mutex,NULL);
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
	/*for(i=1;i<n;i++){
		if(donnees[i].retour>donnees[0].retour){
			donnees[0].retour=donnees[i].retour;
		}
	}*/
	//printf("MAX:%d\n",donnees[0].retour);
	printf("MAX:%d\n",max);
	pthread_mutex_destroy(&mutex);
	return 0;
}

