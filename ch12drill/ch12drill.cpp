// g++ ch12drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
/*
1. Get an empty Simple_window with the size 600 by 400 and a label My
window compiled, linked, and run. Note that you have to link the FLTK
library as described in Appendix D; #include Graph.h and Simple_
window.h in your code; and include Graph.cpp and Window.cpp in your
project.
 2. Now add the examples from §12.7 one by one, testing between each
added subsection example.
 3. Go through and make one minor change (e.g., in color, in location, or in
number of points) to each of the subsection examples.*/

#include "Simple_window.h"
#include "Graph.h"
int main()
{
 using namespace Graph_lib;
 Point tl {100,100};
 Simple_window win {tl,600,400,"My window"};
 win.wait_for_button();
 Axis xa {Axis::x, Point{20,375}, 300, 10, "x tengely"};
 xa.set_color(Color::blue);
 xa.label.set_color(Color::blue);
 win.attach(xa);
 win.set_label("My window #2");
 win.wait_for_button();

 Axis ya {Axis::y, Point{20,375}, 300, 10, "y tengely"};
 ya.set_color(Color::blue);
 ya.label.set_color(Color::blue);
 win.attach(ya);
 win.set_label("My window #3");
 win.wait_for_button();

 Function sine {sin,0,100,Point{20,300},1000,50,50};
 win.attach(sine);
 win.set_label("My window #4");
 win.wait_for_button();

 sine.set_color(Color::black);
 Polygon poly;
 poly.add(Point{50,350});
 poly.add(Point{100,250});
 poly.add(Point{150,350});
 poly.set_color(Color::red);
 poly.set_style(Line_style::dash);
 win.attach(poly);
 win.set_label("My window #5");
 win.wait_for_button();

 Closed_polyline poly_rect;
 poly_rect.add(Point{50,200});
 poly_rect.add(Point{150,200});
 poly_rect.add(Point{150,250});
 poly_rect.add(Point{50,250});
 //poly_rect.add(Point{25,225});
 win.attach(poly_rect);
 Rectangle r {Point{50,150}, 100, 50};
 win.attach(r);
 win.set_label("My window #6");
 win.wait_for_button();

 r.set_fill_color(Color::yellow);
 poly.set_style(Line_style(Line_style::dash,6));
 poly_rect.set_style(Line_style(Line_style::dash,4));
 poly_rect.set_fill_color(Color::green);
 win.set_label("My window #7");
 win.wait_for_button();

 Text t {Point{10,25}, "Hello, graphical world!"};
 t.set_color(Color::red);
 win.attach(t);
 win.set_label("My window #8");
 win.wait_for_button();

 t.set_font(Font::times_bold);
 t.set_font_size(20);
 win.set_label("My window #9");
 win.wait_for_button();

 Image ii {Point{100,50},"image.jpg"};
 win.attach(ii);
 win.set_label("My window #10");
 win.wait_for_button();

 ii.move(175,5);
 win.set_label("My window #11");
 win.wait_for_button();

 Circle c {Point{100,200},50};
 Mark m {Point{100,205},'x'};
 ostringstream oss;
 //oss << "képernyő méret: " << x_max() << "*" << y_max() << "; ablak méret: " << win.x_max() << "*" << win.y_max();
 //Text sizes {Point{100,20},oss.str()};
 Image cal {Point{225,50},"pepe.gif"};
 cal.set_mask(Point{30,10},225,250);
 win.attach(c);
 win.attach(m);
 //win.attach(sizes);
 win.attach(cal);
 win.set_label("My window #12");
 win.wait_for_button();
}