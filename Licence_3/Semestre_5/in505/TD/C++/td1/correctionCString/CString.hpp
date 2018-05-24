
#ifndef CSTRING_h
#define CSTRING_h

class CString
{
	private :
		char* chaine;
		static int nbc;
	public :
		CString(char*);
		CString(char);
		CString();
		static int nbrChaines();
		char* getString();
		CString plus(char);
		CString& operator=(const CString&);
		int taille();
		int plusGrandQue(CString&);
		int infOuEgale(CString&);
		CString& plusGrand(CString&);
		~CString();
};

#endif

