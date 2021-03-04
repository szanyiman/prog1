/*
1. Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the
Polygon red and the lines of the Rectangle blue.

2. Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it.

3. Draw your initials 150 pixels high. Use a thick line. Draw each initial in
a different color.

4. Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.

5. Draw a red ¼-inch frame around a rectangle that is three-quarters the
height of your screen and two-thirds the width.

6. What happens when you draw a Shape that doesn’t fit inside its window?
What happens when you draw a Window that doesn’t fit on your screen?
Write two programs that illustrate these two phenomena.

7. Draw a two-dimensional house seen from the front, the way a child
would: with a door, two windows, and a roof with a chimney. Feel free to
add details; maybe have “smoke” come out of the chimney.

8. Draw the Olympic five rings. If you can’t remember the colors, look
them up.

9. Display an image on the screen, e.g., a photo of a friend. Label the image
both with a title on the window and with a caption in the window.*/

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	Point t1 (100,100);
	Simple_window win (t1, 600,400,"Exercise");
	//win.wait_for_button();
	
	// 1. feladat: Rajzoljon egy téglalapot, mint Rectangle és mint Polygon
	// Legyen a Polygon körvonal színe piros, a Rectangle színe kék
	Rectangle r {Point{50,50},50,25};
	r.set_color(Color::blue);
	win.attach(r);

	Polygon rect;
	rect.add(Point{125,50});
	rect.add(Point{175,50});
	rect.add(Point{175,75});
	rect.add(Point{125,75});
	r.set_color(Color::red);
	 win.attach(rect);

	win.set_label("1. feladat");
	win.wait_for_button();

	// 2. feladat: Rajzoljon egy 100x30-as téglalapot és írjuk a belsejébe hogy "Howdy!"
	Rectangle rt{Point{200,50},100,30};
    win.attach(rt);

    Text t {Point{205,75},"Howdy!"};
    t.set_font(Font::helvetica_bold);
    t.set_font_size(20);
    win.attach(t);

	win.set_label("2. feladat");
	win.wait_for_button();

	// 3. feladat: Rajzolja meg a monogramját 150 pixel magasra, bold betűtípus, legyenek különböző színűek
	Text t2 {Point{20,350},"Sz"};
	t2.set_font(Font::courier_bold);
	t2.set_font_size(150);

	Text t3 {Point{200,350},"M"};
	t2.set_font(Font::courier_bold);
	t2.set_font_size(150);
	t2.set_color(Color::yellow);
	t3.set_font_size(150);
	t3.set_color(Color::green);
	win.attach(t2);
	win.attach(t3);

	win.set_label("3. feladat");
	win.wait_for_button();

	// 4. feladat: Rajzoljon egy 3x3-as amőba táblát piros és fehér színekkel
	Vector_ref<Rectangle> vr;
	int w = 50;
	for (int row=0; row <3; ++row){
		for(int col = 0; col<3; ++col){
			vr.push_back(new Rectangle {Point{350+w*col,200+w*row},w,w});
			int i = vr.size() - 1;
			i % 2 == 0 ? vr[i].set_fill_color(Color::red) : vr[i].set_fill_color(Color::white);
			win.attach(vr[i]);
		}
	}
	win.set_label("4. feladat");
	win.wait_for_button();

	// 5. feladat: Rajzoljon piros ¼ hüvelykes keretet egy téglalap köré,
	// amely háromnegyede a képernyő magasságának és kétharmada szélességű
	Rectangle huge {Point{150,160},x_max() * 2 / 3, y_max() * 3 / 4};
	huge.set_style(Line_style(Line_style::solid, 8));
	huge.set_color(Color::red);
	win.attach(huge);

	win.set_label("5. feladat");
	win.wait_for_button();

	// 6. feladat: Mi történik, ha olyan alakzatot rajzol, amely nem fér bele az ablakába?
	// Mi történik, ha olyan ablakot rajzol, amely nem fér el a képernyőn?
	// Írjon két programot, amelyek szemléltetik ezt a két jelenséget!
	Polygon poly;
	poly.add(Point{550,100});
	poly.add(Point{200,600});
	poly.add(Point{800,600});
	Point t4 (200,200);
	win.attach(poly);
	win.set_label("6./a feladat");
	win.wait_for_button();
	Simple_window win2 (t4, 2000,1000,"6./b feladat");
	win2.wait_for_button();
	// 7. feladat: Rajzoljon egy kétdimenziós házat elölről nézve, 
	// ajtóval, két ablakkal és kéményes tetővel. Adjon hozzá részleteket;
	// pl.: „füst” jön ki a kéményből.
	Rectangle house {Point{100,150},300,200};
	house.set_color(Color::yellow);
	house.set_fill_color(Color::yellow);
	win.attach(house);
	Rectangle door {Point{225,250},60,100};
	door.set_color(Color::blue);
	door.set_fill_color(Color::blue);
	win.attach(door);
	Rectangle window1 {Point{135,175},75,75};
	window1.set_color(Color::white);
	window1.set_fill_color(Color::white);
	win.attach(window1);
	Rectangle window2 {Point{295,175},75,75};
	window2.set_color(Color::white);
	window2.set_fill_color(Color::white);
	win.attach(window2);
	Polygon teto;
	teto.add(Point{250,50});
	teto.add(Point{100,150});
	teto.add(Point{400,150});
	teto.set_fill_color(Color::red);
	Point t5 (100,100);
	win.attach(teto);
	win.set_label("7. feladat");
	win.wait_for_button();

	Circle c1 {Point{100,200},50};
	c1.set_color(Color::blue);
	win.attach(c1);
	Circle c2 {Point{210,200},50};
	win.attach(c2);
	Circle c3 {Point{320,200},50};
	c3.set_color(Color::red);
	win.attach(c3);
	Circle c4 {Point{155,250},50};
	c4.set_color(Color::yellow);
	win.attach(c4);
	Circle c5 {Point{265,250},50};
	c5.set_color(Color::green);
	win.attach(c5);
	win.set_label("8. feladat");
	win.wait_for_button();

	Image ii {Point{0,50},"friend.jpg"};
	win.attach(ii);
	win.set_label("9. feladat: Photo of a friend");
	Text barat {Point{205,380},"Photo of a friend"};
    barat.set_font(Font::helvetica_bold);
    barat.set_font_size(20);
    win.attach(barat);
	win.wait_for_button();
}
//g++ -w -Wall -std=c++0x Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex01.cpp `fltk-config --ldflags --use-images` -o a.out
