#include "point_color.hh"
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

void Point::deplacer(int dx, int dy){
	x += dx;
	y += dy;
}

Point::~Point(){
	//cout << "appel au destructeur de Point\n";
}

	/* Classe PointColor */
PointColor::PointColor() : Point(), coul("blanc"){}
PointColor::PointColor(int x, int y, string couleur) : Point(x,y), coul(couleur){}
PointColor::PointColor(const PointColor& p) : Point(p), coul(p.coul){}

void PointColor::afficher(){
	cout << "x = " << x << " ; y = " << y << " ; coul = " << coul << endl;
}

PointColor::~PointColor(){
	//cout << "appel au destructeur de PointColor\n";
}
