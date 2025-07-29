#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base {
public:
	int var;

	Base() : var(0) {}
	Base(int _var) : var(_var) { std::cout << "Base\n"; }
};

#endif