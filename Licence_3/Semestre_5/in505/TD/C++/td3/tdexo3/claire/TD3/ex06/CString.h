#ifndef _CString_H
#define _CString_H

class CString{
	private:
		char* _str;
		int length;
		static int nb_chaines;
	
	public:
		CString();
		CString(char* s);
		CString(char c);
		
		CString& operator=(const CString&);
		
		
		static int nbr_chaines();
		CString plus(char c);
		char* getString();
		bool plusGrandQue(CString& s);
		bool infOuEgale(CString& s);
		CString& plusGrand(CString& s);
		
		~CString();
	
};

#endif
