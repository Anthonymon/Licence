#include <iostream>
#include "forme.h"
#include "segment.h"
#include "triangle.h"
#include "rectangle.h"
#include "cercle.h"
#include "point.h"

using namespace std;

int main()
{
	Point p1(2,3);
	Point p2(4,5);
	Point p3(3,9);
	Point p4(1,2);
	Point p5(9,0);
	Forme* s1=new Segment(p1,p2,Couleur::Bleu);
	Forme* t1=new Triangle(p3,p4,p5,Couleur::Rouge);
	Forme* r1=new Rectangle(p1,p2,p3,p4,Couleur::Jaune);
	/*s1->dessiner();
	s1->deplacer(2,3);
	s1->dessiner();*/
	r1->dessiner();
	r1->deplacer(2,3);
	r1->dessiner();
	
	delete s1;
	delete t1;
	delete r1;
	return 0;
}
