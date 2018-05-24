/**
 * \file dessinFractaleGL.cc
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la definition des methodes de DessinFractaleGL
 */

#include "../head/dessinFractaleGL.hh"
#include "../head/complex.hh"
#include "../head/mandelbrot.hh"
#include "../head/types.hh"
#include <QtOpenGL>
#include <QGLWidget>
#include <iostream>
#include <GL/glu.h>

/**
 * \fn DessinFractaleGL::DessinFractaleGL(QWidget *parent) 
 * Constructeur de DessinFractaleGL
 * Permet de créer le dessin de la fractale
 * Ce constructeur sera uniquement utilise pour dessiner une fractale Mandelbrot
 */
DessinFractaleGL::DessinFractaleGL(QWidget *parent): QGLWidget(parent){
	// position initiale de la Camera
	this->camera.x=INITIAL_X; 
	this->camera.y=INITIAL_Y;
	this->camera.z=INITIAL_Z;
	
	this->granularite=INITIAL_GRANULARITE; //granularite initiale du dessin de la fractale
	this->chromatique=MONOCHROMATIQUE; //dessin en noir et blanc au depart (COULEURX ensuite)
	this->xMin=-2.0;
	this->xMax=2.0;
	this->yMin=-2.0;
	this->yMax=2.0;
	fractale=new Mandelbrot(); // creation de la fractale Mandelbrot
}

/**
 * \fn DessinFractaleGL::DessinFractaleGL(Complex& complex,QWidget *parent)
 * Constructeur de DessinFractaleGL
 * Permet de créer le dessin de la fractale JuliaFatou.
 * Ce constructeur sera uniquement utilise pour dessiner une fractale JuliaFatou.
 */
DessinFractaleGL::DessinFractaleGL(Complex& complex,QWidget *parent): QGLWidget(parent){
	// position initiale de la Camera
	this->camera.x=INITIAL_X; 
	this->camera.y=INITIAL_Y;
	this->camera.z=INITIAL_Z;
	
	this->granularite=INITIAL_GRANULARITE; //granularite initiale du dessin de la fractale
	this->chromatique=MONOCHROMATIQUE; //dessin en noir et blanc au depart (COULEURX ensuite)
	this->xMin=-2.0;
	this->xMax=2.0;
	this->yMin=-2.0;
	this->yMax=2.0;
	fractale=new JuliaFatou(complex); //creation de la fractale JuliaFatou
}

/**
 * \fn void DessinFractaleGL::initializeGL()
 * Fonction qui initialise DessinFractaleGL afin de pouvoir dessiner ensuite la fractale
 */
void DessinFractaleGL::initializeGL(){
    glShadeModel(GL_SMOOTH); // specifie la technique d'ombrage (initialisation avec la valeur initiale)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // couleur initiale de la fenetre --> blanc
    glClearDepth(1.0f); // valeur de profondeur utilisee lorsque le tampon de profondeur est effacee (initialisation avec la valeur initiale)
    glEnable(GL_DEPTH_TEST); // activation GL
    glDepthFunc(GL_LEQUAL); // activation de l'ordre des elements pour l'affichage (un pixel dessine avant un autre le replacera)
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // specialisation des mises en oeuvre
}

/**
 * \fn void DessinFractaleGL::resizeGL(int width, int height)
 * Fonction qui permet de redimensionner le dessin en fonction de la nouvelle taille choisie.
 * Utile pour le Zoom et le DeZoom
 */
void DessinFractaleGL::resizeGL(int largeur, int longueur){
    try{
		if((longueur<0)||(largeur<0)) throw string("Erreur taille Fenetre. ");
	}
	catch(string const& erreur){
		cerr << erreur << endl;
	}
    glViewport(0, 0, largeur, longueur); // specification de la taille de la fenetre apres une redimension
    glMatrixMode(GL_PROJECTION); // specification de la matrice actuelle
    glLoadIdentity(); // Vision au centre de l'ecran car la "camera" a ete possiblement deplacee
    float distanceSpectateurPlan=(GLfloat)largeur/(GLfloat)longueur;
    gluPerspective(45.0f, distanceSpectateurPlan, 0.1f, 100.0f); // definition de la projection sur le plan
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // Replacement de la camera au centre
}

/**
 * \fn void DessinFractaleGL::paintGL()
 * Fonction qui va replacer la "camera" au centre, dessiner la fractale puis dessiner les axes X et Y 
 */
void DessinFractaleGL::paintGL(){
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Effacement de l'ecran et du buffer de profondeur
    glLoadIdentity(); // Replacement de la camera au centre
    glTranslatef(camera.x, camera.y, camera.z); // Deplacement de la camera (initial)
    
	this->dessineFractale(*fractale); // dessin de la fractale
	
	// dessin des axes horizontaux et verticaux
	glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex2i(-2,0);
    glVertex2i(1,0);
    
    glColor3ub(255,0,0);
    glVertex2i(0,-1);
    glVertex2i(0,1);
    glEnd();
}

