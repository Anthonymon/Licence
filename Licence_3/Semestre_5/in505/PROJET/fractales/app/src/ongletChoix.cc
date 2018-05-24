/**
 * \file ongletChoix.cc 
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient les methodes et les fonctions concernant la classe OngletChoix
 */

#include "../head/types.hh"
#include "../head/ongletChoix.hh"
#include "../head/ongletVide.hh"
#include "../head/menu.hh"
#include "../head/fenetreJuliaFatouGL.hh"
#include <iostream>
#include <string>


/**
 * \fn OngletChoix::OngletChoix() 
 * Constructeur de PageJulia
 * Permet de créer le menu de la fractale Julia et Fatou
 */
OngletChoix::OngletChoix(){
	
	// on crée le bouton pour quitter afin de quitter proprement le programme
	boutonValider2=new QPushButton("Valider",this); 
	boutonValider2->move(LONGUEUR_BOUTON_VALIDER,LARGEUR_BOUTON_VALIDER);
	
	// on crée un ensemble de choix pour la constante c
    choixConstante=new QGroupBox("Choix de la constante", this);
    constante1=new QRadioButton("c1 = -0.0519 + i 0.688");
    constante2=new QRadioButton("c2 = -0.577 + i 0.478");
    constante3=new QRadioButton("c3 =");
    constante1->setChecked(true);
    
    // les choix initiaux de l'utilisateur 
    decisionConstante=CHOIXC1;
    
    activation=false;
    
	// on peut choisir la constante c3 avec des valeurs diverses
    partieReelle=new QDoubleSpinBox;
    partieReelle->setRange(-10.000,10.000);
    partieReelle->setSingleStep(0.001);
    partieReelle->setValue(0.000);
    partieReelle->setDecimals(5);
    partieImaginaire=new QDoubleSpinBox;
    partieImaginaire->setRange(-10.000,10.000);
    partieImaginaire->setSingleStep(0.001);
    partieImaginaire->setValue(0.000);
    partieImaginaire->setPrefix("+i ");
    partieImaginaire->setDecimals(5);
    
    // on place le choix numero 3 dans un layout horizontal
    layoutComplexe=new QHBoxLayout;
    layoutComplexe->addWidget(constante3);
    layoutComplexe->addWidget(partieReelle);
    layoutComplexe->addWidget(partieImaginaire);

    // puis on place tous les widgets ensemble dans un meme layout vertical
    layoutConstante=new QVBoxLayout;
    layoutConstante->addWidget(constante1);
    layoutConstante->addWidget(constante2);
    layoutConstante->addLayout(layoutComplexe);
    choixConstante->setLayout(layoutConstante);
    choixConstante->move(DEPLACEMENT_CHOIX_CONSTANTE,DEPLACEMENT_CHOIX_CONSTANTE);
    
    // si on clique sur Valider, on va ouvrir une fenetre JuliaFatou en fonction des choix de l'utilisateur
    QObject::connect(boutonValider2,SIGNAL(clicked()),this,SLOT(validation()));
    
    // si l'utilisateur a choisi de dessiner la fractale Julia et Fatou avec la constante 1, 2 ou une autre
    QObject::connect(constante1,SIGNAL(clicked()),this,SLOT(changementConstante1()));
    QObject::connect(constante2,SIGNAL(clicked()),this,SLOT(changementConstante2()));
    QObject::connect(constante3,SIGNAL(clicked()),this,SLOT(changementConstante3()));
    
    // si l'utilisateur a choisi la constante 3 et donc de choisir le nombre complexe
    QObject::connect(partieReelle,SIGNAL(valueChanged(double)),SLOT(choixPartieReelle(double)));
    QObject::connect(partieImaginaire,SIGNAL(valueChanged(double)),SLOT(choixPartieImaginaire(double)));
}

/**
 * \fn void OngletChoix::changementConstante1()
 * Slot pour choisir la constante c1 par l'utilisateur
 */
void OngletChoix::changementConstante1(){
	this->decisionConstante=CHOIXC1;
}

/**
 * \fn void OngletChoix::changementConstante2()
 * Slot pour choisir la constante c2 par l'utilisateur
 */
void OngletChoix::changementConstante2(){
	this->decisionConstante=CHOIXC2;
}

/**
 * \fn void OngletChoix::changementConstante3()
 * Slot pour choisir la constante c3 par l'utilisateur
 */
void OngletChoix::changementConstante3(){
	this->decisionConstante=CHOIXC3;
}

/**
 * \fn void OngletChoix::choixPartieReelle(double reelle)
 * Slot pour stocker la partie reelle du complexe choisi par l'utilisateur
 */
void OngletChoix::choixPartieReelle(double reelle){
	this->choixReel=reelle;
}

/**
 * \fn void OngletChoix::choixPartieImaginaire(double imaginaire)
 * Slot pour stocker la partie imaginaire du complexe choisi par l'utilisateur
 */
void OngletChoix::choixPartieImaginaire(double imaginaire){
	this->choixImagi=imaginaire;
}

/**
 * \fn void OngletChoix::validation()
 * Slot pour ouvrir la nouvelle fenetre en fonction de l'attribut decisionInterface 
 */
void OngletChoix::validation(){ //mettre le test activation
	this->activation=true;
	if(this->decisionConstante==CHOIXC1){ //avec la constante 1
		Complex complex1(-0.0519,0.688);
		fenetre=new FenetreJuliaFatouGL(complex1);
	}
	else if(this->decisionConstante==CHOIXC2){ //avec la constante 2
		Complex complex2(-0.577,0.478);
		fenetre=new FenetreJuliaFatouGL(complex2);
	}
	else{ //avec un nombre complexe choisi par l'utilisateur
		Complex complex3(this->choixReel,this->choixImagi);
		fenetre=new FenetreJuliaFatouGL(complex3);
	}
	fenetre->show();
}

/**
 * \fn OngletChoix::~OngletChoix()
 * Destructeur de l'onglet
 * Permet de détruire le menu pour la fractale Julia et Fatou
 */
OngletChoix::~OngletChoix(){
	delete constante1;
	delete constante2;
	delete constante3;
	delete partieReelle;
	delete partieImaginaire;
	if(activation==true) delete fenetre;
	delete layoutComplexe;
	delete layoutConstante;
	delete choixConstante;
}
