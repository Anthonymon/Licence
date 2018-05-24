#include "forme.hh"
#include <iostream>
#include <cmath>
using namespace std;

	/* Classe Rectangle */
Rectangle::Rectangle(): bg(0,0), hd(1,1){}

Rectangle::Rectangle(const Point BG, const Point HD): bg(BG), hd(HD){}

void Rectangle::deplacer(int dx, int dy){
	bg.deplacer(dx, dy);
	hd.deplacer(dx, dy);
}

void Rectangle::afficher(){
	cout << "(" << bg.getAbscisse() << " ; " << hd.getOrdonnee() << ")";
	cout << "		(" << hd.getAbscisse() << " ; " << hd.getOrdonnee() << ")\n";
	cout << "(" << bg.getAbscisse() << " ; " << bg.getOrdonnee() << ")";
	cout << "		(" << hd.getAbscisse() << " ; " << bg.getOrdonnee() << ")\n";
	
}

Rectangle::~Rectangle(){}

	/* Classe Cercle */

Cercle::Cercle() : c(0,0){}
Cercle::Cercle(Point C) : c(C){}
void Cercle::afficher(){ c.afficher(); }
void Cercle::deplacer(int dx, int dy){ c.deplacer(dx, dy); }
Cercle::~Cercle(){}
		
	/* Classe Triangle */

Triangle::Triangle(): s(1,1), bg(0,0), bd(1,0){}
Triangle::Triangle(const Point S, const Point BG, const Point BD) : s(S),bg(BG),bd(BD) {}

void Triangle::afficher(){
	cout << "	(" << s.getAbscisse() << " ; " << s.getOrdonnee() << ")\n";
	cout << "(" << bg.getAbscisse() << " ; " << bg.getOrdonnee() << ")";
	cout << "	(" << bd.getAbscisse() << " ; " << bd.getOrdonnee() << ")\n";
}

void Triangle::deplacer(int dx, int dy){
	s.deplacer(dx,dy);
	bg.deplacer(dx, dy);
	bd.deplacer(dx, dy);
}

Triangle::~Triangle(){}

	/* Classe Segment */
Segment::Segment(): p1(0,0), p2(1,1){}

Segment::Segment(const Point P1, const Point P2): p1(P1), p2(P2){}

void Segment::afficher(){
	cout << "Point p1: ";
	this->p1.afficher();
	cout << "Point p2: ";
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

void Segment::deplacer(int dx, int dy){
	p1.deplacer(dx, dy);
	p2.deplacer(dx, dy);
	}

Segment::~Segment(){
	//cout << "appel au destructeur de Segment\n";
}
