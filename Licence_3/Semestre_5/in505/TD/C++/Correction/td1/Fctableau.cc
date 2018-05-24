using namespace std;

#include <iostream>

//affecte a chaque case du tableau son indice
void tableauEcriture(int *tab, int taille)
{
	int i;
	
	for(i = 0; i < taille; i++)
		tab[i] = i;
}

//affiche un a un les elements du tableau
void tableauLecture(const int *tab, int taille)
{
	int i;
	
	for(i = 0; i < taille; i++)
		cout << tab[i] << "\n";
}

/* On peut récupérer la taille d'un tableau sans la passer en argument
 * avec un sizeof : sizeof(tab) / sizeof(type du tableau)
 * /!\ qd on passe un tableau en arg de fonction, il est considere comme un pointeur et sizeof(ptr) / sizeof(int) == 2
 * */
int main()
{
	int tab[10];
	
	tableauEcriture(tab, 10);
	tableauLecture(tab, 10);
	cout << "taille du tableau = " << sizeof(tab)/sizeof(int) << endl;
	
}
