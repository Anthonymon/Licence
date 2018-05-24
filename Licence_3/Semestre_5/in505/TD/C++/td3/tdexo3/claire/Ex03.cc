#include <iostream>
#include "List.hh"
#include "File.hh"
#include "Pile.hh"

using namespace std;

int main(){
	CPile pile;
	CFile file;
	
	CList* ptList = &file;
	*ptList < 0 < 1 < 2; // empiler deux valeur dans la file
	cout << "FILE\n" << *ptList;
	int i;
	file[7] = 33;
	cout << "FILE\n" << *ptList;
	*ptList > i; // recuperer une valeur de la file dans i
	cout << *ptList << "i= " << i << endl;
	 
	ptList = &pile;
	*ptList < 0 < 1 < 2; //empiler deux valeurs dans la pile
	cout << "PILE\n" << *ptList;
	*ptList > i;
	cout << *ptList << "i= " << i << endl;
	
	
}
