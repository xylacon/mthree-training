#ifndef TEST_H
#define TEST_H

#include "Student.h"

#include <iostream>

class Test : protected Student {
public:
	void set_marks(const float mark1, const float mark2) {
		subject1 = mark1;
		subject2 = mark2;
	}
	void print_marks() {
		std::cout << "Marks of subject1: " << subject1 << '\n';
		std::cout << "Marks of subject2: " << subject2 << '\n';
	}

protected:
	float subject1, subject2;
};

#endif