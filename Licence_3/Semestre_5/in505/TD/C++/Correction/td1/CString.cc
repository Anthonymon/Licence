using namespace std;

#include "CString.h"
#include <string.h>

int CString::nbreChaines; //init a 0 implicitement

CString::CString()
{
	size = 0;
	chaine = new char[1];
	chaine[0] = '\0';
	nbreChaines++; //on incrémente la variable statique (on crée un objet en plus)
}

CString::CString(const char *str)
{
	size = strlen(str);
	chaine = new char[size + 1]; //+1 pour le char de fin de chaine
	strcpy(chaine, str); //recopie automatiquement le char de fin de chaine
	nbreChaines++;
}

CString::CString(const char c)
{
	size = 1;
	chaine = new char[2];
	chaine[0] = c;
	chaine[1] = '\0';
	nbreChaines++;
}

CString::CString(const CString& s)
{
	size = s.getSize();
	chaine = new char[size + 1];
	strcpy(chaine, s.getString());
	nbreChaines++;
}

const char* CString::getString() const{ return chaine; }
int CString::getSize() const{ return size; }
char CString::getChar(int i) const{ return chaine[i]; }

CString::~CString()
{
	//cout << "destruction de la chaine " << chaine << endl;
	delete[] chaine; //on détruit la chaine qu'on a alloue dynamiquement dans le constructeur
	nbreChaines--;
}

//ajoute le caractere c a la fin de la chaine de l'objet
CString CString::plus(const char c)
{
	//creation d'une chaine pour utiliser la fonction de la librairie
	char *s2 = new char[2];
	s2[0] = c;
	s2[1] = '\0';
	
	//chaine a la memoire allouee pour tout juste sa chaine
	//il faut allouer une case en plus pour que strcat marche
	char *str = new char[size + 1];
	strcpy(str, chaine);
	delete[] chaine;
	chaine = new char[size + 2];
	strcpy(chaine, str);
	delete[] str;
	
	strcat(chaine, s2); //ajoute s2 a la fin de chaine
	size++; //on augmente la taille de 1
	
	delete[] s2; //libere la memoire allouee dynamiquement
	return *this;
}

//comparaison de l'ordre alphabetique, pas la taille
bool CString::plusGrandQue(CString s)
{ 
	return strcmp(chaine, s.getString()) > 0;
}

bool CString::infOuEgale(CString s)
{	
	return !(plusGrandQue(s)); // <= est la negation de >
}

CString CString::plusGrand(CString s)
{
	if(plusGrandQue(s)) //*this > s
		return *this;
	return s; //else
}

//copie la chaine de s dans l'objet receveur, ainsi que a taille
CString& CString::operator=(const CString& s)
{
	delete[] chaine; //supprime l'espace allouee pour la chaine existante
	chaine = new char[s.getSize() + 1];
	//allocation dynamique pour faire une copie complete, pas juste les adresses
	//evite les bugs a la destrction des objets, (tenterait de delete deux fois la meme chaine sinon)
	
	size = s.getSize();
	strcpy(chaine, s.getString());
		
	return *this;
}

ostream& operator<<(ostream& o,const CString& s)
{
	const char *str =  s.getString();
	o << str;
	
	return o;
}
//~ int main()
//~ {
	//~ CString s1("toto"), s2('q'), s3;
	//~ 
	//~ //accession a la methode statique
	//~ cout << "nbreChaines = " << CString::getNbrChaine() << endl;
	//~ 
	//~ s3 = s1.plus('w');
	//~ cout << "s3 = " << s3.getString() << endl;
	//~ 
	//~ if(s1.plusGrandQue(s2))
		//~ cout << s1.getString() << " plus grand que " << s2.getString() << endl;
		//~ 
	//~ if(s1.infOuEgale(s2))
		//~ cout << s1.getString() << " plus petit que " << s2.getString() << endl;
	//~ 
	//~ s3 = s1.plusGrand(s2);
	//~ cout << "s3 = " << s3.getString() << endl;
	//~ 
	//~ //Le destructeur est appelé plus de fois que précisé dans le main :
	//~ //cela est dû à la copie d'objets (voir diapo page 109 c++), 
	//~ //le constructeur par copie est appele automatiquement pour le "return" d'un objet CString
	//~ //et donc les appels du destructeur pour ces copies créées, les methodes plus et plusGrand en ont besoin
	//~ 
	//~ //De plus l'operateur d'affectation doit etre redefini pour les lignes 141 et 150, ainsi que
	//~ //pour les methodes qui necessitent un CString en parametre (utilisation implicite de l'operateur
	//~ // pour la copie des param)
	//~ return 0;
//~ }
