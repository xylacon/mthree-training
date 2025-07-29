#ifndef DERIVED_B_H
#define DERIVED_B_H

#include "Base.h"

#include <iostream>

class DerivedB : public Base {
public:
	DerivedB() : Base() {}
	DerivedB(int var) : Base(var) { std::cout << "DerivedB\n"; }
};

#endif