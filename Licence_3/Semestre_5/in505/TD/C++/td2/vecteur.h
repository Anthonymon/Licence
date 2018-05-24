#ifndef VECTEUR__H
#define VECTEUR__H

#include <iostream>


class Vecteur{
	private:
		int* tab;
		int taille;
		
	public:
		Vecteur();
		Vecteur(int taille,int nb);
		Vecteur(Vecteur& v);
		int getTaille();
		Vecteur& operator=(const Vecteur& v);
		//friend Vecteur& operator+(const Vecteur& v1,const Vecteur& v2);
		Vecteur& operator+=(const Vecteur& un_vecteur);
		int& operator[](const int i);
		//ostream&  operator<<(ostream& os,Vecteur& v);
		//void push(int nb);
		//int pop();
		void affiche();
		~Vecteur();
		
};

#endif
