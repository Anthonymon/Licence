#ifndef POINTCOLOR__H
#define POINTCOLOR__H

#include <iostream>
#include "point.h"

typedef enum{
	Rouge,
    Bleu,
    Vert,
    Jaune
}Couleur;



class PointColor: public Point {
	private: 
		Couleur c;

	public:
		PointColor(double x,double y,Couleur c);
		PointColor(Point& p,Couleur c);
		void affiche();
		void clone(Point& p);
		~PointColor();
		
};

#endif
