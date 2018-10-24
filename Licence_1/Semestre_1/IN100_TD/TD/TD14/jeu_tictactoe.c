//jeu tictactoe clement caumes 30/12/15 v1
#include "graphics.h"

int jouable[9]; //0-->non jouable; 1-->jouable
int nature[9]; //0-->rien; 1-->humain; 2-->ordi
int etat_du_jeu;//0-->rien;1-->humain gagne;2-->ordi gagne
int nb_coups; //indique le nombre de coups

void dessine_humain(POINT p){ //dessine un rond bleu sur la case choisi par lutilisateur
	draw_circle(p,90,bleu);
	draw_circle(p,89,bleu);
	draw_circle(p,88,bleu);
}

void dessine_ordi(POINT p){ //dessine un carre rouge sur la case choisi par lordi
	POINT p1,p2;
	p1.x=p.x+90;p1.y=p.y+90;
	p2.x=p.x-90;p2.y=p.y-90;
	draw_line(p1,p2,rouge);
	p1.x=p1.x-1;p2.x=p2.x-1;
	draw_line(p1,p2,rouge);
	p1.x=p1.x+2;p2.x=p2.x+2;
	draw_line(p1,p2,rouge);
	p1.x=p.x-90;p1.y=p.y+90;
	p2.x=p.x+90;p2.y=p.y-90;
	draw_line(p1,p2,rouge);
	p1.x=p1.x-1;p2.x=p2.x-1;
	draw_line(p1,p2,rouge);
	p1.x=p1.x+2;p2.x=p2.x+2;
	draw_line(p1,p2,rouge);
}

POINT calcul_centre(POINT p){ //calcul le centre de la case en fonction du clic
	if(p.x<200){
		p.x=100;
	}
	else if((p.x>200)&&(p.x<400)){
		p.x=300;
	}
	else if(p.x>400){
		p.x=500;
	}
	
	if(p.y<200){
		p.y=100;
	}
	else if((p.y>200)&&(p.y<400)){
		p.y=300;
	}
	else if(p.y>400){
		p.y=500;
	}
	return p;
}

POINT calcul_centre2(int i){ //calcul le centre de la case en fonction du numero de cette case
	POINT p;
	p.x=0;p.y=0;
	if(i==0){p.x=100;p.y=100;return p;}
	else if(i==1){p.x=300;p.y=100;return p;}
	else if(i==2){p.x=500;p.y=100;return p;}
	else if(i==3){p.x=100;p.y=300;return p;}
	else if(i==4){p.x=300;p.y=300;return p;}
	else if(i==5){p.x=500;p.y=300;return p;}
	else if(i==6){p.x=100;p.y=500;return p;}
	else if(i==7){p.x=300;p.y=500;return p;}
	else if(i==8){p.x=500;p.y=500;return p;}
	else {return p;}
}

int calcul_numero_case(POINT p){ //calcul le numero de la case en fonction du clic
	int numero_case;
	numero_case=0;
	if((p.x<200)&&(p.y<200)){numero_case=0;}
	else if((p.x>200)&&(p.x<400)&&(p.y<200)){numero_case=1;}
	else if((p.x>400)&&(p.y<200)){numero_case=2;}
	else if((p.x<200)&&(p.y>200)&&(p.y<400)){numero_case=3;}
	else if((p.x>200)&&(p.x<400)&&(p.y>200)&&(p.y<400)){numero_case=4;}
	else if((p.x>400)&&(p.y>200)&&(p.y<400)){numero_case=5;}
	else if((p.x<200)&&(p.y>400)){numero_case=6;}
	else if((p.x>200)&&(p.x<400)&&(p.y>400)){numero_case=7;}
	else if((p.x>400)&&(p.y>400)){numero_case=8;}
	return numero_case;
}

void init_jeu(){ //met les valeurs dans les differentes cases lors du debut du jeu
	fill_screen(blanc);
	etat_du_jeu=0;
	nb_coups=0;
	{//dessine les traits pour le jeu
		POINT p1,p2;
		p1.x=200;p1.y=0;
		p2.x=200;p2.y=600;
		draw_line(p1,p2,noir);
		p1.x=400;p2.x=400;
		draw_line(p1,p2,noir);
		p1.x=0;p1.y=200;
		p2.x=600;p2.y=200;
		draw_line(p1,p2,noir);
		p1.y=400;p2.y=400;
		draw_line(p1,p2,noir);
	}
	{//initialise toutes les cases a partir des tableaux
		int i;
		for(i=0;i<9;i++){
			jouable[i]=1;
			nature[i]=0;
		}
	}
}

