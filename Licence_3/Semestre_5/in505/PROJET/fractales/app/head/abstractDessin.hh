/*!
 * \file abstractDessin.hh
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la defintion de la classe AbstractDessin
 */

#ifndef ABSTRACTDESSIN_H
#define ABSTRACTDESSIN_H

#include <QtOpenGL>
#include <QGLWidget>
#include "../head/fractale.hh"

/*!
 * \class AbstractDessin 
 * Cette classe va permettre de dessiner une fractale avec OpenGL et Cairo.
 * auteur: Yassin Doudouh
 */
class AbstractDessin {
	public:
		AbstractDessin(); 
		virtual void dessinePixel(double x,double y,double r,double g,double b)=0;
		~AbstractDessin();
};

#endif
