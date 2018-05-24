#include <iostream>
#include <string.h>


using namespace std;

class Automate //Un etat est un numero, l'automate est deterministe (d'ou le tableau a 2 dimensions)
{
	private :
		int E; //nombre d'etats
		int S; //taille de symboles declare dessous
		int* symboles; //l'alphabet, on numérote les symboles de 0 a S-1
		int I; //etat initial
		int F; // etat final
		int **transition; //tableau a double dimension
		
	public:
		Automate(int E, int S, int I, int F, int **t);
		~Automate();
		int compteTion(const char* txt);
};

Automate::Automate(int E, int S, int I, int F, int **t) //t est le tableau des transitions
{
	this->E = E;
	this->S = S;
	this->I = I;
	this->F = F;
	
	symboles = new int[S];
	int i;
	for(i = 0; i < S; i++)
		symboles[i] = i;
	
	int j;
	transition = new int*[S]; //On lit un symbole / alloue la memoire pour S pointeurs sur int
	for(i = 0; i < S; i++)
	{
		transition[i] = new int[E]; //Pour chacun des etats de l'automate / alloue la memoire pour E int
		for(j = 0; j < E; j++)
			transition[i][j] = t[i][j]; //On obtient l'état sur lequel arrive la transition
	}
}

Automate::~Automate() //Voir l'appel des new pour comprendre l'appel des delete (le meme ordre)
{
	delete[] symboles;
	int i;
	for(i = 0; i < S; i++)
		delete[] transition[i];
	delete[] transition;
}

int Automate::compteTion(const char* txt)
{
	int count = 0;
	int etatTmp = 0;
	int i;
	for(i = 0; i < strlen(txt); i++)
	{
		etatTmp = transition[txt[i]][etatTmp]; //On lit txt[i], on se trouve dans l'etat etatTmp, on se deplace.
		if(etatTmp == 4)
			count++;
	}
	return count;
}

void fct(){ cout << "tibo t con" << endl;}

//crée un automate qui reconnait la chaine "tion" pour la question 2.a
int** creaAutomate(int S, int E)
{
	//Un char est sur 1 octet 0 a 255
	int i,j;
	int **t = new int*[S]; //init d'un tableau a 0;
	for(i = 0; i < S; i++)
	{
		t[i] = new int[E]; 
		for(j = 0; j < E; j++)
			t[i][j] = 0;
	}

	for(i = 0; i < S; i++)
	{
		for(j = 0; j < E; j++)
		{
			if(i == 't' && j == 0) t[i][j] = 1; // si on lit 't', a l'etat 0, on va a 1
			if(i == 'i' && j == 1) t[i][j] = 2; // si on lit 'i', a l'etat 1, on va a 2
			if(i == 'o' && j == 2) t[i][j] = 3; // si on lit 'o', a l'etat 2, on va a 3
			if(i == 'n' && j == 3) t[i][j] = 4; // si on lit 'n', a l'etat 3, on va a 4 accepteur
		}
	}
	return t;
}

int main()
{
	int **tab = creaAutomate(256, 5);
	Automate *a = new Automate(5 , 256 , 0 , 4, tab);
	//On a pas appris a manipuler les fichiers (ouverture, lecture, fermeture)
	//une question de ce genre ne tombera surement pas, je modif un peu le sujet, Texte est un char *
	const char *texte = "tionabction poazpopozertion"; fct();
	cout << "nbre de 'tion' " << a->compteTion(texte) << endl;
	delete a;
	int i; //delete de tab
	for(i = 0; i < 256; i++) //S = 256
		delete[] tab[i];
	delete[] tab;
	return 0;
}
