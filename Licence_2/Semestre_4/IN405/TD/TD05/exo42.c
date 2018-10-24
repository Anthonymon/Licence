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

int main(){
	//if(mkfifo("message",0666)!=-1) exit(1);
	int ecr=open("message",O_RDONLY);
	char* buf=malloc(1024*sizeof(char));
	read(ecr,buf,1024);
	printf("%s\n",buf);
	unlink("message");
}
