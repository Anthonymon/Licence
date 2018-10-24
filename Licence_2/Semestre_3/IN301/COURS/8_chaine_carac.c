#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define LEN 256
typedef char line[LEN];

void teste_args(int argc, char** argv){
  if ( argc != 3 ){
      fprintf( stderr, "Usage: %s id_in id_out\n", argv[0]);
      exit( EXIT_FAILURE );
  }
}


void remplace_id1(char* ligne, char* id_in, char* id_out){
  char* cherche;  
  if(strlen(id_in) == strlen(id_out)){
    cherche = strstr(ligne, id_in);
    if(cherche != NULL)
      memcpy(cherche, id_out, strlen(id_out));
  }
}

void remplace_id2(char* ligne, char* id_in, char* id_out){
  char* cherche;  
  if(strlen(id_in) == strlen(id_out)){
    cherche = strstr(ligne, id_in);
    if(cherche != NULL)
      if( isalnum(*(cherche-1)) == 0 && isalnum(*(cherche+strlen(id_in))) == 0 )
	memcpy(cherche, id_out, strlen(id_out));
  }
}

void remplace_id3(char* ligne, char* id_in, char* id_out){
  char* cherche;  
  line  temp;

  memcpy(temp, ligne, strlen(ligne)+1);

  cherche = strstr(ligne, id_in);
  if(cherche != NULL){
    if( isalnum(*(cherche-1)) == 0 && isalnum(*(cherche+strlen(id_in))) == 0 ){
      memcpy(temp + (cherche - ligne), id_out, strlen(id_out));
      memcpy(temp + (cherche - ligne)  + strlen(id_out), cherche + strlen(id_in), strlen( cherche + strlen(id_in) ) + 1);
    }
  }
  memcpy(ligne, temp, strlen(temp)+1);
}


void remplace_id4(char* ligne, char* id_in, char* id_out){
  char* cherche;  
  line  temp;
  int   nb = 0;
  int   l = strlen(id_out) - strlen(id_in);

  memcpy(temp, ligne, strlen(ligne)+1);

  cherche = strstr(ligne, id_in);
  while(cherche != NULL){
    if( isalnum(*(cherche-1)) == 0 && isalnum(*(cherche+strlen(id_in))) == 0 ){
      memcpy(temp + (cherche - ligne) + nb*l, id_out, strlen(id_out));
      memcpy(temp + (cherche - ligne)  + strlen(id_out) + nb*l, cherche + strlen(id_in), strlen( cherche + strlen(id_in) ) + 1);
      nb++;
    }
    cherche = strstr(cherche + strlen(id_in) , id_in);
  }
  memcpy(ligne, temp, strlen(temp)+1);
}


void affiche_ligne(char* ligne){
  int test = 0;
  int i = 0;
  while(test == 0 && i<strlen(ligne)){
    test += isalnum(ligne[i]);
    i++;
  }
  
  if(test != 0 || rand()%2 == 0 ){
    printf("%s", ligne);
  }
    
}

int main ( int argc, char** argv )
{
  line  str;
  
  teste_args(argc, argv);
  char* id_in = argv[1];
  char* id_out = argv[2];
  
  srand(time(NULL));
  
  while (fgets(str, LEN, stdin) != NULL){//lit une ligne du fichier en entrée jusqu'à la fin
    //remplace_id1(str, id_in, id_out);
    //remplace_id2(str, id_in, id_out);
    //remplace_id3(str, id_in, id_out);
    //remplace_id4(str, id_in, id_out);
    
    affiche_ligne(str);

  }
  
  return 1;
}
