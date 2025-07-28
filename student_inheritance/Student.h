#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student {
public:
	void set_number(const int rno) {
		roll_number = rno;
	}
	void print_number() {
		std::cout << "Roll Number: " << roll_number << '\n';
	}

protected:
	int roll_number;
};

#endif