#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	char* nom="clement";
	int f1;
	int c;
	f1=open(nom,O_RDONLY|O_CREAT,666);
	if(f1==-1)exit(1);
	int d=read(f1,&c,1);
	if(d==-1) exit(1);
	int e=write(0,&c,1);
	if(e==-1) exit(1);
	return 0;	
}
