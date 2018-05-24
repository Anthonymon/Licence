/**
 * \file enregistreurFractale.cc
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la definition des methodes de EnregistreurFractale
 */

#include "../head/enregistreurFractale.hh"
#include "../head/types.hh"

using namespace Cairo;

/**
 * \fn EnregistreurFractale::EnregistreurFractale(string filename)
 * Constructeur de EnregistreurFractale 
 */
EnregistreurFractale::EnregistreurFractale(string filename){
	this->filename=filename;
	this->largeur=0;
	this->hauteur=0;
}

/**
 * \fn EnregistreurFractale::~EnregistreurFractale()
 * Destructeur de EnregistreurFractale
 */
EnregistreurFractale::~EnregistreurFractale(){}

/**
 * \fn void EnregistreurFractale::dessinePixel(double x,double y,double r,double g,double b)
 * Fonction qui dessine un pixel 
 * Redfinition de la methode de AbstractDessin pour dessiner un pixel selon Cairo
 */
void EnregistreurFractale::dessinePixel(double x,double y,double r,double g,double b){
	contexte->stroke(); //afficher 
	contexte->set_source_rgb(r, g, b); //dessiner en couleur r,g,b
	contexte->move_to(x, y); //place le point en (x,y)
	contexte->line_to(x+1, y); // place le point juste a cote
}

/**
 * \fn void EnregistreurFractale::enregistrerFractale(DessinFractaleGL& dessin)
 * Fonction qui enregistre la fractale, cad qui cree un fichier SVG afin de la dessiner
 */
void EnregistreurFractale::enregistrerFractale(DessinFractaleGL& dessin){
	// en fonction de la granularite du dessin, on va creer une image SVG selon la taille de la fractale
	// permet de determiner le nombre de pixels dans l'image svg
	double calculTaille=((dessin.getXMax()-dessin.getXMin())/dessin.getGranularite());
	this->largeur=calculTaille;
	this->hauteur=calculTaille;
	
	//creation de SvgSurface
	this->surface = SvgSurface::create(this->filename,this->largeur, this->hauteur);
	
	//creation du contexte pour dessiner
	this->contexte = Context::create(surface);
	contexte->set_source_rgb(0, 0, 0); //couleur noire
	contexte->set_line_width(1); //mettre des traits de la taille d'un pixel
	
	double compteurX=dessin.getXMin(); 
	double compteurY=dessin.getYMax();	
	double x,y;
	int test;
	for(x=0;x<(this->largeur); x=x+0.5){ //pour chaque pixel de l'image SVG
		compteurY=dessin.getYMax();
		for(y=0;y<(this->hauteur);y=y+0.5){
			//calcul de la fractale pour chaque pixel
			test=dessin.getFractale().calculFractale(compteurX,compteurY);
			if(test==FRACTALE) dessinePixel(x,y,0,0,0);
			compteurY-=dessin.getGranularite();
		}
		compteurX+=dessin.getGranularite();
	}
	contexte->stroke(); 
	
	std::cout<<"Nouveau fichier "<<filename<<" cree"<<std::endl;
}
