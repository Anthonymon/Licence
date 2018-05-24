#include "CString.h"
#include <iostream>

using namespace std;

//classe composée
class Definition
{
	private:
		CString clef;
		CString def;
		
	public:
		Definition(const char *c1, const char *c2);
		~Definition();
		CString getClef();
		CString getDef();
};

//Utilisation implicite des constructeurs de CString
Definition::Definition(const char *c1, const char *c2): clef(c1), def(c2){}
Definition::~Definition(){}
CString Definition::getClef(){return clef;}
CString Definition::getDef(){return def;}

int main()
{
	Definition homer("Homer", "Buveur de biere");
	cout << "la definition du mot " << homer.getClef().getString()\
	 << " est " << homer.getDef().getString() << endl;
}
