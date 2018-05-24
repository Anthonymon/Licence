#include "graphics.h"
int a;
 void modifie (int b)
 {
	 int a;
	 
	 b=b+10;
	 a=b*2;
 }
 
 int main()
 {
	 int b;
	 a=10;
	 b=30;
	 modifie(b);
	 modifie(a);
 }