void affiche_jeu(){ //affiche le jeu en fonction des valeurs que prend les cases
	//fill_screen(blanc);
	int i;
	POINT centre;
	for(i=0;i<9;i++){
		if(i==0){centre.x=100;centre.y=100;}
		else if(i==1){centre.x=300;centre.y=100;}
		else if(i==2){centre.x=500;centre.y=100;}
		else if(i==3){centre.x=100;centre.y=300;}
		else if(i==4){centre.x=300;centre.y=300;}
		else if(i==5){centre.x=500;centre.y=300;}
		else if(i==6){centre.x=100;centre.y=500;}
		else if(i==7){centre.x=300;centre.y=500;}
		else if(i==8){centre.x=500;centre.y=500;}
		
		if(jouable[i]==1){
			if(nature[i]==1){
				dessine_humain(centre);
				jouable[i]=0;
				nature[i]=1;
			}
			if(nature[i]==2){
				dessine_ordi(centre);
				jouable[i]=0;
				nature[i]=2;
			}
		}
	}
}

int gagne_ou_perdu(){ //retourne 0-->rien;retourne 1-->joueur gagne;retourn 2-->ordi gagne
	int test=0;
	POINT p1,p2;
	if((nature[0]==1)&&(nature[1]==1)&&(nature[2]==1)){ //si le joueur gagne sur la premiere ligne
		p1=calcul_centre2(0);p1.x=p1.x-50;
		p2=calcul_centre2(2);p2.x=p2.x+50;
		draw_line(p1,p2,bleu);
		p1.y=p1.y-1;p2.y=p2.y-1;
		draw_line(p1,p2,bleu);
		p1.y=p1.y+2;p2.y=p2.y+2;
		draw_line(p1,p2,bleu);
		test=1;
		return test;
	}
	if((nature[0]==2)&&(nature[1]==2)&&(nature[2]==2)){ //si lordi gagne sur la premiere ligne
		p1=calcul_centre2(0);p1.x=p1.x-50;
		p2=calcul_centre2(2);p2.x=p2.x+50;
		draw_line(p1,p2,rouge);
		p1.y=p1.y-1;p2.y=p2.y-1;
		draw_line(p1,p2,rouge);
		p1.y=p1.y+2;p2.y=p2.y+2;
		draw_line(p1,p2,rouge);
		test=2;
		return test;
	}
	if((nature[3]==1)&&(nature[4]==1)&&(nature[5]==1)){ //si le joueur gagne sur la deuxieme ligne
		p1=calcul_centre2(3);p1.x=p1.x-50;
		p2=calcul_centre2(5);p2.x=p2.x+50;
		draw_line(p1,p2,bleu);
		p1.y=p1.y-1;p2.y=p2.y-1;
		draw_line(p1,p2,bleu);
		p1.y=p1.y+2;p2.y=p2.y+2;
		draw_line(p1,p2,bleu);
		test=1;
		return test;
	}
	if((nature[3]==2)&&(nature[4]==2)&&(nature[5]==2)){ //si lordi gagne sur la deuxieme ligne 
		p1=calcul_centre2(3);p1.x=p1.x-50;
		p2=calcul_centre2(5);p2.x=p2.x+50;
		draw_line(p1,p2,rouge);
		p1.y=p1.y-1;p2.y=p2.y-1;
		draw_line(p1,p2,rouge);
		p1.y=p1.y+2;p2.y=p2.y+2;
		draw_line(p1,p2,rouge);
		test=2;
		return test;
	}
	if((nature[6]==1)&&(nature[7]==1)&&(nature[8]==1)){ //si le joueur gagne sur la troisieme ligne 
		p1=calcul_centre2(6);p1.x=p1.x-50;
		p2=calcul_centre2(8);p2.x=p2.x+50;
		draw_line(p1,p2,bleu);
		p1.y=p1.y-1;p2.y=p2.y-1;
		draw_line(p1,p2,bleu);
		p1.y=p1.y+2;p2.y=p2.y+2;
		draw_line(p1,p2,bleu);
		test=1;
		return test;
	}
	if((nature[6]==2)&&(nature[7]==2)&&(nature[8]==2)){ //si lordi gagne sur la troisieme ligne 
		p1=calcul_centre2(6);p1.x=p1.x-50;
		p2=calcul_centre2(8);p2.x=p2.x+50;
		draw_line(p1,p2,rouge);
		p1.y=p1.y-1;p2.y=p2.y-1;
		draw_line(p1,p2,rouge);
		p1.y=p1.y+2;p2.y=p2.y+2;
		draw_line(p1,p2,rouge);
		test=2;
		return test;
	}
	
	if((nature[0]==1)&&(nature[3]==1)&&(nature[6]==1)){ //si le joueur gagne sur la premiere colonne
		p1=calcul_centre2(0);p1.y=p1.y-50;
		p2=calcul_centre2(6);p2.y=p2.y+50;
		draw_line(p1,p2,bleu);
		p1.x=p1.x-1;p2.x=p2.x-1;
		draw_line(p1,p2,bleu);
		p1.x=p1.x+2;p2.x=p2.x+2;
		draw_line(p1,p2,bleu);
		test=1;
		return test;
	}
	if((nature[0]==2)&&(nature[3]==2)&&(nature[6]==2)){ //si lordi gagne sur la premiere colonne
		p1=calcul_centre2(0);p1.y=p1.y-50;
		p2=calcul_centre2(6);p2.y=p2.y+50;
		draw_line(p1,p2,rouge);
		p1.x=p1.x-1;p2.x=p2.x-1;
		draw_line(p1,p2,rouge);
		p1.x=p1.x+2;p2.x=p2.x+2;
		draw_line(p1,p2,rouge);
		test=2;
		return test;
	}
	if((nature[1]==1)&&(nature[4]==1)&&(nature[7]==1)){ //si le joueur gagne sur la deuxieme colonne
		p1=calcul_centre2(1);p1.y=p1.y-50;
		p2=calcul_centre2(7);p2.y=p2.y+50;
		draw_line(p1,p2,bleu);
		p1.x=p1.x-1;p2.x=p2.x-1;
		draw_line(p1,p2,bleu);
		p1.x=p1.x+2;p2.x=p2.x+2;
		draw_line(p1,p2,bleu);
		test=1;
		return test;
	}
	if((nature[1]==2)&&(nature[4]==2)&&(nature[7]==2)){ //si lordi gagne sur la deuxieme colonne
		p1=calcul_centre2(1);p1.y=p1.y-50;
		p2=calcul_centre2(7);p2.y=p2.y+50;
		draw_line(p1,p2,rouge);
		p1.x=p1.x-1;p2.x=p2.x-1;
		draw_line(p1,p2,rouge);
		p1.x=p1.x+2;p2.x=p2.x+2;
		draw_line(p1,p2,rouge);
		test=2;
		return test;
	}
	if((nature[2]==1)&&(nature[5]==1)&&(nature[8]==1)){ //si le joueur gagne sur la troisieme colonne
		p1=calcul_centre2(2);p1.y=p1.y-50;
		p2=calcul_centre2(8);p2.y=p2.y+50;
		draw_line(p1,p2,bleu);
		p1.x=p1.x-1;p2.x=p2.x-1;
		draw_line(p1,p2,bleu);
		p1.x=p1.x+2;p2.x=p2.x+2;
		draw_line(p1,p2,bleu);
		test=1;
		return test;
	}
	if((nature[2]==2)&&(nature[5]==2)&&(nature[8]==2)){ //si lordi gagne sur la troisieme colonne
		p1=calcul_centre2(2);p1.y=p1.y-50;
		p2=calcul_centre2(8);p2.y=p2.y+50;
		draw_line(p1,p2,rouge);
		p1.x=p1.x-1;p2.x=p2.x-1;
		draw_line(p1,p2,rouge);
		p1.x=p1.x+2;p2.x=p2.x+2;
		draw_line(p1,p2,rouge);
		test=2;
		return test;
	}
	if((nature[0]==1)&&(nature[4]==1)&&(nature[8]==1)){ //si le joueur gagne sur la premiere diagonale
		p1=calcul_centre2(0);p1.x=p1.x-50;p1.y=p1.y-50;
		p2=calcul_centre2(8);p2.x=p2.x+50;p2.y=p2.y+50;
		draw_line(p1,p2,bleu);
		p1.x=p1.x-1;p2.x=p2.x-1;
		draw_line(p1,p2,bleu);
		p1.x=p1.x+2;p2.x=p2.x+2;
		draw_line(p1,p2,bleu);
		test=1;
		return test;
	}
	if((nature[0]==2)&&(nature[4]==2)&&(nature[8]==2)){ //si lordi gagne sur la premiere diagonale
		p1=calcul_centre2(0);p1.x=p1.x-50;p1.y=p1.y-50;
		p2=calcul_centre2(8);p2.x=p2.x+50;p2.y=p2.y+50;
		draw_line(p1,p2,rouge);
		p1.x=p1.x-1;p2.x=p2.x-1;
		draw_line(p1,p2,rouge);
		p1.x=p1.x+2;p2.x=p2.x+2;
		draw_line(p1,p2,rouge);
		p1.x=p1.x+1;p2.x=p2.x+1;
		draw_line(p1,p2,rouge);
		test=2;
		return test;
	}
	if((nature[6]==1)&&(nature[4]==1)&&(nature[2]==1)){ //si le joueur gagne sur la deuxieme diagonale
		p1=calcul_centre2(6);p1.x=p1.x-50;p1.y=p1.y+50;
		p2=calcul_centre2(2);p2.x=p2.x+50;p2.y=p2.y-50;
		draw_line(p1,p2,bleu);
		p1.x=p1.x-1;p2.x=p2.x-1;
		draw_line(p1,p2,bleu);
		p1.x=p1.x+2;p2.x=p2.x+2;
		draw_line(p1,p2,bleu);
		test=1;
		return test;
	}
	if((nature[6]==2)&&(nature[4]==2)&&(nature[2]==2)){ //si lordi gagne sur la deuxieme diagonale
		p1=calcul_centre2(6);p1.x=p1.x-50;p1.y=p1.y+50;
		p2=calcul_centre2(2);p2.x=p2.x+50;p2.y=p2.y-50;
		draw_line(p1,p2,rouge);
		p1.x=p1.x-1;p2.x=p2.x-1;
		draw_line(p1,p2,rouge);
		p1.x=p1.x+2;p2.x=p2.x+2;
		draw_line(p1,p2,rouge);
		p1.x=p1.x+1;p2.x=p2.x+1;
		draw_line(p1,p2,rouge);
		test=2;
		//POINT p;
		//p.x=144;p.y=122;
		//aff_int(test,100,p,rouge);
		return test;
	}
	return test;
}

