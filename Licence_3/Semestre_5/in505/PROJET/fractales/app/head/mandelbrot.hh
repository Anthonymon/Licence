/**
 * \file mandelbrot.hh
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la definition de la classe Mandelbrot
 */

#ifndef MANDELBROT__HH
#define MANDELBROT__HH

#include <iostream>
#include "../head/fractale.hh"

using namespace std;

/**
 * \class Mandelbrot representant une fractale Mandelbrot heritant de Fractale
 * auteur: Yassin Doudouh
 */
class Mandelbrot : public Fractale{
	
	public:
		Mandelbrot();
		Mandelbrot(double z);
		int calculFractale(double x,double y);
		void setPartieReelle(double reel);
		void setPartieImaginaire(double img);
		~Mandelbrot();
};

#endif
