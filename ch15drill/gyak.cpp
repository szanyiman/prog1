#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }

int main(){

	using namespace Graph_lib;
	constexpr int x_orig = xmax/2; // position of (0,0) is center of window
	constexpr int y_orig = ymax/2;
	constexpr Point orig {x_orig,y_orig};

	constexpr int r_min = –10; // range [–10:11)
	constexpr int r_max = 11;

	constexpr int n_points = 400; // number of points used in range

	constexpr int x_scale = 30; // scaling factors
	constexpr int y_scale = 30;
	Simple_window win {Point{100,100},600,400,"Function graphing"};
	Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};
	win.attach(s);
	win.attach(s2);
	win.attach(s3);
	win.wait_for_button();

}