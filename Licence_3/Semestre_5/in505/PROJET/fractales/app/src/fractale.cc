/**
 * \file fractale.cc
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la definition de la classe Fractale
 */
 
#include "../head/types.hh"
#include "../head/fractale.hh"
#include <iostream>

/**
 * \fn Fractale::Fractale() 
 * Constructeur sans parametre de Fractale
 */
Fractale::Fractale(){
	this->zMax=INITIAL_ZMAX;
	this->myType=__func__;
}

/**
 * \fn Fractale::Fractale(double z)
 * Constructeur avec parametre de Fractale
 */
Fractale::Fractale(double z){
	this->zMax=z;
	this->myType=__func__;
}

/**
 * \fn double Fractale::getZMax() Accesseur zmax de Fractale
 * Permet d'obtenir le double representant zmax
 */
double Fractale::getZMax(){
	return this->zMax;
}

/**
 * \fn void Fractale::setZMax(double nouveauZMax)
 * Permet de modifier zMax
 */
void Fractale::setZMax(double nouveauZMax){
	this->zMax=nouveauZMax;
}

/**
 * \fn string Fractale::getMyType()
 * Permet d'obtenir en string le type de ma classe
 */
string Fractale::getMyType(){
	return this->myType;
}

/**
 * \fn Fractale::~Fractale()
 * Destructeur de Fractale
 * Permet de detruire les instances de Fractale
 */
Fractale::~Fractale(){}

