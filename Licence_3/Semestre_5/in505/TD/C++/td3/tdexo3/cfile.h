#include "clist.h"

#ifndef CFILE__H
#define CFILE__H

class CFile:public CList{
	public:
		CFile();
		void setContent(int nb);
		~CFile();	
};


#endif