void test_entre_coups(){ //sait si cest continue gagne perdu ou egalite
	etat_du_jeu=gagne_ou_perdu();
	if(nb_coups==9){
		POINT p;
		p.x=75;p.y=375;
		aff_pol("EGALITE",100,p,noir);
		wait_escape();
		exit(0);
	}
	if(etat_du_jeu==1){
		POINT p;
		p.x=100;p.y=375;
		aff_pol("GAGNE!",100,p,vert);
		wait_escape();
		exit(0);
	}
	if(etat_du_jeu==2){
		POINT p;
		p.x=115;p.y=375;
		aff_pol("PERDU!",100,p,orangered);
		wait_escape();
		exit(0);
	}
}

void tour_joueur1(){ //tour du premier joueur
	POINT pUtilisateur;
	int caseJoueur;
	pUtilisateur=wait_clic();
	caseJoueur=calcul_numero_case(pUtilisateur);
	while(jouable[caseJoueur]==0){ //si il clique sur une case deja prise ca recommence lattente du clic
		pUtilisateur=wait_clic();
		caseJoueur=calcul_numero_case(pUtilisateur);
	}
	nature[caseJoueur]=1;
	nb_coups++;
	affiche_jeu();
}

void tour_joueur2(){ //tour du deuxieme joueur
	POINT pUtilisateur;
	int caseJoueur;
	pUtilisateur=wait_clic();
	caseJoueur=calcul_numero_case(pUtilisateur);
	while(jouable[caseJoueur]==0){ //si il clique sur une case deja prise ca recommence lattente du clic
		pUtilisateur=wait_clic();
		caseJoueur=calcul_numero_case(pUtilisateur);
	}
	//write_int(caseJoueur);
	//jouable[caseJoueur]=0; ////////PAS BESOIN DE SOCCUPER DU TABLEAU JOUABLE!!!!!
	nature[caseJoueur]=2;
	nb_coups++;
	affiche_jeu();
}

