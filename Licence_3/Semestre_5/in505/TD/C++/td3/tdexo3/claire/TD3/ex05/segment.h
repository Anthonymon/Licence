#ifndef __SEGMENT_H
#define __SEGMENT_H


class Point{
	private:
		int x,y;
	
	public:		
		Point();
		Point(int x, int y);
		Point(const Point& p);
		
		void afficher();
		void cloner(const Point& p);
		int getAbscisse();
		int getOrdonnee();
		~Point();
};

class Segment{
	private:
		Point p1, p2;
		
	public:
		Segment();
		Segment(const Point P1, const Point P2);
		void afficher();
		bool estVertical();
		bool estHorizontal();
		bool estSurDiagonale();
		double longueur();
		
		~Segment();
};

#endif
