#include "graphics.h"
#define PI 3.14
#define R 180
int seg[7];
int etat_affichage; //0 horloge 1 chrono


struct chrono{
	int h;
	int m;
	int s;
};
typedef struct chrono CHRONO;
CHRONO chronoJeu;

void afficher_chrono(){
	chronoJeu.h=0;chronoJeu.m=0;chronoJeu.s=0;
	while(1){
		transforme(chronoJeu.h,seg);
		afficher_dizaine_heure();
		attendre(1000);
		chronoJeu.h++;
	}
}

void afficher_cadran(){
	POINT centre,p;
	int h;
	int m;
	float alpha;
	centre.x=WIDTH/2;
	centre.y=2*HEIGHT/3;
	for(h=1;h<13;h++){
		alpha=(3-h)%12*2*PI/12;
		p.x=centre.x+R*cosf(alpha);
		p.y=centre.y+R*sinf(alpha);
		aff_int(h,10,p,blanc);
	}
	
	//calcul des graduations des heures 
	for(h=0;h<12;h++){
		alpha=(3-h)%12*2*PI/12;
		p.x=centre.x+R*8.0/10*cosf(alpha);
		p.y=centre.y+R*8.0/10*sinf(alpha);
		draw_fill_circle(p,5,blanc);
	}
	
	//calcul des graduations des minutes 
	for(m=0;m<60;m++){
		alpha=(15-m)%60*2*PI/60;
		p.x=centre.x+R*8.0/10*cosf(alpha);
		p.y=centre.y+R*8.0/10*sinf(alpha);
		draw_fill_circle(p,2,blanc);
	}
}

void afficher_aiguille_heure(int h,int m,int s){
	POINT centre,p;
	int sec;
	float alpha;
	int sec_total=12*60*60;
	sec=s+60*m+3600*h;
	centre.x=WIDTH/2;
	centre.y=2*HEIGHT/3;
	alpha=(sec_total/4-sec)%sec_total*2*PI/sec_total;
	p.x=centre.x+R*cos(alpha)/3;
	p.y=centre.y+R*sin(alpha)/3;
	draw_line(centre,p,blanc);
}

void afficher_aiguille_minute(int h,int m,int s){
	POINT centre,p;
	int sec;
	float alpha;
	int sec_total=60*60;
	sec=s+60*m;
	centre.x=WIDTH/2;
	centre.y=2*HEIGHT/3;
	alpha=(sec_total/4-sec)%sec_total*2*PI/sec_total;
	p.x=centre.x+2*R*cos(alpha)/3;
	p.y=centre.y+2*R*sin(alpha)/3;
	draw_line(centre,p,blanc);
}

void afficher_aiguille_seconde(int s){
	POINT centre,p;
	int sec=s;
	float alpha;
	int sec_total=60;
	centre.x=WIDTH/2;
	centre.y=2*HEIGHT/3;
	alpha=(sec_total/4-sec)%sec_total*2*PI/sec_total;
	p.x=centre.x+5*R*cos(alpha)/6;
	p.y=centre.y+5*R*sin(alpha)/6;
	draw_line(centre,p,rouge);
}

void afficher_analogique(int h,int m,int s){
	afficher_aiguille_heure(h,m,s);afficher_aiguille_minute(h,m,s);afficher_aiguille_seconde(s);
}

void transforme(int a,int segments[7]){
	if(a==0){
		segments[0]=segments[1]=segments[2]=segments[3]=segments[4]=segments[5]=1;
		segments[6]=0;
	}
	else if(a==1){
		segments[3]=segments[4]=1;
		segments[0]=segments[1]=segments[2]=segments[5]=segments[6]=0;
	}
	else if(a==2){
		segments[2]=segments[3]=segments[6]=segments[0]=segments[5]=1;
		segments[1]=segments[4]=0;
	}
	else if(a==3){
		segments[2]=segments[3]=segments[4]=segments[5]=segments[6]=1;
		segments[0]=segments[1]=0;
	}
	else if(a==4){
		segments[1]=segments[6]=segments[3]=segments[4]=1;
		segments[2]=segments[0]=segments[5]=0;
	}
	else if(a==5){
		segments[2]=segments[1]=segments[6]=segments[4]=segments[5]=1;
		segments[3]=segments[0]=0;
	}
	else if(a==6){
		segments[2]=segments[1]=segments[0]=segments[5]=segments[4]=segments[6]=1;
		segments[3]=0;
	}
	else if(a==7){
		segments[2]=segments[3]=segments[4]=1;
		segments[1]=segments[6]=segments[0]=segments[5]=0;
	}
	else if(a==8){
		int i;
		for(i=0;i<7;i++){
			segments[i]=1;
		}
	}
	else if(a==9){
		segments[6]=segments[1]=segments[2]=segments[3]=segments[4]=segments[5]=1;
		segments[0]=0;
	}
		
}

