// ################################################
//       UVSQ -- Licence UFR des Sciences
//
// Licence Informatique : IN100, IN200, IN301, ...
// FSI -- Formation à la Science Informatique pour l'ISN
//
// Franck QUESSETTE -- Franck.Quessette@uvsq.fr
// Yann STROZECKI
// Pierre COUCHENEY
// Version de novembre 2016
//
// SOMMAIRE
//
// 0. AFFICHAGE DE TEXTE AVEC SDL_ttf ... ligne   28
// 1. VARIABLES, CONSTANTES ............. ligne   39
// 2. AFFICHAGE ......................... ligne   62
// 3. GESTION D'ÉVÉNEMENTS .............. ligne  154
// 4. DESSIN D'OBJETS ................... ligne  373
// 5. ÉCRITURE DE TEXTE ................. ligne  677
// 6. LECTURE D'ENTIER .................. ligne  820
// 7. GESTION DU TEMPS .................. ligne  837
// 8. VALEUR ALÉATOIRES ................. ligne  896
// 9. DIVERS ............................ ligne  915
// #################################################


// ########################################
// 0. AFFICHAGE DE TEXTE AVEC SDL_ttf (qst)
// ########################################

#include <SDL_ttf.h>
#include <SDL/SDL_ttf.h>
// Si on veut changer la police, c'est ici.
#define POLICE_NAME "/usr/share/fonts/truetype/verdana.ttf"

#include <uvsqgraphics.h>

// ##############################
// 1. VARIABLES, CONSTANTES (qst)
// ##############################

	// 1.1 La variable dans laquelle
	// l'image finale est écrite
	SDL_Surface *SDL_screen;
	
	// 1.2 Pour ne pas oublier l'appel à init_graphics()
	int SDL_init_graphics_is_already_called = 0;

	// 1.3 Si SDL_AFFICHE_AUTO vaut 1, l'affichage
	// est automatiquement fait pour chaque objet
	// Sinon il faut le fait à la main
	int SDL_AFFICHE_AUTO = 1;
	
	// 1.4 Les constantes de taille max de l'écran
	#define MAX_WIDTH  1921
	#define MAX_HEIGHT 1201

	// 1.5 
	POINT SDL_MOUSE_POSITION = {0,0};
	
// ##################
// 2. AFFICHAGE (qst)
// ##################

	// 2.0 Ouverture des polices de caractere.
	//fenêtre sur laquelle on dessine
	// W et H sont la largeur et la hauteur désirée.
	// La variable globale SDL_screen est initialisée

	// 2.1 Initialisation de la fenêtre sur laquelle on dessine
	// W et H sont la largeur et la hauteur désirée.
	// La variable globale SDL_screen est initialisée
void init_graphics(int W, int H) {
	// Initialisation d'une taille raisonnable
	if ((W>10) && (W<MAX_WIDTH )) WIDTH  = W; else WIDTH  = 640;
	if ((H>10) && (H<MAX_HEIGHT)) HEIGHT = H; else HEIGHT = 480;
	WIDTH  = W;
	HEIGHT = H;
	// Initialisation de la SDL_surface
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	
	if ( SDL_screen == NULL ) {
		fprintf(stderr, "Impossible de passer en %dx%d en 32 bits: %s\n", WIDTH, HEIGHT, SDL_GetError());
		exit(1);
		}
	WIDTH  = SDL_screen->w;
	HEIGHT = SDL_screen->h;
	printf("Ecran de %d x %d\n",WIDTH,HEIGHT);
	// Supprime le curseur de la souris dans la fenêtre
	// SDL_ShowCursor(SDL_DISABLE);
	
	// Autorise la prise en compte de répétition lors d'un appui
	// long sur une touche
	SDL_EnableKeyRepeat(1,0);
	
	// Le titre de la fenêtre
	SDL_WM_SetCaption("Franck Quessette -- UVSQ (2016)",NULL);
	
	SDL_init_graphics_is_already_called = 1;
	
	// Remplit la fenêtre de noir
	fill_screen(noir);
	affiche_all();
}

	// 2.2 Affichage automatique ou manuel
void affiche_auto_on () { SDL_AFFICHE_AUTO = 1; }
void affiche_auto_off() { SDL_AFFICHE_AUTO = 0; }
	// Affiche tous les objets et vérifie que la fonction init_graphics 
	// a été appelée précédemment et affiche un message d'erreur sinon.	
