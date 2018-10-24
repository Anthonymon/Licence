#include "graphics.h"

int main(){
	init_graphics(900,600);
	POINT p1,p2;
	p1.x=300;p1.y=0;
	p2.x=300;p2.y=600;
	draw_line(p1,p2,blanc);
	p1.x=600;p1.y=0;
	p2.x=600;p2.y=600;
	draw_line(p1,p2,blanc);
	
	int compteurgeneral=0;
	int compteurbleu=0;
	int compteurblanc=0;
	int compteurrouge=0;
	
	POINT pUtilisateur;
	
	
	while(compteurgeneral<20){
		pUtilisateur=wait_clic();
		if(pUtilisateur.x<300){
			p1.x=0;p1.y=0;
			p2.x=300;p2.y=600;
			if(compteurbleu%2==0){
				draw_fill_rectangle(p1,p2,bleu);
			}
			else if(compteurbleu%2==1){
				draw_fill_rectangle(p1,p2,noir);
			}
			compteurbleu++;
		}
		
		else if((pUtilisateur.x>300)&&(pUtilisateur.x<600)){
			p1.x=300;p1.y=0;
			p2.x=600;p2.y=600;
			if(compteurblanc%2==0){
				draw_fill_rectangle(p1,p2,blanc);
			}
			else if(compteurblanc%2==1){
				draw_fill_rectangle(p1,p2,noir);
			}
			compteurblanc++;
		}
		
		else if((pUtilisateur.x>600)){
			p1.x=600;p1.y=0;
			p2.x=900;p2.y=600;
			if(compteurrouge%2==0){
				draw_fill_rectangle(p1,p2,rouge);
			}
			else if(compteurrouge%2==1){
				draw_fill_rectangle(p1,p2,noir);
			}
			compteurrouge++;
		}
		
		compteurgeneral++;
		
	}
	
	wait_escape();
	exit(0);
}
