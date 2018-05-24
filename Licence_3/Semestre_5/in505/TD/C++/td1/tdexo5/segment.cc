#include "segment.h"
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

Segment::Segment(){
	this->p1=Point();
	this->p2=Point();
};
Segment::Segment(double i,double j,double k,double l):p1(i,j),p2(k,l){
	//this->p1=Point(i,j);
	//this->p2=Point(k,l);
}
		
Segment::Segment(Point P1,Point P2){
	this->p1=P1;
	this->p2=P2;
};

Point Segment::getPoint1(){
	return this->p1;
}

Point Segment::getPoint2(){
	return this->p2;
}
		
double Segment::calculeDistanceAxe(Point p1,Point p2){
	double retour;
	if((this->p1.getX())==(this->p2.getX())){ //si cest vertical
		if((this->p1.getX())>(this->p2.getX())) return ((this->p1.getX())-(this->p2.getX()));
		else retour=((this->p2.getX())-(this->p1.getX()));
	}
	else{ //si cest horizontal
		if((this->p1.getY())>(this->p2.getY())) return ((this->p1.getY())-(this->p2.getY()));
		else retour=((this->p2.getY())-(this->p1.getY()));
	}
	return retour;
};
		
bool Segment::estVertical(){
	if((this->p1.getX())==(this->p2.getX())) return true;
	else return false;
};
		
bool Segment::estHorizontal(){
	if((this->p1.getY())==(this->p2.getY())) return true;
	else return false;
};
		
double Segment::longueur(){
	return sqrt(((this->p1.getX())-(this->p2.getX()))*((this->p1.getX())-(this->p2.getX()))+(((this->p1.getY())-(this->p2.getY()))*((this->p1.getY())-(this->p2.getY()))));
}
		
Segment::~Segment(){
	cout << "appel au destructeur Segment"<<endl;
};
		
