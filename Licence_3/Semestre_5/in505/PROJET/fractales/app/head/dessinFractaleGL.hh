/**
 * \file dessinFractaleGL.hh
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la definition de la classe DessinFractaleGL
 */

#ifndef DESSINFRACTALEGL__H
#define DESSINFRACTALEGL__H

#include <QApplication>
#include <QWidget>
#include <GL/glu.h>
#include "../head/complex.hh"
#include "../head/fractale.hh"
#include "../head/mandelbrot.hh"
#include "../head/juliaFatou.hh"
#include "../head/abstractDessin.hh"

/**
 * \struct PositionCamera
 * Structure correspondant a un point dans l'espace
 * auteur: Clement Caumes
 */
struct PositionCamera{
	double x; /*!< Variable sur l'axe des x */
	double y; /*!< Variable sur l'axe des y */
	double z; /*!< Variable sur l'axe des z */
};

/**
 * \class DessinFractaleGL heritant de la classe AbstractDessinGL et QGLWidget
 * Cette classe correspond au dessin de la fractale
 */
class DessinFractaleGL : public QGLWidget,public AbstractDessin
{
    Q_OBJECT
    
    private:
		double granularite; /*!< Variable representant la granluarite a un temps donne */
		PositionCamera camera; /*!< Variable de la position de la camera */
		int chromatique; /*!< Variable representant en quelles couleurs est dessine la fractale */
		Fractale* fractale; /*!< Fractale dessine dans le dessin OpenGL */
		double xMin; /*!< xMin de la fenetre */
		double xMax; /*!< xMax de la fenetre */
		double yMin; /*!< yMin de la fenetre */
		double yMax; /*!< yMax de la fenetre */
		
	public:
		DessinFractaleGL(QWidget *parent);
		DessinFractaleGL(Complex& complex,QWidget *parent);
		void initializeGL();
		void resizeGL(int largeur, int longueur);
		void paintGL();
		double getXMin();
		double getXMax();
		double getYMin();
		double getYMax();
		double getGranularite();
		double getZoom();
		int getChromatique();
		Fractale& getFractale();
		void setZMax(double nouveauZMax);
		void setPartieReelle(double nouveau);
		void setPartieImaginaire(double nouveau);
		void dessinePixel(double x,double y,double r,double g,double b);
		void dessineFractale(Fractale& f);
		~DessinFractaleGL();
		
	public slots:
		void zoom();
		void dezoom();
		void granul();
		void degranul();
		void goUp();
		void goDown();
		void goRight();
		void goLeft();
		void changeCouleur();
};
#endif
