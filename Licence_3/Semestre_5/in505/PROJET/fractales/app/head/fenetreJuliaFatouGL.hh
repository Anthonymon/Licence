/**
 * \file fenetreJuliaFatouGL.hh
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la definition de la classe FenetreJuliaFatouGL
 */

#ifndef FENETREJULIAFATOUGL__HH
#define FENETREJULIAFATOUGL__HH

#include "../head/fenetreMandelbrotGL.hh"
#include "../head/abstractFenetreGL.hh"
#include "../head/complex.hh"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDoubleSpinBox>

/**
 * \class FenetreJuliaFatouGL heritee de la classe AbstractFenetreGL
 * Cette classe correspond a la fenetre qui s'ouvrira quand l'utilisateur aura choisi la fractale JuliaFatou a dessiner 
 * auteur: Clement Caumes
 */
class FenetreJuliaFatouGL : public AbstractFenetreGL {
	Q_OBJECT
	
	private:
		QHBoxLayout* layoutHorizontal; /*!< Layout de contenance des widgets boutons */
		QVBoxLayout* layoutVertical; /*!< Layout de contenance de toute la fenetre */
		QDoubleSpinBox* partieReelle; /*!< Widget pour determiner la partie reelle de la fractale julia et fatou */
		QDoubleSpinBox* partieImaginaire; /*!< Widget pour determiner la partie imaginaire de la fractale julia et fatou */
		
	public:
		FenetreJuliaFatouGL(Complex& complex); 
		~FenetreJuliaFatouGL();
		
	public slots:
		void choixPartieImaginaire(double nouveau);
		void choixPartieReelle(double nouveau);
};


#endif
