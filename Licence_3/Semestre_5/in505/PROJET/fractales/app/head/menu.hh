/**
 * \file menu.hh
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient les definitions des methodes et des fonctions concernant la classe Menu
 */

#ifndef MENU__HH
#define MENU__HH

#include "ongletVide.hh"
#include "ongletChoix.hh"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTabWidget>

/**
 * \class Menu heritee de la classe QWidget (Qt)
 * Cette classe correspond au menu affiche
 * Il y aura 2 pages : Julia et Fatou ; Mandelbrot afin de choisir la fractale a afficher
 * auteur: Yassin Doudouh
 */
class Menu:public QWidget {
	private:
		OngletChoix* fenetreJuliaFatou; /*!< Onglet pour le choix de julia et fatou */
		OngletVide* fenetreMandelbrot; /*!< Onglet pour le choix de mandelbrot */
		QTabWidget* tableau; /*!< Tableau qui contient les deux onglets */
		QPushButton* boutonQuitter; /*!< Bouton pour quitter */
	
	public:
		Menu();
		~Menu();
};

#endif
