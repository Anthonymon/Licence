#include <iostream>
#include "CString.h"
using namespace std;

#include <cstring>

int CString::nb_chaines = 0;

CString::CString(){
	this->_str = new char[1];
	this->_str[0] = '\0';
	this->length = 0;
	CString::nb_chaines++;
	
}

CString::CString(char* s){
	this->length = strlen(s);
	this->_str = new char[this->length+1];
	strcpy(this->_str, s);

	CString::nb_chaines++;
}

CString::CString(char c){
	this->length = 1;
	this->_str = new char[this->length + 1];
	this->_str[0] = c;
	this->_str[1] = '\0';
	CString::nb_chaines++;
	}
	
CString& CString::operator=(const CString& s){
	if(this != &s){
		delete[] this->_str;
		_str = new char[s.length+1];
		strcpy(_str, s._str);
	}
	return *this;
	
}

char* CString::getString(){
	return this->_str;
}

int CString::nbr_chaines(){ return CString::nb_chaines; }

CString CString::plus(char c){
	CString* res = new CString(this->_str);
	char* tmp = new char[2];
	tmp[0] = c;
	tmp[1] = '\0';
	strcat(res->_str, tmp);
	res->length++;
	return *res;
	
}

bool CString::plusGrandQue(CString& s){
	int i;
	char* S = s.getString();
	
	for(i = 0; i != -1; i++){
		if(S[i] > this->_str[i] || this->_str == '\0') return 0;
		else if(S[i] < this->_str[i] || S[i] == '\0') return 1;
	}
}




bool CString::infOuEgale(CString& s){
	if(this->plusGrandQue(s)) return 0;
	return 1;
}

CString& CString::plusGrand(CString& s){
	if(this->plusGrandQue(s)) return *this;
	return s;
}

CString::~CString(){ 
	cout << "Appel du destructeur\n";
	delete[] this->_str;
	CString::nb_chaines--; 
}
