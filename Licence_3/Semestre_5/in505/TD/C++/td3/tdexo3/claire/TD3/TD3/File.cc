#include "File.hh"
#include <iostream>


using namespace std;

CFile::CFile(){
	cout << "Construct\n";
	content = NULL;
	size = 0;
}

CFile::CFile(int n){
	cout << "Construct\n";
	content = new elem;
	content->val = n;
	content->next = NULL;
	size = 1;
}


void CFile::push(int n){
	if(content != NULL){
		elem* tmp = content;
		elem* tmp2;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp2 = new elem;
		tmp2->val = n;
		tmp2->next = NULL;
		tmp->next = tmp2;
	}
	else{
		elem* tmp = new elem;
		tmp->val = n;
		tmp->next = NULL;
		content = tmp;
	}
	size++;	
}

 


CFile::~CFile(){	
	cout << "Destruct File\n";
}

