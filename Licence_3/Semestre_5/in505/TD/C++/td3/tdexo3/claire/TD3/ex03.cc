#include <iostream>

#define size 10
using namespace std;

void tableauEcriture(int* tab){
	for(int i = 0; i < size; i++)
		tab[i] = i;
}

void tableauLecture(int* tab){
	for(int i=0;i<size;i++)
		cout << tab[i] << endl;
}

int main(){
	int tab[size];
	tableauEcriture(tab);
	tableauLecture(tab);
}