void afficher_segments(POINT centre,int segments[7]){
	POINT p1,p2;
	p1.x=centre.x+5;p1.y=centre.y;
	p2.x=centre.x+55;p2.y=centre.y+5;
	if(segments[5]==1){
		draw_fill_rectangle(p1,p2,rouge);
	}
	p1.x=p2.x+5;p1.y=p2.y+70;
	if(segments[4]==1){
		draw_fill_rectangle(p1,p2,rouge);
	}
	p1.x=centre.x;p1.y=centre.y+5;
	p2.x=centre.x+5;p2.y=centre.y+75;
	if(segments[0]==1){
		draw_fill_rectangle(p1,p2,rouge);
	}
	p2.x=centre.x+5;p2.y=centre.y+75; //70
	p1.x=centre.x+55;p1.y=centre.y+80; //75
	if(segments[6]==1){
		draw_fill_rectangle(p1,p2,rouge);
	}
	p2.x=centre.x+60;p2.y=centre.y+145;
	if(segments[3]==1){
		draw_fill_rectangle(p1,p2,rouge);
	}
	p1.x=centre.x;p1.y=centre.y+75;
	p2.x=centre.x+5;p2.y=centre.y+145;
	if(segments[1]==1){
		draw_fill_rectangle(p1,p2,rouge);
	}
	p1.x=centre.x+55;p1.y=p2.y+5;
	if(segments[2]==1){
		draw_fill_rectangle(p1,p2,rouge);
	}
}

void afficher_dizaine_heure(){
	POINT p;
	int segments[7];
	int h=heure()/10;
	transforme(h,segments);
	p.x=165;p.y=22;
	afficher_segments(p,segments);
}

void afficher_unite_heure(){
	POINT p;
	int segments[7];
	int h=heure()%10;
	transforme(h,segments);
	p.x=255;p.y=22;
	afficher_segments(p,segments);
}

void afficher_dizaine_minute(){
	POINT p;
	int segments[7];
	int m=minute()/10;
	transforme(m,segments);
	p.x=375;p.y=22;
	afficher_segments(p,segments);
}

void afficher_unite_minute(){
	POINT p;
	int segments[7];
	int m=minute()%10;
	transforme(m,segments);
	p.x=465;p.y=22;
	afficher_segments(p,segments);
}

void afficher_dizaine_seconde(){
	POINT p;
	int segments[7];
	int s=seconde()/10;
	transforme(s,segments);
	p.x=585;p.y=22;
	afficher_segments(p,segments);
}

void afficher_unite_seconde(){
	POINT p;
	int segments[7];
	int s=seconde()%10;
	transforme(s,segments);
	p.x=675;p.y=22;
	afficher_segments(p,segments);
}

void deux_points(){
	POINT p1,p2,p3,p4,p5,p6,p7,p8;
	p1.x=340;p1.y=80-50+17;
	p2.x=350;p2.y=90-50+17;
	p3.x=340;p3.y=160-50+17;
	p4.x=350;p4.y=170-50+17;
	p5.x=550;p5.y=80-50+17;
	p6.x=560;p6.y=90-50+17;
	p7.x=550;p7.y=160-50+17;
	p8.x=560;p8.y=170-50+17;
	int s=seconde();
	if((s%2)==0){
		draw_fill_rectangle(p1,p2,rouge);
		draw_fill_rectangle(p3,p4,rouge);
		draw_fill_rectangle(p5,p6,rouge);
		draw_fill_rectangle(p7,p8,rouge);
	}
	else if((s%2)==1){
		draw_fill_rectangle(p1,p2,noir);
		draw_fill_rectangle(p3,p4,noir);
		draw_fill_rectangle(p5,p6,noir);
		draw_fill_rectangle(p7,p8,noir);
	}
}

void affiche_digitale(int h,int m,int s){
	afficher_dizaine_heure();afficher_unite_heure();
		afficher_dizaine_minute();afficher_unite_minute();
		afficher_dizaine_seconde();afficher_unite_seconde();
		deux_points();
}

void afficher_bouton(){
	POINT p1,p2;
	p1.x=60;p1.y=75;
	p2.x=120;p2.y=135;
	draw_fill_rectangle(p1,p2,bleu);
	POINT p3;
	p3.x=63;p3.y=112;
	aff_pol("CHRONO",12,p3,blanc);
}

int main(){
	init_graphics(900,600);
	affiche_auto_off();
	etat_affichage=0;

	POINT p1,p2;
	int s,m,h;
	p1.y=p2.y=HEIGHT/3;
	p1.x=0;
	p2.x=WIDTH;
	affiche_all();

	while(etat_affichage==0){
		afficher_cadran();
		draw_line(p1,p2,blanc);
		s=seconde();m=minute();h=heure();
		afficher_analogique(h,m,s);
		affiche_digitale(h,m,s);
		affiche_all();
		fill_screen(black);
		afficher_bouton();
		
	}

	wait_escape();
	exit(0);
}
