/**
 * \file complex.hh 
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient les definitions des methodes et des fonctions concernant la classe Complex 
 */
 
#ifndef COMPLEX__H
#define COMPLEX__H

#include <iostream>

using namespace std;

/**
 * \class Complex
 * Cette classe correspond a un complexe avec une partie reelle et une partie imaginaire x+iy
 * auteur: Clement Caumes
 */
class Complex {
	
	private:
		double re; /*!< Partie reelle du complexe */
		double im; /*!< Partie Imaginaire du complexe */
	
	public:
		Complex();
		Complex(double r, double i);
		~Complex();
		
		double getRe();
		double getIm();
		double getModule();
		double getModuleCarre();
		void setRe(double nb);
		void setIm(double nb);
		void setComplex(double re,double im);
		
		Complex& operator=(Complex& s);
		
		friend Complex operator+ (const Complex& c1, const Complex& c2); /*!< Redefinition de l'operateur + */
		Complex& operator+=(const Complex& c);
		
		friend Complex operator* (const Complex& c1, const Complex& c2); /*!< Redefinition de l'operateur * */
		Complex& operator*=(const Complex& c);
		
};

ostream& operator<<(ostream& os, Complex& c);

#endif
