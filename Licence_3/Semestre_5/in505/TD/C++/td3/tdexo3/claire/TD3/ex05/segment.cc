#include "segment.h"
#include <iostream>
#include <cmath>
using namespace std;

	/* Classe Point */
Point::Point(){ x = 0; y = 0; }
Point::Point(int x, int y){this->x = x; this->y = y; }
Point::Point(const Point& p){ x = p.x; y = p.y; }

void Point::afficher(){
	cout << "x = " << x << " ; y = " << y << endl;
}

void Point::cloner(const Point& p){
	x = p.x; y = p.y;
}

int Point::getAbscisse(){ return x; }
int Point::getOrdonnee(){ return y; }

Point::~Point(){
	cout << "appel au destructeur de Point\n";
}

	/* Classe Segment */
Segment::Segment(): p1(0,0), p2(1,1){}

Segment::Segment(const Point P1, const Point P2): p1(P1), p2(P2){}

void Segment::afficher(){
	cout << "Point p1: \n";
	this->p1.afficher();
	cout << "Point p2: \n";
	this->p2.afficher();
}

bool Segment::estVertical(){
	if(this->p1.getAbscisse() == this->p2.getAbscisse()) return true;
	return false;
}

bool Segment::estHorizontal(){
	if(this->p1.getOrdonnee() == this->p2.getOrdonnee()) return true;
	return false;
}

bool Segment::estSurDiagonale(){
	if(this->estVertical() && this->estHorizontal()) return false;
	return true;
}

double Segment::longueur(){
	return sqrt((this->p1.getAbscisse()-this->p2.getAbscisse())*(this->p1.getAbscisse()-this->p2.getAbscisse()) + (this->p1.getOrdonnee()-this->p2.getOrdonnee())*(this->p1.getOrdonnee()-this->p2.getOrdonnee()));
}		
Segment::~Segment(){
cout << "appel au destructeur de Segment\n";
}

