using namespace std;

#include <iostream>

class Vecteur
{
	private:
		int *vect;
		int taille;
		
	public:
		Vecteur(int t);
		Vecteur(const Vecteur& v);
		~Vecteur();
		int* getVect();
		int getTaille();
		void setIndex(int val, int i);
		Vecteur& operator=(const Vecteur& v);
		int operator[](int i);
		Vecteur& operator+=(int n);
};

Vecteur::Vecteur(int t)
{
	vect = new int[t];
	int i = 0;
	while(i < t)
		vect[i++] = 0;
	taille = t;
}

Vecteur::Vecteur(const Vecteur& v)
{
	vect = new int[v.taille];
	int i = 0;
	while(i < v.taille)
		vect[i] = v.vect[i++];
	taille = v.taille;
}

Vecteur::~Vecteur()
{
	int i = 0;
	cout << "destruction du tableau :" << endl;
	while(i < taille)
		cout << vect[i++] << ' ';
	cout << endl;
	delete[] vect;
	vect = 0;
}

Vecteur& Vecteur::operator=(const Vecteur& v)
{
	if(vect)
		delete[] vect;
	int t = v.taille;
	vect = new int[t];
	
	taille = t;
	int i = 0;
	while(i < t)
		vect[i] = v.vect[i++];
	return *this;
	
}

int Vecteur::operator[](int i)
{
	if(i >= getTaille() || i < 0)
		cerr << "Erreur indice depasse la taille du tableau." << endl;
	return vect[i];
}

Vecteur& Vecteur::operator+=(const int n)
{
	int tmp[taille];
	int i;
	for(i = 0; i < taille - 1; i++)
		tmp[i] = vect[i];
	delete[] vect;
	
	taille++;
	vect = new int[taille];
	for(i = 0; i < taille - 2; i++)
		vect[i] = tmp[i];
	vect[taille - 1] = n;
	
	return *this;
}

int* Vecteur::getVect(){ return vect; }
int Vecteur::getTaille(){ return taille; }
void Vecteur::setIndex(int val, int i)
{
	if(i >= 0 && i < taille)
		vect[i] = val;
	else
		cerr << "Erreur au niveau de l'indice.\n";
}

ostream& operator<<(ostream& o, Vecteur& v)
{
	int i;
	for(i = 0; i < v.getTaille(); i++)
		o << v.getVect()[i] << ' ';
	return o;
}

istream& operator>>(istream& i, Vecteur& v)
{
	int n;
	for(n = 0; n < v.getTaille(); n++)
		i >> v.getVect()[n];
	return i;
}
	

int main()
{
	Vecteur *v1 = new Vecteur(10);
	Vecteur *v2 = new Vecteur(*v1);
	
	Vecteur& vv1 = *v1;
	Vecteur& vv2 = *v2;
	
	cout << vv1[11] << endl; //l'erreur s'affiche bien (indicage)
	cout << vv2[1] << endl; //OK
	
	vv1.setIndex(7, 0); //OK
	vv2 = vv1; //OK
	vv1 += 2; //OK
	
	cout << vv1; //OK
	cin >> vv1; //OK.il faut rentrer sur l'entree std, les vals(entiers)
	//que l'on veut affecter une a une (comme un scanf)
	
	
	delete v1;
	delete v2;
}


