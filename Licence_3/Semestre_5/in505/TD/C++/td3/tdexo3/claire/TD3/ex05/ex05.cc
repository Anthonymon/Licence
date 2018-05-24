#include "segment.h"
#include <iostream>
using namespace std;

int main(){
	Point p,q(2,5);
	p.afficher();
	q.afficher();
	
	Segment s(p,q);
	s.afficher();
	if(s.estSurDiagonale()) cout << "s est une diagonale\n";
	
	Point z(3,5),y(6,1);
	Segment* a = new Segment(z,y);
	if(a->estVertical()) cout << "s est une diagonale\n";
	cout << "longueur de a = " << a->longueur() << endl;
	delete a;
}
