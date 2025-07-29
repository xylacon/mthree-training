#ifndef BASE_B_H
#define BASE_B_H

#include <iostream>

class BaseB {
public:
	BaseB() {
		std::cout << "Default constructor: BaseB()\n";
	}
	BaseB(int var) {
		std::cout << "Parameterized constructor: BaseB(int) ... var = " << var << '\n';
	}
};

#endif