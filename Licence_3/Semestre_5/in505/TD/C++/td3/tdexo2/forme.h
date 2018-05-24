#ifndef FORME__H
#define FORME__H



typedef enum{
	Rouge,
    Bleu,
    Vert,
    Jaune
}Couleur;

class Forme{
	protected:
		Couleur coul;
	
	public:
		Forme(Couleur couleur);
		Couleur getCoul();
		virtual void dessiner()=0;
		virtual void deplacer(double longueur,double largeur)=0;
		~Forme();
		
};

#endif
