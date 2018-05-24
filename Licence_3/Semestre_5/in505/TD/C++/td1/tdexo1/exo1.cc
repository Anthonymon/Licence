#include <iostream>
#include <cstring>
using namespace std;

int compte_caracteres(char* str){
	int i=0;
	while(str[i]!='\0') i++;
	return i+1;
}

int main(){
	/*---------QUESTION A-----------*/
	/*int t[10];
	int i;
	for(i=0;i<10;i++){
		t[i]=12;
	}
	int* p=t;
	for(i=0;i<10;i++){
		std::cout<<*(p+i)<<std::endl;
	}*/
	/*--------------------------------*/
	
	/*---------QUESTION B-----------*/
	char* str1[]={"truc","machin","chose"};
	char* str[3];
	str[0]=new char[strlen("truc")+1];
	str[1]=new char[strlen("machin")+1];
	str[2]=new char[strlen("chose")+1];
	int j;
	for(j=0;j<3;j++){
		strcpy(str[j],str1[j]);
	}
	for(j=0;j<3;j++){
		std::cout<<str[j]<<std::endl;
	}
	for(j=0;j<3;j++){
		delete[] str[j];
	}

	/*------------------------------*/
	
}
