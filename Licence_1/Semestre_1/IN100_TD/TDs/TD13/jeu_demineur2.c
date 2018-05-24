//jeu demineur clement caumes version1 21/12/15

#include "graphics.h"

int bombes_autour[400]; //tableau pour savoir combien il y a de bombes autour de la case 
int couverture_case[400]; //tableau pour savoir si la case est découverte ou non: couverte-->0;decouverte-->1;
int bombe_ou_non[400]; //tableau pour savoir si la case est une bombe ou non: pas de bombe-->0; presence de bombe-->1; 
int cases_deduites[400]; //tableau pour savoir les cases deduites: 0-->case non deduites 1-->cases deduites


int nb_cases_deduites;
int mode_du_jeu;
int etat_du_jeu;


POINT calcul_case(int i){ //trouve le point en fonction du numero du tableau
	POINT p;
	p.x=(i%20)*30+15+10;
	p.y=(i/20)*30+15+90;
	return p;
}

int calcul_valeur_tableau(POINT p){ //trouve le numero de la case en fonction du point 
	int a,b,c;
	a=0;
	b=0;
	c=0;
	if((p.x>10)&&(p.x<30)){a=0;}
	else if((p.x>30)&&(p.x<60)){a=1;}
	else if((p.x>60)&&(p.x<90)){a=2;}
	else if((p.x>90)&&(p.x<120)){a=3;}
	else if((p.x>120)&&(p.x<150)){a=4;}
	else if((p.x>150)&&(p.x<180)){a=5;}
	else if((p.x>180)&&(p.x<210)){a=6;}
	else if((p.x>210)&&(p.x<240)){a=7;}
	else if((p.x>240)&&(p.x<270)){a=8;}
	else if((p.x>270)&&(p.x<300)){a=9;}
	else if((p.x>300)&&(p.x<330)){a=10;}
	else if((p.x>330)&&(p.x<360)){a=11;}
	else if((p.x>360)&&(p.x<390)){a=12;}
	else if((p.x>390)&&(p.x<420)){a=13;}
	else if((p.x>420)&&(p.x<450)){a=14;}
	else if((p.x>450)&&(p.x<480)){a=15;}
	else if((p.x>480)&&(p.x<510)){a=16;}
	else if((p.x>510)&&(p.x<540)){a=17;}
	else if((p.x>540)&&(p.x<570)){a=18;}
	else if((p.x>570)&&(p.x<600)){a=19;}
	
	if((p.y>90)&&(p.y<120)){b=0;}
	else if((p.y>120)&&(p.y<150)){b=20;}
	else if((p.y>150)&&(p.y<180)){b=40;}
	else if((p.y>180)&&(p.y<210)){b=60;}
	else if((p.y>210)&&(p.y<240)){b=80;}
	else if((p.y>240)&&(p.y<270)){b=100;}
	else if((p.y>270)&&(p.y<300)){b=120;}
	else if((p.y>300)&&(p.y<330)){b=140;}
	else if((p.y>330)&&(p.y<360)){b=160;}
	else if((p.y>360)&&(p.y<390)){b=180;}
	else if((p.y>390)&&(p.y<420)){b=200;}
	else if((p.y>420)&&(p.y<450)){b=220;}
	else if((p.y>450)&&(p.y<480)){b=240;}
	else if((p.y>480)&&(p.y<510)){b=260;}
	else if((p.y>510)&&(p.y<540)){b=280;}
	else if((p.y>540)&&(p.y<570)){b=300;}
	else if((p.y>570)&&(p.y<600)){b=320;}
	else if((p.y>600)&&(p.y<630)){b=340;}
	else if((p.y>630)&&(p.y<660)){b=360;}
	else if((p.y>660)&&(p.y<690)){b=380;}
	
	c=a+b;
	return c;
}

void dessine_mode_decouverte(){
	POINT p1,p2;
	p1.x=135;p1.y=25;
	p2.x=175;p2.y=65;
	draw_fill_rectangle(p1,p2,gray);
}

void dessine_mode_deduction(){
	POINT p1,p2;
	p1.x=135;p1.y=25;
	p2.x=175;p2.y=65;
	draw_fill_rectangle(p1,p2,gray);
	draw_line(p1,p2,rouge);
	p1.y=65;p2.y=25;
	draw_line(p1,p2,rouge);
}

