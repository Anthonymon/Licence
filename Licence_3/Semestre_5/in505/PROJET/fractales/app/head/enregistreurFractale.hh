/**
 * \file enregistreurFractale.hh 
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la definition de la classe EnregistreurFractale
 */

#ifndef ENREGISTREURFRACTALE__HH
#define ENREGISTREURFRACTALE__HH

#include "../head/fractale.hh"
#include "../head/mandelbrot.hh"
#include "../head/juliaFatou.hh"
#include "../head/dessinFractaleGL.hh"
#include "../head/abstractDessin.hh"
#include <cairommconfig.h>
#include <cairomm/cairomm.h>

using namespace Cairo;

/**
 * \class EnregistreurFractale representant l'enregistrement vectoriel svg
 * auteur: Yassin Doudouh
 */
class EnregistreurFractale: public AbstractDessin{
	private:
		double largeur; /*!< Largeur de l'image svg construite */
		double hauteur; /*!< Hauteur de l'image svg construite */
		string filename; /*!< Nom du fichier svg */
		RefPtr<SvgSurface> surface; /*!< Pour creer une image SVG */
		RefPtr<Context> contexte; /*!< Pour dessiner sur cette image SVG */
	
	public:
		EnregistreurFractale(string filename);
		void enregistrerFractale(DessinFractaleGL& dessin);
		void dessinePixel(double x,double y,double r,double g,double b);
		~EnregistreurFractale();
};

#endif
