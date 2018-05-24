#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 4

void* affiche_thread(void* val){
	int entier=*((int*)val);
	printf("thread affiche: %d\n",entier);
	int* new=malloc(sizeof(int));
	*new=entier*2;
	return new;
}

int main(){
	pthread_t tab_threads[N];
	int tab[N];
	int i;
	int ret;
	void* val;
	//int p;
	for(i=0;i<N;i++){
		tab[i]=i;
		pthread_create(&tab_threads[i],NULL,affiche_thread,&(tab[i]));
	}
	
	for(i=0;i<N;i++){
		pthread_join(tab_threads[i],&val);
		ret=*((int*)val);
		printf("retour du thread: %d\n",ret);
	}
	return 0;
}
