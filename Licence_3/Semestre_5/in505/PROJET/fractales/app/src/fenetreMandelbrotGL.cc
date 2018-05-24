/**
 * \file fenetreMandelbrotGL.cc
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la defintion des methodes de FenetreMandelbrotGL
 */

#include "../head/fenetreMandelbrotGL.hh"
#include "../head/types.hh"
#include "../head/enregistreurFractale.hh"
#include "../head/dessinFractaleGL.hh"
#include <iostream>
#include <ctime> 
#include <string>

/**
 * \fn FenetreMandelbrotGL::FenetreMandelbrotGL()
 * Constructeur de FenetreMandelbrotGL
 * Permet de créer la fenetre pour dessiner une fractale Mandelbrot
 */
FenetreMandelbrotGL::FenetreMandelbrotGL():AbstractFenetreGL(){
	this->zMaxChoix=INITIAL_ZMAX;

	layoutHorizontal=new QHBoxLayout;
	layoutHorizontal->addWidget(zMax);
	layoutHorizontal->addWidget(enregistrer);
    layoutHorizontal->addWidget(quitter);
	
	dessin=new DessinFractaleGL(this); // dessin qui contiendra la fractale
	dessin->move(DEPLACEMENT_LONGUEUR_DESSIN,DEPLACEMENT_LARGEUR_DESSIN);
	dessin->initializeGL();
	dessin->resize(LONGUEUR_DESSIN,LARGEUR_DESSIN);
	
	// si l'utilisateur clique sur le bouton Enregistrer : cela creera un fichier SVG de la fractale
	QObject::connect(enregistrer,SIGNAL(clicked()),this,SLOT(enregistrerCairo())); 
	// si l'utilisateur clique sur le bouton Quitter : cela fermera l'application
	QObject::connect(quitter,SIGNAL(clicked()),qApp,SLOT(quit()));
	
	// si l'utilisateur change la valeur du zMax : cela changera l'aspect de la fractale
	QObject::connect(zMax,SIGNAL(valueChanged(double)),SLOT(choixZMax(double)));
	
	layoutVertical=new QVBoxLayout;
	layoutVertical->addLayout(layoutHorizontal);
	layoutVertical->addWidget(dessin);
	this->setLayout(layoutVertical);
}

/**
 * \fn FenetreMandelbrotGL::~FenetreMandelbrotGL()
 * Destructeur de FenetreOpenGL
 * Permet de détruire la fenetre
 */
FenetreMandelbrotGL::~FenetreMandelbrotGL(){
	delete dessin;
}
