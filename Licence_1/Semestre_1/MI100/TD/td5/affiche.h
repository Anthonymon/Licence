#include <stdio.h>
#include <stdlib.h>
#define aff_int(x) printf(#x" = %d\n",x) 		// Affiche un int
#define aff_long_int(x) printf(#x" = %ld\n",x) 	// Affiche un int
#define aff_float(x) printf(#x" = %f\n",x) 		// Affiche un float
#define aff_double(x) printf(#x" = %lf\n",x) 	// Affiche un float
#define aff_string(x) printf("%s",x) 			// Affiche une string (chaîne de caractère)
#define aff_string_nl(x) printf("%s\n",x) 		// Affiche une string (chaîne de caractère)
#define aff_tab_int(t,i) printf(#t"["#i"] = %d\n",t[i]); // Affiche une case d'un tableau de int
