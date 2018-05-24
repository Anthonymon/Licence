#include <iostream>
#include <cstring>
using namespace std;

class Point{
	private:
		int x;
		int y;
	public:
		Point(){
			this->x=0;
			this->y=0;
		};
		Point(int x,int y){
			this->x=x;
			this->y=y;
		};
		Point(Point& p){
			this->x=p.getX();
			this->y=p.getY();
		};
		int getX(){
			return this->x;
		};
		int getY(){
			return this->y;
		};
		void affiche(){
			cout<<"POINT ("<<this->x<<","<<this->y<<")"<<endl;
		};
		void clone(const Point& p){
			this->x=p.x;
			this->y=p.y;
		};
		~Point(){
			cout << "appel au destructeur"<<endl;
		}
		
};

int main(){
	Point* p1=new Point(2,3); //dynamiquement
	p1->affiche();
	Point p2(5,6);
	p2.clone(*p1);
	p2.affiche();
	delete p1;
	//delete &p2; INTERDIT CAR ALLOUE STATIQUEMENT !!!!!IMPORTANT
	
}

