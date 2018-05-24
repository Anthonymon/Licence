#include <iostream>
#include <cstring>
#include "point.h"
#include "pointColor.h"
using namespace std;

PointColor::PointColor(double x,double y,Couleur c):Point(x,y),c(c){
	//this->myType="__POINTCOLOR__";
	this->myType=__func__;
}

PointColor::PointColor(Point& p,Couleur c):Point(p),c(c){
	this->myType=__func__;
	}

PointColor::~PointColor(){
	cout<<"Destruction de PointColor"<<endl;
}

void PointColor::affiche(){
	cout<< this->myType << " : "<< this->x << "," << this->y<< ",";
	if(this->c=Couleur::Bleu) cout<<" BLEU ";
	else if(this->c=Couleur::Jaune) cout<<" JAUNE ";
	else if(this->c=Couleur::Rouge) cout<<" ROUGE ";
	else if(this->c=Couleur::Vert) cout<<" VERT";
	cout<<")"<<endl;
}

void PointColor::clone(Point& p){
	/*if(strcmp(p.myType,this->myType)==0){
		this->x=p.getX();
		this->y=p.getY();
	}
	else {
		cout<<"TEST ECHOUE"<<endl;
	}
	
	//this->c=Couleur::Rouge;*/
	if(p.getMyType()=="PointColor"){
		PointColor* pc=(PointColor*)&p; //downwardcast
		this->x=p.getX();
		this->y=p.getY();
		this->c=pc->c;
	}
	else{
		this->Point::clone(p);
	}
	
	
}
