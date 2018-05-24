#include <uvsqgraphics.h>

// ############################
// 1. Les structures de donnÃ©es
// ############################
#define LF LARGEUR_FENETRE
#define HF HAUTEUR_FENETRE

// Pour stocker une balle
struct balle {
	POINT centre;
	int rayon;
	int dx, dy;
	int R,V,B;
};

// Pour stocker le trait vertical et horizontal
struct traits {
	int TV, TH;
	POINT H,B;
	POINT G,D;
};

// #####################
// 2. Gestion des balles
// #####################

struct balle init_balle (int i) {
	struct balle B;

	if (i==0) { B.centre.x = 200; B.centre.y = 300; B.dx =  3; B.dy =  2; B.R=B.V=0; B.B=255; B.rayon = 70; }
	if (i==1) { B.centre.x = 700; B.centre.y = 500; B.dx = -5; B.dy = -7; B.R=255; B.V=B.B=0; B.rayon = 50; }
	if (i==2) { B.centre.x = 100; B.centre.y = 600; B.dx = -1; B.dy =  5; B.R=B.B=0; B.V=255; B.rayon = 40; }
	if (i==3) { B.centre.x = 800; B.centre.y = 100; B.dx =  5; B.dy = -3; B.R=B.V=255; B.B=0; B.rayon = 60; }
	return B;
}

// Rebond d'une balle sur le bord
struct balle rebond_bord(struct balle B) {
	if ((B.centre.x - B.rayon <  0) && (B.dx<0)) B.dx = -B.dx;
	if ((B.centre.x + B.rayon > LF) && (B.dx>0)) B.dx = -B.dx;
	if ((B.centre.y - B.rayon <  0) && (B.dy<0)) B.dy = -B.dy;
	if ((B.centre.y + B.rayon > HF) && (B.dy>0)) B.dy = -B.dy;
	return B;
}

// Rebond d'une balle sur les traits
struct balle rebond_traits(struct balle B, struct traits T) {
	if ((B.centre.x < LF/2) && (B.centre.x+B.rayon > LF/2) && (B.dx>0) && (T.TV)) B.dx = -B.dx;
	if ((B.centre.x > LF/2) && (B.centre.x-B.rayon < LF/2) && (B.dx<0) && (T.TV)) B.dx = -B.dx;
	if ((B.centre.y < HF/2) && (B.centre.y+B.rayon > HF/2) && (B.dy>0) && (T.TH)) B.dy = -B.dy;
	if ((B.centre.y > HF/2) && (B.centre.y-B.rayon < HF/2) && (B.dy<0) && (T.TH)) B.dy = -B.dy;
	return B;
}

// Déplacement d'une balle
struct balle deplace_balle(struct balle B, struct traits T) {
	B.centre.x += B.dx;
	B.centre.y += B.dy;
	B = rebond_bord(B);
	B = rebond_traits(B,T);
	return B;
}

// Affichage d'un balle avec effet d'éclairage
void affiche_balle(struct balle B) {
	int r,v,b,i;
	int nb_step;
	int dr,dv,db,dra;
	POINT P;
	int R;
	COULEUR C;
	nb_step = B.rayon*0.5;
	dr = (255-B.R)/nb_step;
	dv = (255-B.V)/nb_step;
	db = (255-B.B)/nb_step;
	dra = B.rayon/nb_step;
	for (i=0 ; i<nb_step ; i++) {
		r = B.R + dr*i;
		v = B.V + dv*i;
		b = B.B + db*i;
		P.x = B.centre.x + i;
		P.y = B.centre.y + i;
		R = B.rayon - dra*i;
		C = couleur_RGB(r,v,b);
		draw_fill_circle(P,R,C);
	}
}

// Effacement d'une balle
void efface_balle(struct balle B) { draw_fill_circle(B.centre,B.rayon,noir); }

// #####################
// 3. Gestion des traits
// #####################

struct traits init_traits() {
	struct traits T;
	T.TV = T.TH = 1;
	T.H.x = T.B.x = LF/2; T.H.y = HF; T.B.y = 0;
	T.G.x = 0; T.D.x = LF; T.G.y = T.D.y = HF/2;
	return T;
}

// Change les traits de visible Ã  invisible et vice-versa avec une proba de 0.001
struct traits modifie_traits(struct traits T) {
	if (alea_int(1000) == 0) T.TV=1-T.TV;
	if (alea_int(1000) == 0) T.TH=1-T.TH;
	return T;
}

// Affichage des traits
void affiche_traits(struct traits T) {
	if (T.TV) draw_line(T.H,T.B,blanc);
	if (T.TH) draw_line(T.G,T.D,blanc);
}

// Effacement des traits
void efface_traits(struct traits T) {
	draw_line(T.H,T.B,noir);
	draw_line(T.G,T.D,noir);
}

void affiche_legende() {
	int taille_police = 50;
	static POINT centre = {0,0};
	static char s[64] = "Fermer la fen"ecirc"tre pour terminer";
	int largeur = largeur_texte(s,taille_police);
	int hauteur = hauteur_texte(s,taille_police);
	static int dx = 1;
	static int dy = 1;
	centre.x += dx;
	centre.y += dy;
	POINT hg, hg1;
	hg.x = centre.x-largeur/2;
	hg.y = centre.y+hauteur/2;
	hg1.x = hg.x-5;
	hg1.y = hg.y+5;
	aff_pol(s,taille_police+1,hg1,noir);
	aff_pol(s,taille_police,hg,orange);
	if ((hg.x<0) && (dx<0)) dx = -dx;
	if ((LARGEUR_FENETRE<hg.x+largeur) && (dx>0)) dx = -dx;
	if ((hg.y-hauteur<0) && (dy<0)) dy = -dy;
	if ((HAUTEUR_FENETRE<hg.y) && (dy>0)) dy = -dy;
}


// ##########
// 4. Le main
// ##########


int main () {
	int i;
	struct balle B[4];
	struct traits T;
//	float attente = 1;
//	float delta_attente = 1.01;

	init_graphics (1020,700);
	for (i=0 ; i<4 ; i++) B[i] = init_balle(i);
	T = init_traits();
	affiche_auto_off();
	while(1) {
		// On affiche
		affiche_legende();
		affiche_traits(T);
		for (i=0 ; i<4 ; i++) affiche_balle(B[i]);
		affiche_all();
//		fill_screen(noir);
		// On efface
		efface_traits(T);
		for (i=0 ; i<4 ; i++) efface_balle(B[i]);
		// On modifie
		T = modifie_traits(T);
		for (i=0 ; i<4 ; i++) B[i] = deplace_balle(B[i],T);
//		attente *= delta_attente;
//		if (attente > 100) delta_attente = 0.99;
//		if (attente < 0.000001) delta_attente = 1.01;
//		attendre(attente);
	}
	wait_escape();
	exit(0);
}