int test_defense(){ //test si il faut defendre
	if((nature[0]==1)&&(nature[1]==1)&&(jouable[2]==1)){return 2;} //premiere ligne
	else if((nature[0]==1)&&(nature[2]==1)&&(jouable[1]==1)){return 1;}
	else if((nature[1]==1)&&(nature[2]==1)&&(jouable[0]==1)){return 0;}
	if((nature[3]==1)&&(nature[4]==1)&&(jouable[5]==1)){return 5;} //deuxieme ligne
	else if((nature[3]==1)&&(nature[5]==1)&&(jouable[4]==1)){return 4;}
	else if((nature[4]==1)&&(nature[5]==1)&&(jouable[3]==1)){return 3;}
	if((nature[6]==1)&&(nature[7]==1)&&(jouable[8]==1)){return 8;} //troisieme ligne
	else if((nature[6]==1)&&(nature[8]==1)&&(jouable[7]==1)){return 7;}
	else if((nature[7]==1)&&(nature[8]==1)&&(jouable[6]==1)){return 6;}
	if((nature[0]==1)&&(nature[3]==1)&&(jouable[6]==1)){return 6;} //premiere colonne
	else if((nature[0]==1)&&(nature[6]==1)&&(jouable[3]==1)){return 3;}
	else if((nature[3]==1)&&(nature[6]==1)&&(jouable[0]==1)){return 0;}
	if((nature[1]==1)&&(nature[4]==1)&&(jouable[7]==1)){return 7;} //deuxieme colonne
	else if((nature[1]==1)&&(nature[7]==1)&&(jouable[4]==1)){return 4;}
	else if((nature[4]==1)&&(nature[7]==1)&&(jouable[1]==1)){return 1;}
	if((nature[2]==1)&&(nature[5]==1)&&(jouable[8]==1)){return 8;} //troisieme colonne
	else if((nature[2]==1)&&(nature[8]==1)&&(jouable[5]==1)){return 5;}
	else if((nature[5]==1)&&(nature[8]==1)&&(jouable[2]==1)){return 2;}
	if((nature[6]==1)&&(nature[4]==1)&&(jouable[2]==1)){return 2;} //premiere diagonale
	else if((nature[6]==1)&&(nature[2]==1)&&(jouable[4]==1)){return 4;}
	else if((nature[4]==1)&&(nature[2]==1)&&(jouable[6]==1)){return 6;}
	if((nature[8]==1)&&(nature[4]==1)&&(jouable[0]==1)){return 0;} //deuxieme diagonale
	else if((nature[8]==1)&&(nature[0]==1)&&(jouable[4]==1)){return 4;}
	else if((nature[4]==1)&&(nature[0]==1)&&(jouable[8]==1)){return 8;}	
	return -1;
}