void affiche_all() {
	static SDL_Event event[256];
	int n=0;
	while (SDL_PollEvent(event+n)) {
		if (event[n].type == SDL_QUIT) exit(0);
		n++;
		if (n>256) exit(12);
	}
	int i;
	for (i=0 ; i<n ; i++) SDL_PushEvent(event+i);

	if (!SDL_init_graphics_is_already_called) {
			init_graphics(380,80);
			write_text("init_graphics() n'a pas "eacute"t"eacute" appel"eacute"e.");
			write_ln();
			write_text("");
			write_ln();
			write_text("           Cliquer pour terminer.");
			fprintf(stderr,"init_graphics() n'a pas été appelée.\n");
			fprintf(stderr,"Cliquer pour terminer.\n");
			wait_clic();
			exit(1);
		}
	SDL_Flip(SDL_screen);
}

	// La fonction synchro est la fonction historique	
void synchro() { affiche_all(); }

	// 2.3 Création de couleur
COULEUR couleur_RGB(int r, int g, int b) { return ((r%256)<<16) + ((g%256)<<8) + (b%256); }

	// 2.4 Affichage ou non du curseur de la souris
	//     Permet d'afficher le curseur
	//     Par défaut il est affiché
void mouse_on() { SDL_ShowCursor(1); }

	// Supprime l'affichage du curseur de la souris
void mouse_off() { SDL_ShowCursor(0); }

// ##################################
// 3. GESTION D'ÉVÉNEMENTS (qst + ys)
// ##################################

// 3.1 CLAVIER

	// 3.1.1 Renvoie le code ascii du caractère de la dernière touche 
	// du clavier qui a été pressée.
	// Si aucune touche n'a été pressée, renvoie -1
	// Fonction non bloquante.
int get_key() { // Made by ys
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		/* Si l'utilisateur a demandé à fermer la fenêtre, on quitte */
		if (event.type == SDL_QUIT) exit(0);
		/* Si l'utilisateur a appuyé sur une touche */
		if (event.type == SDL_KEYUP) return event.key.keysym.sym;
	}
	return -1;
}

	// 3.1.2 Attend que l'on tape Echap et quitte
	// Fonction bloquante
void wait_escape() {
	int display = 1;
	SDL_Event event;
	POINT p;
	char *texte =  "Appuyer sur Echap pour terminer";
	int taille = 20;
	p.x = WIDTH/2 - largeur_texte(texte,taille)/2;
	while (p.x<0) {
		taille--;
		p.x = WIDTH/2 - largeur_texte(texte,taille)/2;
	}
	p.y = hauteur_texte(texte,taille);
	aff_pol(texte,taille,p,gris);
	affiche_all();
	while (SDL_WaitEvent(&event) && display) {
		/* Si l'utilisateur a demandé à fermer la fenêtre, on quitte */
		if (event.type == SDL_QUIT) display=0;
		/* Si l'utilisateur a appuyé sur une touche */
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE : display=0; break;
				default : break;
			}
		}
	}
printf("free surface\n");
	SDL_FreeSurface(SDL_screen);
printf("quitsubsystem\n");
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
printf("quit\n");
	SDL_Quit();
}

	// 3.1.3 Renvoie le ou les flèches appuyées
	// sous forme d'un déplacement en 
	// x négatif = nombre d'appuis sur la flèche gauche
	// x positif = nombre d'appuis sur la flèche droite
	// y négatif = nombre d'appuis sur la flèche bas
	// y positif = nombre d'appuis sur la flèche haut
	// Fonction non bloquante, si aucune flèche n'a été
	// appuyée les champs x et y vaudront 0.
POINT get_arrow() {
	POINT deplacement = {0,0};
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		/* Si l'utilisateur a demandé à fermer la fenêtre, on quitte */
		if (event.type == SDL_QUIT) exit(0);
		/* Si l'utilisateur a appuyé sur une touche */
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE : exit(0);
				case SDLK_LEFT   : (deplacement.x) -= MINDEP; break;
				case SDLK_RIGHT  : (deplacement.x) += MINDEP; break;
				case SDLK_UP     : (deplacement.y) += MINDEP; break;
				case SDLK_DOWN   : (deplacement.y) -= MINDEP; break;
				default          : break;
			}
		}
	}
	return deplacement;
}

// 3.2 SOURIS

	// 3.2.1 Renvoie la position de la souris
POINT get_mouse() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		/* Si l'utilisateur a demandé à fermer la fenêtre, on quitte */
		if (event.type == SDL_QUIT) exit(0);
		/* Si l'utilisateur a appuyé sur une touche */
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE : exit(0);
				default :	break;
			}
		}
		/* Si l'utilisateur a bougé la souris */
		if (event.type == SDL_MOUSEMOTION) {
			SDL_MOUSE_POSITION.x = event.motion.x;
			SDL_MOUSE_POSITION.y = HEIGHT-event.motion.y;
		}
	}
	return SDL_MOUSE_POSITION;
}

	// 3.2.2 Attend que l'utilisateur clique sur le bouton gauche
	// Renvoie les coordonnées du point cliqué
	// Fonction bloquante
