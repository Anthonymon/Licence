#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define N 3
#define NB_PRODUCTEURS 4
#define NB_CONSOMMATEURS 4

int tab[N];
int rang_pose;
int rang_prise;
int objet_cons=0;
int objet_prod=0;
sem_t case_vide;
sem_t case_pleine;
pthread_mutex_t mutex1;
pthread_mutex_t mutex2; 
pthread_t prod[NB_PRODUCTEURS];
pthread_t cons[NB_CONSOMMATEURS];
//semwait decremente si sup a 0
//sempost incremente
//si cest à 


void* produire(void* donnee){
	//int d=(int)donnee;
	sem_wait(&case_vide); //il attend que case_vide!=N il decremente case_vide
	int a=pthread_mutex_lock(&mutex1);
	tab[rang_pose]=/*donnee*/objet_prod;
	rang_pose=(rang_pose+1)%N;
	printf("INSERTION DE %d\n",objet_prod);
	a=pthread_mutex_unlock(&mutex1); 
	sem_post(&case_pleine); //il incremente case_pleine
	return NULL;
}

void* consommer(void* infos){
	sem_wait(&case_pleine); //il attend que case_pleine!=0 il decremente case_pleine
	int a=pthread_mutex_lock(&mutex2);
	int donnee=tab[rang_prise];
	printf("CONSOMMATION DE %d\n",donnee);
	rang_prise=(rang_prise-1)%N;
	a=pthread_mutex_unlock(&mutex2);
	sem_post(&case_pleine); //il incremente case_vide
	//return donnee;
	return NULL;
}

int main(){
	//pthread_t threads[NB_PRODUCTEURS+NB_CONSOMMATEURS];
	//int bool;
	/*for(i=0;i<NB_PRODUCTEURS+NB_CONSOMMATEURS;i++){
		bool=rand()%2;
		if(bool==0) pthread_create(&threads[i].th,NULL,
		pthread_create(&threads[i].th,NULL,recherche,&donnees[i]);
	}*/
	int i;
	int test1=sem_init(&case_vide,0,N);
	int test2=sem_init(&case_pleine,0,0);
	int test3=pthread_mutex_init(&mutex1,NULL);
	int test4=pthread_mutex_init(&mutex2,NULL);
	rang_pose=rang_prise=0;
	//cree les threads
	for(i=0;i<NB_PRODUCTEURS;i++)
		pthread_create(&prod[i],NULL,consommer,NULL);
	for(i=0;i<NB_CONSOMMATEURS;i++)
		pthread_create(&cons[i],NULL,produire,NULL);

	//attend la fin des threads
	for(i=0;i<NB_PRODUCTEURS;i++)
		pthread_join(prod[i],NULL);
	for(i=0;i<NB_CONSOMMATEURS;i++)
		pthread_join(cons[i],NULL);

	return 0;
}
