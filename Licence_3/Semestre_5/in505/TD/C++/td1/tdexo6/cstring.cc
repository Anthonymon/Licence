#include <iostream>
#include <cstring>
#include <cmath>
#include "cstring.h"
using namespace std;

int CString::nbrChaines=0;

CString::CString(){
	this->_myString=new char[1];
	this->_myString[0]='\0';
	this->_length=1;
	CString::nbrChaines+=1;
}
		
CString::CString(char* word){
	CString::nbrChaines+=1;
	int j,i=0;
	char c;
	do{
		c=word[i];
		i++;
	}while(c!='\0');
	this->_length=i;
	this->_myString=new char[_length];
			
	strcpy(_myString,word);
}
		
CString::CString(char c){
	this->_length=2;
	this->_myString=new char[2];
	this->_myString[0]=c;
	this->_myString[1]='\0';
	CString::nbrChaines+=1;
}

CString& CString:: operator =(const CString& s){
	if(this!=&s){
		delete[] this->_myString;
		_myString=new char[s._length+1];
		strcpy(_myString,s._myString);
	}
	return *this;
}
		
CString CString::plus(char c){
	/*CString str;
	if(this->_length==1){
		
		str=CString(c);
	}
	else {
		str._myString=new char[this->getLength()+2];
		str._length=this->getLength()+2;
		int i;
		for(i=0;i<this->getLength()-1;i++){
			str._myString[i]=this->_myString[i];
		}
		i++;
		str._myString[i]=c;
		i++;
		str._myString[i]='\0';
	}
	return str;*/
	CString* tmp= new CString(this->_myString);
	char* tmp2=new char[2];
	tmp2[0]=c;
	tmp2[1]='\0';
	strcat(tmp->_myString,tmp2);
	//res->_length+=2;
	return *tmp;
}

/*bool CString::plusGrandQue(CString c1){
	int min,i;
	if(this->getLength()==1){
		if(c1.getLength()==1) return false;
		else return true;
	}
	if(c1.getLength()==1) return false;
	if(c1.getLength()<(this->getLength())) min=c1.getLength();
	else min=this->getLength();
	for(i=0;i<min;i++){
		if((this->getMyChar(i))<c1.getMyChar(i)) return false;
		//else cout<<this->getMyChar(i)<<">="<<endl;
	}
	return true;
}*/

bool CString::plusGrandQue(CString& c){
	int i;
	char* s=c.getMyString();
	for(i=0;i!=-1;i++){
		if(s[i]>this->_myString[i] || this->_myString=="\0") return false;
		else if(s[i]<this->_myString[i]||s[i]=='\0') return true;
	}
}

CString& CString::plusGrand(CString& c){
	if(this->plusGrandQue(c)){
		return* this;
	}
	return c;
}
		
char CString::getMyChar(int rang){
	char c;
	if(rang>(this->getLength()-1)) c=-1;
	else{
		c=this->_myString[rang];
	}
	return c;
}
		
char* CString::getMyString(){
	return this->_myString;
}
int CString::getLength(){
	return this->_length;
}
void CString::afficheMyString(){
	//if(this->getLength()!=0){
		int i;
		for(i=0;i<(this->getLength());i++){
			cout<<this->getMyString()[i];
		}
		cout<<endl;
	//}
}
int CString::getNbrChaines(){
	return CString::nbrChaines;
}
CString::~CString(){
	cout<<"Appel au destructeur"<<endl;
	delete[] this->_myString;
	this->nbrChaines--;

}

