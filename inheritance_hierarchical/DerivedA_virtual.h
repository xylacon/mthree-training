#ifndef DERIVED_A_VIRTUAL_H
#define DERIVED_A_VIRTUAL_H

#include "Base.h"

#include <iostream>

class DerivedA_virtual : virtual public Base {
public:
	DerivedA_virtual() : Base() {}
	DerivedA_virtual(int var) : Base(var) { std::cout << "DerivedA (virtual)\n"; }
};

#endif