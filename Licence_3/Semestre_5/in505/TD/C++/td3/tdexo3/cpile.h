#include "clist.h"

#ifndef CPILE__H
#define CPILE__H

class CPile:public CList{
	public:
		CPile();
		void setContent(int nb);
		~CPile();
};

#endif