int debut_attaque(){ //debut dune possible attaque
	int i;
	int caseOrdi=0;
	for(i=0;i<9;i++){
		if(nature[i]==2){
			caseOrdi=i;
		}
	}
	if(caseOrdi==0){
		if(jouable[3]==1){return 3;}
		else {return 1;}
	}
	else if(caseOrdi==6){
		if(jouable[3]==1){return 3;}
		else {return 7;}
	}
	else if(caseOrdi==8){
		if(jouable[7]==1){return 7;}
		else {return 5;}
	}
	else if(caseOrdi==2){
		if(jouable[1]==1){return 1;}
		else {return 5;}
	}
	else if(caseOrdi==1){
		if(jouable[0]==1){return 0;}
		else if(jouable[4]==1){return 4;}
		else if(jouable[2]==1){return 2;}
	}
	else if(caseOrdi==3){
		if(jouable[0]==1){return 0;}
		else if(jouable[4]==1){return 4;}
		else if(jouable[6]==1){return 6;}
	}
	else if(caseOrdi==7){
		if(jouable[4]==1){return 4;}
		else if(jouable[6]==1){return 6;}
		else if(jouable[8]==1){return 8;}
	}
	else if(caseOrdi==5){
		if(jouable[2]==1){return 2;}
		else if(jouable[4]==1){return 4;}
		else if(jouable[8]==1){return 8;}
	}
	else if(caseOrdi==4){
		if(jouable[1]==1){return 1;}
		else if(jouable[3]==1){return 3;}
		else if(jouable[7]==1){return 7;}
		else if(jouable[5]==1){return 5;}
	}
	return -2;
}

