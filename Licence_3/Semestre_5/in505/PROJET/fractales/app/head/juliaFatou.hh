/**
 * \file juliaFatou.hh
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la definition de la classe JuliaFatou
 */

#ifndef JULIAFATOU__HH
#define JULIAFATOU__HH

#include "../head/fractale.hh"
#include "../head/complex.hh"
#include <iostream>

using namespace std;

/**
 * \class JuliaFatou representant une fractale JuliaFatou heritant de Fractale
 * auteur: Clement Caumes
 */
class JuliaFatou : public Fractale{
	
	private:
		Complex* complex; /*!< Complexe representant la fractale */
		
	public:
		JuliaFatou();
		JuliaFatou(double z);
		JuliaFatou(Complex& complex);
		void setPartieReelle(double reel);
		void setPartieImaginaire(double img);
		int calculFractale(double x,double y);
		~JuliaFatou();
};


#endif

