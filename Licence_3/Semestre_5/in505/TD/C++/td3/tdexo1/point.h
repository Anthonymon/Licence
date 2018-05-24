#include <string.h>

using namespace std;

#ifndef POINT__H
#define POINT__H

class Point{
	protected:
		double x;
		double y;
		string myType;
	public:
		Point();
		Point(double x,double y);
		Point(Point& p);
		double getX();
		double getY();
		string getMyType();
		virtual void affiche();
		virtual void clone(Point& p);
		~Point();
		
};

#endif
