/**
 * \file fenetreJuliaFatouGL.cc
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la definition des methodes de la classe FenetreJuliaFatou
 */

#include "../head/fenetreJuliaFatouGL.hh"
#include "../head/enregistreurFractale.hh"
#include "../head/dessinFractaleGL.hh"
#include "../head/types.hh"
#include <iostream>
#include <ctime> 
#include <string>

/**
 * \fn FenetreJuliaFatouGL::FenetreJuliaFatouGL(Complex& complex)
 * Constructeur de FenetreJuliaFatouGL
 * Permet de créer la fenetre pour dessiner une fractale JuliaFatou
 */
FenetreJuliaFatouGL::FenetreJuliaFatouGL(Complex& complex):AbstractFenetreGL(){    
    partieReelle=new QDoubleSpinBox; // pour modifier la partie reelle du complexe de la fractale 
    partieReelle->setRange(-10.000,10.000);
    partieReelle->setSingleStep(0.001);
    partieReelle->setValue(complex.getRe());
    partieReelle->setPrefix("c= ");
    partieReelle->setDecimals(5);
    
    partieImaginaire=new QDoubleSpinBox; // pour modifier la partie imaginaire du complexe de la fractale
    partieImaginaire->setRange(-10.000,10.000);
    partieImaginaire->setSingleStep(0.001);
    partieImaginaire->setValue(complex.getIm());
    partieImaginaire->setPrefix("+i ");
    partieImaginaire->setDecimals(5);

	layoutHorizontal=new QHBoxLayout;
	layoutHorizontal->addWidget(partieReelle);
	layoutHorizontal->addWidget(partieImaginaire);
	layoutHorizontal->addWidget(zMax);
	layoutHorizontal->addWidget(enregistrer);
    layoutHorizontal->addWidget(quitter);
	
	dessin=new DessinFractaleGL(complex,this); // dessin contenant la fractale de JuliaFatou
	dessin->move(DEPLACEMENT_LONGUEUR_DESSIN,DEPLACEMENT_LARGEUR_DESSIN);
	dessin->initializeGL();
	dessin->resize(LONGUEUR_DESSIN,LARGEUR_DESSIN);
	
	// si l'utilisateur clique sur le bouton Enregistrer : cela creera un fichier SVG de la fractale
	QObject::connect(enregistrer,SIGNAL(clicked()),this,SLOT(enregistrerCairo())); 
	
	// si l'utilisateur clique sur le bouton Quitter : cela fermera l'application
	QObject::connect(quitter,SIGNAL(clicked()),qApp,SLOT(quit()));
	
	// si l'utilisateur change la valeur du zMax : cela changera l'aspect de la fractale
	QObject::connect(zMax,SIGNAL(valueChanged(double)),SLOT(choixZMax(double)));
	
	// a chaque fois que l'utilisateur changera de valeurs pour le complexe cela changera le complexe de la fractale de JuliaFatou
	QObject::connect(partieReelle,SIGNAL(valueChanged(double)),SLOT(choixPartieReelle(double)));
	QObject::connect(partieImaginaire,SIGNAL(valueChanged(double)),SLOT(choixPartieImaginaire(double)));
	
	layoutVertical=new QVBoxLayout;
	layoutVertical->addLayout(layoutHorizontal);
	layoutVertical->addWidget(dessin);
	this->setLayout(layoutVertical);
}

/**
 * \fn void FenetreJuliaFatouGL::choixPartieReelle(double nouveau)
 * Change la valeur de la partie Reelle pour la fractale (qui sera de nouveau dessine)
 */
void FenetreJuliaFatouGL::choixPartieReelle(double nouveau){
	this->dessin->setPartieReelle(nouveau);
}

/**
 * \fn void FenetreJuliaFatouGL::choixPartieImaginaire(double nouveau)
 * Change la valeur de la partie Imaginaire pour la fractale (qui sera de nouveau dessine)
 */
void FenetreJuliaFatouGL::choixPartieImaginaire(double nouveau){
	this->dessin->setPartieImaginaire(nouveau);
}

/**
 * \fn FenetreJuliaFatouGL::~FenetreJuliaFatouGL() 
 * Destructeur de FenetreJuliaFatouGL
 * Permet de détruire la fenetre
 */
FenetreJuliaFatouGL::~FenetreJuliaFatouGL(){
	delete dessin;
	delete partieReelle;
	delete partieImaginaire;
	delete layoutHorizontal;
	delete layoutVertical;
}
