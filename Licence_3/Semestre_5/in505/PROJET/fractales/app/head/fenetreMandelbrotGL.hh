/**
 * \file fenetreMandelbrotGL.hh
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la defintion de la classe FenetreMandelbrotGL
 */

#ifndef FENETREMANDELBROTGL__HH
#define FENETREMANDELBROTGL__HH

#include "../head/abstractFenetreGL.hh"
#include "../head/complex.hh"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDoubleSpinBox>

/**
 * \class FenetreMandelbrotGL heritee de la classe AbstractFenetreGL
 * Cette classe correspond a la fenetre qui s'ouvrira quand l'utilisateur aura choisi la fractale Mandelbrot a dessiner 
 * auteur: Yassin Doudouh
 */
class FenetreMandelbrotGL:public AbstractFenetreGL {
	Q_OBJECT
	
	private:
		QHBoxLayout* layoutHorizontal; /*!< Layout pour contenir les boutons */
		QVBoxLayout* layoutVertical; /*!< Layout pour contenir toute la fenetre */
		
	public:
		FenetreMandelbrotGL(); 
		~FenetreMandelbrotGL(); 

};

#endif