void affiche_nombre_case(int c,int compteur){ //affiche le nombre de bombes autour de la case en question
	POINT p;
	p=calcul_case(c);
	p.x=p.x-15;p.y=p.y+15;
	if(compteur==0){
		aff_pol("  ",20,p,rouge);
	}
	else if(compteur==1){
		aff_pol(" 1",20,p,bleu);
	}
	else if(compteur==2){
		aff_pol(" 2",20,p,vert);
	}
	else if(compteur==3){
		aff_pol(" 3",20,p,rouge);
	}
	else if(compteur==4){
		aff_pol(" 4",20,p,noir);
	}
	else if(compteur==5){
		aff_pol(" 5",20,p,noir);
	}
	else if(compteur==6){
		aff_pol(" 6",20,p,noir);
	}
	else if(compteur==7){
		aff_pol(" 7",20,p,noir);
	}
	else if(compteur==8){
		aff_pol(" 8",20,p,noir);
	}
}

void init_plateau(){ //met les valeurs des differentes cases dans les differents tableaux
	
	nb_cases_deduites=0;
	mode_du_jeu=1;
	etat_du_jeu=0;
	int j,k,inter,g,h;
	int compteur=0;
	int compteur1=0;
	
	for(k=0;k<400;k++){ //initialise toutes les cases à 0 (pas de bombe)
		bombe_ou_non[k]=0;
	}
	
	for(k=0;k<400;k++){ //initialise toutes les cases à 0 (pas de bombes déduites)
		cases_deduites[k]=0;
	}
	
	while(compteur<20){ //initialise au hasard 20 cases à 1 (avec une bombe) initialisation de bombe_ou_non
		
		j=alea_int(401);
		inter=bombe_ou_non[j];
		
		if(inter==0){
			bombe_ou_non[j]=1;
			compteur++;
		}
		else if(inter==1){
			bombe_ou_non[j]=1;
		}
	}
	
	for(h=0;h<400;h++){ //affiche sur les cases les differents numeros qui indiquent les bombes aux alentours
		if(bombe_ou_non[h]==0){
			if((h%20==0)&&(h!=0)&&(h!=380)){ //cas du cote gauche sauf le 0 et le 380
				if(bombe_ou_non[h-20]==1){compteur1++;}
				if(bombe_ou_non[h-19]==1){compteur1++;}
				if(bombe_ou_non[h+1]==1){compteur1++;}
				if(bombe_ou_non[h+21]==1){compteur1++;}
				if(bombe_ou_non[h+20]==1){compteur1++;}
				bombes_autour[h]=compteur1;
				//affiche_nombre_case(h,compteur1);
				compteur1=0;
			}
			else if((h%10==9)&&((h-19)%20==0)&&(h!=19)&&(h!=399)){ //cas du cote droit sauf le 19 et le 399
				if(bombe_ou_non[h-20]==1){compteur1++;}
				if(bombe_ou_non[h-21]==1){compteur1++;}
				if(bombe_ou_non[h-1]==1){compteur1++;}
				if(bombe_ou_non[h+19]==1){compteur1++;}
				if(bombe_ou_non[h+20]==1){compteur1++;}
				bombes_autour[h]=compteur1;
				//affiche_nombre_case(h,compteur1);
				compteur1=0;
			}
			else if (((h/10==0)||((h-10)/10==0))&&(h!=0)&&(h!=19)){ //cas du cote en bas sauf 0 et 19
				if(bombe_ou_non[h-1]==1){compteur1++;}
				if(bombe_ou_non[h+1]==1){compteur1++;}
				if(bombe_ou_non[h+19]==1){compteur1++;}
				if(bombe_ou_non[h+21]==1){compteur1++;}
				bombes_autour[h]=compteur1;
				//affiche_nombre_case(h,compteur1);
				compteur1=0;
			}
			else if (((h/10==38)||((h-10)/10==38))&&(h!=380)&&(h!=399)){ //cas du cote en haut sauf 380 et 399
				if(bombe_ou_non[h-20]==1){compteur1++;}
				if(bombe_ou_non[h-21]==1){compteur1++;}
				if(bombe_ou_non[h-19]==1){compteur1++;}
				if(bombe_ou_non[h-1]==1){compteur1++;}
				if(bombe_ou_non[h+1]==1){compteur1++;}
				bombes_autour[h]=compteur1;
				//affiche_nombre_case(h,compteur1);
				compteur1=0;
			}
			else if (h==0){ //cas de la case 0
				if(bombe_ou_non[1]==1){compteur1++;}
				if(bombe_ou_non[21]==1){compteur1++;}
				if(bombe_ou_non[20]==1){compteur1++;}
				bombes_autour[h]=compteur1;
				//affiche_nombre_case(h,compteur1);
				compteur1=0;
			}
			else if (h==19){ //cas de la case 19
				if(bombe_ou_non[18]==1){compteur1++;}
				if(bombe_ou_non[38]==1){compteur1++;}
				if(bombe_ou_non[39]==1){compteur1++;}
				bombes_autour[h]=compteur1;
				//affiche_nombre_case(h,compteur1);
				compteur1=0;
			}
			else if (h==380){ //cas de la case 380
				if(bombe_ou_non[360]==1){compteur1++;}
				if(bombe_ou_non[361]==1){compteur1++;}
				if(bombe_ou_non[381]==1){compteur1++;}
				bombes_autour[h]=compteur1;
				//affiche_nombre_case(h,compteur1);
				compteur1=0;
			}
			else if (h==399){ //cas de la case 399
				if(bombe_ou_non[378]==1){compteur1++;}
				if(bombe_ou_non[379]==1){compteur1++;}
				if(bombe_ou_non[398]==1){compteur1++;}
				bombes_autour[h]=compteur1;
				//affiche_nombre_case(h,compteur1);
				compteur1=0;
			}
			else {
				if(bombe_ou_non[h-20]==1){compteur1++;}
				if(bombe_ou_non[h-19]==1){compteur1++;}
				if(bombe_ou_non[h-21]==1){compteur1++;}
				if(bombe_ou_non[h-1]==1){compteur1++;}
				if(bombe_ou_non[h+1]==1){compteur1++;}
				if(bombe_ou_non[h+20]==1){compteur1++;}
				if(bombe_ou_non[h+19]==1){compteur1++;}
				if(bombe_ou_non[h+21]==1){compteur1++;}
				bombes_autour[h]=compteur1;
				//affiche_nombre_case(h,compteur1);
				compteur1=0;
			}
			
		}
	}
	
	for(g=0;g<400;g++){//initialise toutes les cases à 0 (couverte)
		couverture_case[g]=0;
	}
}


