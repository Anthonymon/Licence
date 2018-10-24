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
#include <signal.h>

int main(){
	if(mkfifo("message",0666)!=-1) exit(1);
	int ecr=open("message",O_WRONLY);
	write(ecr,"zbeub",5);
}
