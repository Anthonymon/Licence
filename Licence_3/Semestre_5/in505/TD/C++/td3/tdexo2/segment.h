#include "point.h"

#ifndef SEGMENT__H
#define SEGMENT__H


class Segment : public Forme{
	private:
		Point x;
		Point y;
	public:
		Segment(Couleur couleur);
		Segment(Point x,Point y,Couleur couleur);
		void dessiner();
		void deplacer(double longueur,double largeur);
		~Segment();
};

#endif
