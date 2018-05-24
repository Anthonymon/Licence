#include <iostream>
using namespace std;

class Point{
	private:
		int x,y;
	
	public:		
		Point(){ x = 0; y = 0; }
		Point(int x, int y){this->x = x; this->y = y; }
		Point(const Point& p){ x = p.x; y = p.y; }
		
		void afficher(){
			cout << "x = " << x << endl;
			cout << "y = " << y << endl;
		}
		
		void cloner(const Point& p){
			x = p.x; y = p.y;
		}
		~Point(){
			cout << "appel au destructeur\n";
		}
};


int main(){
	Point* p = new Point(42,84);
	Point h;
	p->cloner(h);
	p->afficher();
	h.afficher();
	delete p;
}
