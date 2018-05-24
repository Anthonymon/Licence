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

struct mailbox{
	int valeur;
	int plein;
	pthread_cond_t cond;
	pthread_mutex_t mut;
};typedef struct mailbox MAILBOX;


struct thread{
	pthread_t thr;
	int m;
	int p;
};typedef struct thread THREAD;

void mbox_init(MAILBOX* mb){
	mb->valeur=-1;
	mb->plein=0;
	pthread_mutex_init(&(mb->mut),NULL);
	pthread_cond_init(&(mb->cond),NULL);
}

void mbox_write(MAILBOX* mb,int i){
	pthread_mutex_lock(&(mb->mut));
	if((mb->plein)==1) pthread_cond_wait(&(mb->cond),&(mb->mut));
	else{
		//pthread_cond_broadcast(&(mb->cond));
		(mb->plein)=1;
		(mb->valeur)=i;
		pthread_cond_signal(&(mb->cond));
	}
	pthread_mutex_unlock(&(mb->mut));
}

int mbox_read(MAILBOX* mb){
	pthread_mutex_lock(&(mb->mut));
	if((mb->plein)==0) pthread_cond_wait(&(mb->cond),&(mb->mut));
	pthread_cond_signal(&(mb->cond));
	(mb->plein)=0;
	int i=(mb->valeur);
	pthread_mutex_unlock(&(mb->mut));
	return i;
}

void* func(void* val){
	THREAD t=*((THREAD*)val);
	
}

int main(int argc, char** argv){
	int i;
	int n=atoi(argv[1]);
	int m=atoi(argv[2]);
	
	THREAD t[n];
	pthread_t th[n];
	MAILBOX mail[n+1];
	
	for(i=0;i<n;i++){
		t[i].thr=th[i];
		t[i].p=i;
		t[i].m=m;
	}
	for(i=0;i<n;i++){
		pthread_create(&(t[i].thr),NULL,func,&(t[i]));
	}
	
	for(i=0;i<n;i++){
		pthread_join(t[i].thr,NULL);
	}
	
	return 0;
}
