#include <iostream>
#include <cstring>
using namespace std;

#define TAILLE 12


void tableauEcriture(int* tab){
	int i;
	for(i=0;i<TAILLE;i++){
		tab[i]=i;
	}
}

void tableauLecture(int* tab){
	int i;
	for(i=0;i<TAILLE;i++){
		cout<<"tab["<<i<<"]="<<tab[i]<<endl;
	}
}

int main(){
	int t[TAILLE];
	tableauEcriture(t);
	tableauLecture(t);
	
}

