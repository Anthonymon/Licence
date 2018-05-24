#include "graphics.h"
int main()
{
	init_graphics(900,600);
	POINT p1;
	POINT p2;
	p1.x=300;p1.y=0;
	p2.x=300;p2.y=600;
	draw_line(p1,p2,blanc);
	p1.x=600;p1.y=0;
	p2.x=600;p2.y=600;
	draw_line(p1,p2,blanc);
	
	
	int compteurGauche;
	compteurGauche=1;
	int compteurMilieu;
	compteurMilieu=1;
	int compteurDroit;
	compteurDroit=1;
	
	POINT p3;
	p3=wait_clic();
	while((compteurGauche<=5)&&(compteurMilieu<=5)&&(compteurDroit<=5)){
		
			if(p3.x<300){
				draw_fill_circle(p3,50,bleu);
				compteurGauche=compteurGauche+1;
				}
			else if(p3.x>600){
				draw_fill_circle(p3,50,rouge);
				compteurDroit=compteurDroit+1;
				}
			else if((p3.x>300)&&(p3.x<600)){
				draw_fill_circle(p3,50,blanc);
				compteurMilieu=compteurMilieu+1;
				}
			p3=wait_clic();
		}
	
	wait_escape();
	exit(0);
}

