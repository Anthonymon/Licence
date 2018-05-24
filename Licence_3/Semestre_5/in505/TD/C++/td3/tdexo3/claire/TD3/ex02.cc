#include <iostream>

void echange(int& arg1, int& arg2){
	int tmp=arg1;
	arg1 = arg2;
	arg2 = tmp;
	
}


int main(){
	int arg1 = 1;
	int arg2 = 42;
	std :: cout << "Avant" << std :: endl;
	std :: cout << arg1 << std :: endl;
	std :: cout << arg2 << std :: endl;
	
	echange(arg1, arg2);
	
	std :: cout << "Avant" << std :: endl;
	std :: cout << arg1 << std :: endl;
	std :: cout << arg2 << std :: endl; 
	
}
