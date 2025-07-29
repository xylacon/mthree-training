#ifndef DERIVED_B_VIRTUAL_H
#define DERIVED_B_VIRTUAL_H

#include "Base.h"

#include <iostream>

class DerivedB_virtual : virtual public Base {
public:
	DerivedB_virtual() : Base() {}
	DerivedB_virtual(int var) : Base(var) { std::cout << "DerivedB (virtual)\n"; }
};

#endif