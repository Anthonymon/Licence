#include <iostream>
#include <string.h>

using namespace std;

#ifndef CLIST__H
#define CLIST__H

struct element{
	int value;
	struct element* next;
};

class CList{
	protected:
		element* elt;
		string my_type;
		
	public:
		CList();
		~CList();
		CList& operator<(int i);
		virtual CList& operator>(int& i);
		int& operator[](int i);
		friend ostream& operator<<(ostream& flux, CList& l);
};

#endif
