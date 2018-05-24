#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 12

struct acteur{
	int* bool;
	int* base;
	pthread_t thr;
	pthread_mutex_t* m;
	pthread_cond_t* c;
};typedef struct acteur ACTEUR;


void* produire(void* donnee){
	ACTEUR a=*((ACTEUR*)donnee);
	pthread_mutex_lock(a.m);
	if(*(a.bool)==0) pthread_cond_wait((a.c),(a.m));
	else{
		*(a.bool)=1;
		*(a.base)=90;
		printf("PRODUIT\n");
		pthread_cond_signal(a.c);
	}
	pthread_mutex_unlock(a.m);
}

void* consommer(void* donnee){
	ACTEUR a=*((ACTEUR*)donnee);
	pthread_mutex_lock(a.m);
	printf("Q\n");
	if(*(a.bool)==1){
		pthread_cond_wait((a.c),(a.m));
		printf("B\n");
	}
	else{
		*(a.bool)=0;
		printf("CONSOMME\n");
		pthread_cond_signal(a.c);
	}
	pthread_mutex_unlock(a.m);
}

int main(){
	pthread_mutex_t mutex;
	pthread_cond_t condition_producteur;
	pthread_cond_t condition_consommateur;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&condition_producteur,NULL);
	pthread_cond_init(&condition_consommateur,NULL);
	
	int base_donnees;
	int boolean_libre=1;
	ACTEUR producteur[N];
	ACTEUR consommateur[N];
	int i;
	
	for(i=0;i<N;i++){
		producteur[i].bool=&boolean_libre;
		producteur[i].base=&base_donnees;
		producteur[i].m=&mutex;
		producteur[i].c=&condition_producteur;
		
		consommateur[i].bool=&boolean_libre;
		consommateur[i].base=&base_donnees;
		consommateur[i].m=&mutex;
		consommateur[i].c=&condition_consommateur;
	}
	
	for(i=0;i<N;i++){
		pthread_create(&producteur[i].thr,NULL,produire,&producteur[i]);
	}
	for(i=0;i<N;i++){
		pthread_create(&consommateur[i].thr,NULL,consommer,&consommateur[i]);
	}
	
	for(i=0;i<N;i++){
		pthread_join(producteur[i].thr,NULL);
	}
	/*for(i=0;i<N;i++){
		pthread_join(consommateur[i].thr,NULL);
	}*/
	
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&condition_producteur);
	pthread_cond_destroy(&condition_consommateur);
}
