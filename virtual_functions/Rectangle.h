#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

#include <iostream>

// Assignment 1
class Rectangle : public Shape {
public:
	// Assignment 3: remove display_area()
	void display_area() const override {
		const double area = length1 * length2;
		std::cout << "Rectangle area: " << area << '\n';
	}
};

#endif