/**
 * \fn Fractale& DessinFractaleGL::getFractale()
 * Accesseur de la fractale du dessin 
 */
Fractale& DessinFractaleGL::getFractale(){
	Fractale& fr=*fractale;
	return fr;
}

/**
 * \fn double DessinFractaleGL::getXMin()
 * Accesseur xMin
 */
double DessinFractaleGL::getXMin(){
	return this->xMin;
}

/**
 * \fn double DessinFractaleGL::getXMax()
 * Accesseur xMax
 */
double DessinFractaleGL::getXMax(){
	return this->xMax;
}

/**
 * \fn double DessinFractaleGL::getYMin()
 * Accesseur yMin
 */
double DessinFractaleGL::getYMin(){
	return this->yMin;
}

/**
 * \fn double DessinFractaleGL::getYMax()
 * Accesseur yMax
 */
double DessinFractaleGL::getYMax(){
	return this->yMax;
}

/**
 * \fn double DessinFractaleGL::getGranularite()
 * Accesseur granularite
 */
double DessinFractaleGL::getGranularite(){
	return this->granularite;
}

/**
 * \fn int DessinFractaleGL::getChromatique()
 * Accesseur chromatique 
 */
int DessinFractaleGL::getChromatique(){
	return this->chromatique;
}

/**
 * \fn double DessinFractaleGL::getZoom()
 * Accesseur du zoom de la camera
 */
double DessinFractaleGL::getZoom(){
	return this->camera.z;
}

/**
 * \fn void DessinFractaleGL::setZMax(double nouveauZMax)
 * Change la valeur de zMax pour la fractale en parametre
 */
void DessinFractaleGL::setZMax(double nouveauZMax){
	this->fractale->setZMax(nouveauZMax);
	this->updateGL();
}

/**
 * \fn void DessinFractaleGL::setPartieReelle(double nouveau)
 * Modifie la partie reelle du complexe de la fractale
 */
void DessinFractaleGL::setPartieReelle(double nouveau){
	fractale->setPartieReelle(nouveau);
	this->updateGL();
}

/**
 * \fn void DessinFractaleGL::setPartieImaginaire(double nouveau)
 * Modifie la partie imaginaire du complexe de la fractale
 */
void DessinFractaleGL::setPartieImaginaire(double nouveau){
	fractale->setPartieImaginaire(nouveau);
	this->updateGL();
}

/**
 * \fn void DessinFractaleGL::dessinePixel(double x,double y,double r,double g,double b)
 * Fonction virtuelle de AbstractDessin redefinie ici pour dessiner un pixel selon OpenGL
 */
void DessinFractaleGL::dessinePixel(double x,double y,double r,double g,double b){
	glColor3f(r, g, b);
	glVertex3f(x,y,0.0f);
}

/**
 * \fn void DessinFractaleGL::dessineFractale(Fractale& f)
 * Fonction qui dessine la fractale qui est en parametre
 */
void DessinFractaleGL::dessineFractale(Fractale& f){
	double x,y;
	double test;
	double PointFractale=(double)FRACTALE/(double)ITERATIONS_MAX; // Point de la fractale
	glBegin(GL_POINTS); //demarre la serie de points
	for(x=xMin;x<xMax;x=x+(this->granularite)){
		for(y=yMin;y<yMax;y=y+(this->granularite)){ 
			test=(double)f.calculFractale(x,y)/ITERATIONS_MAX; //pour chaque point (x,y)--> calcul du nombre d'iterations
			if(test==PointFractale){ //si c'est un point de la fractale on dessine un pixel noir
				dessinePixel(x,y,0.0f,0.0f,0.0f);
			}
			else{
				if(this->chromatique!=MONOCHROMATIQUE){ //si on a active les couleurs --> en fonction du nombre d'iterations, on calcule sa couleur RGB
					// /!\ utilisation de fmod afin d'avoir le modulo de la division par 1.0 car glColor3f n'accepte que (R,G,B) avec [0;1]
					// resultats des couleurs les plus interessantes et jolies
					if(this->chromatique==COULEUR1) dessinePixel(x,y,fmod((test+test),1.0),fmod((test*test),1.0),fmod((test/test),1.0));
					else if (this->chromatique==COULEUR2) dessinePixel(x,y,fmod((test*test),1.0),fmod((test*test),1.0),fmod((test/test),1.0));
					else if (this->chromatique==COULEUR3) dessinePixel(x,y,fmod((test+test),1.0),fmod((test/test+67),1.0),fmod((test/test*160),1.0));
					else if (this->chromatique==COULEUR4) dessinePixel(x,y,fmod((test*test),1.0),fmod((test+test),1.0),fmod((test/test)*(test+test),1.0));
					else if (this->chromatique==COULEUR5) dessinePixel(x,y,fmod((test+78*test),1.0),fmod((test*test),1.0),fmod((test+50*test),1.0));
					else if (this->chromatique==COULEUR6) dessinePixel(x,y,fmod((test+12),1.0),fmod((test*test)*(test+78),1.0),fmod((test/67),1.0));
				}
			}
		}
	}
	glEnd();
}

