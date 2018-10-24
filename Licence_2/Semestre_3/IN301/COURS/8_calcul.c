#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct elem{
  int val;
  char c;
};

void test_args( int argc, char** argv ){
  if(argc != 2){
    fprintf(stderr, "Usage: %s chaine_Carac\n", argv[0]);
    exit(EXIT_FAILURE);
  }
}

void test_parenthese(char* str){
  int cmp = 0;
  while(*str && cmp >= 0){
    if(*str == '(')
      cmp++;
    if(*str == ')')
      cmp--;
    str++;
  }
  if(cmp < 0 || cmp > 0){
    fprintf(stderr, "Erreur parentesage\n");
    exit(EXIT_FAILURE);
  }
}

void initTab(struct elem* tab, int n){
  int i;
  for(i=0; i<n; i++){
    tab[i].val = 0;
    tab[i].c = '\0';
  }
}

int calculeNombre(char** str){
  int j = 0;
  char tab[10];
  while(isdigit((*str)[j])){
    tab[j] = (*str)[j];
    j++;
  }
  tab[j] = '\0';
  *str += j;
  return atoi(tab);
}

void remplitTab(struct elem* tab, char* str){
  int i = 0;
  while(*str){
    if(!isdigit(*str)){
      tab[i].c = *str;
      str++;
    }
    else{
      tab[i].val = calculeNombre(&str);
      tab[i].c = 'n';
    }
    i++;
  }
}

void afficheTab(struct elem* tab){
  int i=0;
  while(tab[i].c){
    if(tab[i].c == 'n')
      printf("%d\n", tab[i].val);
    else
      printf("%c\n", tab[i].c);
    i++;
  }
}

int tailleTab(struct elem* tab){
  int i=0;
  while(tab[i].c)
    i++;
  return i;
}

int oper(int a, int b, char c){
  switch(c){
  case '+': return a+b;
  case '-': return a-b;
  case '*': return a*b;
  case '/': return a/b;
  case '%': return a%b;
  default: return 0;
  }
}

int calcule(struct elem* tab, int g, int d){
  int cmp;
  int iG, iD, i;
  int valG ,valD;
  char op;
  if(g == d) return tab[g].val;
  if(tab[g].c == 'n'){
    valG = tab[g].val;
    op = tab[g+1].c;
  }
  else{
    iG = g+1;
    if(tab[iG].c == 'n')
      iD = iG;
    else{
      cmp = 1;
      i = iG+1;
      while(cmp > 0){
	if(tab[i].c == '(')
	  cmp++;
	if(tab[i].c == ')')
	  cmp--;
	i++;
      }
      iD = i-1;
    }
    op = tab[iD+1].c;
    valG = calcule(tab, iG, iD);
  }
  
  if(tab[d].c == 'n')
    valD = tab[d].val;
  else{
    iD = d-1;
    if(tab[iD].c == 'n')
      iG = iD;
    else{
      cmp = 1;
      i = iD-1;
      while(cmp > 0){
	if(tab[i].c == ')')
	  cmp++;
	if(tab[i].c == '(')
	  cmp--;
	i--;
      }
      iG = i+1;
    }
    valD = calcule(tab, iG, iD);
  }
  return oper(valG, valD, op);
}


int main ( int argc, char** argv ){
  char*  str;
  struct elem* tab;
  int n;

  test_args(argc, argv);
  str = argv[1];
  test_parenthese(str);

  n = strlen(str);
  tab = malloc(n*sizeof(struct elem));
  initTab(tab, n);
  remplitTab(tab, str);
  afficheTab(tab);
  
  n = tailleTab(tab);
  printf("***\nL'expression vaut: %d\n***\n", calcule(tab, 0, n-1));
  


  free(tab);
  return 1;
}
