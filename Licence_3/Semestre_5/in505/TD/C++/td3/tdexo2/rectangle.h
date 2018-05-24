#include "point.h"

#ifndef RECTANGLE__H
#define RECTANGLE__H


class Rectangle : public Forme{
	private:
		Point x;
		Point y;
		Point z;
		Point u;
	public:
		Rectangle(Couleur couleur);
		Rectangle(Point x,Point y,Point z,Point u,Couleur couleur);
		void dessiner();
		void deplacer(double longueur,double largeur);
		~Rectangle();
};

#endif
