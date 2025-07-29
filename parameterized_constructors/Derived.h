#ifndef DERIVED_H
#define DERIVED_H

#include "BaseA.h"
#include "BaseB.h"

#include <iostream>

class Derived : public BaseA, public BaseB {
public:
	Derived() {
		std::cout << "Default constructor: Derived()\n";
	}
	Derived(int var) : BaseA(var), BaseB(var) {
		std::cout << "Parameterized constructor: Derived(int) ... var = " << var << '\n';
	}
	Derived(int var1, int var2) : BaseA(var1), BaseB() {
		std::cout << "Parameterized constructor: Derived(int, int) ... var1 = " << var1 << ", var2 = " << var2 << '\n';
	}
};

#endif