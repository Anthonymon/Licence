#include "point_color.hh"
#include "forme.hh"
#include <vector>

int main(){
	PointColor p(5,5,"rouge"), q(10,10,"bleu");
	Point S(15,5);
	Cercle c(S);
	Segment s(p,q);
	Rectangle r(p,q);
	Triangle t(S,p,q);
	
	
	std::vector<Forme*> collec;
	collec.push_back(&c);
	collec.push_back(&s);
	collec.push_back(&r);
	collec.push_back(&t);
	
	for(int i=0; i < collec.size(); i++){
		collec[i]->deplacer(10,10);
		collec[i]->afficher();
	}
}
