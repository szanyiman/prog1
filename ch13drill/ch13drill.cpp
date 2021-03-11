// g++ ch13drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	int max_width = 800;
	int max_height = 1000;
	Simple_window win{Point{100,100},max_width,max_height,"Chapter 13 Drill"};
    Lines grid;
    int x_size = 800;
    int y_size = 800;
    for (int i = 100; i<=x_size; i+=100) {
        grid.add(Point(i,0),Point(i,y_size));
        grid.add(Point(0,i),Point(x_size,i));
    }
    win.attach(grid);
	win.wait_for_button();

	Vector_ref<Rectangle> vr;
    for (int i = 0; i<8; ++i) {
        vr.push_back(new Rectangle(Point(i*100,i*100),101,101));
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }
    win.wait_for_button();

    Image kep1(Point(600,0),"seal.jpeg");
    win.attach(kep1);
    Image kep2(Point(500,200),"mario.jpeg");
    win.attach(kep2);
    Image kep3(Point(0,600),"dog.jpeg");
    win.attach(kep3);
    win.wait_for_button();

    Image kep4(Point(0,0),"logo.jpeg");
	kep4.set_mask(Point(0,0),100,100);
	win.attach(kep4);
	int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    while (true) {
        x = randint(7);
        y = randint(7);
        dx = 100*x - kep4.point(0).x;
        dy = 100*y - kep4.point(0).y;
        kep4.move(dx,dy);
        win.wait_for_button();
    }
}
