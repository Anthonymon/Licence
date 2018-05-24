#ifndef POINT__H
#define POINT__H

class Point{
	protected:
		double x;
		double y;
	public:
		Point();
		Point(double x,double y);
		Point(Point& p);
		double getX();
		double getY();
		void setX(double a);
		void setY(double a);
		virtual void affiche();
		void clone(const Point& p);
		~Point();
		
};

#endif
