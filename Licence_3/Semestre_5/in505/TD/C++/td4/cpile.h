#include "clist.h"

#ifndef CPILE__H
#define CPILE__H

template <class T>
class CPile:public CList<T>{
	public:
		CPile(){
			this->my_type="CPILE";
		}
		~CPile(){}
		CList<T>& operator>(T& i){
			if(this->elt==NULL){
				cout<<"Pile Vide"<<endl;
				exit(1);
			}
			else{
				element<T>* tmp=this->elt;
				i=this->elt->value;
				this->elt=this->elt->next;
				delete tmp;
				return *this;
			}
		}
};

#endif
