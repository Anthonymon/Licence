#include "clist.h"
#include "cpile.h"
#include "cfile.h"
#include <iostream>

using namespace std;

CList::CList(){
	this->size=0;
	this->content=NULL;
	this->myType=__func__;
}

bool CList::testVide(){
	if(this->size==0) return true;
	else return false;
}

int CList:: getSize(){
	return this->size;
}

struct elem* CList::getContent(){
	return this->content;
}

void CList::setContent(int nb){
	struct elem* tmp=this->content;
	this->content=new struct elem;
	this->content->val=nb;
	this->content->suiv=tmp;
	size++;
}

string CList::getMyType(){
	return this->myType;
}

void CList::affiche(){
	if(this->size==0) cout<<"LISTE VIDE"<<endl;
	else{
		struct elem* tmp=this->content;
		while(tmp){
			cout<<tmp->val<<" ";
			tmp=tmp->suiv;
		}
		cout<<endl;
	}
}

CList::~CList(){
	struct elem* tmp=content;
	int i;
	for(i=0;i<size;i++){
		cout<<"Destructeur LISTE"<<endl;
		content=tmp->suiv;
		tmp->suiv=NULL;
		delete tmp;
		tmp=content;
	}
	delete content;
	delete tmp;
}

ostream& operator<<(ostream& os, CList& c){
	if(c.getSize()==0) os<<"LISTE VIDE"<<endl;
	else{
		struct elem* tmp=c.getContent();
		while(tmp){
			os<<tmp->val<<" ";
			tmp=tmp->suiv;
		}
		os<<endl;
	}
	return os;
}

int& operator>(CList& c, int& i){
		if(c.getSize()==0) return i=-1;
		else{
			struct elem* tmp=c.getContent();
			i=tmp->val;
			
			/*c.getContent()=tmp->suiv;
			tmp->suiv=NULL;
			delete tmp;*/
		}
	return i;
}

CList& operator<(CList& c, int i){
	c.setContent(i);
	return c;
}

int CList::operator[](int i){
	//struct elem* tmp=c.getContent();
	/*if(this->testVide()) return -1;
	else{
		struct elem* tmp=this->getContent();
		int n=0;
		while((tmp)&&(n<i)){
			std::cout<<"a";
			if((n+1)==i){
				std::cout<<"z";
				return tmp->val;
			}
			//std::cout<<tmp->val<<std::endl;
			tmp=tmp->suiv;
			n++;
		}
	}*/
	if((0>i)||(i>=getSize())) return -1;
	else{
		struct elem* tmp=this->getContent();
		while(i>0){
			tmp=tmp->suiv;
			i--;
		}
		return tmp->val;
	}
}
