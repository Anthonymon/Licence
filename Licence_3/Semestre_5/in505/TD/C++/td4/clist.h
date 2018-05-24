


#ifndef CLIST__H
#define CLIST__H

#include <iostream>
#include <string.h>


using namespace std;

template<class T>
struct element{
	T value;
	struct element* next;
};

template<class T>
class CList{
	protected:
		element<T>* elt;
		string my_type;
		
	public:
		CList(){
			elt=NULL;
			my_type="CLIST";
		};
		
		~CList(){
			if(elt!=NULL){
				while(elt->next!=NULL){
					element<T>* tmp=elt;
					elt=elt->next;
					delete tmp;
				}
				delete elt;
				elt=NULL;
			}
		};
		
		CList<T>& operator<(T i){
			element<T>* tmp=new element <T>;
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
		};
		
		virtual CList<T>& operator>(T& i){
			cout<<" i dont know how remove an elt" <<endl;
			return *this;
		};
		
		T& operator[](int i){
			element<T>* tmp=elt;
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
		};
		friend ostream& operator<<(ostream& flux, CList& l){
			flux << "Voici un liste de type " << l.my_type << " : ";
			if(l.elt==NULL) flux <<"empty list" <<endl;
			else{
				element<T>* tmp=l.elt;
				while(tmp!=NULL){
					flux<<" "<<tmp->value;
					tmp=tmp->next;
			
					}
				flux<<endl;
			}
			return flux;
		};
};

#endif
