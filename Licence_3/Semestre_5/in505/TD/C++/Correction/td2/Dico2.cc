#include "CString2.h"
#include <iostream>

using namespace std;
//exo similaire a Vecteur2 : liste chainee
//classe composée
class Definition
{
	private:
		CString clef;
		CString def;
		
	public:
		Definition(const char *c1, const char *c2);
		Definition(const Definition& d);
		~Definition();
		CString getClef() const;
		CString getDef() const;
		Definition& operator=(const Definition& d);
};

//Utilisation implicite des constructeurs de CString
Definition::Definition(const char *c1, const char *c2): clef(c1), def(c2){}
Definition::Definition(const Definition& d): clef(d.getClef()), def(d.getDef()){}
Definition::~Definition(){}
CString Definition::getClef() const{return clef;}
CString Definition::getDef() const{return def;}

Definition& Definition::operator=(const Definition& d)
{
	//utilise l'operateur = redefini pour CString
	clef = d.getClef();
	def = d.getDef();
}


class Noeud
{
	private:
		Definition mot;
		Noeud *nextNoeud;
		
	public:
		Noeud(Definition def);
		Noeud(const Noeud& nd);
		~Noeud();
		Definition getMot() const;
		Noeud* getNext() const;
		void setMot(Definition mot2);
		void setNext(Noeud *next);
		Noeud& operator=(const Noeud& nd);
};

Noeud::Noeud(Definition def): mot(def){ nextNoeud = NULL; }
Noeud::Noeud(const Noeud& nd): mot(nd.getMot())
{	
	Noeud *tmp2 = nd.getNext();
	if(tmp2 == NULL)
		nextNoeud = NULL;
	else
	{
		nextNoeud = new Noeud(tmp2->getMot());
		Noeud *tmp = nextNoeud;
		
		tmp2 = tmp2->getNext();
		while(tmp2 != NULL)
		{
			tmp->setNext(new Noeud(tmp2->getMot()));
			tmp = tmp->getNext();
			tmp2 = tmp2->getNext();
		}
	}
}

Noeud& Noeud::operator=(const Noeud& nd)
{
	mot = nd.getMot();
	
	if(nextNoeud != NULL)
		delete nextNoeud;
		
		
	Noeud *tmp2 = nd.getNext();
	if(tmp2 == NULL)
		nextNoeud = NULL;
	else
	{
		nextNoeud = new Noeud(tmp2->getMot());
		Noeud *tmp = nextNoeud;
		
		tmp2 = tmp2->getNext();
		while(tmp2 != NULL)
		{
			tmp->setNext(new Noeud(tmp2->getMot()));
			tmp = tmp->getNext();
			tmp2 = tmp2->getNext();
		}
	}
	return *this;
}

Noeud::~Noeud()
{
	if(nextNoeud != NULL)
	{
		delete nextNoeud;
	}
}

Definition Noeud::getMot() const{ return mot; }
Noeud* Noeud::getNext() const{ return nextNoeud; }
void Noeud::setMot(Definition mot2){ mot = mot2; } 
void Noeud::setNext(Noeud *next){ nextNoeud = next; }

//liste chainee, triee de definitions (dans l'ordre alphabetique des clefs)
class Dictionnaire
{
	private:
		Noeud *tete;
		int taille;
		
	public:
		Dictionnaire();
		Dictionnaire(const Dictionnaire& dico);
		~Dictionnaire();
		int getTaille() const;
		Noeud* getTete() const;
		Dictionnaire& operator=(const Dictionnaire& dico);
		Dictionnaire& operator+=(const Definition& def);
		bool recherche(const char *clef);
		void affiche(const char *clef);
};

Dictionnaire::Dictionnaire()
{
	taille = 0;
	tete = NULL;
}

Dictionnaire::Dictionnaire(const Dictionnaire& dico)
{
	if(dico.getTete() != NULL)
	{
		Noeud *tete_tmp = dico.getTete();
		taille = dico.getTaille();

		Noeud *ptr = new Noeud(tete_tmp->getMot());
		tete_tmp = tete_tmp->getNext();
		tete = ptr;
		while(tete_tmp != NULL)
		{
			ptr->setNext(new Noeud(tete_tmp->getMot()));
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

Dictionnaire::~Dictionnaire()
{
	if(tete != NULL)
		delete tete;
}

int Dictionnaire::getTaille() const{ return taille; }
Noeud* Dictionnaire::getTete() const{ return tete; }

Dictionnaire& Dictionnaire::operator=(const Dictionnaire& dico)
{
	if(tete != NULL)
		delete tete;

	if(dico.getTete() != NULL)
	{
		Noeud *tete_tmp = dico.getTete();
		taille = dico.getTaille();

		Noeud *ptr = new Noeud(tete_tmp->getMot());
		tete_tmp = tete_tmp->getNext();
		tete = ptr;
		while(tete_tmp != NULL)
		{
			ptr->setNext(new Noeud(tete_tmp->getMot()));
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

//ajout dans l'ordre alphabetique : n'insere pas dans l'ordre alphabetique (j'ai oublié de modif la fonction de Vecteur2)
Dictionnaire& Dictionnaire::operator+=(const Definition& def)
{
	if(tete == NULL)
		tete = new Noeud(def);
	else
	{
		Noeud *tmp = tete;
		tete = new Noeud(def);
		tete->setNext(tmp);
	}
	taille++;
}

//Parcourt le dico et retourne vrai si la def de la clef est enregistree, non sinon
bool Dictionnaire::recherche(const char *clef)
{
	CString c = clef;
	Noeud *tmp = tete;
	while(tmp != NULL && tmp->getMot().getClef() <= c) //Comparaison de CString
	{
		if(c == tmp->getMot().getClef())
			return true;
		tmp = tmp->getNext();
	}
	return false;
}

//Affiche la def de la clef
void Dictionnaire::affiche(const char *clef)
{
	if(!(recherche(clef)))
		cout << "La clef n'est pas presente dans le dictionnaire. \n";
	else //la clef est dans le dico
	{
	Noeud *tmp = tete;
	CString c = clef;
	while(c > tmp->getMot().getClef())
		tmp = tmp->getNext();
	//a la sortie du while, tmp est le noeud contenant la clef
	cout << "la definition du mot " << tmp->getMot().getClef().getString()\
	 << " est " << tmp->getMot().getDef().getString() << endl;
	}
}

int main()
{
	Dictionnaire *d1 = new Dictionnaire();
	Definition homer("Homer", "Buveur de biere");
	*d1 += homer;
	
	Dictionnaire *d2 = new Dictionnaire(*d1);
	
	cout << d1->recherche("Allo") << endl; //affiche 0, le mot n'est pas trouve
	d1->affiche("Homer"); //la definition est affichee
	
	delete d1;
	delete d2;
	return 0;
}
