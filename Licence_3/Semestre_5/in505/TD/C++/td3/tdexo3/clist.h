#include <iostream>
#include <string.h>

using namespace std;

#ifndef CLIST__H
#define CLIST__H

struct elem{
	int val;
	struct elem* suiv;
};

class CList{
	protected:
		int size;
		struct elem* content;
		string myType;
		
	public:
		CList();
		bool testVide();
		void affiche();
		struct elem* getContent();
		int getSize();
		virtual void setContent(int nb);
		string getMyType();
		~CList();
		int operator[](int i);
};

ostream& operator<<(ostream& os, CList& c);
int& operator>(CList& c, int& i);
CList& operator<(CList& c, int i);
//int& operator[](CList& c, int i);

#endif
