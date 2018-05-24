#include "cpile.h"

/*CPile::CPile(){
	this->size=0;
	this->content=NULL;
	this->myType=__func__;
}

void CPile::setContent(int nb){
	struct elem* tmp=this->content;
	this->content=new struct elem;
	this->content->val=nb;
	this->content->suiv=tmp;
	size++;
}

CPile::~CPile(){
	cout<<"Destructeur PILE"<<endl;
}*/

CPile::CPile(){my_type="CPILE";}
CPile::~CPile(){};
CList& CPile::operator>(int& i){
	if(elt==NULL){
		cout<<"Pile Vide"<<endl;
		exit(1);
	}
	else{
		i=elt->value;
		elt=elt->next;
		return *this;
	}
}
