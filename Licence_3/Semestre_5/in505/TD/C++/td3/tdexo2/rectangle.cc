#include "forme.h"
#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(Couleur coul):Forme(coul){
	this->x=Point(0,0);
	this->y=Point(0,2);
	this->z=Point(1,0);
	this->u=Point(1,2);
}

Rectangle::Rectangle(Point x,Point y,Point z,Point u,Couleur couleur):Forme(couleur){
	this->x=x;
	this->y=y;
	this->z=z;
	this->u=u;
}

void Rectangle::dessiner(){
	std::cout<<"RECTANGLE entre ";
	this->x.affiche();
	std::cout<<" , ";
	this->y.affiche();
	std::cout<<" , ";
	this->z.affiche();
	std::cout<<" et ";
	this->u.affiche();
	std::cout<<" COULEUR= ";
	if(this->coul==Couleur::Bleu) std::cout<<"Bleu "<<std::endl;
	else if(this->coul==Couleur::Jaune) std::cout<<"Jaune "<<std::endl;
	else if(this->coul==Couleur::Rouge) std::cout<<"Rouge "<<std::endl;
	else if(this->coul==Couleur::Vert) std::cout<<"Vert "<<std::endl;
	else std::cout<<"Inconnu"<<std::endl;
}

void Rectangle::deplacer(double longueur,double largeur){
	this->x.setX(this->x.getX()+longueur);
	this->y.setX(this->y.getX()+longueur);
	this->z.setX(this->z.getX()+longueur);
	this->u.setX(this->u.getX()+longueur);
	this->x.setY(this->x.getY()+largeur);
	this->y.setY(this->y.getY()+largeur);	
	this->z.setY(this->z.getY()+largeur);
	this->u.setY(this->u.getY()+largeur);
}

Rectangle::~Rectangle(){
	std::cout<<"Destruction Rectangle"<<std::endl;
}
