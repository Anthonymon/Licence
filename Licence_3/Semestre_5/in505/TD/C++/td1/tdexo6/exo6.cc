#include <iostream>
#include <cstring>
#include <cmath>
#include "cstring.h"
using namespace std;

int main()
{
	CString s1( "toto" );
	CString s2( 'q');
	CString s3;	
	s1.afficheMyString();
	s2.afficheMyString();
	cout << "nbrChaines: " << CString::getNbrChaines() << endl ;
	//afficher le nombre de chaines créées
	s3 = s2.plus( 'w' ) ;
	//s3.afficheMyString();
	cout << "s3=" << s3.getMyString() << endl ;
	//if( s1.plusGrandQue(s2) ) // si s1 > s2 au sens alphabétique
	//cout <<s1.getMyString()<< " plus grand " <<s2.getMyString()<< endl ;
	//else cout <<s1.getMyString()<< " plus petit " <<s2.getMyString()<< endl ;
	/*if( s1.infOuEgale(s2) ) // si s1 <= s2 au sens alphabétique
	cout << "plus petit" << endl ;
	s3 = s1.plusGrand( s2 ) ;// retourner s1 si s1>s2, s2 sinon*/
	//delete s1;
	//delete []s2;
}

