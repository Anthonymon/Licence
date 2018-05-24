#include <iostream>
#include "point.h"
#include "pointColor.h"
using namespace std;

int main()
{
	Point * p1=new Point(2,3);
	PointColor * p2=new PointColor(3,4,Couleur::Rouge);
	p1->affiche();
	p2->affiche();
	delete p1;
	delete p2;
	return 0;
}
