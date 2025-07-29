#ifndef DERIVED_A_H
#define DERIVED_A_H

#include "Base.h"

#include <iostream>

class DerivedA : public Base {
public:
	DerivedA() : Base() {}
	DerivedA(int var) : Base(var) { std::cout << "DerivedA\n"; }
};

#endif