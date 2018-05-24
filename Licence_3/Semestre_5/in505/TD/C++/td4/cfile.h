#include "clist.h"
#include <string.h>

#ifndef CFILE__H
#define CFILE__H

template <class T>
class CFile :public CList <T>{
	public:
		CFile(){
			this->my_type="CFILE";
		};
		~CFile(){};
		CList<T>& operator>(T& i){
			if(this->elt==NULL){
				cout<<"File Vide"<<endl;
				exit(1);
			}
			else{
				element<T>* tmp=this->elt->next;
				if(tmp == NULL){
					i=this->elt->value;
					this->elt=NULL;
					delete tmp;
					return *this;
				}
				else{
					element<T>* aux=tmp;
					while(tmp->next!=NULL){
						aux=tmp;
						tmp=tmp->next;
					}
					i=tmp->value;
					aux->next=NULL;
					delete tmp;
					return *this;
				}
				
			}
		};
};


#endif
