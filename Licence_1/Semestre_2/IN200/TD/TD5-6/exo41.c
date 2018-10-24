#include "graphics.h"
#define PI 3.14159
#define RAYON 180

void afficher_cadran(){
	POINT p3;
	p3.x=450;p3.y=400;
	draw_circle(p3,RAYON,blanc);
	//POINT p;
	POINT T[12];
	int i;
	for(i=0;i<12;i++){
		T[i].x=p3.x+(RAYON-15)*sinf(i*(PI/6)+(PI/6))-7;
		T[i].y=p3.y+(RAYON-15)*cosf(i*(PI/6)+(PI/6))+12;
		aff_int(i+1,12,T[i],blanc);
	}
}

void afficher_aiguille_heure(int h,int m,int s){
	POINT centre,p;
	centre.x=450;centre.y=400;
	p.x=centre.x+(RAYON/3)*sinf(h*((2*PI)/6)/*+(PI/6)+m*(PI/30)*/);
	p.y=centre.x+(RAYON/3)*cosf(h*((2*PI)/6)/*+(PI/6)+m*(PI/30)*/);
	draw_line(centre,p,blanc);
}
void afficher_aiguille_minute(int h,int m,int s){
	POINT centre,p;
	centre.x=450;centre.y=400;
	p.x=centre.x+(RAYON/2)*sinf(m*(PI/30)/*+(PI/30)*/);
	p.y=centre.y+(RAYON/2)*cosf(m*(PI/30)/*+(PI/30)*/);
	draw_line(centre,p,rouge);
}

int main(){
	init_graphics(900,600);
	POINT p1,p2;
	p1.x=0;p1.y=200;
	p2.x=900;p2.y=200;
	draw_line(p1,p2,blanc);
	afficher_cadran();
	afficher_aiguille_heure(2,0,0);
	afficher_aiguille_minute(1,30,0);

	wait_escape();
	exit(0);
}
