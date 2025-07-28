#ifndef DERIVED_PROTECTED_H
#define DERIVED_PROTECTED_H

#include "Base.h"

class DerivedProtected : protected Base {
public:
	DerivedProtected() : Base("DerivedProtected", "DerivedProtected", "DerivedProtected") {}

	void print() override {
		std::cout << "DERIVED_PROTECTED\n"
			<< "publicVar: " << publicVar << '\n'
			<< "protectedVar: " << protectedVar << '\n'
			<< "privateVar: inaccessible" << '\n'; 
	}
};

#endif