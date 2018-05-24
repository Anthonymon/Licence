#include <iostream>
#include <cstring>
#include "CString.hpp"

using namespace std;
int CString::nbc = 0;

CString::CString(char* S)
{
	cout << "je construit" <<endl;
	chaine = new char[strlen(S)+1];
	strcpy(chaine,S);
	nbc++;
}

CString::CString(char S)
{
	cout << "je construit" <<endl;
	chaine = new char[2];
	chaine[0] = S;
	chaine[1] = '\0';
	nbc++;
}

CString::CString()
{
	cout << "je construit" <<endl;
	chaine = new char[1];
	strcpy(chaine,"");
	nbc++;
}

int CString::nbrChaines()
{
	return nbc;
}

char* CString::getString()
{
	return chaine;
}

CString CString::plus(char c)
{
	CString S;
	delete[] S.chaine;
	int nbcarac = strlen(this->getString());
	S.chaine = new char[nbcarac+2];
	strcpy(S.chaine,this->getString());
	S.chaine[nbcarac] = c;
	S.chaine[nbcarac+1] = '\0';
	return S;
}

CString& CString::operator=(const CString& s)
{
	if (this != &s) 
	{
		cout << "delete =" << this->chaine << endl;
		delete[] this->chaine;
		chaine = new char[strlen(s.chaine)+1];
		strcpy(chaine,s.chaine);
	}
	return *this;
};

int CString::taille()
{
	int i = 0;
	while(this->chaine[i] != '\0')
	{
		i++;
	}
	return i	;
}

int CString::plusGrandQue(CString& C)
{
	int i;
	char* S = C.getString();
	for(i = 0;i!=-1;i++)
	{
		if(S[i] > this->chaine[i] || this->chaine[i] == '\0')
		{
			return 0;
		}
		else if(S[i] < this->chaine[i] || S[i] == '\0')
		{
			return 1;
		}
	}
}

int CString::infOuEgale(CString& C)
{
	//~ int i;
	//~ char* S = C.getString();
	//~ for(i = 0;i!=-1;i++)
	//~ {
		//~ if(S[i] > this->chaine[i] || this->chaine[i] == '\0')
		//~ {
			//~ return 1;
		//~ }
		//~ else if(S[i] < this->chaine[i] || S[i] == '\0')
		//~ {
			//~ return 0;
		//~ }
	//~ }
	return 1-this->plusGrandQue(C);
}

CString& CString::plusGrand(CString& C)
{
	if(this->plusGrandQue(C))
	{
		return *this;
	}
	else return C;
	
}

CString::~CString()
{
	cout << "je delete" << this->getString() << endl ;
	delete[] chaine;
	//~ cout << "je delete2" << endl ;
}

