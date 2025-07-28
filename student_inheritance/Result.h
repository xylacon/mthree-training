#ifndef RESULT_H
#define RESULT_H

#include "Test.h"

#include <iostream>

class Result : private Test {
public:
	/*
		Since we set inheritance to private,
		we can instead access private methods
		through a constructor.
	*/
	Result(const int num, const float mark1, const float mark2) {
		set_number(num);
		set_marks(mark1, mark2);
	}
	
	void calculate_result() {
		total = subject1 + subject2;
		print_number();
		print_marks();
		std::cout << "Result: " << total << '\n';
	}

private:
	float total;
};

#endif