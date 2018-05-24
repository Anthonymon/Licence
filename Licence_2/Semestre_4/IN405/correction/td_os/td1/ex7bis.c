#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc,char** argv)
{
	DIR* repertoire = opendir(argv[1]);
	
	struct dirent* xd = readdir(repertoire);
	
	while(xd != NULL)
	{
		if(xd -> d_name[0] != '.')
		{
			printf("%s\n",xd -> d_name);
		}
		xd = readdir(repertoire);
	}
	
	closedir(repertoire);

	return 0;
}
