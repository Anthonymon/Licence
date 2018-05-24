#include <iostream>
#include <cstring>
#include "vecteur.h"
using namespace std;

Vecteur::Vecteur(){
	this->tab=NULL;
	this->taille=0;
}

Vecteur::Vecteur(int taille,int nb){
	this->tab=new int[taille];
	//this->tab[0]=nb;
	int i;
	for(i=0;i<taille;i++){
		this->tab[i]=nb;
	}
	this->taille=taille;
}


Vecteur:: Vecteur(Vecteur& v){
	this->tab=new int[v.taille];
	int i;
	for(i=0;i<v.taille;i++){
		this->tab[i]=v.tab[i];
	}
	this->taille=v.taille;
}

Vecteur& Vecteur::operator=(const Vecteur& v){
	if(this!=&v){
		delete[] this->tab;
		this->tab=new int[v.taille+1];
		this->taille=v.taille;
		int i;
		for(i=0;i<v.taille;i++){
			this->tab[i]=v.tab[i];
		}
	}
	return *this;
}

Vecteur& Vecteur:: operator+=(const Vecteur& un_vecteur){
	int i;
	for(i=0;i<this->taille;i++){
		this->tab[i]+=un_vecteur.tab[i];
	}
	return *this;
}

// CE NEST PAS UNE METHODE DE CLASSE BORDEL
ostream&  operator<<(ostream& os,Vecteur& v){
	int i;
	for(i=1;i<v.getTaille()+1;i++){
		os<<v[i];
		if(i!=v.getTaille()) os<<"-";
	}
	os<<endl;
	return os;
}

int Vecteur:: getTaille(){
	return taille;
}

int& Vecteur::operator[](const int i){
	if(i<0 || i>=taille){
		cout<<"erreur";
	}
	return tab[i];
}

/*Vecteur& Vecteur:: operator+(const Vecteur& v){
	
}*/

/*void Vecteur::push(int nb){
	if(this->taille==0) this->tab=new int[1];
	this->tab[taille]=nb;
	this->taille=this->taille+1;
}*/

/*int Vecteur::pop(){
	int retour=this->tab[taille];
	delete[taille] *this;
	this->taille=this->taille-1;
	return retour;
}*/

void Vecteur::affiche(){
	if(this->taille==0){
		cout<<"Vecteur vide"<<endl;
	}
	else{
		int i;
		for(i=0;i<this->taille;i++){
			cout<<this->tab[i]<<" ";
		}
		cout<<endl;
	}
}

Vecteur::~Vecteur(){
	cout<<"Appel au destructeur"<<endl;
	delete[] this->tab;
}
