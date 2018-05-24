#include <iostream>
#include <typeinfo> //Question 2, utilisation de typeid
#include <cstring>

using namespace std;

template<class T>
class Pair;

template<class T>
ostream& operator<<(ostream& o, Pair<T>& pair);

template<class T>
class Pair
{
	private:
		T elt1;
		T elt2;
	public:
		Pair(T a, T b) : elt1(a), elt2(b){}
		~Pair(){} 
		T getMax(){return (elt1 > elt2) ? elt1 : elt2;}//strcmp(typeid( elt1 ),"i") strcmp(typeid( elt1 ),"f")
	friend ostream& operator<< <>(ostream& o, Pair<T>& pair);
	//symbole <> pour indiquer que l'ope redef est generique
};

template<class T>
ostream& operator<<(ostream& o, Pair<T>& pair)
{
	const char *typePair = typeid(pair.elt1).name(); // Le type d'un elt de la paire suffit
	if( strcmp("i", typePair) == 0 || strcmp("f", typePair) == 0) {
		o << pair.elt1 << " " << pair.elt2;
	}
	else {
		o << "fonction pas encore implémentée pour ce type";
	}
	return o;
}

int main(){
	int i=5, j=6;
	float l=10.0, m=5.0;
	
	Pair<int> myInts (i,j); //créer une paire d’entiers
	Pair<float> myFloats (l,m); //créer une paire de flottants
	
	cout << myInts.getMax()<< endl; //affiche le plus grand des 2 entiers
	cout << myFloats.getMax()<<endl;//affiche le plus grand des 2 flottants
	
	cout << myInts << endl;
	cout << myFloats << endl;
	
	char c1='c', c2='d';
	Pair<char> myChars(c1,c2);//creer un objet qui contient une paire d’entiers
	cout << myChars.getMax()<< endl;
	cout << myChars << endl;
	
	return 0 ;
}
