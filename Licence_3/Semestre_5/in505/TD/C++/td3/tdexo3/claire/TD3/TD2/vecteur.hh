
#ifndef VECTEUR_HH
#define VECTEUR_HH


class Vecteur{
	int* v;
	int size;
	
	public:
		Vecteur();
		Vecteur(int n);
		Vecteur(const Vecteur& V);
		int getV(int i);
		int getSize();
		void affect(int i, int n);
		void affiche();
		
		Vecteur& operator=(const Vecteur& v);
		Vecteur& operator+=(const Vecteur& b);
		int& operator[](const int i);
		
		//Vecteur operator<<();
		
		~Vecteur();
	

};

#endif
