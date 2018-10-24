#include "graphics.h"
COULEUR T[256][256];

/*void remplir(int cR,int cV,int cB,int x,int y){
	
	int i,j;
	//for(i=0;i<256;i++){
		//for(j=0;j<256;j++){
			//T[i][j]=couleur_RGB(i,0,j);
		//}
	//}
	for(i=0;i<256;i++){
		for(){
			if((x==1)||(x==-1)){
				cR=cR+
			}
		}
	}
	
}*/

void remplir_rouge_bleu(){
	int i,j;
	for(i=0;i<256;i++){
		for(j=0;j<256;j++){
			affiche_auto_off();
			T[i][j]=couleur_RGB(i,0,j);
			
		}
		affiche_auto_on();
	}
	//affiche_auto_on();
}


void affiche_face1(POINT p1){
	int i,j;
	POINT p;
	p.x=0;p.y=0;
	
	for(i=0;i<256;i++){
		for(j=0;j<256;j++){
			affiche_auto_off();
			p.x=i+p1.x;p.y=j+p1.y;
			draw_pixel(p,T[j][i]);
			affiche_auto_on();
		}
	}
}

int main(){
	init_graphics(900,600);
	fill_screen(blanc);
	remplir_rouge_bleu();
	POINT p5;
	p5.x=256;p5.y=256;
	affiche_face1(p5);
	wait_escape();
	exit(0);
}
