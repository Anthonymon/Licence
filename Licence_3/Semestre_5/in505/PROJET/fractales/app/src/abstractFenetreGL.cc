/**
 * \file abstractFenetreGL.cc 
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la methodes de la classe AbstractFenetreGL
 */

#include "../head/abstractFenetreGL.hh"
#include "../head/types.hh"
#include <iostream>
#include <QMessageBox>

/**
 * \fn AbstractFenetreGL::AbstractFenetreGL() 
 * Constructeur de AbstractFenetreGL
 */
AbstractFenetreGL::AbstractFenetreGL() : QWidget(){
	setFixedSize(LONGUEUR_TAILLE_FENETRE,LARGEUR_TAILLE_FENETRE);
	
	dessin=NULL; // pointeur de AbstractDessinGL a NULL car il sera instancie par les classes filles 
	
	quitter=new QPushButton("Quitter",this); // bouton pour quitter afin de quitter proprement le programme
	
	enregistrer=new QPushButton("Enregistrer",this); // bouton pour enregistrer avec Cairo
	
	this->zMaxChoix=INITIAL_ZMAX; // chaque fractale a zMax=2.0 a l'ouverture de la fenetre 

	zMax=new QDoubleSpinBox; // widget pour changer la valeur de zMax de la fractale
    zMax->setRange(0.00,10.00);
    zMax->setSingleStep(0.01); 
    zMax->setValue(INITIAL_ZMAX);
    zMax->setDecimals(2);
    zMax->setPrefix("ZMAX = ");
}

/**
 * \fn void AbstractFenetreGL::choixZMax(double nouveau)
 * Change la valeur zMax pour la fractale (qui sera de nouveau dessine)
 */
void AbstractFenetreGL::choixZMax(double nouveau){
	this->dessin->setZMax(nouveau); // changement de l'attribut zMax de AbstractDessinGL
}

/**
 * \fn void AbstractFenetreGL::enregistrerCairo()
 * Au clic "Enregistrer", la fractale est enregistre avec Cairo sous forme de fichier SVG
 */
void AbstractFenetreGL::enregistrerCairo(){
	/* si la granularite est beaucoup trop importante, l'ouverture du fichier SVG pose probleme 
	   car trop de pixels doivent etre dessines */
	if(this->dessin->getGranularite()>0.001){ 
		time_t t=time(NULL);
		struct tm* temps=localtime(&t);
		int hour=temps->tm_hour;
		int min=temps->tm_min;
		int sec=temps->tm_sec;
		// creation du titre en fonction de la fractale et de l'heure a laquelle le fichier a ete cree 
		std::string titre = "save/"+(this->dessin->getFractale().getMyType());
		titre+= std::to_string(hour);
		titre+= std::to_string(min);
		titre+=std::to_string(sec);
		titre+=".svg";
		EnregistreurFractale enregistreur(titre);
		enregistreur.enregistrerFractale(*dessin);
		QMessageBox::information(this,"Cairo","Nouveau fichier svg cree dans le dossier save/");
	}
	else{
		QMessageBox::critical(this,"Cairo","Pour des raisons de performances, lorsque la granularite choisie est trop faible, aucun fichier svg ne sera enregistre");
	}
}

/**
 * \fn void AbstractFenetreGL::keyPressEvent(QKeyEvent* event)
 * En fonction de la touche pressee par l'utilisateur, cela change la vue de la fractale
 */
void AbstractFenetreGL::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_O){ //touche Zoom
       dessin->zoom();
    }
    else if(event->key() == Qt::Key_P){ //touche dezoom
       dessin->dezoom();
    }
    else if(event->key() == Qt::Key_L){ //touche diminution distance Pixels
       dessin->granul();
    }
    else if(event->key() == Qt::Key_M){ //touche augmentation distance Pixels
       dessin->degranul();
    }
    else if(event->key() == Qt::Key_Z){ //touche Up
		dessin->goUp();
	}
	else if(event->key() == Qt::Key_S){ //touche Down
		dessin->goDown();
	}
	else if(event->key() == Qt::Key_D){ //touche Right
		dessin->goRight();
	}
	else if(event->key() == Qt::Key_Q){ //touche Left 
		dessin->goLeft();
	}
	else if(event->key() == Qt::Key_C){ //touche de Changement de couleur
		dessin->changeCouleur();
	}
}

/**
 * \fn AbstractFenetreGL::~AbstractFenetreGL() Destructeur de AbstractFenetreGL
 * Permet de détruire la fenetre
 */
AbstractFenetreGL::~AbstractFenetreGL(){
	delete quitter;
	delete enregistrer;
	delete zMax;
}
