#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char mygetchar(){
	char c;
	int d;
	d=read(0,&c,1);
	if(d==-1){
		printf("PROBL4\n");
		exit(1);
	}
	return c;
}

int correction(){
	unsigned char c;
	int a=read(0,&c,1);
	if(a==1) return c;
	ele return EOF;
}

int main(){
	char c=mygetchar();
	write(0,&c,1);
	write(0,"\n",1);
	return 0;
}
