/**
 * \file ongletVide.hh
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient les definitions des methodes et des fonctions concernant la classe OngletVide
 */

#ifndef ONGLETVIDE__HH
#define ONGLETVIDE__HH

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "../head/fenetreMandelbrotGL.hh"

/**
 * \class OngletVide heritee de la classe QWidget (Qt)
 * Cette classe correspond à la page de Mandelbrot dans le menu
 * auteur: Yassin Doudouh
 */
class OngletVide:public QWidget{
	Q_OBJECT
	
	private:
		bool activation; /*!< A chaque fois que l'on clique sur valider */
		FenetreMandelbrotGL* fenetre; /*!< Fenetre qui s'ouvrira lorsque l'utilisateur clique sur valider */
		QPushButton* boutonValider1; /*!< Bouton pour valider */
		QLabel* label1; /*!< Widget pour ecrire la premiere ligne de la presentation */
		QLabel* label2; /*!< Widget pour ecrire la deuxieme ligne de la presentation */
	
	public:
		OngletVide();
		~OngletVide();
		
	public slots:
		void validation();
};

#endif
