/**
 * \file menu.cc 
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient les methodes et les fonctions concernant la classe Menu
 */

#include "../head/types.hh"
#include "../head/menu.hh"

/**
 * \fn Menu::Menu() 
 * Constructeur de Menu
 * Permet de créer le menu de base qui s'affiche à l'exécution du programme
 */
Menu::Menu() : QWidget(){
	setFixedSize(LONGUEUR_MENU,LARGEUR_MENU); //on fixe la taille pour le menu
	
	tableau=new QTabWidget (this); 
	tableau->setFixedSize(LONGUEUR_TAB_WIDGET,LARGEUR_TAB_WIDGET); // on place le TabWidget pour les sous menus
	tableau->move(DEPLACEMENT_LONGUEUR_TAB_WIDGET,DEPLACEMENT_LARGEUR_TAB_WIDGET);
	
	// on crée les 2 sous menus pour que l'utilisateur choisisse le type de fractales
	fenetreJuliaFatou=new OngletChoix();  
	fenetreMandelbrot=new OngletVide();
	tableau->insertTab(1,fenetreMandelbrot,"Mandelbrot");
	tableau->insertTab (2, fenetreJuliaFatou, "Julia et Fatou" );
	
	
	boutonQuitter=new QPushButton("Quitter",this); // on crée le bouton pour quitter afin de quitter proprement le programme
	boutonQuitter->move(DEPLACEMENT_LONGUEUR_QUITTER,DEPLACEMENT_LARGEUR_QUITTER);
	QObject::connect(boutonQuitter,SIGNAL(clicked()),qApp,SLOT(quit())); // si on clique sur le bouton Quitter on ferme le programme
}

/**
 * \fn Menu::~Menu() 
 * Destructeur de Menu
 * Permet de détruire le menu
 */
Menu::~Menu(){
	delete fenetreJuliaFatou;
	delete fenetreMandelbrot;
	delete boutonQuitter;
	delete tableau;
}
