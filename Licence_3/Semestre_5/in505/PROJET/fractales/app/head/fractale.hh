/**
 * \file fractale.hh
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient les definitions des methodes et des fonctions concernant la classe Fractale
 */

#ifndef FRACTALE__HH
#define FRACTALE__HH

#include <iostream>

using namespace std;

/**
 * \class Fractale representant une fractale
 * Cette classe heritera de 2 sous classes : Mandelbrot et JuliaFatou
 * auteur: Clement Caumes
 */
class Fractale{
	protected:
		double zMax; /*!< zMax de la fractale */
		string myType; /*!< Type de la fractale (Fractale, Mandelbrot ou JuliaFatou) */
	
	public:
		Fractale();
		Fractale(double z);
		double getZMax();
		void setZMax(double nouveauZMax);
		// pour les deux types de fractales, il faut redefinir le calcul de celle-ci
		virtual int calculFractale(double x,double y)=0;  
		// necessaire pour AbstractFentreGL
		virtual void setPartieReelle(double reel)=0;
		virtual void setPartieImaginaire(double img)=0;
		string getMyType();
		//virtual pour le delete fractale dans DessinFractaleGL (qui vont utiliser le destructeur de Mandelbrot et JuliaFatou selon la fractale choisie)
		virtual ~Fractale(); 
};

#endif
