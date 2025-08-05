#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

#include <iostream>

// Assignment 2
class Circle : public Shape {
public:
	void get_data(const double r) {
		radius = r;
	}
	void display_area() const override {
		const double area = PI * radius * radius;
		std::cout << "Circle area: " << area << '\n';
	}
private:
	static constexpr double PI = 3.14159265358979323846;
	double radius;
};

#endif