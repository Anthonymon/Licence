#include <iostream>
#include <cstring>
#include "vecteur.h"
using namespace std;

int main()
{
	/*Vecteur* v1 = new Vecteur(2);
	Vecteur* v2;
	v1->affiche();
	v2=v1;
	v2->affiche();
	delete v1;*/
	Vecteur v1(3,2);
	Vecteur v2(3,5);
	v1.affiche();
	//cout<< v1;
	//v2=v1;
	v2.affiche();
	v2+=v1;
	v2.affiche();
	//Vecteur v3;
	//v3=v1+v2;
	
	//v3.affiche();
	return 0;
}
