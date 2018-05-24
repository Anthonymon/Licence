#include "Pile.hh"
#include <iostream>


using namespace std;

CPile::CPile(){
	cout << "Construct\n";
	content = NULL;
	size = 0;
}

CPile::CPile(int n){
	cout << "Construct\n";
	content = new elem;
	content->val = n;
	content->next = NULL;
	size = 1;
}

void CPile::operator >(int& i){
	if(content != NULL){
		i = content->val;
		elem* tmp = content;
		content = tmp->next;
		tmp->next = NULL;
		delete tmp;
		size--;
	}
	else{
		cout << "erreur, Liste NULL\n";
		i=0;
	}
}

CPile::~CPile(){
	cout << "Destruct Pile\n";
}
