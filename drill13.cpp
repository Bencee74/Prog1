#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point p1 {100,100};
	int x_max = 800;
	int y_max = 1000;
	
	Simple_window win (p1, x_max, y_max, "Drill 13");
	
	Lines grid;
	
	for (int x = 100; x < x_max; x += 100)
	{
		grid.add(Point{x, 0}, Point(x, y_max-200));
	}
	
	for (int y = 100; y < y_max; y += 100)
	{
		grid.add(Point{0, y}, Point(x_max, y));
	}
	
	win.attach(grid);
	
	Vector_ref<Rectangle> r;
	
	for (int i = 0; i < 8; i++)
	{
		r.push_back(new Rectangle {Point{i*100, i*100}, 100, 100});
		r[i].set_fill_color(Color::red);
		win.attach(r[i]);
	}
	
	Image i1 (Point{200, 600}, "soccer.jpg");
	Image i2 (Point{600, 400}, "soccer.jpg");
	Image i3 (Point{400, 0}, "soccer.jpg");
	
	win.attach(i1);
	win.attach(i2);
	win.attach(i3);
	
	Image basket (Point{0, 0}, "basket.jpg");
	win.attach(basket);
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			win.wait_for_button();
			if (j < 7) basket.move(100, 0);
			else basket.move(-700, 100);
		}
	}
	
	win.wait_for_button();
	
}
