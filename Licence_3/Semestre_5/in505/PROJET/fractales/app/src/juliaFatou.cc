/**
 * \file juliaFatou.cc
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient les definitions des methodes et des fonctions concernant la classe JuliaFatou
 */
 
#include "../head/types.hh"
#include "../head/fractale.hh"
#include "../head/juliaFatou.hh"
#include "../head/complex.hh"

using namespace std;

/**
 * \fn JuliaFatou::JuliaFatou()
 * Constructeur sans parametre de JuliaFatou
 */
JuliaFatou::JuliaFatou():Fractale(){
	this->myType=__func__;
	this->complex=new Complex();
}

/**
 * \fn JuliaFatou::JuliaFatou(double z)
 * Constructeur avec parametre de JuliaFatou
 */
JuliaFatou::JuliaFatou(double z):Fractale(z){
	this->myType=__func__;
	this->complex=new Complex();
}

/**
 * \fn JuliaFatou::JuliaFatou(Complex& complex)
 * Constructeur avec un complexe en parametre
 */
JuliaFatou::JuliaFatou(Complex& complex):Fractale(){
	this->myType=__func__;
	this->complex=new Complex(complex.getRe(),complex.getIm());
}

/**
 * \fn void JuliaFatou::setPartieReelle(double reel)
 * Accesseur de la partie reelle du complexe representant la fractale
 */
void JuliaFatou::setPartieReelle(double reel){
	this->complex->setRe(reel);
}

/**
 * \fn void JuliaFatou::setPartieImaginaire(double img)
 * Accesseur de la partie imaginaire du complexe representant la fractale
 */
void JuliaFatou::setPartieImaginaire(double img){
	this->complex->setIm(img);
}

/**
 * \fn int JuliaFatou::calculFractale(double x,double y)
 * Calcul de la fractale en fonction des coordonnees (x,y)
 */
int JuliaFatou::calculFractale(double x,double y){
	int iterations;
	Complex z;
	Complex cons(this->complex->getRe(),this->complex->getIm());
	z.setComplex(x,y);
	iterations=0;
	while(iterations<ITERATIONS_MAX){
		if(z.getModuleCarre()>(zMax*zMax)){
			return iterations;
		}
		z*=z;
		z+=cons;
		iterations++;
	}
	return FRACTALE;
}

/**
 * \fn JuliaFatou::~JuliaFatou() 
 * Destructeur de JuliaFatou
 * Permet de detruire les instances de JuliaFatou
 */
JuliaFatou::~JuliaFatou(){
	delete complex;
}

