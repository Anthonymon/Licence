#include <iostream>
#include <string.h>
#include "point.h"

using namespace std;

Point::Point(){
	this->x=0;
	this->y=0;
	this->myType=__func__;
}

Point::Point(double x,double y){
	this->x=x;
	this->y=y;
	this->myType=__func__;
}

Point::Point(Point& p){
	this->x=p.x;
	this->y=p.y;
	this->myType=__func__;
}

double Point::getX(){
	return this->x;
}

double Point::getY(){
	return this->y;
}

string Point::getMyType(){
	return this->myType;
}

void Point::affiche(){
	cout<<this->myType <<" "<<this->x<<","<<this->y<<")"<<endl;
}

void Point::clone(Point& p){
	this->x=p.x;
	this->y=p.y;
}

Point::~Point(){
	//delete myType;
	cout<<"Destruction de point"<<endl;
}
