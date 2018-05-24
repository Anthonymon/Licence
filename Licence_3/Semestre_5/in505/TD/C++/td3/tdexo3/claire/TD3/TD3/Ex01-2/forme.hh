#ifndef FORME_HH
#define FORME_HH


#include "point_color.hh" 

class Forme{
	public:
		virtual void afficher()=0;
		virtual void deplacer(int dx, int dy) = 0;
	
};

class Rectangle : public Forme{
	Point bg, hd;
	
	public:
		Rectangle();
		Rectangle(const Point BG, const Point HD);
		virtual void afficher();
		virtual void deplacer(int dx, int dy);
		~Rectangle();
};

class Cercle : public Forme{
	Point c;
	
	public:
		Cercle();
		Cercle(Point C);
		virtual void afficher();
		virtual void deplacer(int dx, int dy);
		~Cercle();
	};

class Triangle : public Forme{
	Point s,bg,bd;
	
	public:
		Triangle();
		Triangle(const Point S, const Point BG, const Point BD);
		virtual void afficher();
		virtual void deplacer(int dx, int dy);
		~Triangle();
	};

class Segment : public Forme{
	private:
		Point p1, p2;
		
	public:
		Segment();
		Segment(const Point P1, const Point P2);
		virtual void afficher();
		virtual void deplacer(int dx, int dy);
		bool estVertical();
		bool estHorizontal();
		bool estSurDiagonale();
		double longueur();
		
		~Segment();
};

#endif
