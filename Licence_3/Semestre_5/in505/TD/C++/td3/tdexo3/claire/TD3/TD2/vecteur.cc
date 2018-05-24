#include "vecteur.hh"
#include <iostream>
#include <cstdlib>

using namespace std;

Vecteur::Vecteur(){
	this->v = NULL;
	this->size = 0;
}

Vecteur::Vecteur(int n){
	this->v = new int[n];
	this->size = n;
}

Vecteur::Vecteur(const Vecteur& V){
	this->size = V.size;
	this->v = new int[this->size];
	for(int i = 0; i < this->size; i++)
		this->v[i] = V.v[i];
}

Vecteur::~Vecteur(){
	cout << "Appelle du destructeur\n";
	delete[] v;
}

int Vecteur::getV(int i){
	if (i < size)
		return v[i];
	return -1;
}

int Vecteur::getSize(){ return size; }

void Vecteur::affect(int i, int n){
	if (i < size)
		v[i] = n;
}

void Vecteur::affiche(){
	for(int i = 0; i<size; i++)
		cout << v[i] << " ";
	cout << endl;
}

/* Surcharge Operateurs */

Vecteur& Vecteur::operator=(const Vecteur& vec){
	if(this != &vec){
		delete[] v;
		size = vec.size;
		v = new int[size];
		for(int i = 0; i < this->size; i++)
			this->v[i] = vec.v[i];
	}
	return *this;
}

Vecteur& Vecteur::operator+=(const Vecteur& b){
	if(size >= b.size){
		for(int i = 0; i < b.size; i++)
				v[i] = v[i] + b.v[i];
	}
	else if(size < b.size){
		int i;
		int* tmp = new int[b.size];
		for(i = 0; i < size; i++)
			tmp[i] = v[i] + b.v[i];
		for(; i < b.size; i++)
			tmp[i] = b.v[i];
		delete[] v;
		size = b.size;
		v = tmp;
		}
	
	return *this;
}

int& Vecteur::operator[](const int i){
	if( i < 0 || i >= size){
		cerr << "erreur borne\n";
		exit(1);
	}
	return v[i];
}

ostream& operator<<(ostream& os, Vecteur& V){
	int i;
	for (i=0; i < V.getSize(); i++){
		os << V[i];
		if(i != V.getSize()) os << "-";
	}
	os << endl;
	return os;
}

istream& operator>>(istream& is, Vecteur& V){
	int i;
	for(i=0; i<V.getSize(); i++)
		is >> V[i];
	return is;
}





int main(){
	Vecteur v1(3), v2;
	v1.affect(0,0); 
	v1.affect(1,1); 
	v1.affect(2,2);
	
	cin >> v1;
	
	Vecteur v3(2);
	v3.affect(0,0); 
	v3.affect(1,1);
	
	cout << v3;
	cout << v1;
	v1 += v3;
	cout << v1;
	
	v2 = v3;
	cout << v2;
}
