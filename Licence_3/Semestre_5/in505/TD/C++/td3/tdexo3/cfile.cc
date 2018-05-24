#include "cfile.h"
#include <iostream>

CFile::CFile(){
	this->size=0;
	this->content=NULL;
	this->myType=__func__;
}

void CFile::setContent(int nb){ 
	if(this->size==0){ 
		struct elem* tmp=content;
		content=new struct elem;
		content->val=nb;
		content->suiv=tmp;
		size++;
	}
	else{
		struct elem* nouv=new struct elem;
		nouv->val=nb;
		nouv->suiv=NULL;
		struct elem* tmp=this->content;
		while(tmp->suiv){
			tmp=tmp->suiv;
		}
		tmp->suiv=nouv;
		size++;
	}
}

CFile::~CFile(){
	cout<<"Destructeur FILE"<<endl;
}

