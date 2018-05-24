/**
 * \file mandelbrot.cc
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient les definitions des methodes et des fonctions concernant la classe Mandelbrot
 */
 
#include "../head/types.hh"
#include "../head/fractale.hh"
#include "../head/mandelbrot.hh"
#include "../head/complex.hh"

using namespace std;

/**
 * \fn Mandelbrot::Mandelbrot()
 * Constructeur sans parametre de Mandelbrot
 */
Mandelbrot::Mandelbrot():Fractale(){
	this->myType=__func__;
}

/**
 * \fn Mandelbrot::Mandelbrot(double z)
 * Constructeur avec parametre de Mandelbrot
 */
Mandelbrot::Mandelbrot(double z):Fractale(z){
	this->myType=__func__;
}

/**
 * \fn void Mandelbrot::setPartieReelle(double reel)
 * Fonction qui ne sera jamais utilisee : creee pour gerer nimporte quel type de fractale
 */
void Mandelbrot::setPartieReelle(double reel){
	cerr << "Impossible de modifier la partie reelle " << reel <<" du complexe de la fractale de Mandelbrot" << endl;
}

/**
 * \fn void Mandelbrot::setPartieImaginaire(double img)
 * Fonction qui ne sera jamais utilisee : creee pour gerer nimporte quel type de fractale
 */
void Mandelbrot::setPartieImaginaire(double img){
	cerr << "Impossible de modifier la partie imaginaire " << img <<" du complexe de la fractale de Mandelbrot" << endl;
}

/**
 * \fn int Mandelbrot::calculFractale(double x,double y)
 * Fonction de calcul de Fractale en fonction des coordonnees (x,y)
 */
int Mandelbrot::calculFractale(double x,double y){
	int iterations;
	Complex c;
	Complex z;
	c.setComplex(x,y);
	z.setComplex(0,0);
	iterations=0;
	while(iterations<ITERATIONS_MAX){
		//calcul du carre du module pour optimiser (la racine carree est tres couteuse)
		if(z.getModuleCarre()>(zMax*zMax)){ 
			return iterations;
		}
		z*=z;
		z+=c;
		iterations++;
	}
	return FRACTALE;
}

/**
 * \fn Mandelbrot::~Mandelbrot()
 * Destructeur de Mandelbrot
 * Permet de detruire les instances de Mandelbrot
 */
Mandelbrot::~Mandelbrot(){}

