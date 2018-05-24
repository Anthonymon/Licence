#include "clist.h"
#include "cpile.h"
#include "cfile.h"

int main(){

	CPile pile;
	CFile file;
	CList* ptList = &file;
	 * ptList < 0 < 1 < 2; //empiler deux valeurs dans la file
	 
	cout << "FILE: "<<endl;
	cout << * ptList;
	int i;
	* ptList > i;
	int j=(*ptList)[0];
	//récupérer une valeur de la file dans i
	cout << * ptList << "i=" << i << endl;
	cout<< "j="<<j<<endl;
	
	
	ptList = &pile;
	* ptList < 0 < 1 < 2; //empiler deux valeurs dans la pile
	cout<< "PILE: "<<endl;
	cout << *ptList;
	* ptList > i;
	//récupérer une valeur de la pile dans i
	cout << * ptList << "i=" << i << endl;

	return 0;
}