POINT wait_clic() {
	int encore = 1;
	SDL_Event event;
	printf("En attente de clic GAUCHE ... %4d %4d\r",SDL_MOUSE_POSITION.x,SDL_MOUSE_POSITION.y); fflush(stdout);
	while (SDL_WaitEvent(&event) && encore) {
		/* Si l'utilisateur clique avec la souris */
		if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT)) {
			encore=0;
			SDL_MOUSE_POSITION.x = event.button.x;
			SDL_MOUSE_POSITION.y = HEIGHT - event.button.y;
			}
		/* Si l'utilisateur déplace la souris */
		if (event.type == SDL_MOUSEMOTION) {
			SDL_MOUSE_POSITION.x = event.motion.x;
			SDL_MOUSE_POSITION.y = HEIGHT - event.motion.y;
			printf("En attente de clic GAUCHE ... %4d %4d\r",SDL_MOUSE_POSITION.x,SDL_MOUSE_POSITION.y);
			fflush(stdout);
			}
		/* Si l'utilisateur a demandé à fermer la fenêtre, on quitte */
		if (event.type == SDL_QUIT) exit(0);
	}
	printf("Clic GAUCHE en %4d %4d               \n",SDL_MOUSE_POSITION.x,SDL_MOUSE_POSITION.y);
	return SDL_MOUSE_POSITION;
}

	// 3.2.3 Attend que l'on clique et renvoie dans button le bouton cliqué :
	// *button vaut soit 'G' (pour Gauche), soit 'M' (pour milieu),
	// soit 'D' (pour Droit) en fonction du bouton cliqué
	// Fonction bloquante
POINT wait_clic_GMD (char *button) {
	int encore = 1;
	SDL_Event event;
	char *b = NULL;
	printf("En attente de clic GMD ... %4d %4d\r",SDL_MOUSE_POSITION.x,SDL_MOUSE_POSITION.y); fflush(stdout);
	while (SDL_WaitEvent(&event) && encore) {
		/* Si l'utilisateur a cliqué avec la souris */
		if ((event.type == SDL_MOUSEBUTTONDOWN)) {
			encore=0;
			SDL_MOUSE_POSITION.x = event.button.x;
			SDL_MOUSE_POSITION.y = HEIGHT - event.button.y;
			if (event.button.button == SDL_BUTTON_LEFT)   { *button = 'G'; b = "GAUCHE"; }
			if (event.button.button == SDL_BUTTON_MIDDLE) { *button = 'M'; b = "MILIEU"; }
			if (event.button.button == SDL_BUTTON_RIGHT)  { *button = 'D'; b = "DROIT "; }
			}
		/* Si l'utilisateur déplace la souris */
		if (event.type == SDL_MOUSEMOTION) {
			SDL_MOUSE_POSITION.x = event.motion.x;
			SDL_MOUSE_POSITION.y = HEIGHT - event.motion.y;
			printf("En attente de clic GMD ... %4d %4d\r",SDL_MOUSE_POSITION.x,SDL_MOUSE_POSITION.y);
			fflush(stdout);
			}
		/* Si l'utilisateur a demandé à fermer la fenêtre, on quitte */
		if (event.type == SDL_QUIT) exit(0);
		}
	
	printf("Clic %s en %4d %4d            \n",b,SDL_MOUSE_POSITION.x,SDL_MOUSE_POSITION.y);
	return SDL_MOUSE_POSITION;
}

	// 3.2.4 Renvoie la position du dernier clic de souris.
	// Si le bouton gauche n'a pas été pressée, renvoie (-1,-1)
	// Fonction non bloquante.
POINT get_clic() { // Made by ys
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		/* Si l'utilisateur a demandé à fermer la fenêtre, on quitte */
		if (event.type == SDL_QUIT) exit(0);
		/* Si l'utilisateur a appuyé sur une touche */
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE : exit(0);
				default : break;
			}
		}
		POINT le_clic;
		if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT)) {
			le_clic.x = event.button.x;
			le_clic.y = HEIGHT - event.button.y;
			printf("Clic GAUCHE en %4d %4d               \n",le_clic.x,le_clic.y);
			return le_clic;
		}
	}
	POINT def =  {-1,-1};
	return def;
}

	// 3.2.5 Attend que l'on appuie soit sur une lettre, une flèche ou que l'on clique.
	// La fonction modifie la touche la flèche ou le point selon le premier événement qui arrive.
	// La fonction renvoie le type d'événement (touche, fleche ou point) 
	// Cette fonction est bloquante.
