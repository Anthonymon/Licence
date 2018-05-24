#include "List.hh"
#include <iostream>
#include <stdlib.h>

using namespace std;

CList::CList(){
	cout << "Construct\n";
	content = NULL;
	size = 0;
}

CList::CList(int n){
	cout << "Construct\n";
	content = new elem;
	content->val = n;
	content->next = NULL;
	size = 1;
}

void CList::push(int n){
	elem* tmp = content;
	content = new elem;
	content->val = n;
	content->next = tmp;
	size++;
}


CList& operator<(CList& c, int n){
	c.push(n);
	return c;	
}

void CList::operator >(int& i){
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

int& CList::operator[](int i){
	if((i >= 0 && i < size) && (content != NULL)){
		elem* tmp = content;
		while(i > 0){
			tmp = tmp->next;
			i--;
		}
		return tmp->val;
	}
	else
		cerr << "error: i out of range or the list is null\n SHOULD ADD EXCEPTION\n";
}

void CList::operator =(int n){
	if(this != NULL)
		*this = n;
	else
		cerr << "Variable null\n";
}

ostream& operator<<(ostream& os, CList& l){
	if(l.content != NULL){
		int i;
		elem* tmp = l.content;
		for (i=1; i <= l.size; i++){
			os << tmp->val;
			tmp = tmp->next;
			if(i != l.size) os << "-";
		}
	}
	else
		os << "Liste NULL";
	os << endl;
	return os;
}

CList::~CList(){
	cout << "Destruct\n";
	elem* tmp = content;
	for(int i=1; i<=size; i++){
		
		content = tmp->next;
		delete tmp;
		tmp = content;
	}
	delete content;
	delete tmp;
}

