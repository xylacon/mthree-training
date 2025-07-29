#ifndef DERIVED_C_PUBLIC_PUBLIC_H
#define DERIVED_C_PUBLIC_PUBLIC_H

#include "DerivedA.h"
#include "DerivedB.h"

#include <iostream>

class DerivedC_public_public : public DerivedA, public DerivedB {
public:
	DerivedC_public_public() : DerivedA(), DerivedB() {}
	DerivedC_public_public(int var1, int var2) : DerivedA(var1), DerivedB(var2) { std::cout << "Derived C (public,public)\n"; }
};

#endif