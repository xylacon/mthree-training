#ifndef DERIVED_C_VIRTUAL_PUBLIC_H
#define DERIVED_C_VIRTUAL_PUBLIC_H

#include "DerivedA_virtual.h"
#include "DerivedB.h"

#include <iostream>

class DerivedC_virtual_public : public DerivedA_virtual, public DerivedB {
public:
	DerivedC_virtual_public() : DerivedA_virtual(), DerivedB() {}
	DerivedC_virtual_public(int var1, int var2) : DerivedA_virtual(var1), DerivedB(var2) { std::cout << "Derived C (virtual,public)\n"; }
};

#endif