void affiche_plateau(){ //affiche le plateau
	{ //dessin du quadrillage
		POINT p1,p2;
		p1.x=10;p1.y=90;
		p2.x=610;p2.y=90;
		while(p1.y<=690){ //dessin du quadrillage horizontal
			draw_line(p1,p2,noir);
			p1.y=p1.y+30;p2.y=p1.y;
		}
		p1.x=10;p1.y=90;
		p2.x=10;p2.y=690;
		while(p1.x<=610){ //dessin du quadrillage vertical
			draw_line(p1,p2,noir);
			p1.x=p1.x+30;p2.x=p1.x;
		}
	}
	
	{ //dessin du bouton du mode et la partie numero de cases deduites
		POINT p1,p2;
		p1.x=125;p1.y=15;
		p2.x=185;p2.y=75;
		draw_fill_rectangle(p1,p2,blanc); //dessin du carre du mode
		if(mode_du_jeu==1){
			dessine_mode_decouverte();
		}
		else if(mode_du_jeu==2){
			dessine_mode_deduction();
		}
		
		p1.x=405;p1.y=15;
		p2.x=525;p2.y=75;
		draw_fill_rectangle(p1,p2,blanc); //dessin du carre avec les carres en deduction en bas de l'ecran
		p1.x=415;p1.y=25;
		p2.x=455;p2.y=65;
		draw_fill_rectangle(p1,p2,gray);
		draw_line(p1,p2,rouge);
		p1.x=415;p1.y=65;
		p2.x=455;p2.y=25;
		draw_line(p1,p2,rouge);
		p1.x=465;p1.y=70;
		aff_int(nb_cases_deduites,40,p1,noir); //ecrit le nombre de cases deduites 
	}
	
	{ //affiche chacunes des cases en fonction de leurs caracteristiques
		int i;
		POINT milieuCase;
		for(i=0;i<400;i++){
			milieuCase=calcul_case(i);
			if(couverture_case[i]==0){ //si c'est couvert
				if(cases_deduites[i]==0){ //si la case n'est pas deduite dessine un carre sombre
					POINT p3,p4;
					p3.x=milieuCase.x-14;p3.y=milieuCase.y-14;
					p4.x=milieuCase.x+14;p4.y=milieuCase.y+14;
					draw_fill_rectangle(p3,p4,gray);
				}
				if(cases_deduites[i]==1){ //si la case est deduite dessine un carre deduit
					POINT p3,p4;
					p3.x=milieuCase.x-14;p3.y=milieuCase.y-14;
					p4.x=milieuCase.x+14;p4.y=milieuCase.y+14;
					draw_fill_rectangle(p3,p4,gray);
					draw_line(p3,p4,rouge);
					p3.y=milieuCase.y+14;p4.y=milieuCase.y-14;
					draw_line(p3,p4,rouge);
				}
			}
			else if(couverture_case[i]==1){ //si cest pas couvert
				if(bombe_ou_non[i]==1){ //si cest une bombe
					POINT p1,p2;
					p1.x=milieuCase.x-14;p1.y=milieuCase.y-14;
					p2.x=milieuCase.x+14;p2.y=milieuCase.y+14;
					draw_fill_rectangle(p1,p2,argent);
					draw_fill_circle(milieuCase,10,rouge);
				}
				else if(bombe_ou_non[i]==0){
					if(bombes_autour[i]>0){
						POINT p1,p2;
						p1.x=milieuCase.x-14;p1.y=milieuCase.y-14;
						p2.x=milieuCase.x+14;p2.y=milieuCase.y+14;
						draw_fill_rectangle(p1,p2,argent);
						affiche_nombre_case(i,bombes_autour[i]);
					}
					else {
						POINT p3,p4;
						p3.x=milieuCase.x-14;p3.y=milieuCase.y-14;
						p4.x=milieuCase.x+14;p4.y=milieuCase.y+14;
						draw_fill_rectangle(p3,p4,argent);
					}
				}
			}
		}
	} //fin du bon prog
	
}

