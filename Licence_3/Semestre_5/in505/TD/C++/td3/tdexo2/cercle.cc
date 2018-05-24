#include "forme.h"
#include "cercle.h"

Cercle::Cercle(Couleur coul):Forme(coul){
	this->centre=Point(0,0);
	this->rayon=2;
}

Cercle::Cercle(Point centre,Couleur couleur):Forme(couleur){
	this->centre=centre;
}

void Cercle::dessiner(){
	std::cout<<"CERCLE sur ";
	this->centre.affiche();
	std::cout<<" de rayon "<<this->rayon<<" ";
	std::cout<<" COULEUR= ";
	if(this->coul==Couleur::Bleu) std::cout<<"Bleu "<<std::endl;
	else if(this->coul==Couleur::Jaune) std::cout<<"Jaune "<<std::endl;
	else if(this->coul==Couleur::Rouge) std::cout<<"Rouge "<<std::endl;
	else if(this->coul==Couleur::Vert) std::cout<<"Vert "<<std::endl;
	else std::cout<<"Inconnu"<<std::endl;
}

void Cercle::deplacer(double longueur,double largeur){
	this->centre.setX(this->centre.getX()+longueur);
	this->centre.setX(this->centre.getX()+longueur);
}

Cercle::~Cercle(){
	std::cout<<"Destruction Cercle"<<std::endl;
}
