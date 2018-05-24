/**
 * \file complex.cc 
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient les methodes et les fonctions concernant la classe Complex 
 */
 
#include "../head/complex.hh"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * \fn Complex::Complex()
 * Constructeur par defaut de Complex
 */
Complex::Complex(){
	this-> re=0;
	this-> im=0;
}

/**
 * \fn Complex::Complex(double r, double i)
 * Constructeur avec parametre de Complexe
 */
Complex::Complex(double r, double i){
	this->re=r;
	this->im=i;
}

/**
 * \fn Complex::~Complex()
 * Destructeur de Complex
 */
Complex::~Complex(){}

/**
 * \fn Complex& Complex::operator=(Complex& c)
 * Surcharge de l'operateur =
 */
Complex& Complex::operator=(Complex& c){
	if (this != &c){
		this->re=c.getRe();
		this->im=c.getIm();
	}
	return *this;
}

/**
 * \fn Complex operator+(const Complex& c1, const Complex& c2)
 * Surcharge de l'operateur +
 */
Complex operator+(const Complex& c1, const Complex& c2){
	return Complex(c1.re+c2.re, c1.im+c2.im);
}

/**
 * \fn Complex& Complex::operator+= (const Complex& c)
 * Surcharge de l'operateur +=
 */
Complex& Complex::operator+= (const Complex& c){
	re+=c.re;
	im+=c.im;
	return *this;
}

/**
 * \fn Complex operator* (Complex c1, Complex c2)
 * Surcharge de l'operateur *
 */
Complex operator* (const Complex& c1, const Complex& c2){
	return Complex(((c1.re*c2.re)-(c1.im*c2.im)),((c1.re*c2.im)+(c1.im*c2.re)));
}

/**
 * \fn Complex& Complex::operator*= (const Complex& c)
 * Surcharge de l'operateur *=
 */
Complex& Complex::operator*= (const Complex& c){
	double reel=((this->re*c.re)-(this->im*c.im));
	double imaginaire=((this->re*c.im)+(this->im*c.re));
	this->re=reel;
	this->im=imaginaire;
	return *this;
}

/**
 * \fn double Complex:: getRe()
 * Accesseur de la partie reelle
 */
double Complex:: getRe(){
	return this->re;
}

/**
 * \fn double Complex:: getIm()
 * Accesseur de la partie imaginaire
 */
double Complex:: getIm(){
	return this->im;
}

/**
 * \fn double Complex::getModule()
 * Retourne le module du complexe
 */
double Complex::getModule(){
	return sqrt((re*re)+(im*im));
}

/**
 * \fn double Complex::getModuleCarre()
 * Retourne le module au carre du complexe (utile pour l'optimisation)
 */
double Complex::getModuleCarre(){
	return ((re*re)+(im*im));
}

/**
 * \fn void Complex::setRe(double nb)
 * Modifie la partie reelle du complexe
 */
void Complex::setRe(double nb){
	this->re=nb;
}

/**
 * \fn void Complex::setIm(double nb)
 * Modifie la partie imaginaire du complexe
 */
void Complex::setIm(double nb){
	this->im=nb;
}

/**
 * \fn void Complex::setComplex(double re,double im)
 * Modifie le complexe
 */
void Complex::setComplex(double re,double im){
	this->re=re;
	this->im=im;
}

/**
 * \fn ostream& operator<<(ostream& os, Complex& c)
 * Permet d'afficher le complexe avec cout
 */
ostream& operator<<(ostream& os, Complex& c){
	os<<c.getRe();
	if(c.getIm()<0){
		os<<c.getIm();
	}
	else {
		os<<"+";
		os<<c.getIm();
	}
	os<<"i";
	return os;
}
