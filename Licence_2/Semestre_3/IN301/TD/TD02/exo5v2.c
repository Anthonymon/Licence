#include <stdio.h>

int main(){
	int temps; int secondes; int minutes; int heures;
	printf("Donnez un temps en secondes : ");
	scanf("%d",&temps);
	heures=temps/3600;
	minutes=(temps-heures*3600)/60;
	secondes=temps-(minutes*60)-(heures*3600);
	printf("%d secondes representent : %d heures, %d minutes et %d secondes\n",temps,heures,minutes,secondes);
	
	return 0;
}
