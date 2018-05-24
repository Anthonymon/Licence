/**
 * \file ongletVide.cc 
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient les methodes et les fonctions concernant la classe OngletVide
 */

#include <iostream>
#include "../head/types.hh"
#include "../head/ongletVide.hh"
#include "../head/menu.hh"
#include "../head/fenetreMandelbrotGL.hh"

/**
 * \fn OngletVide::OngletVide()
 * Constructeur de OngletVide
 * Permet de créer le menu de la fractale Mandelbrot
 */
OngletVide::OngletVide():QWidget(){
	this->setFixedSize(TAILLE_FENETRE_MENU,TAILLE_FENETRE_MENU);
	
	label1=new QLabel("Aucun choix possible pour le dessin de la ",this);
	label1->move(DEPLACEMENT_LONGUEUR_LABEL1,DEPLACEMENT_LARGEUR_LABEL1);
	
	label2=new QLabel("fractale Mandelbrot ",this);
	label2->move(DEPLACEMENT_LONGUEUR_LABEL2,DEPLACEMENT_LARGEUR_LABEL2);
	
	boutonValider1=new QPushButton("Valider",this); 
	boutonValider1->move(LONGUEUR_BOUTON_VALIDER,LARGEUR_BOUTON_VALIDER);
	
	// si l'utilisateur clique sur Valider : ouverture de FenetreMandelbrotGL
	QObject::connect(boutonValider1,SIGNAL(clicked()),this,SLOT(validation()));
	
	this->activation=false; //si l'utilisateur a clique sur validation
}

/**
 * \fn void OngletVide::validation()
 * Slot pour ouvrir la nouvelle fenetre pour afficher la fractale Mandelbrot
 */
void OngletVide::validation(){
	this->activation=true;
	fenetre=new FenetreMandelbrotGL();
	fenetre->show();
}

/**
 * \fn OngletVide::~OngletVide() 
 * Destructeur de OngletVide
 * Permet de détruire le menu pour la fractale Mandelbrot
 */
OngletVide::~OngletVide(){
	delete boutonValider1;
	delete label1;
	delete label2;
	if(activation==true) delete fenetre;
}
