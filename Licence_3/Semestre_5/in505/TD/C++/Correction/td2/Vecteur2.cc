using namespace std;

#include <iostream>

class Noeud
{
	private:
		int val;
		Noeud *nextNoeud;
	
	//Il faut toujours redefinir les constructeur par copie et l'operateur =
	//pour eviter les erreurs memoire lors de la copie d'objet
	//methodes invoquees implicitement cours page 109
	public:
	Noeud(int valeur);
	Noeud(const Noeud& nd); //constructeur par copie
	~Noeud();
	int getVal() const;
	Noeud* getNext() const;
	void setVal(int valeur);
	void setNext(Noeud *next);
	Noeud& operator=(const Noeud& nd);
};

Noeud::Noeud(int valeur)
{
	val = valeur;
	nextNoeud = NULL;
}


Noeud::~Noeud()
{
	if(nextNoeud != NULL)
	{
		cout << val << ' ';
		delete nextNoeud;
	}
	else
	{
		cout << val<< " fin destruction" << endl;
	}
}

int Noeud::getVal() const{ return val; }
Noeud* Noeud::getNext() const{ return nextNoeud; }
void Noeud::setVal(int valeur){ val = valeur; }
void Noeud::setNext(Noeud *next){ nextNoeud = next; }

Noeud::Noeud(const Noeud& nd)
{
	val = nd.getVal();
	
	Noeud *tmp2 = nd.getNext();
	if(tmp2 == NULL)
		nextNoeud = NULL;
	else
	{
		nextNoeud = new Noeud(tmp2->getVal());
		Noeud *tmp = nextNoeud;
		
		tmp2 = tmp2->getNext();
		while(tmp2 != NULL)
		{
			tmp->setNext(new Noeud(tmp2->getVal()));
			tmp = tmp->getNext();
			tmp2 = tmp2->getNext();
		}
	}
}

Noeud& Noeud::operator=(const Noeud& nd)
{
	val = nd.getVal();
	
	//Pour eviter les fuites memoires, on suprime le contenu initial du noeud
	//avant la copie par affectation
	if(nextNoeud != NULL)
		delete nextNoeud;
		
		
	Noeud *tmp2 = nd.getNext();
	if(tmp2 == NULL)
		nextNoeud = NULL;
	else
	{
		nextNoeud = new Noeud(tmp2->getVal());
		Noeud *tmp = nextNoeud;
		
		tmp2 = tmp2->getNext();
		while(tmp2 != NULL)
		{
			tmp->setNext(new Noeud(tmp2->getVal()));
			tmp = tmp->getNext();
			tmp2 = tmp2->getNext();
		}
	}
	return *this;
}

//Une liste est un pointeur sur le Noeud tete de liste
class Liste
{
	private:
		Noeud *tete;
		int taille;
		
	public:
		Liste();
		Liste(const Liste& v);
		Liste(int nbreElt);
		~Liste();
		Noeud* getTete() const;
		int getTaille() const;
		Liste& operator=(const Liste& v);
		void setIndex(int val, int i);
		int operator[](int i);
		Liste& operator+=(int n);
};

Liste::Liste()
{
	tete = new Noeud(0);
	taille = 1;
}

Noeud* Liste::getTete() const{ return tete; }
int Liste::getTaille() const{ return taille; }

Liste::Liste(const Liste& l)
{
	if(l.getTete() != NULL)
	{
		Noeud *tete_tmp = l.getTete();
		taille = l.getTaille();

		Noeud *ptr = new Noeud(tete_tmp->getVal());
		tete_tmp = tete_tmp->getNext();
		tete = ptr;
		while(tete_tmp != NULL)
		{
			ptr->setNext(new Noeud(tete_tmp->getVal()));
			tete_tmp = tete_tmp->getNext();
			ptr = ptr->getNext();
		}
	}
	else
	{
		taille = 0;
		tete = NULL;
	}
}

//crée un tableau de nbreElt vals, et initialise avec des vals decroissantes
Liste::Liste(int nbreElt)
{
	taille = nbreElt;
	int i = taille;
	tete = new Noeud(i);
	Noeud *ptr = tete;
	i--;
	while(i > 0)
	{
		ptr->setNext(new Noeud(i));
		ptr = ptr->getNext();
		i--;
	}
}

Liste::~Liste()
{
	delete tete;
}

Liste& Liste::operator=(const Liste& v)
{
	if(tete != NULL)
		delete tete;

	if(v.getTete() != NULL)
	{
		Noeud *tete_tmp = v.getTete();
		taille = v.getTaille();

		Noeud *ptr = new Noeud(tete_tmp->getVal());
		tete_tmp = tete_tmp->getNext();
		tete = ptr;
		while(tete_tmp != NULL)
		{
			ptr->setNext(new Noeud(tete_tmp->getVal()));
			tete_tmp = tete_tmp->getNext();
			ptr = ptr->getNext();
		}
	}
	else
	{
		taille = 0;
		tete = NULL;
	}
	return *this;
}

void Liste::setIndex(int valeur, int i)
{
	if(i >= 0 && i < taille)
	{
		int j = 0;
		Noeud *tmp = tete;
		while(j++ < i)
			tmp = tmp->getNext();
		tmp->setVal(valeur);
	}
	else
		cerr << "Erreur au niveau de l'indice.\n";
}

int Liste::operator[](int i)
{
	if(i >= 0 && i < taille)
	{
		int j = 0;
		Noeud *tmp = tete;
		while(j++ < i)
			tmp = tmp->getNext();
		return tmp->getVal();
	}
	else
		cerr << "Erreur au niveau de l'indice.\n";
}

//ajoute n en tete de liste
Liste& Liste::operator+=(int n)
{
	if(tete == NULL)
		tete = new Noeud(n); //L'instruction se répète: on peut d'abord le créer, puis distinguer les cas
	else
	{
		Noeud *tmp = tete;
		tete = new Noeud(n);
		tete->setNext(tmp);
	}
	taille++;
	return *this;
}

ostream& operator<<(ostream& o, Liste& v)
{
	int i, tmp;
	for(i = 0; i < v.getTaille(); i++)
	{
		tmp = v[i];
		o << tmp << ' ';
	}
	return o;
}

istream& operator>>(istream& i, Liste& v)
{
	int n, tmp;
	for(n = 0; n < v.getTaille(); n++)
	{
		i >> tmp;
		v.setIndex(tmp, n);
	}
	return i;
}

int main()
{
	Liste *l1 = new Liste(7);
	Liste *l2 = new Liste(5);
	Liste *l3 = new Liste(*l2);
	
	(*l1)[8];
	cout << (*l2)[2] << endl;
	*l1 += 4;
	cout << *l1 << endl;
	cin >> *l2;
	
	delete l1;
	delete l2;
	delete l3;
	
	return 0;
}
