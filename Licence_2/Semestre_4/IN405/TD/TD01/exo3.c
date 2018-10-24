#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void recopie(){
	int d;
	char c;
	int f1=open("toto",O_RDONLY);
	if(f1==-1){
		printf("PROBL1\n");
		exit(1);
	}
	
	int f2=open("titi",(O_CREAT | O_WRONLY),S_IRWXU);
	if(f2==-1){
		printf("PROBL2\n");
		exit(1);
	}
	
	do{
		d=read(f1,&c,1);
		if(d==-1){
			printf("PROBL3\n");
			exit(1);
		}
		write(f2,&c,1);
	}while(d!=0);
	close(f1);
	close(f2);
}

int main(){
	recopie();
	return 0;
}
