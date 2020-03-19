#pragma once
#include "gnuplot_i.hpp"

struct Point {
	int x;
	int y;
	int bias;
	int label;
	Point(int _x, int _y, int _label) :
		x(_x), y(_y), bias(1), label(_label) {}
};

Gnuplot gp;

void draw_graph(double a, double b, int count) {
	gp.set_title("Perceptron æw. 1");
	gp.set_xlabel("X axis");
	gp.set_ylabel("Y axis");
	gp.set_style("lines");
	//gp.set_grid();
	gp.set_xrange(a, b);
	gp.set_yrange(a, b);
	gp.plot_equation("2 * x - 2");
}

void draw_point(double x, double y) {
	gp.set_style("points");
	gp.plot_xy(std::vector<double>({ x }), std::vector<double>({ y }));
}

void draw_set_of_points(std::vector<Point> data) {
	gp.set_style("points");

	std::vector<int> x0, y0, x1, y1;

	for (int i = 0; i < data.size(); i++) {
		if (data[i].label == 0) {
			x0.push_back(data[i].x);
			y0.push_back(data[i].y);
		}
		else {
			x1.push_back(data[i].x);
			y1.push_back(data[i].y);
		}
	}

	gp.plot_xy(x0, y0, "class 0");
	gp.plot_xy(x1, y1, "class 1");
}