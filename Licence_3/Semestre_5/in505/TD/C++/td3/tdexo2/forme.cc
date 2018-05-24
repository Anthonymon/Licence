#include <iostream>
#include "forme.h"
#include <cstring>

using namespace std;

Forme::Forme(Couleur couleur){
	this->coul=couleur;
}

Couleur Forme::getCoul(){
	return this->coul;
}

Forme::~Forme(){
	//delete coul;
	cout<<"Destruction Forme"<<endl;
}
