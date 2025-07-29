#ifndef BASE_A_H
#define BASE_A_H

#include <iostream>

class BaseA {
public:
	BaseA() {
		std::cout << "Default constructor: BaseA()\n";
	}
	BaseA(int var) {
		std::cout << "Parameterized constructor: BaseA(int) ... var = " << var << '\n';
	}
};

#endif