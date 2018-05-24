#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define T_MAX 1024
//#define EOF -1

struct fichier
{
	int flags;
	int fd;
	int reste;
	unsigned char buf[T_MAX];
	unsigned char* p;
};
typedef struct fichier FICHIER;

FICHIER* my_open(const char*,const char);
int my_close(FICHIER*);
int my_getc(FICHIER*);
int my_putc(int,FICHIER*);

int main(int argc,char** argv)
{
	FICHIER* f1;
	FICHIER* f2;
	int c;
	
	f1 = my_open(argv[1],'r');
	if(f1 == NULL)
	{
		perror("ne peux pas ouvrir le 1er fichier");
		exit(1);
	}
	
	f2 = my_open(argv[2],'r');
	if(f2 == NULL)
	{
		perror("ne peux pas ouvrir le 2nd fichier");
		exit(1);
	}
	
	while((c = my_getc(f1)) != EOF ) my_putc(c,f2);
	
	my_close(f1);
	my_close(f2);
	
	return 0;
}

FICHIER* my_open(const char* nom_fic,const char flag)
{
	FICHIER* fic;
	
	if(!(fic = malloc(sizeof(FICHIER)))) exit(1);
	
	int mode;
	
	switch(flag)
	{
		case 'r':
			mode = O_RDONLY;
			break;
		case 'w':
			mode = O_CREAT | O_TRUNC | O_WRONLY;
			break;
		default:
			exit(0);
			break;
	}
	
	fic -> fd = open(nom_fic,mode,0666);
	
	if(fic -> fd == -1) return NULL;
	fic -> flags = flag;
	fic -> reste = 0;
	fic -> p = fic -> buf;
	
	return fic;
}

int my_close(FICHIER* fic)
{
	if(((fic -> flags & 'w') != 0)&& fic -> reste >0)
	{
		if(write(fic -> fd, fic -> buf, fic -> reste) != fic -> reste) return EOF;
	}
	
	close(fic -> fd);
	free(fic);
	
	return 0;
}

int my_getc(FICHIER* fic)
{
	if((fic -> flags & 'r') == 0)return EOF;
	
	if(fic -> reste == 0)
	{
		fic -> reste = read(fic -> fd,fic -> buf,T_MAX);
		fic -> p = fic -> buf;
	}
	if(fic -> reste != 0)
	{
		fic -> reste --;
		return *(fic -> p++);
	}
	else return EOF;
}

int my_putc(int c,FICHIER* fic)
{
	if((fic -> flags & 'w') == 0)return EOF;
	
	if(fic -> reste >= T_MAX)
	{
		if(write(fic->fd,fic->buf,T_MAX) != T_MAX) return EOF;
		fic -> p = fic -> buf;
		fic -> reste = 0;
	}
	*(fic -> p++) = c;
	fic -> reste ++;
	
	return c;
}