int test_attaque(){ //test si lattaque est possible
	if((nature[0]==2)&&(nature[1]==2)&&(jouable[2]==1)){return 2;} //premiere ligne
	else if((nature[0]==2)&&(nature[2]==2)&&(jouable[1]==1)){return 1;}
	else if((nature[1]==2)&&(nature[2]==2)&&(jouable[0]==1)){return 0;}
	if((nature[3]==2)&&(nature[4]==2)&&(jouable[5]==1)){return 5;} //deuxieme ligne
	else if((nature[3]==2)&&(nature[5]==2)&&(jouable[4]==1)){return 4;}
	else if((nature[4]==2)&&(nature[5]==2)&&(jouable[3]==1)){return 3;}
	if((nature[6]==2)&&(nature[7]==2)&&(jouable[8]==1)){return 8;} //troisieme ligne
	else if((nature[6]==2)&&(nature[8]==2)&&(jouable[7]==1)){return 7;}
	else if((nature[7]==2)&&(nature[8]==2)&&(jouable[6]==1)){return 6;}
	if((nature[0]==2)&&(nature[3]==2)&&(jouable[6]==1)){return 6;} //premiere colonne
	else if((nature[0]==2)&&(nature[6]==2)&&(jouable[3]==1)){return 3;}
	else if((nature[3]==2)&&(nature[6]==2)&&(jouable[0]==1)){return 0;}
	if((nature[1]==2)&&(nature[4]==2)&&(jouable[7]==1)){return 7;} //deuxieme colonne
	else if((nature[1]==2)&&(nature[7]==2)&&(jouable[4]==1)){return 4;}
	else if((nature[4]==2)&&(nature[7]==2)&&(jouable[1]==1)){return 1;}
	if((nature[2]==2)&&(nature[5]==2)&&(jouable[8]==1)){return 8;} //troisieme colonne
	else if((nature[2]==2)&&(nature[8]==2)&&(jouable[5]==1)){return 5;}
	else if((nature[5]==2)&&(nature[8]==2)&&(jouable[2]==1)){return 2;}
	if((nature[6]==2)&&(nature[4]==2)&&(jouable[2]==1)){return 2;} //premiere diagonale
	else if((nature[6]==2)&&(nature[2]==2)&&(jouable[4]==1)){return 4;}
	else if((nature[4]==2)&&(nature[2]==2)&&(jouable[6]==1)){return 6;}
	if((nature[8]==2)&&(nature[4]==2)&&(jouable[0]==1)){return 0;} //deuxieme diagonale
	else if((nature[8]==2)&&(nature[0]==2)&&(jouable[4]==1)){return 4;}
	else if((nature[4]==2)&&(nature[0]==2)&&(jouable[8]==1)){return 8;}	
	return -3;
}

void au_hasard(){ //met au hasard la case de l'ordi
	int g;
	int palier=-1;
	for(g=0;g<9;g++){
		if(jouable[g]==1){
			palier=g;
		}
	}
	nature[palier]=2;
	nb_coups++;
	affiche_jeu();
}

