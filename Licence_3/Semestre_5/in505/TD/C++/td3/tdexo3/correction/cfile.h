#include "clist.h"

#ifndef CFILE__H
#define CFILE__H

class CFile:public CList{
	public:
		CFile();
		~CFile();	
		CList& operator>(int& i);
};


#endif