/*void jouer(){
	POINT pUtilisateur;
	pUtilisateur=wait_clic();
	//int i=calcul_valeur_tableau(pUtilisateur);
	int continu,continu2;
	continu=plateau_case(pUtilisateur);
	continu2=mode(pUtilisateur);
	int i=calcul_valeur_tableau(pUtilisateur);
	
	while((continu==-1)&&(continu2==0)){ //hors du plateau et du mode
		pUtilisateur=wait_clic();
		continu=plateau_case(pUtilisateur);
		continu2=mode(pUtilisateur);
		i=calcul_valeur_tableau(pUtilisateur);
	}
	if((continu==-1)&&(continu2==1)){ //dans le carre du mode
		if(mode_du_jeu==1){
			mode_du_jeu=2;
			dessine_mode_deduction();
		}
		else if(mode_du_jeu==2){
			mode_du_jeu=1;
			dessine_mode_decouverte();
		}
	}
	if((continu!=-1)&&(continu2==0)){ //sur le plateau
		if(mode_du_jeu==1){ //mode decouverte
			couverture_case[i]=1;
			POINT p1,p2;
			p1=calcul_case(i);
			p1.x=p1.x-14;p1.y=p1.y-14;
			p2=calcul_case(i);
			p2.x=p2.x+14;p2.y=p2.y+14;
			draw_fill_rectangle(p1,p2,argent);
			affiche_plateau();
		}
		if(mode_du_jeu==2){ //mode deduction
			POINT p1,p2;
			p1=calcul_case(i);
			if(cases_deduites[i]==0){
				POINT inter=p1;
				p1.x=p1.x-14;p1.y=p1.y-14;
				p2.x=inter.x+14;p2.y=inter.y+14;
				draw_line(p1,p2,rouge);
				p1.y=p2.y;
				p2.y=inter.y-14;
				draw_line(p1,p2,rouge); //dessine le carre deduit ////////si ya un probleme ca vient surement de la 
				nb_cases_deduites++;
				cases_deduites[i]=1;
				affiche_plateau();
			}
			if(cases_deduites[i]==1){
				POINT inter=p1;
				p1.x=p1.x-14;p1.y=p1.y-14;
				p2.x=inter.x+14;p2.y=inter.y+14;
				draw_fill_rectangle(p1,p2,gray);
				cases_deduites[i]=0;
				nb_cases_deduites--;
				affiche_plateau();
			}
			
		}
	}
}*/

int mode(POINT p){
	if((p.x>125)&&(p.x<185)&&(p.y>15)&&(p.y<75)){
		//write_int(1);
		return 1;
	}
	else {
		write_int(0);
		return 0;
	}
}

int plateau_case(POINT p){
	if((p.x>10)&&(p.x<610)&&(p.y>90)&&(p.y<690)){
		int i;
		i=calcul_valeur_tableau(p);
		write_int(i);
		return i;
	}
	else {
		write_int(-1);
		return -1;
	}
}

