#include <iostream>
using namespace std;

class CString
{
	private:
		char *chaine;
		int size;
		static int nbreChaines; //variable partagée par l"ensemble des obj de la classe
	
	public:
		CString();
		CString(const char *chaine);
		CString(const char c);
		CString(const CString& s);//constructeur par copie
		~CString();
		static int getNbrChaine(){ return CString::nbreChaines; }
		const char* getString() const;
		//le const apres la methode indique qu'on ne va pas modifier l'objet receveur
		//et sera donc compatible avec les objets const de la classe
		char getChar(int i) const;
		int getSize() const;
		CString plus(const char c);
		bool plusGrandQue(CString s);
		bool infOuEgale(CString s);
		CString plusGrand(CString s);
		CString& operator=(const CString& s);
		friend ostream& operator<<(ostream& o,const CString& s);
};

ostream& operator<<(ostream& o,const CString& s);