void premier_tour(){ //premier tour
	if((nature[0]==1)||(nature[2]==1)||(nature[6]==1)||(nature[8]==1)){ //jeu sur les coins
		nature[4]=2;
		nb_coups++;
		affiche_jeu();
	}
	else if((nature[4]==1)){ //jeu sur le centre
		int i;
		i=alea_int(4);
		if(i==0){
			nature[0]=2;
		}
		else if(i==1){
			nature[2]=2;
		}
		else if(i==2){
			nature[6]=2;
		}
		else if(i==3){
			nature[8]=2;
		}
		nb_coups++;
		affiche_jeu();
	}
	else if((nature[1]==1)||(nature[3]==1)||(nature[5]==1)||(nature[7]==1)){ //jeu sur les cotes 
		nature[4]=2;
		nb_coups++;
		affiche_jeu();
	}
}

void deuxieme_tour(){ //deuxieme tour
	int i;
	int j;
	i=test_defense();
	if(i!=-1){
		nature[i]=2;
		nb_coups++;
		affiche_jeu();
	}
	else if(i==-1){
		j=debut_attaque();
		nature[j]=2;
		nb_coups++;
		affiche_jeu();
	}
}

void troisieme_tour(){ //troisieme et autre tour
	int n;
	int k;
	n=test_defense();
	
	if(n!=-1){
		nature[n]=2;
		nb_coups++;
		affiche_jeu();
	}
	else if(n==-1){
		k=test_attaque();
		if(k!=-3){
			nature[k]=2;
			nb_coups++;
			affiche_jeu();
		}
		else if(k==-3){
			au_hasard();
		}
	}
}

void tour_ordi(){ //tour de lordi
	attendre(200);
	if(nb_coups==1){
		premier_tour();
	}
	if(nb_coups==3){
		deuxieme_tour();
	}
	if(nb_coups==5){
		troisieme_tour();
	}
	if(nb_coups==7){
		troisieme_tour();
	}
}

void partie_un_joueur(){ //partie un joueur
	init_jeu();
	affiche_jeu();
	tour_joueur1();
	tour_ordi();
	tour_joueur1();
	tour_ordi();
	tour_joueur1();
	test_entre_coups();
	tour_ordi();
	test_entre_coups();
	tour_joueur1();
	test_entre_coups();
	tour_ordi();
	test_entre_coups();
	tour_joueur1();
	test_entre_coups();
}

void partie_deux_joueurs(){ //partie deux joueurs
	init_jeu();
	int i;
	affiche_jeu();
	for(i=0;i<2;i++){
		tour_joueur1();
		tour_joueur2();
	}
	for(i=0;i<3;i++){
		test_entre_coups();
		tour_joueur1();
		test_entre_coups();
		tour_joueur2();
	}
}

void demarrage(){ //propose une partie seul ou a deux
	fill_screen(gris);
	POINT p;
	p.x=60;p.y=550;
	aff_pol("TIC TAC TOE",75,p,noir);
	POINT p1,p2,ecriture1,ecriture2;
	p1.x=75;p1.y=300;
	p2.x=225;p2.y=335;
	ecriture1.x=110;ecriture1.y=333;
	draw_fill_rectangle(p1,p2,argent);
	aff_pol("1 joueur",20,ecriture1,bleu);
	p1.x=375;p1.y=300;
	p2.x=525;p2.y=335;
	ecriture2.x=405;ecriture2.y=333;
	draw_fill_rectangle(p1,p2,argent);
	aff_pol("2 joueurs",20,ecriture2,rouge);
	
	POINT pUtilisateur;
	pUtilisateur.x=2;pUtilisateur.y=2;
	while((((pUtilisateur.x<75)||(((pUtilisateur.x>225)&&(pUtilisateur.x<375)))||(pUtilisateur.x>575)))&&((pUtilisateur.y<300)||(pUtilisateur.y>335))){
		pUtilisateur=wait_clic();
	}
	if((pUtilisateur.x>75)&&(pUtilisateur.x<225)&&(pUtilisateur.y>300)&&(pUtilisateur.y<335)){
		partie_un_joueur();
	}
	else if((pUtilisateur.x>375)&&(pUtilisateur.x<525)&&(pUtilisateur.y>300)&&(pUtilisateur.y<335)){
		partie_deux_joueurs();
	}
}

int main(){
	init_graphics(600,600);
	fill_screen(blanc);
	demarrage();
	wait_escape();
	exit(0);
}
