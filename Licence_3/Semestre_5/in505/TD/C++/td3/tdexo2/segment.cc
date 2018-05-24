#include "forme.h"
#include "segment.h"
#include "point.h"
#include "iostream"

Segment::Segment(Couleur couleur):Forme(couleur){
	this->x=Point(0,0);
	this->y=Point(1,1);
}

Segment::Segment(Point x,Point y,Couleur couleur):Forme(couleur){
	this->x=x;
	this->y=y;
}

void Segment::dessiner(){
	std::cout<<"SEGMENT entre ";
	this->x.affiche();
	std::cout<<" et ";
	this->y.affiche();
	std::cout<<" COULEUR= ";
	if(this->coul==Couleur::Bleu) std::cout<<"Bleu "<<std::endl;
	else if(this->coul==Couleur::Jaune) std::cout<<"Jaune "<<std::endl;
	else if(this->coul==Couleur::Rouge) std::cout<<"Rouge "<<std::endl;
	else if(this->coul==Couleur::Vert) std::cout<<"Vert "<<std::endl;
	else std::cout<<"Inconnu"<<std::endl;
}

void Segment::deplacer(double longueur,double largeur){
	this->x.setX(this->x.getX()+longueur);
	this->y.setX(this->y.getX()+longueur);
	this->x.setY(this->x.getY()+largeur);
	this->y.setY(this->y.getY()+largeur);
	
}

Segment::~Segment(){
	std::cout<<"Destruction Segment "<<std::endl;
}
