/**
 * \file ongletChoix.hh
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient les definitions des methodes et des fonctions concernant la classe OngletChoix
 */

#ifndef ONGLETCHOIX__HH
#define ONGLETCHOIX__HH

#include "../head/ongletVide.hh"
#include "../head/fenetreJuliaFatouGL.hh"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTabWidget>
#include <QLabel>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDoubleSpinBox>

/**
 * \class OngletChoix heritee de QWidget
 * Cette classe correspond à la page de Julia et Fatou dans le menu
 * auteur: Clement Caumes
 */
class OngletChoix:public QWidget{
	Q_OBJECT
	
	private:
		int decisionConstante; /*!< Variable pour conserver la constante choisie par l'utilisateur */
		bool activation; /*!< A chaque fois que l'on clique sur valider */
		double choixReel; /*!< Variable qui stocke le choix de la partie reelle du complexe choisi */
		double choixImagi; /*!< Variable qui stocke le choix de la partie imaginaire du complexe choisi */
		FenetreJuliaFatouGL* fenetre; /*!< Fenetre qui s'ouvrira lorsque l'utilisateur clique sur valider */
		QPushButton* boutonValider2; /*!< Bouton pour valider */
		QGroupBox* choixConstante; /*!< Widget pour choisir la constante */
		QRadioButton* constante1; /*!< Widget de la constante 1 */
		QRadioButton* constante2; /*!< Widget de la constante 2 */
		QRadioButton* constante3; /*!< Widget de la constante 3 */
		QDoubleSpinBox* partieReelle; /*!< Widget pour choisir la partie reelle du complexe */
		QDoubleSpinBox* partieImaginaire; /*!< Widget pour choisir la partie imaginaire du complexe */
		QHBoxLayout* layoutComplexe; /*!< Layout pour stocker les widgets */
		QVBoxLayout* layoutConstante; /*!< Bouton pour stocker les widgets concernant la constante 3 */
		
	public slots:
		void validation(); 
		void changementConstante1();
		void changementConstante2();
		void changementConstante3();
		void choixPartieReelle(double reelle);
		void choixPartieImaginaire(double imaginaire);

	public:
		OngletChoix();
		~OngletChoix();
};

#endif