/*int gagner_ou_perdutest1(){
	int i;
	for(i=0;i<400;i++){
		if((couverture_case[i]==1)&&(bombe_ou_non[i]==1)){ //si il perd
			return -1;
		}
		else if((bombe_ou_non[i]==0)&&(couverture_case[i]==1)){ //si il gagne
			return 1;
		}
		else {return 0;} //si il continue normalement 
	}
	return 0; //si il continue normalement
}*/

/*int gagner_ou_perdutest2(){
	int i;
	int compteurbombe=0;
	for(i=0;i<400;i++){
		if((couverture_case[i]==1)&&(bombe_ou_non[i]==1)){ //si il perd
			return -1;
		}
		if((bombe_ou_non[i]==1)){
			if(couverture_case[i]==0){
				compteurbombe++;
			}
			else if(couverture_case[i]==1){
				compteurbombe=0;
			}
		}
	
	if(compteurbombe==20){ //si il gagne
		return 1;
		}
	}
	return 0;
}*/

int gagner_ou_perdu(){
	int i;
	int compteurbombe=0;
	for(i=0;i<400;i++){
		if((couverture_case[i]==1)&&(bombe_ou_non[i]==1)){ //si il perd
			return -1;
		}
		if((bombe_ou_non[i]==1)&&(cases_deduites[i]==1)){
			/*if(couverture_case[i]==0){
				compteurbombe++;
			}
			else if(couverture_case[i]==1){
				compteurbombe=0;
			}*/
			compteurbombe++;
		}
	}
	if(compteurbombe==20){ //si il gagne
		compteurbombe=0;
		return 1;
		}
	//}
	return 0;
}

void perdu(){
	int i;
	for(i=0;i<400;i++){
		if(bombe_ou_non[i]==1){
			couverture_case[i]=1;
			//affiche_plateau();
		}
	}
	affiche_plateau();
	POINT p;
	p.x=50;p.y=475;
	aff_pol("PERDU",150,p,rouge);
	//wait_escape();
	//exit(0);
}

void gagne(){
	POINT p;
	p.x=50;p.y=475;
	aff_pol("BRAVO",150,p,vert);
}

void jeu(){
	POINT pUtilisateur;
	int caseClic;
	int clic_dans_le_mode;
	int clic_dans_le_plateau;
	
	
	while(etat_du_jeu==0){ //pas gagne
		pUtilisateur=wait_clic();
		caseClic=calcul_valeur_tableau(pUtilisateur);
		clic_dans_le_mode=mode(pUtilisateur);
		clic_dans_le_plateau=plateau_case(pUtilisateur);
		
		if((clic_dans_le_mode==1)&&(clic_dans_le_plateau==-1)){
			if(mode_du_jeu==1){
				mode_du_jeu=2;
				write_text("clic mode");
				affiche_plateau();
			}
			else if(mode_du_jeu==2){
				mode_du_jeu=1;
				affiche_plateau();
			}
		}
		else if((clic_dans_le_mode==0)&&(clic_dans_le_plateau!=-1)){
			if(mode_du_jeu==1){
				if(couverture_case[caseClic]==0){
					couverture_case[caseClic]=1;
					affiche_plateau();
				}
			}
			else if(mode_du_jeu==2){
				int test1=0;
				//int test2=0;
				if(couverture_case[caseClic]==0){
					
					if((cases_deduites[caseClic]==0)&&(test1==0)){
						cases_deduites[caseClic]=1;
						nb_cases_deduites++;
						affiche_plateau();
						test1=1;
					}
					
					if((cases_deduites[caseClic]==1)&&(test1==0)){
						cases_deduites[caseClic]=0;
						nb_cases_deduites--;
						affiche_plateau();
					}
					test1=0;
				}
			}
		}
		etat_du_jeu=gagner_ou_perdu();
		//writeln();
		//write_int(etat_du_jeu);
	}
	if(etat_du_jeu==-1){
		perdu();
	}
	if(etat_du_jeu==1){
		gagne();
	}
	
	
}

int main(){
	
	init_graphics(620,700);
	
	fill_screen(argent);
	
	init_plateau();
	affiche_plateau();
	//jouer();
	//jouer();
	//jouer();
	//jeu();
	wait_clic();
	int i;
	for(i=0;i<400;i++){
		if(bombe_ou_non[i]==1){
			cases_deduites[i]=1;
		}
	}
	jeu();
	
	
	
	wait_escape();
	exit(0);
}
