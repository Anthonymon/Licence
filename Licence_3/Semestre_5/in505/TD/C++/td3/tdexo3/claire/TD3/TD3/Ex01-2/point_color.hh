#ifndef POINT_COLOR_HH
#define POINT_COLOR_HH

#include <iostream>
using namespace std;


class Point{
	protected:
		int x,y;
	
	public:		
		Point();
		Point(int x, int y);
		Point(const Point& p);
		
		void afficher();
		void cloner(const Point& p);
		int getAbscisse();
		int getOrdonnee();
		void deplacer(int dx, int dy);
		~Point();
};

class PointColor : public Point{
	string coul;
	
	public:
		PointColor();
		PointColor(int x, int y, string couleur);
		PointColor(const PointColor& p);
		
		void afficher();
				
		~PointColor();
};

#endif
