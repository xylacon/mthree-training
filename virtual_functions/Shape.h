#ifndef SHAPE_H
#define SHAPE_H

// Assignment 1
class Shape {
public:
	double length1;
	double length2;

	void get_data(const double val1, const double val2) {
		length1 = val1;
		length2 = val2;
	}
	virtual void display_area() const = 0;
};

#endif