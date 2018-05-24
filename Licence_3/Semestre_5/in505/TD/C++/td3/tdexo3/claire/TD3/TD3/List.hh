#ifndef LIST_HH
#define LIST_HH
#include <iostream>


using namespace std;

struct elem{
	int val;
	elem* next;
};

class CList{
	protected:
		int size;
		elem* content;
	
	public:
		CList();
		CList(int n);
		
		virtual void push(int n);
		friend CList& operator<(CList& c, int n);
		virtual void operator >(int& i);
		int& operator[](int i);
		friend ostream& operator<<(ostream& os, CList& l);
		void operator =(int n);
		virtual ~CList();
	};


#endif
