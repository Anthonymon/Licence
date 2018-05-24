using namespace std;

#include <iostream>
#include <cmath>

// const : rend constant le type juste à sa gauche,
// 			à droite s'il n'y a rien
class Point
{
	private:
		double x;
		double y;
		
	public:
		Point();
		Point(double x, double y);
		Point(const Point& p);
		~Point();
		double getx();
		double gety();
		void afficher();
		void cloner(const Point& p);
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

//classe composée : au moins un membre est lui-meme un objet d'une classe
class Segment
{
	private:
		Point p1;
		Point p2;
		
	public:
		Segment();
		Segment(Point const& p, const double x, const double y);
		~Segment(); //un destructeur ne se surcharge pas.
		double longueur();
		bool estHorizontal();
		bool estVertical();
		bool estSurDiagonal();
};

Segment::Segment(){}
//L'appel des constructeurs de p1 et p2 se fait automatiquement avec cette notation pour une classe composee
Segment::Segment(Point const& p, const double x, const double y): p1(p), p2(x, y){}
Segment::~Segment(){ cout << "destruction du segment" << endl; }
double Segment::longueur(){ return sqrt(pow(p2.getx()-p1.getx(),2) + pow(p2.gety()-p1.gety(),2)); }
bool Segment::estHorizontal(){ return p1.getx() == p2.getx(); }
bool Segment::estVertical(){ return p1.gety() == p2.gety();}
bool Segment::estSurDiagonal(){ return p1.getx() == p1.gety() && p2.getx() == p2.gety() ;}

int main() //pour tester les methodes
{
	Point *p1 = new Point(); //Allocation dynamique
	Point p2(2.4, 3);
	Point p3(*p1);
	
	p1->afficher();
	p1->cloner(p2);
	p1->afficher();
	
	Point& p = *p1;
	Segment *s1 = new Segment();
	Segment s2; //on initialise sans parentheses pour un objet statique avec le constructueur vide
	//Segment s2 = Point(); marche aussi
	Segment *s3 = new Segment(p, 0.3, 5);
	Segment s4(p, 0.3, 5);
	
	cout << "longueur " << s1->longueur() << endl;
	cout << "longueur " << s2.longueur() << endl; 
	cout << "longueur " << s3->longueur() << endl;
	cout << "longueur " << s4.longueur() << endl;
	
	cout << s1->estHorizontal() << endl; //1
	cout << s3->estHorizontal() << endl; //0
	cout << s1->estVertical() << endl; //1
	cout << s1->estSurDiagonal() << endl; //1
	
	delete p1; //liberation de la memoire allouee (car utilisation de new, objets dynamiques)
	//p2, p3 appel automatique du destructeur (objets statiques)
	delete s1;
	delete s3;
	//au total destruction de 3 points + 4segments + les 8 points des segments
	
	return 0;
}
