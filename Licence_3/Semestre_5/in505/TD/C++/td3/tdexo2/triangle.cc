#include "forme.h"
#include "triangle.h"
#include <iostream>

Triangle::Triangle(Couleur coul):Forme(coul){
	this->x=Point(0,0);
	this->y=Point(1,1);
	this->z=Point(2,2);
}

Triangle::Triangle(Point x,Point y,Point z,Couleur couleur):Forme(couleur){
	this->x=x;
	this->y=y;
	this->z=z;
}

void Triangle::dessiner(){
	std::cout<<"TRIANGLE entre ";
	this->x.affiche();
	std::cout<<" , ";
	this->y.affiche();
	std::cout<<" et ";
	this->z.affiche();
	std::cout<<" COULEUR= ";
	if(this->coul==Couleur::Bleu) std::cout<<"Bleu "<<std::endl;
	else if(this->coul==Couleur::Jaune) std::cout<<"Jaune "<<std::endl;
	else if(this->coul==Couleur::Rouge) std::cout<<"Rouge "<<std::endl;
	else if(this->coul==Couleur::Vert) std::cout<<"Vert "<<std::endl;
	else std::cout<<"Inconnu"<<std::endl;
}

void Triangle::deplacer(double longueur,double largeur){
	this->x.setX(this->x.getX()+longueur);
	this->y.setX(this->y.getX()+longueur);
	this->z.setX(this->z.getX()+longueur);
	this->x.setY(this->x.getY()+largeur);
	this->y.setY(this->y.getY()+largeur);	
	this->z.setY(this->z.getY()+largeur);
}

Triangle::~Triangle(){
	std::cout<<"Destruction Triangle"<<std::endl;
}
