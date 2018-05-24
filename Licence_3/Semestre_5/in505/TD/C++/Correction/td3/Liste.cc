#include <iostream>

using namespace std;

class CNoeud
{
	private:
		int val;
		CNoeud *next;
	public:
		CNoeud(int val);
		CNoeud(const CNoeud& n);
		~CNoeud();
		int getVal() const;
		CNoeud* getNext() const;
		void setNext(CNoeud *n);
};

CNoeud::CNoeud(int v){ val = v; next = NULL; }
CNoeud::CNoeud(const CNoeud& n)
{
	val = n.getVal();
	CNoeud *ptr = n.getNext();
	if(ptr == NULL)
		next = NULL;
	
	next = new CNoeud(ptr->getVal());
	ptr = ptr->getNext();
	CNoeud *ptr2 = next;
	while(ptr != NULL)
	{
		ptr2 = new CNoeud(ptr->getVal());
		ptr = ptr->getNext();
		ptr2 = ptr2->getNext();
	}
}
CNoeud::~CNoeud(){ delete next; next = NULL; }
int CNoeud::getVal() const{ return val; }
CNoeud* CNoeud::getNext() const{ return next; }
void CNoeud::setNext(CNoeud *n){ next = n; }
		
class CList
{
	protected:
		CNoeud *tete;
	public:
		CList();
		~CList();
		CNoeud* getTete() const;
		virtual CList& operator<(int i) = 0;
		CList& operator>(int& i);
};

CList::CList(){ tete = NULL; }
CList::~CList(){ delete tete; tete = NULL; }
CNoeud* CList::getTete() const{ return tete; }

CList& CList::operator>(int& i)
{
	if(tete != NULL) {
		CNoeud *tmp = tete->getNext();
		tete->setNext(NULL);
		i = tete->getVal();
		delete tete;
		tete = tmp;
	}
	return *this;
}

ostream& operator<<(ostream& o, const CList& p)
{
	CNoeud *ptr = p.getTete();
	while(ptr != NULL )
	{
		o << ptr->getVal() << ' ';
		ptr = ptr->getNext();
	}
	o << endl;
	return o;
}

class CPile : public CList
{
	public:
		CPile();
		~CPile();
		CPile& operator<(int i);
};

CPile::CPile(){}
CPile::~CPile(){}//appel auto de celui de la classe de base
CPile& CPile::operator<(int i)
{
	CNoeud *ptr = tete;
	tete = new CNoeud(i);
	tete->setNext(ptr);
	return *this;
}

class CFile : public CList
{
	public:
		CFile();
		~CFile();
		CFile& operator<(int i);
};

CFile::CFile(){}
CFile::~CFile(){}//appel auto de celui de la classe de base
CFile& CFile::operator<(int i)
{ 
	CNoeud *tmp = new CNoeud(i);
	if(tete == NULL)
		tete = tmp;
	else
	{
		CNoeud *ptr;
		ptr = tete;
	
		while(ptr->getNext() != NULL)
			ptr = ptr->getNext();
		
		ptr->setNext(tmp);
	}
	return *this;
}
		
int main()
{
	CPile pile;
	CFile file;
	
	CList *ptlist = &file;
	*ptlist < 0 < 1;
	cout << *ptlist;
	int i;
	*ptlist > i;
	cout << *ptlist << "i=" << i << endl;
	
	 ptlist = &pile;
	 *ptlist < 0 < 1;
	cout << *ptlist;
	*ptlist > i;
	cout << *ptlist << "i=" << i << endl;
	
	return 0;
}
