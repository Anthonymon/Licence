#ifndef CERCLE__H
#define CERCLE__H

class Cercle : public Forme{
	private:
		Point centre;
		int rayon;
	public:
		Cercle(Couleur couleur);
		Cercle(Point c,int rayon,Couleur couleur);
		void dessiner();
		void deplacer(double longueur,double largeur);
		~Cercle();
};

#endif
