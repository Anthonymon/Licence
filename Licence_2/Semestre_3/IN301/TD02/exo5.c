#include <stdio.h>

int main(){
	int secondeTapee;int heure;int minute;int seconde;
	printf("Tapez le nombre de secondes : ");
	scanf(" %d",&secondeTapee);
	heure=secondeTapee/3600;
	minute=(secondeTapee-heure*3600)/60;
	seconde=secondeTapee-(heure*3600)-(minute*60);
	printf("%d secondes correspond à %d heures, %d minutes et %d secondes\n",secondeTapee,heure,minute,seconde);
}
