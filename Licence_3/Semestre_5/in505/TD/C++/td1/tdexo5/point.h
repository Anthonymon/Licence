

#ifndef POINT__H
#define POINT__H

class Point{
	private:
		double x;
		double y;
	public:
		Point();
		Point(double x,double y);
		Point(Point& p);
		double getX();
		double getY();
		void affiche();
		void clone(const Point& p);
		~Point();
		
};

#endif
