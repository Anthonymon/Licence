/**
 * \file abstractFenetreGL.hh
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la defintion de la classe AbstractFenetreGL
 */

#ifndef FENETREGL__HH
#define FENETREGL__HH

#include "../head/complex.hh"
#include "../head/enregistreurFractale.hh"
#include "../head/dessinFractaleGL.hh"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDoubleSpinBox>

/**
 * \class AbstractFenetreGL heritee de la classe QWidget (Qt)
 * Cette classe correspond a la classe abstraite des fenetres de l'application.
 * auteur: Clement Caumes.
 */
class AbstractFenetreGL:public QWidget {
	Q_OBJECT
	
	protected:
		QPushButton* quitter; /*!< Bouton quitter */
		QPushButton* enregistrer; /*!< Bouton enregistrer */
		QDoubleSpinBox* zMax; /*!< Endroit pour choisir zMax */
		double zMaxChoix; /*!< Variable qui va contenir le choix de l'utilisateur */
		DessinFractaleGL* dessin; /*!< Dessin de la fractale avec OpenGL */
		
	public:
		AbstractFenetreGL(); 
		void keyPressEvent(QKeyEvent* event);
		~AbstractFenetreGL(); 
		
	public slots:
		void choixZMax(double nouveau);
		void enregistrerCairo();
};

#endif
