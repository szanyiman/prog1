#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
//1/4. Add double slope(double x) { return x/2; } to the window.
double slope(double x) { return x/2; }
//1/6. Add double square(double x) { return x*x; } to the window
double square(double x) { return x*x; }
/*1/9. Write a function sloping_cos() that adds a cosine to slope() (as defined above)
and add it to the window.*/
double sloping_cos(double x) { return cos(x) + slope(x); }

int main(){

    const int xmax = 600;
    const int ymax = 600;

    const int x_orig = xmax/2;
    const int y_orig = ymax/2;
    const Point orig(x_orig,y_orig);

    const int r_min = -10;
    const int r_max = 11;

    const int n_points = 400;

    const int x_scale = 20;
    const int y_scale = 20;

//1. Make an empty 600-by-600 Window labeled “Function graphs.”
    Point tl(600,50);
    Simple_window win(tl,xmax,ymax,"Function graphs");

    const int xlength = xmax - 200;
    const int ylength = ymax - 200;

/*4. Add an x axis and a y axis each of length 400, labeled “1 = = 20 pixels”
and with a notch every 20 pixels. The axes should cross at (300,300).*/
    Axis x(Axis::x,Point(100,y_orig),xlength,xlength/x_scale,"1 == 20 pixels");
    Axis y(Axis::y,Point(x_orig,500),ylength,ylength/y_scale,"1 == 20 pixels");
//5. Make both axes red.
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);
    win.wait_for_button();

/*1/1. Graph the function double one(double x) { return 1; } in the range [–10,11]
with (0,0) at (300,300) using 400 points and no scaling (in the window).*/
    Function s(one,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(s);
    win.wait_for_button();

//1/2. Change it to use x scale 20 and y scale 20
    Function s2(slope,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(s2);
    win.wait_for_button();

//1/5. Label the slope with a Text "x/2" at a point just above its bottom left end point.
    Text texts2(Point(100,y_orig+4*y_scale),"x/2");
    win.attach(texts2);
    win.wait_for_button();

//1/6. Add double square(double x) { return x*x; } to the window.
    Function s3(square,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(s3);
    win.wait_for_button();

//1/7. Add a cosine to the window.
    Function s4(cos,r_min,r_max,orig,n_points,x_scale,y_scale);
//1/8. Make the cosine blue
    s4.set_color(Color::blue);
    win.attach(s4);
    win.wait_for_button();

/*1/9. Write a function sloping_cos() that adds a cosine to slope() (as defined
above) and add it to the window.*/
    Function s5(sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(s5);
    win.wait_for_button();
}