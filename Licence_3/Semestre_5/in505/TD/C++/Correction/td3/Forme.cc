#include <iostream>

using namespace std;

class Forme
{
	//pas d'attributs pour une forme abstraite
	public:
		virtual ~Forme(); //virtual pour le destructeur car la methode est abstraite
		virtual void deplacer(double dx, double dy) = 0; //methode virtuelle pure => classe abstraite
		virtual void afficher() = 0; //dx decalage horizontal, dy decalage vertical
};

Forme::~Forme(){}

class Point : public Forme //classe nécessaire pour construire les autres formes
{
	private:
		double x;
		double y;
	public:
		Point();
		Point(double xx, double yy);
		Point(const Point& p);
		~Point();
		Point& operator=(const Point& p);
		void deplacer(double dx, double dy);
		void afficher();
	friend class Segment; //Pour que les classes puissent manipuler les coords directement
	friend class Triangle;
	friend class Rectangle;
	friend class Cercle;
};

Point::Point(){ x = 0; y = 0; }
Point::Point(double xx, double yy){ x = xx; y = yy;}
Point::Point(const Point& p){ x = p.x; y = p.y; }
Point::~Point(){}
Point& Point::operator=(const Point& p){ x = p.x; y = p.y;}
void Point::deplacer(double dx, double dy){ x += dx; y += dy; }
void Point::afficher(){ cout << "x = " << x << " y = " << y << endl;}

class Segment : public Forme //derivation publique (les membres de la classe de base gardent leurs propriétés d'accès dans la classe dérivée)
{
	private:
		Point p1;
		Point p2;
	public:
		Segment(Point pp1, Point pp2);
		Segment(const Segment& seg);
		~Segment();
		void deplacer(double dx, double dy);
		void afficher();
};

Segment::Segment(Point pp1, Point pp2): p1(pp1.x, pp1.y), p2(pp2.x, pp2.y){}
Segment::Segment(const Segment& seg){ p1 = seg.p1; p2 = seg.p2; }
Segment::~Segment(){}
void Segment::deplacer(double dx, double dy){ p1.deplacer(dx, dy); p2.deplacer(dx, dy); }
void Segment::afficher(){ cout << "Segment\npoint 1 : "; p1.afficher(); cout << "point 2 : "; p2.afficher(); }

class Triangle : public Forme
{
	private:
		Point p1; //Un tableau de 3 points est plus simple a manipuler
		Point p2;
		Point p3;
	public:
		Triangle(Point pp1, Point pp2, Point pp3);
		Triangle(const Triangle& tri);
		~Triangle();
		void deplacer(double dx, double dy);
		void afficher();
};

Triangle::Triangle(Point pp1, Point pp2, Point pp3): p1(pp1.x, pp1.y), p2(pp2.x, pp2.y), p3(pp3.x, pp3.y){}
Triangle::Triangle(const Triangle& tri){ p1 = tri.p1; p2 = tri.p2; p3 = tri.p3; }
Triangle::~Triangle(){}
void Triangle::deplacer(double dx, double dy){ p1.deplacer(dx, dy); p2.deplacer(dx, dy); p3.deplacer(dx, dy); }
void Triangle::afficher(){ cout << "Triangle\npoint 1 : "; p1.afficher(); cout << "point 2 : "; p2.afficher(); cout << "point 3 : "; p3.afficher(); }

class Rectangle : public Forme
{
	private:// on peut aussi 1 point, la longueur et la largeur
		Point hautG;
		double largeur;
		double longueur;
	public:
		Rectangle(Point hg, double l, double L);
		Rectangle(const Rectangle& rect);
		~Rectangle();
		void deplacer(double dx, double dy);
		void afficher();
};

Rectangle::Rectangle(Point hg, double l, double L): hautG(hg.x, hg.y){ largeur = l; longueur = L;}
Rectangle::Rectangle(const Rectangle& rect){ hautG = rect.hautG; longueur = rect.longueur; largeur = rect.largeur;}
Rectangle::~Rectangle(){}
void Rectangle::deplacer(double dx, double dy){ hautG.deplacer(dx, dy); }
void Rectangle::afficher(){ cout << "Rectangle\npoint haut gauche : "; hautG.afficher(); cout << "longueur = " << longueur << " largeur = " << largeur << endl;}

class Cercle : public Forme
{
	private:
		Point centre;
		double rayon;
	public:
		Cercle(double r, Point c);
		Cercle(const Cercle& c);
		~Cercle();
		void deplacer(double dx, double dy);
		void afficher();
};

Cercle::Cercle(double r, Point c): centre(c) { rayon = r; }
Cercle::Cercle(const Cercle& c){ rayon = c.rayon; centre = c.centre; }
Cercle::~Cercle(){}
void Cercle::deplacer(double dx, double dy){ centre.x += dx; centre.y += dy; }
void Cercle::afficher(){ cout << "Cercle\ncentre "; centre.afficher(); cout << "rayon = " << rayon << endl; }

int main()
{
	Point p1;
	Point p2(1, -1);
	Point p3(2.1, 4.2);
	Segment *s = new Segment(p1, p2);
	Triangle *t = new Triangle(p1, p2, p3);
	Rectangle *r = new Rectangle(p2, 5, 10);
	Cercle *c = new Cercle(4, p3);
	
	int n = 4;
	Forme **liste = new Forme*[n];
	liste[0] = s;
	liste[1] = t;
	liste[2] = r;
	liste[3] = c;
	int i;
	for(i = 0; i < n; i++)
	{
		liste[i]->afficher();
		liste[i]->deplacer(-2, 3.8);
		liste[i]->afficher();
	}
	delete s;
	delete t;
	delete r;
	delete c;
	return 0;
}
