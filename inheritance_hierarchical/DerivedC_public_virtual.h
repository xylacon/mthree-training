#ifndef DERIVED_C_PUBLIC_VIRTUAL_H
#define DERIVED_C_PUBLIC_VIRTUAL_H

#include "DerivedA.h"
#include "DerivedB_virtual.h"

#include <iostream>

class DerivedC_public_virtual : public DerivedA, public DerivedB_virtual {
public:
	DerivedC_public_virtual() : DerivedA(), DerivedB_virtual() {}
	DerivedC_public_virtual(int var1, int var2) : DerivedA(var1), DerivedB_virtual(var2) { std::cout << "Derived C (public,virtual)\n"; }
};

#endif