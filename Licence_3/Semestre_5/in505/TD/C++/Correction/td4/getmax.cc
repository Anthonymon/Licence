#include "../td2/CString2.h"
#include <iostream>

using namespace std;

template<class T>

T GetMax(T& a, T& b)
{
	return (a > b) ? a : b;
}

int main(){
	int i=5, j=6, k;
	float l=10.0, m=5.0, n;
	
	k = GetMax(i, j); //retourne le plus grand entre i et j
	n = GetMax(l, m); //retourne le plus grand entre l et m
	cout << k << endl;
	cout << n << endl;
	
	//Question 2 : Oui, si la redéfinition de l'opérateur > est faite sur CString
	CString s1("toto"), s2('s'), s3;
	s3 = GetMax(s1, s2); //retourne le plus grand entre s1 et s2
	cout << s3.getString() << endl;
	
	return 0;
}
