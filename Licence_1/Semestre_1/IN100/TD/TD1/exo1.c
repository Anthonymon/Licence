/*td1 exo1 clement caumes*/
#include "graphics.h"

int main()
{
init_graphics(900,600);


POINT p1;
POINT p2;

p1.x = 100; p1.y =  90;
p2.x = 200; p2.y = 300;
draw_fill_rectangle(p1, p2, bleu);

p1.x =  10; p1.y = 10;
p2.x = 400; p2.y = 500;
draw_line(p1,p2,rouge);

p1.x = 300; p1.y = 350;
draw_circle(p1,100, magenta);


wait_escape();
exit(0);
}
