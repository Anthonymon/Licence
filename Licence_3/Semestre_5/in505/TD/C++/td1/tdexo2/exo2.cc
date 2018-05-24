#include <iostream>
#include <cstring>
using namespace std;

void echange(int& a,int& b){
	int temp=a;
	a=b;
	b=temp;
}

int main(){
	int a=2;
	int b=3;
	cout<<"a="<<a<<" b="<<b<<endl;
	echange(a,b);
	cout<<"a="<<a<<" b="<<b<<endl;
	
}
