#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define F_R 1
#define F_W 2
#define eof -1
#define null 0
#define MAX 1024

struct fichier{
	int fd;
	int flags;
	int reste;
	unsigned char buf[1024];
	unsigned char *p;
};typedef struct fichier FICHIER;


FICHIER* my_open(char* file,char* mode){
	FICHIER* fp;
	int m,f,fd;
	
	switch(mode[0]){
		case 'r':
			m=O_RDONLY;
			f=F_R;
			break;
		case 'w':
			m=O_CREAT|O_TRUNC|O_WRONLY; //OTRUNC vide le fichier 
			f=F_W;
			break;
		default:
			return null;
	}
	fd=open(file,m,0666);
	if(fd==-1) return null;
	
	fp=(FICHIER*)malloc(sizeof(*fp));
	if(fp==NULL) return null;
	fp->flags=f;
	fp->fd=fd;
	fp->reste=0;
	fp->p=fp->buf;
	return fp;
}

int my_getc(FICHIER* f){
	char c;
	if((f->flags)==F_R){
		int d=read(f->fd,&c,1);
		if(d==-1) exit(1);
		if(d==0) return eof;
	}
	else return null;
	return c;
}

int my_putc(int c,FICHIER* file){
	if((file->flags)==F_W){
		int d=write(file->fd,&c,1);
		if(d==-1) exit(1);
		return c;
	}
	else null;
}

int my_getc_buf(FICHIER* fp){
	if((fp->flags & F_R)==0) return eof;
	if(fp->reste<=0){
		fp->reste=read(fp->fd,fp->buf,MAX);
		fp->p=fp->buf;
	}
	return (fp->reste<=0) ? eof : (fp->reste--,*(fp->p++));
}

int my_putc_buf(int c,FICHIER* fp){
	if((fp->flags & F_W)==0) return eof;
	if(fp->reste>=MAX){
		if(write(fp->fd,fp->buf,MAX)!=MAX) return eof;
		fp->p=fp->buf;
		fp->reste=0;
	}
	*(fp->p++)=c;
	fp->reste++;
	return c;
}

int my_close(FICHIER* fp){
	if((fp->flags & F_W)!=0 && fp->reste>0){
		if(write(fp->fd,fp->buf,fp->reste)!=fp->reste) return eof;
	}
	close(fp->fd);
	free(fp);
	return 0;
}

int main(int argc,char** argv){
	FICHIER* f1,*f2;
	int c;
	f1=my_open(argv[1],"r");
	if(f1==null) exit(1);
	f2=my_open(argv[2],"w");
	if(f2==null) exit(2);
	while((c=my_getc(f1))!=eof) my_putc(c,f2);
	my_close(f1);
	my_close(f2);
	return 0;
}
