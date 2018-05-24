#include <iostream>
#include "CString.h"
using namespace std;

int main(){
	CString s1("toto"), s2('q'), s3;
	
	cout << s1.getString() << endl;
	cout << s2.getString() << endl;
	cout << "nbrChaines = " << CString::nbr_chaines() << endl; //afficher le nombre de chaines créées
	s3 = s1.plus('w');
	cout << "s3=" << s3.getString() << endl;
	
	if(s1.plusGrandQue(s2)) //si s1 > s2 au sens alphabetique
		cout << "plus grand" << endl;
	
	if(s1.infOuEgale(s2)) //si s1 <= s2 au sens alphabetique 
		cout << "plus petit" << endl;
		
	s3 = s1.plusGrand(s2); //retourner s1 si s1 > s2, s2 sinon
	cout << "s3=" << s3.getString() << endl;
	

}