/**
 * \fn void DessinFractaleGL::zoom()
 * Slot lorsque l'utilisateur va zoomer sur le dessin
 */
void DessinFractaleGL::zoom(){
	camera.z+=0.2;
	this->updateGL();
}

/**
 * \fn void DessinFractaleGL::dezoom()
 * Slot lorsque l'utilisateur va dezoomer sur le dessin
 */
void DessinFractaleGL::dezoom(){
	if(camera.z>-2.7) camera.z-=0.2;
	try{
		if(camera.z<-2.8) throw string("Dezoom important inutile. ");
	}
	catch(string const& erreur){
		cerr << erreur << endl;
	}
	this->updateGL();
}

/**
 * \fn void DessinFractaleGL::granul()
 * Slot lorsque l'utilisateur voudra diminuer la distance entre les pixels
 */
void DessinFractaleGL::granul(){
	if(this->granularite>0.0003){
		if(this->granularite>=0.002) this->granularite-=0.001;
		else this->granularite-=0.0001;
	}
	try{
		if(this->granularite<0.0002) throw string("Distance entre les pixels trop importante. ");
	}
	catch(string const& erreur){
		cerr << erreur << endl;
	}
	this->updateGL();
}

/**
 * \fn void DessinFractaleGL::degranul()
 * Slot lorsque l'utilisateur voudra augmenter la distance entre les pixels
 */
void DessinFractaleGL::degranul(){ 
	if(this->granularite<=0.01){
		if(this->granularite>=0.001) this->granularite+=0.001;
		else this->granularite+=0.0001;
	}
	try{
		if(this->granularite>0.02) throw string("Distance entre les pixels trop espacee (inutile). ");
	}
	catch(string const& erreur){
		cerr << erreur << endl;
	}
	this->updateGL();
}

/**
 * \fn void DessinFractaleGL::goUp()
 * Slot lorsque l'utilisateur voudra monter sur l'image
 */
void DessinFractaleGL::goUp(){
	if(this->camera.y>-1.0){
		this->camera.y-=0.2;
		this->yMax+=0.2;
		this->yMin+=0.2;
	}
	try{
		if(this->camera.y<-1.0) throw string("Deplacement vers le haut trop important (inutile). ");
	}
	catch(string const& erreur){
		cerr << erreur << endl;
	}
	this->updateGL();
}

/**
 * \fn void DessinFractaleGL::goDown()
 * Slot lorsque l'utilisateur voudra descendre sur l'image
 */
void DessinFractaleGL::goDown(){
	if(this->camera.y<1.0){
		this->camera.y+=0.2;
		this->yMax-=0.2;
		this->yMin-=0.2;
	}
	try{
		if(this->camera.y>1.0) throw string("Deplacement vers le bas trop important (inutile). ");
	}
	catch(string const& erreur){
		cerr << erreur << endl;
	}
	this->updateGL();
}

/**
 * \fn void DessinFractaleGL::goRight()
 * Slot lorsque l'utilisateur voudra aller a droite sur l'image
 */
void DessinFractaleGL::goRight(){
	if(this->camera.x>-1.1){
		this->camera.x-=0.2;
		this->xMax+=0.2;
		this->xMin+=0.2;
	}
	try{
		if(this->camera.x<=-1.3) throw string("Deplacement vers la droite trop important (inutile). ");
	}
	catch(string const& erreur){
		cerr << erreur << endl;
	}
	this->updateGL();
}

/**
 * \fn void DessinFractaleGL::goLeft()
 * Slot lorsque l'utilisateur voudra aller a gauche sur l'image
 */
void DessinFractaleGL::goLeft(){
	if(this->camera.x<2.0){
		this->camera.x+=0.2;
		this->xMax-=0.2;
		this->xMin-=0.2;
	}
	try{
		if(this->camera.x>2.1) throw string("Deplacement vers la gauche trop important (inutile). ");
	}
	catch(string const& erreur){
		cerr << erreur << endl;
	}
	this->updateGL();
}

/**
 * \fn void DessinFractaleGL::changeCouleur()
 * Slot lorsque l'utilisateur voudra voir en noir et blanc ou en couleur
 */
void DessinFractaleGL::changeCouleur(){
	if(this->chromatique==MONOCHROMATIQUE) this->chromatique=COULEUR1;
	else if(this->chromatique==COULEUR1) this->chromatique=COULEUR2;
	else if(this->chromatique==COULEUR2) this->chromatique=COULEUR3;
	else if(this->chromatique==COULEUR3) this->chromatique=COULEUR4;
	else if(this->chromatique==COULEUR4) this->chromatique=COULEUR5;
	else if(this->chromatique==COULEUR5) this->chromatique=COULEUR6;
	else if(this->chromatique==COULEUR6) this->chromatique=MONOCHROMATIQUE;
	this->updateGL();
}

/**
 * \fn DessinFractaleGL::~DessinFractaleGL()
 * Destructeur de DessinMandelbrotGL
 */
DessinFractaleGL::~DessinFractaleGL(){
	delete fractale;
}
