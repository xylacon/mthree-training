#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

#include <iostream>

// Assignment 1
class Triangle : public Shape {
public:
	void display_area() const override {
		const double area = length1 * length2 / 2;
		std::cout << "Triangle area: " << area << '\n';
	}
};

#endif