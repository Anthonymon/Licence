#include "point.h"
#ifndef SEGMENT__H
#define SEGMENT__H

class Segment{
	private:
		Point p1;
		Point p2;
	public:
		Segment();
		Segment(double i,double j,double k,double l);
		Segment(Point P1,Point P2);
		Point getPoint1();
		Point getPoint2();
		double calculeDistanceAxe(Point p1,Point p2);
		bool estVertical();
		bool estHorizontal();
		double longueur();
		~Segment();
};
#endif