int wait_key_arrow_clic (char *touche, int *fleche, POINT *P) { // Made by qst & pc
	SDL_Event event;
	while (SDL_WaitEvent(&event)) {
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE)) exit(0);
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_LEFT))  { *fleche = FLECHE_GAUCHE; return EST_FLECHE; }
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RIGHT)) { *fleche = FLECHE_DROITE; return EST_FLECHE; }
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_UP))    { *fleche = FLECHE_HAUTE;  return EST_FLECHE; }
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_DOWN))  { *fleche = FLECHE_BAS;    return EST_FLECHE; }
		if ((event.type == SDL_KEYUP) && ('a' <= event.key.keysym.sym) &&  (event.key.keysym.sym <= 'z'))  { *touche = event.key.keysym.sym-'a'+'A'; return EST_TOUCHE; }
//		if ((event.type == SDL_KEYUP)) { *touche = event.key.keysym.sym; return EST_TOUCHE; }
		if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT)) { P->x = event.button.x; P->y = HEIGHT-event.button.y; return EST_CLIC;}
	}
	return EST_RIEN;
}



// ########################
// 4. DESSIN D'OBJETS (qst)
// ########################
void affiche_image(char *nomfic, POINT bg, int w, int h) {
	SDL_Surface *image = NULL;
	SDL_Rect rect;
	rect.x = bg.x; rect.y = HEIGHT-bg.y;
	rect.w = w; rect.h = h;
	image = SDL_LoadBMP(nomfic);
	if (image == NULL) fprintf(stderr,"Impossible charger l'image : %s\n",nomfic);
	/* On blitte par-dessus l'écran */
	SDL_BlitSurface(image, NULL, SDL_screen, &rect);
	if (SDL_AFFICHE_AUTO) affiche_all();
}

	// 4.1 Remplissage de tout l'écran
void fill_screen(COULEUR coul) {
	int i,j;
	for (i=0;i<WIDTH;i++)
		for (j=0;j<HEIGHT;j++) *((COULEUR *)SDL_screen->pixels + (HEIGHT-j-1) * WIDTH + i) = coul;
	if (SDL_AFFICHE_AUTO) affiche_all();
}

	// 4.x.1 Fonction de clipping (vérification que le point est  dans la fenêtre)
	// Cette fonction n'est pas visible en dehors de ce fichier
int dans_ecran(int x, int y) {
	if (x<0) return 0;
	if (x>=WIDTH) return 0;
	if (y<0) return 0;
	if (y>=HEIGHT) return 0;
	return 1;
}

	// 4.x.2 Macro qui permet d'ajouter un pixel à la SDL_surface
	// Inverse l'ordonnée entre haut et bas
#define add_pix(x,y,coul)  if (dans_ecran((x),(y))) *((COULEUR *)SDL_screen->pixels + (HEIGHT-(y)-1) * WIDTH + (x)) = (coul)

	// 4.2 Affichage un pixel
void draw_pixel(POINT p, COULEUR coul) {
	add_pix(p.x,p.y,coul);
	if (SDL_AFFICHE_AUTO) affiche_all();
}

	// 4.3 Dessine un segment
void draw_line(POINT p1, POINT p2, COULEUR coul) {
	int xmin, xmax;
	int ymin, ymax;
	int i,j;
	float a,b,ii,jj;
	
	if (p1.x < p2.x) {xmin=p1.x; xmax=p2.x;} else{xmin=p2.x; xmax=p1.x;}
	if (p1.y < p2.y) {ymin=p1.y; ymax=p2.y;} else{ymin=p2.y; ymax=p1.y;}
	
	if (xmin==xmax) for (j=ymin;j<=ymax;j++) add_pix(xmin,j,coul);
	if (ymin==ymax) for (i=xmin;i<=xmax;i++) add_pix(i,ymin,coul);
	
	
	// La variation la plus grande est en x
	if ((xmax-xmin >= ymax-ymin) && (ymax-ymin>0)) {
		a = (float)(p1.y-p2.y) / ((float)(p1.x-p2.x));
		b = p1.y - a*p1.x;
		for (i=xmin;i<=xmax;i++) {
			jj = a*i+b;
			j = jj;
			if (((jj-j) > 0.5) && (j < HEIGHT-1)) j++;
			add_pix(i,j,coul);
		}
	}
	
	// La variation la plus grande est en y
	if ((ymax-ymin > xmax-xmin) && (xmax-xmin>0)) {
		a = (float)(p1.y-p2.y) / ((float)(p1.x-p2.x));
		b = p1.y - a*p1.x;
		for (j=ymin;j<=ymax;j++) {
			ii = (j-b)/a;
			i = ii;
			if (((ii-i) > 0.5) && (i < WIDTH-1)) i++;
			add_pix(i,j,coul);
		}
	}
	if (SDL_AFFICHE_AUTO) affiche_all();
}

	// 4.4 Dessine un rectangle non rempli
	// Les deux points sont deux points quelconques 
	// non adjacents du rectangle
