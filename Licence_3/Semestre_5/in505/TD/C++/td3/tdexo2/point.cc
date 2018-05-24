#include <iostream>
#include <cstring>
#include "point.h"

using namespace std;

Point::Point(){
	this->x=0;
	this->y=0;
}

Point::Point(double x,double y){
	this->x=x;
	this->y=y;
}

Point::Point(Point& p){
	this->x=p.x;
	this->y=p.y;
}

double Point::getX(){
	return this->x;
}

double Point::getY(){
	return this->y;
}

void Point::setX(double a){
	this->x=a;
}

void Point::setY(double a){
	this->y=a;
}

void Point::affiche(){
	cout<<"POINT ("<<this->x<<","<<this->y<<")"<<endl;
}

void Point::clone(const Point& p){
	this->x=p.x;
	this->y=p.y;
}

Point::~Point(){
	cout<<"Destruction de point"<<endl;
}
