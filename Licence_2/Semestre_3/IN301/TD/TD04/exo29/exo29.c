#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>

struct pixel{
	int r;
	int g;
	int b;
};
typedef struct pixel PIXEL;

struct image{
	int largeur;
	int longueur;
	int couleurMax;
	PIXEL** img;
 };
typedef struct image IMAGE;

IMAGE lire_image(FILE* f){
	IMAGE monimag;
	
	//faire la premiere ligne
	char c=fgetc(f);
	while(c!='\n'){
		c=fgetc(f);
	}
	//int larg,longu;
	fscanf(f,"%d",&monimag.largeur);
	fscanf(f,"%d",&monimag.longueur);
	fscanf(f,"%d",&monimag.couleurMax);
	monimag.img=malloc(monimag.largeur*sizeof(PIXEL**));
	for(i=0;i<monimag.largeur;i++){
		monimag.img[i]=malloc(monimag
	}
	
	int i,j;
	int rr,gg,bb;
	for(i=0;i<3*monimag.largeur;i++){
		for(j=0;j<3*monimag.longueur;i++){
			fscanf(f,"%d",&rr);
			fscanf(f,"%d",&gg);
			fscanf(f,"%d",&bb);
			monimage.img
			
		}
	 }
	
	
	
	
	return imag;
	
}

int main(){
	FILE* f=fopen("windows-sucks.ppm","r");
	if(f==NULL) exit(1);
	IMAGE im=lire_image(f);

	printf("\n%d x %d\n et %d",im.largeur,im.longueur,im.couleurMax);
	return 0;
 }