void draw_rectangle(POINT p1, POINT p2, COULEUR coul) {
	int xmin, xmax;
	int ymin, ymax;
	int i,j;
	 
	if (p1.x < p2.x) {xmin=p1.x; xmax=p2.x;} else {xmin=p2.x; xmax=p1.x;}
	if (p1.y < p2.y) {ymin=p1.y; ymax=p2.y;} else {ymin=p2.y; ymax=p1.y;}
	
	for (i=xmin ; i<=xmax ; i++) add_pix(i,ymin,coul);
	for (i=xmin ; i<=xmax ; i++) add_pix(i,ymax,coul);
	for (j=ymin ; j<=ymax ; j++) add_pix(xmin,j,coul);
	for (j=ymin ; j<=ymax ; j++) add_pix(xmax,j,coul);
	if (SDL_AFFICHE_AUTO) affiche_all();
}

	// 4.5 Dessine un rectangle rempli
	// Les deux points sont deux points quelconques 
	// non adjacents du rectangle
void draw_fill_rectangle(POINT p1, POINT p2, COULEUR coul) {
	int xmin, xmax;
	int ymin, ymax;
	int i,j;
	
	if (p1.x < p2.x) {xmin=p1.x; xmax=p2.x;} else{xmin=p2.x; xmax=p1.x;}
	if (p1.y < p2.y) {ymin=p1.y; ymax=p2.y;} else{ymin=p2.y; ymax=p1.y;}
	
	for (i=xmin ; i<=xmax ; i++) for (j=ymin ; j<=ymax ; j++) add_pix(i,j,coul);
	if (SDL_AFFICHE_AUTO) affiche_all();
	}

	// 4.6 Dessine un cercle non rempli
void draw_circle(POINT centre, int rayon, COULEUR coul) {
	POINT min, max;
	int i,j;
	float dx, dy, rr;
	
	min.x = centre.x - rayon;  max.x = centre.x + rayon;
	min.y = centre.y - rayon;  max.y = centre.y + rayon;
	rr = rayon*rayon;
	// Variation en x
	for (i=min.x ; i<=max.x ; i++) {
		dx = i - centre.x;
		dy = sqrt(rr - dx*dx);
		j = centre.y + dy;
		add_pix(i,j,coul);
		j = centre.y - dy;
		add_pix(i,j,coul);
	}
	// Variation en y
	for (j=min.y ; j<=max.y ; j++) {
		dy = j - centre.y;
		dx = sqrt(rr - dy*dy);
		i = centre.x + dx;
		add_pix(i,j,coul);
		i = centre.x - dx;
		add_pix(i,j,coul);
	}
	if (SDL_AFFICHE_AUTO) affiche_all();
}

	// 4.7 Dessine un cercle rempli
void draw_fill_circle(POINT centre, int rayon, COULEUR coul) {
	POINT min, max;
	int i,j;
	float dx, dy, rr;
	
	min.x = centre.x - rayon; max.x = centre.x + rayon;
	min.y = centre.y - rayon; max.y = centre.y + rayon;
	rr = rayon*rayon;
	
	// Balayage du carré circonscrit au cercle
	for (i=min.x ; i<=max.x ; i++) {
		dx = i - centre.x;
		for (j=min.y;j<=max.y;j++) {
			dy = j - centre.y;
			if (dx*dx + dy*dy <= rr) add_pix(i,j,coul);
		}
	}
	if (SDL_AFFICHE_AUTO) affiche_all();
}

	// 4.8.0 Dessine un quart de cercle entre min et max
void draw_quart_de_cercle (POINT centre, int rayon, COULEUR coul, POINT min, POINT max) {
	int i,j;
	float dx, dy, rr;
	rr = rayon*rayon;
	for (i=min.x ; i<=max.x ; i++) {
		dx = i - centre.x;
		dy = sqrt(rr - dx*dx);
		j = centre.y + dy;
		add_pix(i,j,coul);
		}
	for (j=min.y;j<=max.y;j++) {
		dy = j - centre.y;
		dx = sqrt(rr - dy*dy);
		i = centre.x + dx;
		add_pix(i,j,coul);
		}
	if (SDL_AFFICHE_AUTO) affiche_all();
}

	// 4.8.1 Dessine un quart de cercle en haut à droite
void draw_circle_HD(POINT centre, int rayon, COULEUR coul) {
	POINT min, max;
	min.x = centre.x;  max.x = centre.x + rayon;
	min.y = centre.y;  max.y = centre.y + rayon;
	draw_quart_de_cercle (centre, rayon, coul, min, max);
}

	// 4.8.2 Dessine un quart de cercle en bas à droite
