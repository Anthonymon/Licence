#include "clist.h"
#include "cpile.h"
#include "cfile.h"

int main(){

	CPile<char> pile;
	CFile<char> file;
	CList<char>* ptList = &file;
	 * ptList < 'a' < 'b' < 'c'; //empiler deux valeurs dans la file
	 
	cout << "FILE: "<<endl;
	cout << * ptList;
	char i;
	* ptList > i;
	char j=(*ptList)[0];
	//récupérer une valeur de la file dans i
	cout << * ptList << "i=" << i << endl;
	//cout<< "j="<<j<<endl;
	
	
	ptList = &pile;
	* ptList < 'a' < 'b' < 'c'; //empiler deux valeurs dans la pile
	cout<< "PILE: "<<endl;
	cout << *ptList;
	* ptList > i;
	//récupérer une valeur de la pile dans i
	cout << * ptList << "i=" << i << endl;

	return 0;
}
