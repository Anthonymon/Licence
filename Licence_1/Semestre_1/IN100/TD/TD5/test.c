#include "graphics.h"
int a, b;
 void echange()
 {
	 int c;
	 write_int(a); write_text(" "); write_int(b); writeln();
	 c=a;
	 a=b;
	 b=c;
	 write_int(a); write_text(" "); write_int(b); writeln();
 }
 
 int main()
 {
	 init_graphics(600,300);
	 
	 a=10;
	 b=20;
	 write_int(a); write_text(" "); write_int(b); writeln();
	 echange();
	 write_int(a); write_text(" "); write_int(b); writeln();
	 wait_escape();
	 return 0;
 }
	 