void draw_circle_BD(POINT centre, int rayon, COULEUR coul) {
	POINT min, max;
	min.x = centre.x; max.x = centre.x + rayon;
	min.y = centre.y - rayon; max.y = centre.y;
	draw_quart_de_cercle (centre, rayon, coul, min, max);
}

	// 4.8.3 Dessine un quart de cercle en haut à gauche
void draw_circle_HG(POINT centre, int rayon, COULEUR coul) {
	POINT min, max;
	min.x = centre.x - rayon; max.x = centre.x;
	min.y = centre.y; max.y = centre.y + rayon;
	draw_quart_de_cercle (centre, rayon, coul, min, max);
}

	// 4.8.4 Dessine un quart de cercle en bas à gauche
void draw_circle_BG(POINT centre, int rayon, COULEUR coul) {
	POINT min, max;
	min.x = centre.x - rayon; max.x = centre.x;
	min.y = centre.y - rayon; max.y = centre.y;
	draw_quart_de_cercle (centre, rayon, coul, min, max);
}

	// 4.9 Dessine une ellipse remplie
	// Les arguments F1 et F2 sont les focales et r est 
	// la somme des distances à chacun des points focaux
void draw_fill_ellipse(POINT F1, POINT F2, int r, COULEUR coul) {
	int i,j;
	int dx, fx;
	int dy, fy;
	float d, d1, d2;
	
	d = (F1.x-F2.x)*(F1.x-F2.x) + (F1.y-F2.y)*(F1.y-F2.y);
	d = sqrt(d);
	
	if (F1.x<F2.x) {dx = F1.x - d - r; fx = F2.x + d + r;} else {dx = F2.x - d - r; fx = F1.x + d + r;}
	if (F1.y<F2.y) {dy = F1.y - d - r; fy = F2.y + d + r;} else {dy = F2.y - d - r; fy = F1.y + d + r;}
	for (i=dx ; i<=fx ; i++)
		for (j=dy ; j<=fy ; j++)
			if (dans_ecran(i,j)) {
				d1 = (i-F1.x)*(i-F1.x) + (j-F1.y)*(j-F1.y);
				d1 = sqrt(d1);
				d2 = (i-F2.x)*(i-F2.x) + (j-F2.y)*(j-F2.y);
				d2 = sqrt(d2);
				if (d1+d2 < d+r) add_pix(i,j,coul);
			}
	if (SDL_AFFICHE_AUTO) affiche_all();
}

	// 4.10 Dessine un triangle
void draw_triangle(POINT p1, POINT p2, POINT p3, COULEUR coul) {
	draw_line(p1,p2,coul);
	draw_line(p2,p3,coul);
	draw_line(p3,p1,coul);
	if (SDL_AFFICHE_AUTO) affiche_all();
}

	// 4.11 Dessine un triangle rempli
	// Fonction annexe qui calcule le min de 3 valeurs
int min3 (int a, int b, int c) {
	if ( (a<b) && (a<c) ) return a;
	if ( (b<a) && (b<c) ) return b;
	return c;
}

	// Fonction annexe qui calcule le max de 3 valeurs
int max3(int a, int b, int c) {
	if ( (a>b) && (a>c) ) return a;
	if ( (b>a) && (b>c) ) return b;
	return c;
}

void draw_fill_triangle(POINT p1, POINT p2, POINT p3, COULEUR coul) {
	float a12, b12, a23, b23, a31, b31;
	float s1, s2, s3;
	// La droite passant par les point pi et pj
	// a pour équation : y = aij x  +  bij
	a12 = (p1.y-p2.y)/(float)(p1.x-p2.x);   b12 = p1.y - a12*p1.x;
	a23 = (p2.y-p3.y)/(float)(p2.x-p3.x);   b23 = p2.y - a23*p2.x;
	a31 = (p3.y-p1.y)/(float)(p3.x-p1.x);   b31 = p3.y - a31*p3.x;
	// Le signe de sk détermine de quel coté pk est de la droite [pi,pj]
	s3 = p3.y - (a12*p3.x + b12);
	s1 = p1.y - (a23*p1.x + b23);
	s2 = p2.y - (a31*p2.x + b31);
	
	int minx, maxx, miny, maxy;
	minx = min3(p1.x,p2.x,p3.x); maxx = max3(p1.x,p2.x,p3.x);
	miny = min3(p1.y,p2.y,p3.y); maxy = max3(p1.y,p2.y,p3.y);
	
	int i,j; 
	int ok;
	for (i=minx ; i<=maxx ; i++)
		for (j=miny ; j<=maxy ; j++) {
			ok = 1;
			// On vérifie que le point (i,j) est du bon coté
			// des 3 droites du triangle
			if (s3 * (j - (a12*i + b12)) < 0) ok = 0;
			if (s1 * (j - (a23*i + b23)) < 0) ok = 0;
			if (s2 * (j - (a31*i + b31)) < 0) ok = 0;
			if (ok) add_pix(i,j,coul);
		}
	draw_line(p1,p2,coul);
	draw_line(p1,p3,coul);
	draw_line(p2,p3,coul);
	if (SDL_AFFICHE_AUTO) affiche_all();
}


