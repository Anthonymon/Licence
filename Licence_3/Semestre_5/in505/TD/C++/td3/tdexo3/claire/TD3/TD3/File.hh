#ifndef __FILE_HH
#define __FILE_HH
#include "List.hh"

class CFile : public CList{
	
	public:
		CFile();
		CFile(int n);
		void push(int n);
		~CFile();
	
	
};

#endif
