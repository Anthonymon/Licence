#include <iostream>
#include <cstring>
using namespace std;


int main(){
	/* Question 1 */
	int tab[10];
	int* p = tab;
	
	for(int i=0; i < 10; i++){
		*(p+i) = 42;
		cout << *(p+i) << endl;
	}
	
	/* Question 2 */
	char* str1[] = {"truc", "machin", "chose"}; //tableau alloué statiquement
	char* str[3];								//tableau alloué dynamiquement
	
	str[0] = new char[strlen("truc")+1]; 
	strcpy(str[0],str1[0]); 
	str[1] = new char[strlen("machin")+1]; 
	strcpy(str[1], str1[1]); 
	str[2] = new char[strlen("chose")+1]; 
	strcpy(str[2], str1[2]);
	
	for(int i=0; i < 3; i++)
	{
		cout << str[i] << endl;
		delete[] str[i];
	}
	
	return 0;
}
