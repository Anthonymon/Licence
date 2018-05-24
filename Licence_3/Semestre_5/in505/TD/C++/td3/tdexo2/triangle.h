#include "point.h"

#ifndef TRIANGLE__H
#define TRIANGLE__H



class Triangle : public Forme{
	private:
		Point x;
		Point y;
		Point z;
	public:
		Triangle(Couleur couleur);
		Triangle(Point x,Point y,Point z,Couleur couleur);
		void dessiner();
		void deplacer(double longueur,double largeur);
		~Triangle();
};

#endif
