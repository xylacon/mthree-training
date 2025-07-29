#ifndef DERIVED_C_VIRTUAL_VIRTUAL_H
#define DERIVED_C_VIRTUAL_VIRTUAL_H

#include "DerivedA_virtual.h"
#include "DerivedB_virtual.h"

#include <iostream>

class DerivedC_virtual_virtual : public DerivedA_virtual, public DerivedB_virtual {
public:
	DerivedC_virtual_virtual() : DerivedA_virtual(), DerivedB_virtual() {}
	DerivedC_virtual_virtual(int var1, int var2) : DerivedA_virtual(var1), DerivedB_virtual(var2) { std::cout << "Derived C (virtual,virtual)\n"; }
};

#endif