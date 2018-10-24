#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

/*#define N 3

int nthreads=0;
pthread_cond_t cond;
pthread_mutex_t mutex;

void barrier(pthread_t* tab_thr,int taille){

	
	pthread_mutex_lock(&mutex);
	while (nthreads <= N) {
		nthreads++;
		pthread_cond_wait(&cond, &mutex);
	}
	//pthread_mutex_unlock(&mutex);
	pthread_cond_broadcast(&cond);
	
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);
}

void* fonction(){
	printf("A\n");
}

int main(){
	int i;
	pthread_t tab_thr[N];
	pthread_cond_init(&cond,NULL);
	pthread_mutex_init(&mutex,NULL);
	for(i=0;i<N;i++){
		pthread_create(&(tab_thr[i]),NULL,fonction,NULL);
	}
	barrier(tab_thr,N);
	for(i=0;i<N;i++){
		pthread_join(tab_thr[i],NULL);
	}
	return 0;
}*/

#define MAXTH 5
int nthreads;

void barrier(void){
	static pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
	static pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
	static int barriercnt=0;
	
	pthread_mutex_lock(&mutex);
	barriercnt++;
	printf("thread %d in barrier, max is %d threads in barrier\n",barriercnt,nthreads);
	if(barriercnt<nthreads) pthread_cond_wait(&cond,&mutex);
	else{
		pthread_cond_broadcast(&cond);
		barriercnt=0;
	}
	pthread_mutex_unlock(&mutex);
}

void* func(void* arg){
	static pthread_mutex_t randmut=PTHREAD_MUTEX_INITIALIZER;
	int delai;
	pthread_mutex_lock(&randmut);
	delai=rand()%10+1;
	pthread_mutex_unlock(&randmut);
	printf("waiting %d seconds\n",delai);
	sleep(delai);
	barrier();
	return NULL;
}

int main(){
	int i;
	pthread_t tab_thr[MAXTH];
	nthreads=3;
	for(i=0;i<MAXTH;i++){
		pthread_create(&(tab_thr[i]),NULL,func,NULL);
	}
	barrier();
	for(i=0;i<MAXTH;i++){
		pthread_join(tab_thr[i],NULL);
	}
	return 0;
}
