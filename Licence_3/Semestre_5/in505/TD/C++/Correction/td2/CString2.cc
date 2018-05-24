using namespace std;

#include <iostream>
#include <string.h>

class CString
{
	private:
		char *chaine;
		int size;
		static int nbreChaines;
	
	public:
		CString();
		CString(const char *chaine);
		CString(const char c);
		CString(const CString& s);
		~CString();
		static int getNbrChaine(){ return CString::nbreChaines; }
		const char* getString() const;
		char getChar(int i) const;
		int getSize() const;
		CString& operator=(const CString& s);
		bool operator>(CString mot);
		bool operator<=(CString mot);
		CString& operator+(char c);
		bool operator==(const CString& c);
		CString plusGrand(CString s);
};

int CString::nbreChaines;

CString::CString()
{
	size = 0;
	chaine = new char[1];
	chaine[0] = '\0';
	nbreChaines++;
}

CString::CString(const char *str)
{
	size = strlen(str);
	chaine = new char[size + 1];
	strcpy(chaine, str);
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
	delete[] chaine;
	nbreChaines--;
}

CString& CString::operator+(const char c)
{
	char *s2 = new char[2];
	s2[0] = c;
	s2[1] = '\0';
	
	char *str = new char[size + 1];
	strcpy(str, chaine);
	delete[] chaine;
	chaine = new char[size + 2];
	strcpy(chaine, str);
	delete[] str;
	
	strcat(chaine, s2);
	size++;
	
	delete[] s2;
	return *this;
}

bool CString::operator>(CString s)
{ 
	return strcmp(chaine, s.getString()) > 0;
}

bool CString::operator<=(CString s)
{	
	//*this designe l'objet courant (CString) / this est un pointeur sur cet objet (CString*)
	return !(*this > s);//utilise l'operateur defini au-dessus
}

CString CString::plusGrand(CString s)
{
	if(*this > s)
		return *this;
	return s; //else
}

CString& CString::operator=(const CString& s)
{
	delete[] chaine;
	chaine = new char[s.getSize() + 1];
	
	size = s.getSize();
	strcpy(chaine, s.getString());
		
	return *this;
}

bool CString::operator==(const CString& c){ return strcmp(getString(), c.getString()) == 0;}

//~ int main()
//~ {
	//~ CString s1("toto"), s2('q'), s3;
//~ 
	//~ cout << "nbreChaines = " << CString::getNbrChaine() << endl;
	//~ 
	//~ s3 = s1 + 'w';
	//~ cout << "s3 = " << s3.getString() << endl;
	//~ 
	//~ if(s1 >s2)
		//~ cout << s1.getString() << " plus grand que " << s2.getString() << endl;
		//~ 
	//~ if(s1 <= s2)
		//~ cout << s1.getString() << " plus petit que " << s2.getString() << endl;
	//~ 
	//~ s3 = s1.plusGrand(s2);
	//~ cout << "s3 = " << s3.getString() << endl;
	//~ 
	//~ return 0;
//~ }
