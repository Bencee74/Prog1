/*
	g++ drill15_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15_1 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

double one(double x) {return 1;};
double slope(double x) {return x/2;};
double square(double x) {return x*x;};
double sloping_cos(double x) {return slope(x)+cos(x);};


int main()
{
	Simple_window win{Point{100,100}, 600, 600, "Function graphs"};

	Axis x {Axis::x, Point{100,300}, 400, 20, "1 == 20 pixels"};
	Axis y {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	int range1 = -10;
	int range2 = 11;
	int points = 400;
	int x_scale = 20;
	int y_scale = 20;
	Point origo{300, 300};

	Function one_graph(one, range1, range2, origo, points, x_scale, y_scale);
	Function slope_graph(slope, range1, range2, origo, points, x_scale, y_scale);
	Text slope_label{Point{100, 385}, "x/2"};
	Function square_graph(square, range1, range2, origo, points, x_scale, y_scale);
	Function cosine([] (double x) {return cos(x);}, range1, range2, origo, points, x_scale, y_scale);
	cosine.set_color(Color::blue);
	Function sloping_cos_graph(sloping_cos, range1, range2, origo, points, x_scale, y_scale);


	win.attach(x);
	win.attach(y);
	win.attach(one_graph);
	win.attach(slope_graph);
	win.attach(slope_label);
	win.attach(square_graph);
	win.attach(cosine);
	win.attach(sloping_cos_graph);

	win.wait_for_button();
}
