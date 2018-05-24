using namespace std;

#include <iostream>
#include <cstring>

void q_a()
{
	int tab[10];
	int *p = tab;
	int i = 0;
	
	while(i < 10)
	{
		tab[i] = i;
		i++;
	}
	
	i = 0;
	while(i++ < 10)
	{
		cout << *p++ << "\n"; //p[i] marche aussi
	}
}

void q_b()
{
	const char *tab[3] = {"truc", "machin", "chose"};
	
	int i = 0;
	char *ptr[3]; //crée la mémoire nécessaire pour 3 char* dans un tableau (uniquement les pointeurs)
	while(i < 3)
	{
		ptr[i] = new char[strlen(tab[i]) + 1];//crée la mémoire pour chacun des caractères d'une chaine
		// + 1 pour caract de fin de chaine
		strcpy(ptr[i], tab[i]); 
		cout << ptr[i] << "\n";
		i++;
	}
	
	i = 0;
	while(i < 3)
	{
		delete ptr[i];
		i++;
	}
	//delete car on alloue dynamiquement avec new
}

int main()
{
	q_a();
	q_b();
}
