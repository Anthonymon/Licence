#include "clist.h"
#include "cpile.h"
#include "cfile.h"
#include <iostream>

using namespace std;

/*CList::CList(){
	this->elt=NULL;
	this->my_type=__func__;
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
		}
	return i;
}

CList& operator<(CList& c, int i){
	element* tmp=new element;
	tmp->
}

int CList::operator[](int i){
	//struct elem* tmp=c.getContent();
	if((0>i)||(i>=getSize())) return -1;
	else{
		struct elem* tmp=this->getContent();
		while(i>0){
			tmp=tmp->suiv;
			i--;
		}
		return tmp->val;
	}
}*/

CList::CList(){
	elt=NULL;
	my_type="CLIST";
}

CList::~CList(){
	if(elt!=NULL){
		while(elt->next!=NULL){
			element* tmp=elt;
			elt=elt->next;
			delete tmp;
		}
		delete elt;
		elt=NULL;
	}
}

CList& CList::operator<(int i){
	element* tmp=new element;
	tmp->value=i;
	if(elt==NULL) {
		elt=tmp;
		tmp->next=NULL;
	}
	else {
		tmp->next=elt;
		elt=tmp;
	}
	return *this;
}

CList& CList::operator>(int& i){
	cout<<" i dont know how remove an elt" <<endl;
	return *this;
}

int& CList:: operator [](int i){
	element* tmp=elt;
	int j=1;
	while(tmp!=NULL && j<i){
		tmp=tmp->next;
		j++;
	}
	if(tmp==NULL){
		cout<<"index of range" <<endl;
		exit(1);
	}
	else return tmp->value;
}

ostream& operator<<(ostream& flux, CList& l){
	flux << "Voici un liste de type " << l.my_type << " : ";
	if(l.elt==NULL) flux <<"empty list" <<endl;
	else{
		element* tmp=l.elt;
		while(tmp!=NULL){
			flux<<" "<<tmp->value;
			tmp=tmp->next;
			
		}
		flux<<endl;
	}
	return flux;
}