// ##########################
// 5. ÉCRITURE DE TEXTE (qst)
// ##########################

	// 5.0 Fonctions générales
	// Ouverture du fichier de police
	// On garde en mémoire les tailles déjà ouvertes pour ne pas avoir
	// à appeler TTF_OpenFont à chaque fois
TTF_Font *ouvrir_police(int taille) {
	static int premiere_fois = 1;
	// Pour stocker les polices déjà ouvertes
	static TTF_Font *police[256];
	if (premiere_fois) {
		TTF_Init();
		int i; for (i=0 ; i<256 ; i++) police[i] = NULL;
		premiere_fois = 0;
	}
	if (police[taille] == NULL) {
		police[taille] = TTF_OpenFont(POLICE_NAME,taille);
		if (police[taille] == NULL) { fprintf(stderr,"Impossible d'ouvrir le fichier de police %s (taille = %d)\n",POLICE_NAME,taille); }
	}
	return police[taille];
}

	// La largeur, en pixel, du texte
int largeur_texte(char *a_ecrire, int taille) {
	int w, h;
	TTF_Font *pol = ouvrir_police(taille);
	TTF_SizeText(pol,a_ecrire,&w,&h);
	return w;
}

	// La hauteur, en pixel, du texte
int hauteur_texte(char *a_ecrire, int taille) {
	int w, h;
	TTF_Font *pol = ouvrir_police(taille);
	TTF_SizeText(pol,a_ecrire,&w,&h);
	return h;
}

	// Permet de changer le style.
	// Les styles possibles sont : NORMAL, GRAS, ITALIQUE et SOULIGNE
	// Le style est appliqué jusqu'au prochain appel de la fonction
void pol_style(int style) {
	static TTF_Font *pol = NULL;
	if (!pol) pol = ouvrir_police(20);
	if ((style < 0x00) || (0x04 < style)) style = 0x00;
	TTF_SetFontStyle(pol,style);
}

	// 5.1 Affiche du texte avec
	// Le texte est passé dans l'argument "a_ecrire" 
	// la police est celle définie par la constante POLICE_NAME 
	// dans graphics.c
	// la taille est passée en argument
	// l'argument hg de type POINT est le point en haut à gauche
	// à partir duquel le texte s'affiche
	// la COULEUR coul passée en argument est la couleur d'affichage
	// Nécessite l'installation  de SDL_ttf.h
void aff_pol(char *a_ecrire, int taille, POINT hg, COULEUR coul) {

	// 0. Si la chaine est vide, on ne fait rien
	if (a_ecrire==NULL) return;

	// 1. Ouverture de la police
	TTF_Font *pol = ouvrir_police(taille);
	if (!pol) { printf("%s\n",a_ecrire); return; }

	// 2. Calcul de la couleur de coul vers color
	SDL_Color color;
	SDL_GetRGB(coul,SDL_screen->format,&(color.r),&(color.g),&(color.b));

	// 3. Création de la surface avec le texte à écrire dans la SDL_Surface "ma_surface" en mode Blended (optimal)
	SDL_Surface *ma_surface = NULL;
	ma_surface = TTF_RenderText_Blended(pol, a_ecrire, color);
	if (!ma_surface) { printf("%s\n",a_ecrire); return; }

	// 4. Ajout de la surface dans la fenêtre graphique
	SDL_Rect position;
	position.x = hg.x;
	position.y = HEIGHT - hg.y;
	SDL_BlitSurface(ma_surface, NULL, SDL_screen, &position); /* Blit du texte par-dessus */
	SDL_FreeSurface(ma_surface);

	if (SDL_AFFICHE_AUTO) affiche_all();
}

	// Idem ci-dessus mais en passant le point central et non plus en haut à gauche
void aff_pol_centre(char *a_ecrire, int taille, POINT centre, COULEUR coul) {
	POINT hg;
	hg.x = centre.x - largeur_texte(a_ecrire,taille)/2;
	hg.y = centre.y + hauteur_texte(a_ecrire,taille)/2;
	aff_pol(a_ecrire,taille,hg,coul);
}

	// 5.2 Affiche un entier
	// Meme sémantique que aff_pol()
