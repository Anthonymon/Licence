#ifndef __PILE_HH
#define __PILE_HH
#include "List.hh"

class CPile : public CList{
	
	public:
		CPile();
		CPile(int n);
		void operator >(int& i);
		~CPile();
	
	
};

#endif

