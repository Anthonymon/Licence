#include "clist.h"

#ifndef CPILE__H
#define CPILE__H

class CPile:public CList{
	public:
		CPile();
		~CPile();
		CList& operator>(int& i);
};

#endif