void aff_int(int n,  int taille, POINT hg, COULEUR coul) {
	char a_ecrire[32];
	sprintf(a_ecrire,"%d",n);
	aff_pol(a_ecrire,taille,hg,coul);
}

	// 5.3 Affiche dans la fenêtre graphique comme dans une fenêtre
	// shell mais sans déroulement. Commence en haut et
	// se termine en bas.
void write_text(char *a_ecrire) {
#define TAILLE_POL_TEXTE 20
	static char s[256];
	static int fin = 0;
	static int premiere_fois = 1;
	static POINT position;

	if (premiere_fois) { position.x = 10; position.y = HEIGHT; premiere_fois = 0; }
	// Retour à la ligne
	if (a_ecrire == NULL) { position.y -= TAILLE_POL_TEXTE; fin = 0; s[0] = 0; return; }
	// Ligne trop longue
	if (fin+strlen(a_ecrire) > 256) { fprintf(stderr,"Chaine de caractère trop longue\n"); return; }
	// Ecriture du texte
	strcat(s+fin,a_ecrire);
	aff_pol(s,TAILLE_POL_TEXTE,position,blanc);
	fin += strlen(a_ecrire);
	s[fin] = 0;
}

void write_int(int n) {
	char s[32];
	sprintf(s,"%d",n);
	write_text(s);
}

void write_float(float x) {
	char s[32];
	sprintf(s,"%f",x);
	write_text(s);
}

void write_bool(BOOL b) { if (b) write_text("True"); else write_text("False"); }

void write_ln() { write_text(NULL); }
// Pour compatibilité
void writeln() { write_ln(); }

// #########################
// 6. LECTURE D'ENTIER (qst)
// #########################

	// 6.1 Renvoie l'entier tapé au clavier.
	// Cette fonction est bloquante
int lire_entier_clavier() {
	int n;
	int ret;
	printf("Donner un entier : ");
	fflush(stdout);
	ret = scanf("%d",&n);
	if (ret==-1) exit(12);
	return n;
}


// #########################
// 7. GESTION DU TEMPS (qst)
// #########################

	// 7.1 Chronomètre élémentaire, précis à la micro seconde.
	// Fonction non visible en dehors de ce fichier
float chrono(int action) {
	static double ch = 0.0;
	double current;
	float delta;
	struct timeval tv;
	
	gettimeofday(&tv,NULL);
	current = tv.tv_sec + (float)(tv.tv_usec)*1e-6;
	if (action == 0) ch = current;
	delta = (float)(current-ch);
	return delta;
}

	// Déclenchement du chrono
	// Le remet à zéro s'il était déjà lancé
void  chrono_start() { chrono(0); }
	// renvoie la valeur courante du chrono en secondes
float chrono_lap()   { return chrono(1); }


	// 7.2 Attend le nombre de millisecondes passé en argument
void attendre(int millisecondes) {
	if (millisecondes>0) SDL_Delay(millisecondes);
}

	// 7.3.1 Renvoie l'heure de l'heure courante
int heure() {
	struct tm *stm;
	struct timeval tv;
	gettimeofday(&tv,NULL);
	stm = localtime((time_t *)&(tv.tv_sec));
	return stm->tm_hour;
}

	// 7.3.2 Renvoie le nombre de minutes de l'heure courante
int minute() {
	struct tm *stm;
	struct timeval tv;
	gettimeofday(&tv,NULL);
	stm = localtime((time_t *)&(tv.tv_sec));
	return stm->tm_min;
}

	// 7.3.3 Renvoie le nombre de secondes.microsecondes de l'heure courante
float seconde() {
	struct tm *stm;
	struct timeval tv;
	gettimeofday(&tv,NULL);
	stm = localtime((time_t *)&(tv.tv_sec));
	return ((float)(stm->tm_sec) + (float)tv.tv_usec/1e6);
}


// ##########################
// 8. VALEUR ALÉATOIRES (qst)
// ##########################
	
	// 8.1 Renvoie un float uniforme dans l'intervalle [0;1[
	// ATTENTION deux exécutions successives donnent 
	// des résultats différents
float alea_float() {
	static int init_alea = 1;
	if (init_alea) srand(getpid());
	init_alea = 0;
	return (float)rand() / (float)RAND_MAX;
}

	// 8.2 Renvoie un int uniforme dans l'intervalle [0..N[
	// soit N valeurs différentes de 0 à N-1
int alea_int(int N) { return (int)(N*alea_float()); }


// ###############
// 9. DIVERS (qst)
// ###############

	// 9.1 Renvoie la distance entre deux points
float distance(POINT P1, POINT P2) {
	int d;
	d = (P1.x-P2.x)*(P1.x-P2.x) + (P1.y-P2.y)*(P1.y-P2.y);
	return (int)(sqrtf((float)d));
}
