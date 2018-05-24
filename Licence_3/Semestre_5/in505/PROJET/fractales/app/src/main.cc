/**
 * \file main.cc 
 * \author {Clement Caumes Doudouh Yassin}
 * \date 9 janvier 2018
 * \brief contient la fonction principale main
 */

#include <QApplication>
#include "../head/menu.hh"

/**
 * \fn main fonction principale du programme qui declenche le menu principal
 */
int main(int argc, char** argv){
	QApplication app(argc, argv);
    Menu m;
    m.show();
	return app.exec();
}
