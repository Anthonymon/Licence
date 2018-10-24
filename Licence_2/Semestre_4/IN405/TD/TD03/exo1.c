#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//compile avec -pthread

#define N 12

void* print(void* val){ //TJRS UN ARG TJRS VOID*
	int valeur=*((int*)val);
	printf("num thread %d\n",valeur);
	int *retour=malloc(sizeof(int));
	*retour=valeur*2;
	printf("retour du thread=%d\n",*retour);
	return retour;
}

int main(){
	int tab[N];
	pthread_t threads[N];
	void* thread_retour;
	int i;
	//long t;
	for(i=0;i<N;i++){
		tab[i]=i;
		printf("Numero du Thread créé: %d\n",i);
		pthread_create(&threads[i], NULL /*tjrs*/, print,&tab[i]);
		//if(thread_return!=0) exit(1);
		//pthread_join(&threads[i],
	}
	for(i=0;i<N;i++){
		pthread_join(threads[i],&thread_retour);
		free(thread_retour);
	}
	//return 0;
	//pthread_exit(NULL);
}
