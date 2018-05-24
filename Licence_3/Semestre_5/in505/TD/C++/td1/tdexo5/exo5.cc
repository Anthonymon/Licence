#include <iostream>
#include <cstring>
#include "point.h"
#include "segment.h"
using namespace std;

int main(){
	Segment s(3,5,6,1);
	s.getPoint1().affiche();
	s.getPoint2().affiche();
	cout<<s.longueur()<<endl;
}
