using namespace std;

#include <iostream>
#include <cmath>
#include <string.h>
//question 1
class Point
{
	
	protected: //Pour l'heritage avec PointColor
		double x;
		double y;
		
	public:
		Point();
		Point(double x, double y);
		Point(const Point& p);
		~Point();
		double getx();
		double gety();
		virtual void afficher(); //question 1 (virtual car la fonction est redefinie dans une classe fille)
		virtual void cloner(const Point& p); //question 1
};

Point::Point()
{
	x = 0;
	y = 0;
}

//double constant
Point::Point(const double x, const double y)
{
	//Pour un type X donne, this est de type X* (pointeur sur X) d'ou la fleche
	//this leve l'ambiguite avec le parametre de la methodes
	this->x = x;
	this->y = y;
}

//référence sur un point constant
Point::Point(const Point& p)
{
	this->x = p.x;
	this->y = p.y;
}

Point::~Point(){ cout << "destruciton point " << x << " " << y << endl; }

double Point::getx(){ return x; }
double Point::gety(){ return y; }

void Point::afficher()
{
	cout << "x = " << x << " y = " << y << endl;
}

void Point::cloner(const Point& p)
{
	this->x = p.x;
	this->y = p.y;
}

class PointColor : public Point
{
	private:
		char *color; //on preferera travailler avec un enum por la couleur
		
	public:
		PointColor(int abs, int ord, const char *couleur);
		PointColor(const PointColor& pc); //constructeur par copie
		~PointColor();
		char* getColor() const;
		void afficher();//question2
		void cloner(const PointColor& p);//question2
		
};

PointColor::PointColor(int abs, int ord, const char *couleur): Point(abs, ord)
{
	color = new char[100]; //on suppose qu'une couleur ne fait pas plus de 100 char
	strcpy(color, couleur);
}

PointColor::PointColor(const PointColor& pc)
{
	this->Point::cloner(pc);
	color = new char[100];
	strcpy(color, pc.getColor());
}

PointColor::~PointColor()
{
	delete color;
}

void PointColor::afficher()
{
	this->Point::afficher();
	cout << color << endl ;	
}

char* PointColor::getColor() const
{ 
	return color;
}

void PointColor::cloner(const PointColor& p)
{
	this->Point::cloner(p);
	strcpy(this->color, p.getColor());
}

int main()//question3
{
	Point p1(5, 5); 
	PointColor p2(2, 4, "noir");
	p1.afficher();
	p2.afficher();
	PointColor p3(5, 5, "balnc");
	p2.cloner(p3);
	p2.afficher();
	
	return 0;
}

