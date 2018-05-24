#ifndef CSTRING__H
#define CSTRING__H

//#define max(int a,int b) (a<b)?b:a

class CString{
	private:
		char* _myString;
		int _length;
		static int nbrChaines;
		
	public:
		CString();
		CString(char* word);
		CString(char c);
		
		CString& operator= (const CString&);
		
		CString plus(char c);
		//bool plusGrandQue(CString c1);
		bool plusGrandQue(CString& c);
		CString& plusGrand(CString& c);
		static int getNbrChaines();
		int getLength(); //longueur reelle+1
		char* getMyString();
		char getMyChar(int rang);
		void afficheMyString();
		~CString();
};

#endif
